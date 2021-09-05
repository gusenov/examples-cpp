#ifndef FILE_SYSTEM_HPP
#define FILE_SYSTEM_HPP


#include <string>
#include <cstring>
#include <cstdio>
#include <cerrno>
#include <fstream>
#include <cwchar>
#include <exception>

#ifdef __APPLE__
    #include <sys/stat.h>
    #include <limits.h>
    #include <fts.h>
    #include <ftw.h>
    #include <dirent.h>
    #define FILE_SEPARATOR L'/'
#elif defined _WIN32 || defined _WIN64
    #define FILE_SEPARATOR '/'
    #define PATH_MAX 260
#endif

#include "StrUtils.hpp"

namespace filesystem {

class path {
public:
    ~path() = default;

    path(path const &other): path(other.wstring()) {
    }

    path & operator=(path const& other) {
        path copy(other);
        swap(*this, copy);
        return *this;
    }

    path() = default;

    explicit path(wchar_t const *const str): path() {
        p_ = str;
        std::replace(p_.begin(), p_.end(), L'\\', FILE_SEPARATOR);
    }

    explicit path(std::wstring const &str): path() {
        p_ = str;
        std::replace(p_.begin(), p_.end(), L'\\', FILE_SEPARATOR);
    }

    path parent_path() const {
        size_t found;
        found = p_.find_last_of(L"/\\");
        if (std::wstring::npos != found) {
            path folder(p_.substr(0, found));
            return folder;
        } else {
            return path();
        }
    }

    path filename() const {
        wchar_t const *name = nullptr;
        (name = wcsrchr(p_.c_str(), FILE_SEPARATOR)) ? ++name : (name = p_.c_str());
        return path(name);
    }

    path stem() const {
        std::wstring name(filename().wstring());
        size_t lastdot = name.find_last_of('.');
        if (lastdot == std::wstring::npos)
            return path(name);
        return path(name.substr(0, lastdot));
    }

    path extension() const {
        std::wstring name(filename().c_str());
        size_t lastdot = name.find_last_of(L".");
        if (lastdot == std::wstring::npos)
            return path(L"");
        return path(name.substr(lastdot));
    }

    std::wstring wstring() const {
        return p_;
    }

    std::string string() const {
        return StrUtils::ToStdString(p_);
    }

    wchar_t const * c_str() const {
        return p_.c_str();
    }

    path & operator+=(std::wstring const &str) {
        p_ += str;
        return *this;
    }

    path & operator+=(wchar_t const ch) {
        p_ += ch;
        return *this;
    }

private:
    std::wstring p_;

    friend void swap(path& lhs, path& rhs) noexcept {
        std::swap(lhs.p_, rhs.p_);
    }

    friend inline path operator/(const path& lhs, std::wstring const &rhs);
    friend inline path operator/(path const &lhs, path const &rhs);
    friend inline bool operator==( const path& lhs, const path& rhs );
    friend inline bool operator!=( const path& lhs, const path& rhs );
};

inline path operator/(const path& lhs, std::wstring const &rhs) {
    path result(lhs);
    if (FILE_SEPARATOR != lhs.p_.back()) { result += FILE_SEPARATOR; }
    result += rhs;
    return result;
}

inline path operator/(path const &lhs, path const &rhs) {
    return lhs / rhs.c_str();
}

inline bool operator==( const path& lhs, const path& rhs ) {
    return lhs.p_ == rhs.p_;
}

inline bool operator!=( const path& lhs, const path& rhs ) {
    return !(lhs == rhs);
}

#ifdef __APPLE__
inline bool exists(path const &p) {
    auto path = StrUtils::ToStdString(p.wstring());
    struct stat st;
    int status = stat(path.c_str(), &st);
    return status == 0;
#else
inline bool exists(path const &) {
    assert(false);
    return false;
#endif
}

#ifdef __APPLE__
inline bool create_directories(path const &p) {
    int status = -1;
    mode_t mode = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;
    std::wstring tmp = p.wstring();
    if (tmp.back() == FILE_SEPARATOR) tmp.pop_back();
    for (size_t i = 1; i < tmp.length(); ++i) {
        if (tmp.at(i) == FILE_SEPARATOR) {
            auto sub = tmp.substr(0, i);
            if (!exists(filesystem::path(sub))) {
                auto path = StrUtils::ToStdString(sub);
                status = mkdir(path.c_str(), mode);
                if (status) return false;
            }
        }
    }
    auto path = StrUtils::ToStdString(tmp);
    status = mkdir(path.c_str(), mode);
    return !status;
#else
inline bool create_directories(path const &) {
    return false;
#endif
}

inline bool is_directory(path const &p) {
    auto pathname = StrUtils::ToStdString(p.wstring());
    struct stat info;
    return stat( pathname.c_str(), &info ) != 0 ? false : info.st_mode & S_IFDIR;
}

inline std::uintmax_t file_size(const path &p) {
    std::ifstream in;
#ifdef __APPLE__
    auto pathStr = StrUtils::ToStdString(p.wstring());
    in.open(pathStr.c_str(), std::ifstream::ate | std::ifstream::binary);
#elif __GNUC__
#elif _MSC_VER
    in.open(p.c_str(), std::ifstream::ate | std::ifstream::binary);
#else
#error "Your compiler is not supported"
#endif
    return in.tellg();
}

#ifdef __APPLE__
inline std::uintmax_t remove_all(path const &p) {
    FTS *ftsp = nullptr;
    FTSENT *curr;
    auto path = StrUtils::ToStdString(p.wstring());
    char *files[] = { const_cast<char *>(path.c_str()), nullptr };
    ftsp = fts_open(files, FTS_NOCHDIR | FTS_PHYSICAL | FTS_XDEV, NULL);
    if (!ftsp) {
        goto finish;
    }
    while ((curr = fts_read(ftsp))) {
        switch (curr->fts_info) {
            case FTS_DP:
            case FTS_F:
            case FTS_SL:
            case FTS_SLNONE:
            case FTS_DEFAULT:
                remove(curr->fts_accpath);
                break;
        }
    }
    finish:
    if (ftsp)
        fts_close(ftsp);
    return 0;
#else
inline std::uintmax_t remove_all(path const &) {
    return 0;
#endif
}

inline bool remove(path const &p) {
    bool result = false;
#ifdef __APPLE__
    auto path = StrUtils::ToStdString(p.wstring());
    result = std::remove(path.c_str()) == 0;
#else
#endif
    return result;
}

inline path relative(path const &p, path const &base) {
    auto newpath = p.wstring();
    auto nit = newpath.begin();
    auto basepath = base.wstring();
    for (auto bit = basepath.begin(); bit != basepath.end(); ++bit, ++nit)
        ;

    if (*nit == L'/')
        ++nit;

    auto str = std::wstring(nit, newpath.end());
    return path(str);
}

class directory_entry {
public:
    directory_entry() = default;

    ~directory_entry() = default;

    directory_entry(directory_entry const &other): _path(other._path) {
    }

    explicit directory_entry(filesystem::path const &path) : _path(path) {
    }

    directory_entry & operator=(directory_entry const &other) {
        _path = other._path;
        return *this;
    }

    filesystem::path const & path() const {
        return _path;
    }

private:
    filesystem::path _path;
};

class directory_iterator {
public:
    using iterator_category = std::input_iterator_tag;
    using value_type = filesystem::directory_entry;
    using difference_type = std::ptrdiff_t;
    using pointer = filesystem::directory_entry const *;
    using reference = filesystem::directory_entry const &;

    directory_iterator() {
        _dir = nullptr;
        _ent = nullptr;
    }

    directory_iterator(directory_iterator const &other): _dirPath(other._dirPath) {
        auto dirPath = StrUtils::ToStdString(_dirPath.wstring());
        _dir = opendir(dirPath.c_str());
        if (_dir)
            _inc();
    }

    explicit directory_iterator(filesystem::path const &path) : _dirPath(path) {
        auto dirPath = StrUtils::ToStdString(_dirPath.wstring());
        _dir = opendir(dirPath.c_str());
        if (_dir)
            _inc();
    }

    ~directory_iterator() {
        if (_dir)
            closedir(_dir);
    }

    directory_iterator & operator++() {
        _inc();
        return *this;
    }

    reference operator*() const {
        return _dirEnt;
    }

    pointer operator->() const {
        return &_dirEnt;
    }

    bool operator==(directory_iterator const &other) const {
        if (_ent && other._ent)
            return std::string(_ent->d_name) == std::string(other._ent->d_name);
        return _ent == other._ent;
    }

    bool operator!=(directory_iterator const &other) const {
        return !(*this == other);
    }

private:
    void _inc() {
        do {
            _ent = readdir(_dir);
            if (_ent) {
                std::string relPath(_ent->d_name);
                if ("." == relPath || ".." == relPath)
                    continue;
            }
            break;
        } while (true);

        if (_ent) {
            std::string d_name(_ent->d_name);
            auto relPath = StrUtils::ToStdWString(d_name);
            auto fullPath = _dirPath / relPath;
            _dirEnt = directory_entry(fullPath);
        }
    }

    filesystem::path _dirPath;
    value_type _dirEnt;

    DIR *_dir = nullptr;
    struct dirent *_ent = nullptr;
};

static directory_iterator begin(directory_iterator it) {
    return it;
}

static directory_iterator end(directory_iterator const &) {
    return directory_iterator();
}

class filesystem_error : public std::system_error {
};

enum class copy_options {
    none,
    skip_existing,
    overwrite_existing,
    update_existing,
    recursive,
    copy_symlinks,
    skip_symlinks,
    directories_only,
    create_symlinks,
    create_hard_links,
};

namespace {

thread_local filesystem::path g_sourceRootPath;
thread_local filesystem::path g_destinationRootPath;

}

extern "C" {

static int copy_file(char const* aSourcePath, struct stat const* aFileStatus, int aInfoAboutCurrentFile)
{
    auto sourcePath = filesystem::path(StrUtils::ToStdWString(aSourcePath));
    auto destinationPath = g_destinationRootPath / filesystem::relative(sourcePath, g_sourceRootPath);
    auto destinationPathAsStdString = destinationPath.string();
    switch (aInfoAboutCurrentFile)
    {
    case FTW_D:
        mkdir(destinationPathAsStdString.c_str(), aFileStatus->st_mode);
        break;
    case FTW_F:
        std::ifstream fin(aSourcePath, std::ios::binary);
        std::ofstream fout(destinationPathAsStdString, std::ios::binary);
        fout << fin.rdbuf();
    }
    return 0;
}

}

static void copy(const filesystem::path& from, const filesystem::path& to, filesystem::copy_options options)
{
    g_sourceRootPath = from;
    g_destinationRootPath = to;
    ftw(from.string().c_str(), copy_file, OPEN_MAX);
}

}

#endif  // FILE_SYSTEM_HPP

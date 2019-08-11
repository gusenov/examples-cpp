#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

void TestStreamConsole() {
  std::cout << "Hello, world!" << std::endl;  // std::cout - это объект std::ostream.
  // А std::cin - это объект std::istream.
}

void TestStreamFile() {
  // Манипулировать содежимым файлов можно с помощью:
  // std::ofstream, std::ifstream и std::fstream.
}

void TestStreamString() {
  std::ostringstream oss;
  oss << "Hello, world!\n";
  oss << 123 << '\n';
  std::string s = oss.str();
  // Читать данные из строки можно с помощью std::istringstream и оператора >>.
}

void TestStreamLog() {
  std::ostringstream oss;

  // Сделать так чтобы clog использовал буфер из oss:
  std::streambuf *former_buff = std::clog.rdbuf(oss.rdbuf());

  std::clog << "This will appear in oss!" << std::flush;

  std::cout << oss.str() << "\n";

  // Вернуть обратно clog-у его предыдущий буфер:
  std::clog.rdbuf(former_buff);
}

int main(int argc, char* argv[]) {
  TestStreamConsole();
  TestStreamFile();
  TestStreamString();
  TestStreamLog();
  return EXIT_SUCCESS;
}

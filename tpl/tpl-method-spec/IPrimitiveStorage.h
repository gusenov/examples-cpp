#ifndef IPrimitiveStorage_h
#define IPrimitiveStorage_h


struct IPrimitiveStorage {
    virtual ~IPrimitiveStorage() = default;

    virtual char& GetRefOfChar() = 0;
    virtual signed char& GetRefOfSignedChar() = 0;
    virtual char signed& GetRefOfCharSigned() = 0;
    virtual unsigned char& GetRefOfUnsignedChar() = 0;

    template<class T>
    T* GetPointerOf() {
        return nullptr;
    }

    template<>
    unsigned char* GetPointerOf<unsigned char>();
};

template<>
char* IPrimitiveStorage::GetPointerOf<char>();

template<>
signed char* IPrimitiveStorage::GetPointerOf<signed char>();

// template<>
// char signed* IPrimitiveStorage::GetPointerOf<char signed>();

#endif /* IPrimitiveStorage_h */

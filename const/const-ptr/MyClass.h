#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
public:
    MyClass() {
        pi_ = new int;
    }

    ~MyClass() {
        delete pi_;
    }

    int GetInt() const;
    void SetInt(int i);

    int* GetIntPtr() const;
    void SetIntPtr(int* pi);

private:
    int* pi_;
};

#endif  // MYCLASS_H

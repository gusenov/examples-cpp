// conversion_detection.h

// Code taken almost verbatim from Andrei Alexandrescu's article:
//    http://www.cuj.com/experts/1810/alexandr.html

// I need this helper or else dumb g++ chokes.
template <class T, class U>
struct ConversionHelper {
   typedef char Small;
   struct Big { char dummy[2]; };
   static Small Test(U);
   static Big   Test(...);
   static T MakeT();
};

template <class T, class U>
struct Conversion {
   typedef ConversionHelper<T,U> H;
   enum { exists = sizeof(H::Test(H::MakeT())) == sizeof(H::Small) };
   enum { exists2Way = exists && Conversion<U, T>::exists };
   enum { sameType = false };
};

template <class T>
class Conversion<T, T> {
public:
   enum { exists = 1, exists2Way = 1, sameType = 1 };
};

// I dislike the SUPERSUBCLASS macro, so I use this.
template <class Derived, class Base>
struct Inherits {
   enum { value = (Conversion<const Derived*, const Base*>::exists && 
                   !Conversion<const Base*, const void*>::sameType) };
};


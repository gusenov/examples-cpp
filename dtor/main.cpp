#include <iostream>
#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"
#include "E.h"
#include "F.h"
#include "G.h"
#include "H.h"
#include "I.h"
#include "J.h"
#include "K.h"
#include "L.h"
#include "M.h"
#include "N.h"
#include "O.h"
#include "P.h"
#include "Q.h"
#include "R.h"
#include "S.h"
#include "T.h"
#include "U.h"
#include "V.h"
#include "W.h"
#include "X.h"
#include "Y.h"
#include "Z.h"

void expnum(int no) {
  std::cout << "Эксперимент № " << no << std::endl;
}

int main(int argc, char* argv[]) {

  expnum(1);
  // A *a = new A();
  // delete a;  // error: ‘A::~A()’ is private within this context

  expnum(2);
  // B *b = new B();  // error: use of deleted function ‘B::B()’

  expnum(3);
  // E *e = new E();
  // delete e;  // error: ‘E::~E()’ is protected within this context

  expnum(4);
  C *c = new C();
  delete c;

  expnum(5);
  D *d = new D();  // class D : C
  delete d;

  expnum(6);
  F *f = new F();  // class F : E
  delete f;
  // OUTPUT:
  // ~F()
  // ~E()

  expnum(7);
  // G *g = new G();  // class G: A
  // delete g;

  //---------------------------------------------------------------------

  expnum(8);
  H *h = new H();
  delete h;
  // OUTPUT:
  // ~H()

  expnum(9);
  I *i = new I();  // class I : H
  delete i;
  // OUTPUT:
  // ~I()
  // ~H()

  expnum(10);
  // h = new I();  // error: ‘H’ is an inaccessible base of ‘I’

  //---------------------------------------------------------------------

  expnum(11);
  J *j = new J();
  delete j;
  // OUTPUT:
  // ~J()

  expnum(12);
  K *k = new K();  // class K : public J
  delete k;
  // OUTPUT:
  // ~K()
  // ~J()

  expnum(13);
  j = new K();  // class K : public J
  delete j;
  // OUTPUT:
  // ~J()

  //---------------------------------------------------------------------

  expnum(14);
  // L *l = new L();
  // In function `L::L()':
  // undefined reference to `vtable for L'

  expnum(15);
  // M *m = new M();  // class M : public L
  // In function `L::L()':
  // undefined reference to `vtable for L'
  // In function `M::~M()':
  // undefined reference to `L::~L()'
  // undefined reference to `typeinfo for L'

  //---------------------------------------------------------------------

  expnum(16);
  N *n = new N();
  delete n;
  // OUTPUT:
  // ~N()

  //---------------------------------------------------------------------

  expnum(17);
  O *o = new O();  // class O : public N
  delete o;
  // OUTPUT:
  // ~N()

  expnum(18);
  n = new O();  // class O : public N
  delete n;
  // OUTPUT:
  // ~N()

  //---------------------------------------------------------------------

  expnum(19);
  P *p = new P();  // class P : public N
  delete p;
  // OUTPUT:
  // ~P()
  // ~N()

  expnum(20);
  n = new P();  // class P : public N
  delete n;
  // OUTPUT:
  // ~P()
  // ~N()

  //---------------------------------------------------------------------

  expnum(21);
  // Q *q = new Q();
  // delete q;  // error: ‘Q::~Q()’ is protected within this context

  expnum(22);
  R *r = new R();  // class R : public Q
  delete r;
  // OUTPUT:
  // ~R()
  // ~Q()

  expnum(23);
  // Q *q = new R();
  // delete q;  // error: ‘Q::~Q()’ is protected within this context

  //---------------------------------------------------------------------

  expnum(24);
  // S *s = new S();
  // error: invalid new-expression of abstract class type ‘S’

  expnum(25);
  // T *t = new T();  // class T : public S
  // delete t;
  // warning: deleting object of polymorphic class type ‘T’
  // which has non-virtual destructor might cause undefined behavior
  // [-Wdelete-non-virtual-dtor]

  //---------------------------------------------------------------------

  // В U чисто виртуальный деструктор virtual ~U() = 0; без определения тела.

  expnum(26);
  // U *u = new U();
  // error: invalid new-expression of abstract class type ‘U’

  // В определении тела класса V ничего нет.

  expnum(27);
  // V *v = new V();  // class V : public U
  // In function `V::~V()':
  // undefined reference to `U::~U()'

  // В классе W определен публичный деструктор ~W() {}

  expnum(28);
  // W *w = new W();  // class W : public U
  // In function `W::~W()':
  // undefined reference to `U::~U()'

  //---------------------------------------------------------------------

  // В X чисто виртуальный деструктор virtual ~X() = 0; с определения тела.

  expnum(29);
  // X *x = new X();
  // error: invalid new-expression of abstract class type ‘X’

  // В определении тела класса Y ничего нет.

  expnum(30);
  Y *y = new Y();  // class Y : public X
  delete y;
  // OUTPUT:
  // ~X()

  expnum(31);
  X *x = new Y();
  delete x;
  // OUTPUT:
  // ~X()

  // В классе Z определен публичный деструктор.

  expnum(32);
  Z *z = new Z();
  delete z;
  // OUTPUT:
  // ~Z()
  // ~X()

  expnum(33);
  // x = new Z();
  // delete z;
  // pure virtual method called
  // terminate called without an active exception

  return 0;
}

// deriv_VirtualFunctions2.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

struct Alignment8 {
  int i;
  // char[4]
  double d; // max alignment 8
  short s;
  // char[6]
  Alignment8() : i(1), d(2), s(3) {}
}; // size is 24

struct Alignment4 {
  char a;
  char b;
  // char[2] - padding
  int i; // max alignment 4
  Alignment4() : a(1), b(2), i(3) {}
}; // size is 8

class Alone {
public:
  void FunctionA() { cout << "Alone Function A" << endl; }

  // Nonvirtual function.
  void FunctionB() { cout << "Alone Function B" << endl; }
};

class Base {
public:
  virtual void FunctionA() { cout << "Base Function A" << endl; }

  // Nonvirtual function.
  void FunctionB() { cout << "Base Function B" << endl; }
};

class Derived : public Base {
public:
  void FunctionA() { cout << "Derived Function A" << endl; }
  void FunctionB() { cout << "Derived Function B" << endl; }
};

int main() {
  // Declare an object of type Derived.
  Derived aDerived;

  // Declare two pointers, one of type Derived * and the other
  //  of type Base *, and initialize them to point to aDerived.
  Derived *pDerived = &aDerived;
  Base *pBase = &aDerived;

  // Call the functions.
  pBase->FunctionA();    // Call virtual function.
  pBase->FunctionB();    // Call nonvirtual function.
  pDerived->FunctionA(); // Call virtual function.
  pDerived->FunctionB(); // Call nonvirtual function.

  std::cout << sizeof(Alone) << " " << sizeof(Base) << " " << sizeof(Derived)
            << " " << sizeof(Alignment4)<< " " << sizeof(Alignment8) << std::endl;
}

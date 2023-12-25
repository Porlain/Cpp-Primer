# Chapter 18. **Tools for Large Programs**

## Exercise 18.1

> What is the type of the exception object in the following throws?

```c++
(a) range_error r("error");
	throw r;
(b) exception *p = &r;
	throw *p;
```

```
（a）range_error；
（b）exception
 // terminate called after throwing an instance of 'std::exception*'
```

## Exercise 18.2

> Explain what happens if an exception occurs at the indicated point:

```c++
void exercise(int *b, int *e)
{
    vector<int> v(b, e);            // the object v will be destroyed by its destructor.
    int *p = new int[v.size()];     // the dynamically allocated int array will be no way deallocated.
    ifstream in("ints");            // the object in will be destroyed.
    // exception occurs here
}
```

## Exercise 18.3

> There are two ways to make the previous code work correctly if an exception is thrown. Describe them and implement them.

The first approach is to mange it using a class. The second one is using smart pointer.

```c+
// first
struct P {
	int *p = nullptr;
	P(std::size_t n):p(new int[n]){}
	~P()
	{
		delete []p;
	}
};

// second 
std::shared_ptr<int> p(new int[v.size()], [](int *p) {delete p});
```

## Exercise 18.4

> Looking ahead to the inheritance hierarchy in Figure 18.1 (p.783), explain what’s wrong with the following try block. Correct it.

```c++
try {
	// use of the C++ standard library
} catch (exception) {
	// ...
} catch (const runtime_error &re) {
	// ...
} catch (overflow_error eobj) { /* ... */ }
```

```c++
try{
	// use of the C++ standard library
}catch(overflow_error eobj){
	// ...
}catch(const runtime_error &re){
	// ...
}catch(exception){
	// ...
}
```

## [Exercise 18.5](ex18_05.cpp)

> Modify the following main function to catch any of the exception types shown in Figure 18.1 (p. 783):

## Exercise 18.6

> Given the following exception types and catch clauses, write a throw expression that creates an exception object that can be caught by each catch clause:

```c++
(a) class exceptionType { };
	catch(exceptionType *pet) { }
(b) catch(...) { }
(c) typedef int EXCPTYPE;
	catch(EXCPTYPE) { }
```

```c++
(a) exceptionType *pet; thorw pet;
(b) Can capture all exceptions
(c) int a; throw a;
```

## Exercise 18.7

> Define your Blob and BlobPtr classes from Chapter 16 to use function try blocks for their constructors.

```c++
template <typename T>
Blob<T>::Blob()try :data(std::make_shared<vector<T>()>) {}
catch(const std::bad_alloc &e){
	handle_out_of_memory(e);
}
template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) try :data(make_shared<vector<T>>(il)) {}
catch(const std::bad_alloc &e){
	handle_out_of_memory(e);
}
```

```c++
template <typename T>
BlobPtr<T>::BlobPtr()try:curr(0){}
catch (const std::bad_alloc& e) {
	handle_out_of_memory(e);
}
template <typename T>
BlobPtr<T>::BlobPtr(Blob<T> &a, size_t sz = 0)try : wptr(a.data), curr(sz) {}
catch (const std::bad_alloc& e) {
	handle_out_of_momory(e);
}
```

## Exercise 18.8

> Review the classes you’ve written and add appropriate exception specifications to their constructors and destructors. If you think one of your destructors might throw, change the code so that it cannot throw.

```c++
// The key is to encapsulate the parts that may experience anomalies with try
class MyTest_Base
{
public:
	virtual ~MyTest_Base()
	{
		// Completely encapsulate exceptions within the construction function
		try {
			// Note: An exception was thrown in the destructor function
			throw std::exception("Intentionally throwing an exception in the destructor, testing！");
		}
		catch(...) {  }
	}

	void Func() throw()
	{
		throw std::exception("Intentionally throwing an exception, testing！");
	}
	void Other() {  }
}
```

## Exercise 18.9 [Header](ex18_09.h) | [CPP](ex18_09.cpp) | [TEST](ex18_09_test.cpp)

## [Exercise 18.10](ex18_09.h)

Same to ex18_9, When an uncaught exception occurs, the program will execute terminate.

## Exercise 18.11

> Why is it important that the what function doesn't throw?

If an exception is thrown in what, it needs to try catch and then call what, looping until memory is exhausted.

## Exercise 18.12

[Query.h](ex18_12_query.h) | [TextQuery.h](ex18_12_textquery.h)

## Exercise 18.13

> When might you use an unnamed namespace?

When it needs to be visible in the file it is located in and not visible outside the file it is located in;Static can only be used for variables and functions, and cannot be used for user-defined types.

you can also refer to [link1](http://stackoverflow.com/questions/154469/unnamed-anonymous-namespaces-vs-static-functions) | [link2](http://stackoverflow.com/questions/5312213/uses-of-unnamed-namespace-in-c)

## Exercise 18.14

> Suppose we have the following declaration of the operator* that is a member of the nested namespace mathLib::MatrixLib:

```c++
namespace mathLib {
	namespace MatrixLib {
		class matrix { /* ... */ };
		matrix operator* (const matrix &, const matrix &);
		// ...
	}
}
```

```c++
mathLib::MatrixLib::matrix mathLib::MatrixLib::operator*(const matrix&, const matrix&);
```

## Exercise 18.15

> Explain the differences between using declarations and directives.

This difference in scope between a using declaration and a using directive stems directly from how these two facilities work. In the case of a using declaration, we are simply making name directly accessible in the local scope. In contrast, a using directive makes the entire contents of a namespace available In general, a namespace might include definitions that cannot appear in a local scope. As a consequence, a using directive is treated as if it appeared in the nearest enclosing namespace scope.

## Exercise 18.16

> Explain the following code assuming using declarations for all the members of namespace Exercise are located at the location labeled position 1. What if they appear at position 2 instead? Now answer the same question but replace the using declarations with a using directive for namespace Exercise.

```c++
namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;
// position1
void main() {
	// position2
	double dvar = 3.1416;
	int iobj = limit + 1;
	++ivar;
	++::ivar;
}
```

```c++
namespace Exercise{
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;

using Exercise::ivar;	//1
using Exercise::dvar;
using Exercise::limit;

// using namespace Exercise;	//3

void mainp(){
	// using Exercise::ivar;	//2
	// using Exercise::dvar;
	// using Exercise::limit;

	// using namespace Exercise;	//4

	double dvar = 3.1416;
	int iobj = limit + 1;
	++ivar;
	++::ivar;
}

int main()
{
	return 0;
}
```

## Exercise 18.17

See Exercise 18.16

## Exercise 18.18

> Given the following typical definition of swap § 13.3 (p. 517), determine which version of swap is used if mem1 is a string. What if mem1 is an int? Explain how name lookup works in both cases.

```c++
void swap(T v1, T v2)
{
	using std::swap;
	swap(v1.mem1, v2.mem1);
	// swap remaining members of type T
}
```

Swap is a template function defined by the standard library. By stating we are using std::swap all the following uses of swap in the scope of the function will look for the matching templatefor its argument types in the standard library.

If mem1 is a string the program will use the standard library function that has string arguments.

If mem1 is int, it will use the standard library template version with int arguments.

## Exercise 18.19:

> What if the call to swap was std::swap(v1.mem1, v2.mem1)?

Only standard library swaps will be used. If v1.mem1 and v2.mem1 are user-defined types, user-defined swaps for that type will not be available

## Exercise 18.20

> In the following code, determine which function, if any, matches the call to compute. List the candidate and viable functions. What type conversions, if any, are applied to the argument to match the parameter in each viable function? What would happen if the using declaration were located in main before the call to compute? Answer the same questions as before.

```c++
namespace primerLib {
	void compute();
	void compute(const void *);
}
using primerLib::compute;
void compute(int);
void compute(double, double = 3.4);
void compute(char*, char* = 0);
void f()
{
	compute(0);
}
```

Candidate functions: all;

**Feasible function:**

Void compute (int) (best match)

Void compute (double, double=3.4) (int ->double)

Void compute (char *, char *=0) (0->nullptr)

Void compute (const void *) (0->nullptr)

**After the change:**

Void compute (const void *) is the best match.

## Exercise 18.21

> Explain the following declarations. Identify any that are in error and explain why they are incorrect:

```c++
(a) class CADVehicle : public CAD, Vehicle { ... };
(b) class DbiList : public List, public List { ... };
(c) class iostream : public istream, public ostream { ... };
```

```c++
(a) CADVehicle publicly inherits CAD and privately inherits Vehicle;
(b) Repeated inheritance;
(c) Iostream publicly inherits istream and ostream.
```

## Exercise 18.22

> Given the following class hierarchy, in which each class defines a default constructor:

```c++
class A { ... };
class B : public A { ... };
class C : public B { ... };
class X { ... };
class Y { ... };
class Z : public X, public Y { ... };
class MI : public C, public Z { ... };
```

> what is the order of constructor execution for the following definition?

```c++
MI mi;
```

A->B->C->X->Y->Z->MI

## Exercise 18.23

> Using the hierarchy in exercise 18.22 along with class D defined below, and assuming each class defines a default constructor, which, if any, of the following conversions are not permitted?

```c++
class D : public X, public C { ... };
p *pd = new D;
(a) X *px = pd;
(b) A *pa = pd;
(c) B *pb = pd;
(d) C *pc = pd;
```

All are allowed

## Exercise 18.24

> On page 807 we presented a series of calls made through a Bear pointer that pointed to a Panda object. Explain each call assuming we used a ZooAnimal pointer pointing to a Panda object instead

```c++
Pe ->print() is correct;
Pe ->highlight() error;
Pe ->toes() error;
Pe ->cuddle() error;
The delete pe is correct.
```

## Exercise 18.25

> Assume we have two base classes, Base1 and Base2, each of which defines a virtual member named print and a virtual destructor. From these base classes we derive the following classes, each of which redefines the print function:

```c++
class D1 : public Base1 { /* ... */};
class D2 : public Base2 { /* ... */};
class MI : public D1, public D2 { /* ... */};
```

Using the following pointers, determine which function is used in each call:

```c++
Base1 *pb1 = new MI;
Base2 *pb2 = new MI;
D1 *pd1 = new MI;
D2 *pd2 = new MI;
(a) pb1->print();
(b) pd1->print();
(c) pd2->print();
(d) delete pb2;
(e) delete pd1;
(f) delete pd2;
```

```c++
(a) MI::print();
(b) MI::print();
(c) MI::print();
(d) MI destructor (will sequentially call the base class destructor);
(e) MI destructor (will sequentially call the base class destructor);
(f) MI destructor (will sequentially call the base class destructor).
```

## [Exercise 18.26](ex18_26.cpp)

## Exercise 18.27

> Given the class hierarchy in the box on page 810 and assuming we add a function named foo to MI as follows:

```c++
int ival;
double dval;
void MI::foo(double cval)
{
	int dval;
	// exercise questions occur here
}
(a) List all the names visible from within MI::foo.
(b) Are any names visible from more than one base class?
(c) Assign to the local instance of dval the sum of the dval member of Base1 and the dval member of Derived.
(d) Assign the value of the last element in MI::dvec to Base2::fval.
(e) Assign cval from Base1 to the first character in sval from Derived
```

```c++
（a）	In Base1: ival、dval、cval、print；
	In Base2: val、print；
	In Derived: sval、dval、print；
	In MI: ival、dvec、print、foo
(b)	ival、dval、print
(c)(d)(e) see ex18_27.cpp
```

## Exercise 18.28

> Given the following class hierarchy, which inherited members can be accessed without qualification from within the VMI class? Which require qualification? Explain your reasoning.

```c++
struct Base {
	void bar(int);
protected:
	int ival;
};
struct Derived1 : virtual public Base {
	void bar(char);
	void foo(char);
protected:
	char cval;
};
struct Derived2 : virtual public Base {
	void foo(int);
protected:
	int ival;
	char cval;
};
class VMI : public Derived1, public Derived2 { };
```

```c++
without qualification:
// (bar is not only a member of Base, but also a member of Derived1
// with derived class bars having higher priority than shared virtual machine class bars);
Derived1:: bar 

// (the ival of the derived class Derived2 has a higher priority than the ival of the shared virtual machine class);
Derived2:: ival 

require qualification:
// (both Derived1 and Derived2 have this member);
Foo 

// (both Derived1 and Derived2 have this member);
Cval 


Other reasons that require qualifiers are that they will be overwritten.

```

## Exercise 18.29

> Given the following class hierarchy:

```c++
class Class { ... };
class Base : public Class { ... };
class D1 : virtual public Base { ... };
class D2 : virtual public Base { ... };
class MI : public D1, public D2 { ... };
class Final : public MI, public Class { ... };
(a) In what order are constructors and destructors run on a Final object?
(b) A Final object has how many Base parts? How many Class parts?
(c) Which of the following assignments is a compile-time error?
Base *pb; Class *pc; MI *pmi; D2 *pd2;
(a) pb = new Class;
(b) pc = new Final;
(c) pmi = pb;
(d) pd2 = pmi;
```

```
(a) The constructor execution order is Class, Base, D1, D2, MI, Class, Final, and the destructor execution times are opposite to the above
(b) One Base, Two Classes
(c) (a) Compilation error, (b) Compilation error, (c) Compilation error, (d) Correct
```

## [Exercise 18.30](ex18_30.cpp)

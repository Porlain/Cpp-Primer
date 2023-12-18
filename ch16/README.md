# Chapter 16. Templates and Generic Programming

## Exercise 16.1:

> Define instantiation.

When the compiler instantiates a template, it creates a new “instance” of the template using the actual template argument(s) in place of the corresponding template parameter(s).

## [Exercise 16.2](ex16.1.2.3/main.cpp)

## [Exercise 16.3](ex16.1.2.3/main.cpp)

## [Exercise 16.4](ex16.4/main.cpp)

## [Exercise 16.5](ex16.5/main.cpp)

## [Exercise 16.6](ex16.6/main.cpp)

## [Exercise 16.7](ex16.7/main.cpp)

## Exercise 16.8

> In the “Key Concept” box on page 108, we noted that as a matter of habit C+ + programmers prefer using != to using <. Explain the rationale for this habit.

The reason is that more class defines "!=" rather than "<". Doing so can reduce the number of requirement of the class used with a template class.

## Exercise 16.9:

> What is a function template? What is a class template?

A function template is a formula from which we can generate type-specific versions of that function.

A class template is a blueprint for generating classes. Class templates differ from function templates in that the compiler cannot deduce the template parameter type(s) for a class template. Instead, as we've seen many times, to use a class template we must supply additional information inside angle brackets following the template's name.

## Exercise 16.10:

> What happens when a class template is instantiated?

The compiler uses these template arguments to instantiate a specific class from the template.

## Exercise 16.11:

> The following definition of List is incorrect. How would you fix it?

```c++
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
	List<elemType>();
	List<elemType>(const List<elemType> &);
	List<elemType>& operator=(const List<elemType> &);
	~List();
	void insert(ListItem *ptr, elemType value);
private:
	ListItem *front, *end;
};

```

```c++
template <typename elemType> class ListItem;
template <typename elemType> class List
{
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem<elemType> *ptr, elemType value);
    //                 ^^^^^^^^^^  -- template is not a type, the type must be provided

private:
    ListItem<elemType> *front, *end;
    //      ^^^^^^^^ -- template is not a type, the type must be provided
};

int main()
{
    return 0;
}
```

## [Exercise 16.12](ex16.12/main.cpp)

## Exercise 16.13

> Explain which kind of friendship you chose for the equality and relational operators for BlobPtr.

See [ex16.12](ex16.12/main.cpp)

## [Exercise 16.14](ex16.14/Screen.h)

## [Exercise 16.15](ex16.15/Screen.h)

## [Exercise 16.16](ex16.16/Vec.h)

## Exercise 16.17:

> What, if any, are the differences between a type parameter that is declared as a typename and one that is declared as a class? When must typename be used?

There is no difference. typename and class are interchangeable in the declaration of a type template parameter. You do, however, have to use class (and not typename) when declaring a template template parameter. When we want to inform the compiler that a name represents a type, we must use the keyword typename, not class

## Exercise 16.18:

> Explain each of the following function template declarations and identify whether any are illegal. Correct each error that you find.

```c++
(a) template <typename T, U, typename V> void f1(T, U, V);
(b) template <typename T> T f2(int &T);
(c) inline template <typename T> T foo(T, unsigned int *);
(d) template <typename T> f4(T, T);
(e) typedef char Ctype;
	template <typename Ctype> Ctype f5(Ctype a);

```

```
(a) illegal, typename must be added before U;
(b) illegal, parameter name T cannot be reused within the template;
(c) illegal, inline must after template<>;
(d) illegal, return type must be declared;
(e) legal, the same name declared by the outer scope will be hidden within the scope of the template parameter Ctype.

```

## [Exercise 16.19](ex16.19/main.cpp)

## [Exercise 16.20](ex16.20/main.cpp)

## [Exercise 16.21](ex16.21.22/DebugDelete.h)

## [Exercise 16.22](ex16.21.22/main.cpp)

## Exercise 16.23:

> Predict when the call operator will be executed in your main query program. If your expectations and what happens differ, be sure you understand why.

When destroying shared_ptr, call DebugDelete()

## [Exercise 16.24](ex16.24/Blob.h)

## Exercise 16.25:

> Explain the meaning of these declarations:

```c++
// Instantiate the declaration template class vector, which is not instantiated in this file;
extern template class vector<string>;
// Instantiating the definition template class vector<Sales_ Instantiate data in this file.
template class vector<Sales_data>;
```

## Exercise 16.26:

> Assuming NoDefault is a class that does not have a default constructor, can we explicitly instantiate vector `<NoDefault>`? If not, why not?

No, if there is no default constructor and we do not provide parameters, the class cannot be initialized and the vector cannot be instantiated

We can refer to this [link](https://stackoverflow.com/questions/21525169/while-explicitly-instantiating-vectorsometype-what-is-the-sometype-default-co)

## Exercise 16.27:

> For each labeled statement explain what, if any, instantiations happen. If a template is instantiated, explain why; if not, explain why not.

```c++
template <typename T> class Stack {	};
void f1(Stack<char>); 		//(a)
class Exercise {
	Stack<double> &rds;		//(b)
	Stack<int> si;			//(c)
};
int main() {
	Stack<char> *sc;		//(d)
	f1(*sc);				//(e)
	int iObj = sizeof(Stack<string>);	//(f)
}
```

```
(a) No, because it is only a declaration;
(b) No, references and pointers do not need to be instantiated;
(c) Yes, defined within the class;
(d) No, references and pointers do not need to be instantiated;
(e) Yes, required when calling;
(f) Yes, sizeof requires knowing the definition of Stack<string>in order to give the size of a Stack<string>object, which will be instantiated.
```

## [Exercise 16.28](ex16.28/main.cpp)

## [Exercise 16.29](ex16.29/Blob.h)

## [Exercise 16.30](ex16.29/main.cpp)

## Exercise 16.31:

> Explain how the compiler might inline the call to the deleter if we used DebugDelete with unique_ptr.

unique_ptr sets DebugDelete as the default deletor and will execute DebugDelete during compilation.

## Exercise 16.32:

> What happens during template argument deduction?

The process of determining the template arguments from the function arguments is known as template argument deduction. Duringtemplate argument deduction, the compiler uses types of the arguments in the call to find the template arguments that generate a version of the function that best matches the given call.

## Exercise 16.33:

> Name two type conversions allowed on function arguments involved in template argument deduction.

• const conversions: A function parameter that is a reference (or pointer) to a const can be passed a reference (or pointer) to a nonconst object (§ 4.11.2, p. 162).

• Array-or function-to-pointer conversions: If the function parameter is not a reference type, then the normal pointer conversion will be applied to arguments of array or function type. An array argument will be converted to a pointer to its first element. Similarly, a function argument will be converted to a pointer to the function’s type (§ 4.11.2, p. 161).

## Exercise 16.34:

> Given only the following code, explain whether each of these calls is legal.If so, what is the type of T? If not, why not?

```c++
template <class T> int compare(const T&, const T&);
(a) compare("hi", "world");
(b) compare("bye", "dad");
```

```
(a) It didn't complie, as two types are different, the first type being char[3] , second char[6]
(b) legal, the type should be pointer to char i.e. char*
```

## Exercise 16.35:

> Which, if any, of the following calls are errors? If the call is legal, what is the type of T? If the call is not legal, what is the problem?

```c++
template <typename T> T calc(T, int);
tempalte <typename T> T fcn(T, T);
double d; float f; char c;
(a) calc(c, 'c'); 
(b) calc(d, f);
(c) fcn(c, 'c');
(d) fcn(d, f);
```

```
(a) Legal, T is char;
(b) Legal, T is double;
(c) Legal, T is char;
(d) Illegal, unable to determine whether the type of T is double or float.
```

## Exercise 16.36:

> What happens in the following calls:

```c++
template <typename T> f1(T, T);
template <typename T1, typename T2) f2(T1, T2);
int i = 0, j = 42, *p1 = &i, *p2 = &j;
const int *cp1 = &i, *cp2 = &j;
(a) f1(p1, p2);
(b) f2(p1, p2);
(c) f1(cp1, cp2);
(d) f2(cp1, cp2);
(e) f1(p1, cp1);
(f) f2(p1, cp1);

```

```
（a） f1（int*，int*）
（b） f2（int*，int*）
（c） f1（const int*，const int*）
（d） f2（const int*，const int*）
（e） deduced conflicting types for parameter 'T'
（f） f2（int*，const int*）
```

## Exercise 16.37:

> The library max function has two function parameters and returns the larger of its arguments. This function has one template type parameter. Could you call max passing it an intand a double? If so, how? If not, why not?

Yes, just offer an explicit template argument, like:

```c++
int a = 1;
double b = 2.0;
max<double>(a, b);
```

## Exercise 16.38:

> When we call make_shared (§ 12.1.1, p. 451), we have to provide an explicittemplateargument. Explain why that argument is needed and how it is used.

Without specified type given, make_shared has no possibility to determine how big the size it should allocate.

## [Exercise 16.39](ex16.39/main.cpp)

## Exercise 16.40:

> Is the following function legal? If not, why not? If it is legal, what, if any, are the restrictions on the argument type(s) that can be passed, and what is the return type?

```c++
template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
	//处理序列
	return *beg;
}
```

legal.

As shown below, only type that support this+0 operation can be passed. thereturn type depends on the what type the operator +returns. In the case below, the return type is Bar.

## [Exercise 16.41](ex16.41/main.cpp)

## Exercise 16.42:

> Determine the type of T and of val in each of the following calls:

```c++
template <typename T> void g(T&& val);
int i = 0; const int ci = i;
(a) g(i);
(b) g(ci);
(c) g(i * ci);
```

```
(a) T is int&，val is int& && -> int&；
(b) T is const int&，val is const int& && -> const int&；
(c) T is int，val is int&&
```

## Exercise 16.43:

> Using the function defined in the previous exercise, what would the template parameter of g be if we called g(i = ci)?

(i=ci) returns lvalue refering to the object i. Hence T is deduced as int& val is int& &&. any change on val changes the object i.

## Exercise 16.44:

> Using the same three calls as in the first exercise, determine the types for T if g’s function parameter is declared as T (not T&&). What if g’s function parameter is const T&?

```
T：
（a）T is deduced as int
（b）T is deduced as int, const is ignored.
（c）T is deduced as int, (i * ci) returns rvalue which is copied to T

const T&：
（a）T is deduced as int  , val : const int&
（b）T is deduced as int  , val : const int&
（c）T is deduced as int  , val : const int&(see example on page 687)
```

## Exercise 16.45:

> Given the following template, explain what happens if we call g on a literal value such as 42. What if we call g on a variable of type int?

```c++
template <typename T> void g(T&& val) { vector<T> v; }
```

```
42: T is int, val is int&&, vector<int> v;
int: T is int, val is int & &&->int &, vector<int&> v, Unable to allocate memory for int&, an error will be reported.
```

## Exercise 16.46:

> Explain this loop from StrVec::reallocate in § 13.5 (p.530):

```c++
for (size_t i = 0; i != size(); ++i)
	alloc.construct(dest++, std::move(*elem++));
```

In each iteration, the dereference operator * returns a lvalue which is changed to rvalue by std::move , becasue the member function construct takes rvalue reference rather than lvalue reference.

## [Exercise 16.47](ex16.47/main.cpp)

## [Exercise 16.48](ex16.48/main.cpp)

## Exercise 16.49:

> Explain what happens in each of the following calls:

```c++
template <typename T> void f(T);
tempalte <typename T> void f(const T*);
tempalte <typename T> void g(T);
tempalte <typename T> void g(T*);
int i = 42, *p = &i;
const int ci = 0, *p2 = &ci;
g(42); g(p); g(ci); g(p2);
f(42); f(p); f(ci); f(p2);
```

```c++
    //g(42);      //template <typename T> void g(T ); --is called
    //g(p);       //template <typename T> void g(T*); --is called
    //g(ci);      //template <typename T> void g(T)   --is called
    //g(p2);      //template <typename T> void g(T*)    --is called
    //f(42);      //f(T)
    //f(p);       //f(T)
    //f(ci);      //f(T)
    //f(p2);      //f(const T*)
```

## [Exercise 16.50](ex16.50/main.cpp)

## [Exercise 16.51](ex16.51/main.cpp)

> Determine what sizeof...(Args) and sizeof...(rest) return for each call to foo in this section.

## [Exercise 16.52](ex16.51/main.cpp)

## [Exercise 16.53](ex16.53/main.cpp)

## Exercise 16.54:

> What happens if we call print on a type that doesn’t have an << operator?

It didn't  compile

## Exercise 16.55:

> Explain how the variadic version of print would execute if we declared the nonvariadic version of print after the definition of the variadic version.

error: no matching function for call to 'print(std::ostream&)'

## [Exercise 16.56](ex16.56/main.cpp)

## Exercise 16.57:

> Compare your variadic version of errorMsg to the error_msg function in § 6.2.6 (p. 220). What are the advantages and disadvantages of each approach?

The error_msg takes initializer_list as the argument. So only the elements stored in it must be the same or at least convertible. In contrast, the variadic version provides better flexibility.

## [Exercise 16.58](ex16.58/main.cpp)

## Exercise 16.59:

> Assuming s is a string, explain svec.emplace_back(s).

Will forward extension packets in the construt function

## Exercise 16.60:

> Explain how make_shared (§ 12.1.1, p. 451) works.

make_shared shoudl be a variadic template function that forwards all arguments to underlying constructors that allocate and initializes an object in dynamic memory and, at last, build a shared_ptr by wrapping the raw pointer.

## [Exercise 16.61](ex16.61/main.cpp)

## [Exercise 16.62](ex16.62/main.cpp)

## [Exercise 16.63](ex16.63/main.cpp)

## [Exercise 16.64](ex16.63/main.cpp)

## [Exercise 16.65](ex16.65/main.cpp)

## Exercise 16.66:

> What are the advantages and disadvantages of overloading these debug_rep functions as compared to defining specializations?

Overloading changes the function match.

## Exercise 16.67:

> Would defining these specializations affect function matching for debug_rep? If so, how? If not, why not?

Won't change.

Specializations instantiate a template; they do not overload it. As a result, specializations do not affect function matching.

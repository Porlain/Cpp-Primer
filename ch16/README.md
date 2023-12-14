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

> What happens when an object of type Query is copied, moved, assigned, and destroyed?

## Exercise 16.33:

> What about objects of type `Query_base`?

## Exercise 16.34:

> For the expression built in Figure 16.3 (p. 638):

## Exercise 16.35:

> Implement the `Query` and `Query_base classes`, including a definition of rep but omitting the definition of `eval`.

## Exercise 16.36:

> Put print statements in the constructors and rep members and run your code to check your answers to (a) and (b) from the first exercise.

## Exercise 16.37:

The interface function needs to be changed, and Query needs to be changed to shared_ptr<Query_base>.

## Exercise 16.38:

> Are the following declarations legal? If not, why not? If so, explain what the declarations mean.

## Exercise 16.39:

> Implement the `Query` and `Query_base` classes. Test your application by evaluating and printing a query such as the one in Figure 16.3 (p. 638).

## Exercise 16.40:

> In the `OrQuery` eval function what would happen if its `rhs` member returned an empty set? What if its `lhs` member did so? What if both `rhs` and `lhs` returned empty sets?

## Exercise 16.41:

## Exercise 16.42:

> Design and implement one of the following enhancements:

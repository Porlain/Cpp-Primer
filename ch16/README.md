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

> Why did we define a default constructor for Disc_quote? What effect, if any, would removing that constructor have on the behavior of Bulk_quote?

## Exercise 16.26:

> Define the `Quote` and `Bulk_quote` copy-control members to do the same job as the synthesized versions. Give them and the other constructors print statements that identify which function is running. Write programs using these classes and predict what objects will be created and destroyed.

## Exercise 16.27:

> Redefine your `Bulk_quote` class to inherit its constructors.

## [Exercise 16.28](ex16.28.29/main.cpp)

## Exercise 16.29:

> Repeat your program, but this time store `shared_ptrs` to objects of type `Quote`. Explain any discrepancy in the sum generated by the this version and

## Exercise 16.30:

> Write your own version of the `Basket` class and use it to compute prices for the same transactions as you used in the previous exercises.

## Exercise 16.31:

> Given that s1, s2, s3, and s4 are all strings, determine what objects are created in the following expressions:

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

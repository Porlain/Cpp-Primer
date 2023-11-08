Reference Documents:https://github.com/Mooophy/Cpp-Primer/

## Exercise 1.1

> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.

## Exercise 1.2

> Exercise 1.2: Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.

## Exercise 1.3

> Write a program to print Hello, World on the standard output.

## Exercise 1.4

> Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.

# Exercise 1.5

> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

## Exercise 1.6

> Explain whether the following program fragment is legal.

It's illegal.

**[Error] expected primary-expression before '<<' token**

Fixed it: remove the spare semicolons.

The truth is :
std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;

## Exercise 1.7

> Compile a program that has incorrectly nested comments.

## Exercise 1.8

> Indicate which, if any, of the following output statements are legal:
```cpp
// legal
std::cout << "/*";
std::cout << "*/";
// illegal
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```
> After you’ve predicted what will happen, test your answers by compiling a
program with each of these statements. Correct any errors you encounter.

Compiled result(g++):

Output:

    /**/ */ /* 

## [Exercise 1.9](ex1_9.cpp)
## [Exercise 1.10](ex1_10.cpp)
## [Exercise 1.11](ex1_11.cpp)

## Exercise 1.12
> What does the following for loop do? What is the final value

int sum = 0;
for (int i = -100; i <= 100; ++i)
    sum += i;

Function: Accumulate from -100 to 100
## Exercise 1.13
Refer to the code for the corresponding problem(Exercise 1.9-1.11)

## Exercise 1.14
> Compare and contrast the loops that used a for with those
using a while. Are there advantages or disadvantages to using either form?

[A similar question on Stack Overflow](http://stackoverflow.com/questions/2950931/for-vs-while-in-c-programming)

## Exercise 1.15
> Write programs that contain the common errors discussed in
the box on page 16. Familiarize yourself with the messages the compiler
generates.

**Syntax Errors**:
```c++
int main(){
    std::cout << "Hello World!" << std::endl // semicolon missed 
    return 0;
}
```

**Type errors**:
```c++
int main(){
    char s = "Hello World!"; // Here char should be std::string
    std::cout << s << endl;
    return 0;
}
```

**Declaration errors**:
```c++
int main(){
    int k = 0;
    std::cout << K << std::endl; // use of undeclared identifier 'K'
    return 0;
}
```

## Exercise 1.17

> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

If the input values are all equal, it will print a line which shows the count of the number you input.

If there are no duplicated values, when different values input, a new line will be printed if you click `Enter`.

## Exercise 1.18

> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.

## Exercise 1.19

> Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.

## Exercise 1.20

> http://www.informit.com/title/032174113 contains a copy of Sales_item.h in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.

## Exercise 1.21
> Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.

The program should check whether the objects have the same ISBN.

## Exercise 1.22

> Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.

Tips: this program will appear in the section 1.6.

## Exercise 1.23
> Write a program that reads several transactions and counts
how many transactions occur for each ISBN.

Tip: please review the `1.4.4`.

## Exercise 1.24
> Test the previous program by giving multiple transactions
representing multiple ISBNs. The records for each ISBN should be grouped
together.

`data/book.txt` may be used as the records.

## Exercise 1.25
> Using the Sales_item.h header from the Web site,
compile and execute the bookstore program presented in this section.

It is the same as Exercise 1.22.
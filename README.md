
# cpp_learning

[![GitHub license](https://img.shields.io/badge/license-CC0-blue.svg)](https://raw.githubusercontent.com/Mooophy/Cpp-Primer/master/LICENSE)

[![img](https://img.shields.io/badge/%E4%B8%AD%E6%96%87-%E8%AE%A8%E8%AE%BA%E5%8C%BA-yellowgreen.svg)](https://github.com/ReadingLab/Discussion-for-Cpp)

[![img](https://img.shields.io/badge/douban-%E5%B0%8F%E7%BB%84-green.svg)](http://www.douban.com/group/532124/)

### Compilers recommended

* Windows: Visual Studio 2015+
* Linux: g++ 5.0+

```
g++ -std=c++14 some_ex.cpp -o some_ex
```

* Mac: clang++ 3.7+

```
clang++ -std=c++1y some_ex.cpp -o some_ex
```

### note

This document is suitable for students with a certain foundation in C language or some understanding of C++to read.

In the first few chapters, (**using namespace std;** )will be used, which may be a bit unfriendly for those who only read C++Primer books

**The Chinese version of the answers will be organized after the English version is completed**

**Tips: You can try to use the method below, which only includes what is needed instead of using (using namespace std;). However, if you only use (using namespace std;), it may produce some issues when your project is large. For the introduction of the program header file section, we will use (using namespace std;).**

### Contents

- [Chapter 1. Getting Started](ch01/README.md)
- Part I: The Basics
  - [Chapter 2. Variables and Basic Types](ch02/README.md)
  - [Chapter 3. Strings, Vectors, and Arrays](ch03/README.md)
  - [Chapter 4. Expressions](ch04/README.md)
  - [Chapter 5. Statements](ch05/README.md)
  - [Chapter 6. Functions](ch06/README.md)
  - [Chapter 7. Classes](ch07/README.md)
- Part II: The C++ Library
  - [Chapter 8. The IO Library](ch08/README.md)
  - [Chapter 9. Sequential Containers](ch09/README.md)
  - [Chapter 10. Generic Algorithms](ch10/README.md)
  - [Chapter 11. Associative Containers](ch11/README.md)
  - [Chapter 12. Dynamic Memory](ch12/README.md)
- Part III: Tools for Class Authors
  - [Chapter 13. Copy Control](ch13/README.md)
  - [Chapter 14. Overloaded Operations and Conversions](ch14/README.md)
  - [Chapter 15. Object-Oriented Programming](ch15/README.md)
  - [Chapter 16. Templates and Generic Programming](ch16)
- Part IV:  Advanced Topics
  - [Chapter 17. Specialized Library Facilities](ch17)
  - [Chapter 18. Tools for Large Programs](ch18)
  - [Chapter 19. Specialized Tools and Techniques](ch19)

**Tips: distinguish `const *int p` and `int *const p`，easy to understand explanation, const will protect the nearest variable:**

`const *int p` , we can't modify *p, but we can modify p. It's logic seems to be `const (*int p`), int is protected.

`int *const p`, we can't modify the value of p, but we can modify *p, It's logic seems to be `int (const *p)`, the point is protected.

```c++
const *int p1 = &a;
int *const p2 = &a;

p1 = &b; // error
*p1 = 10; // true

p2  = &b; //true
*p2 = 10; // error

```

**[Reference Documents](https://github.com/Mooophy/Cpp-Primer/)**

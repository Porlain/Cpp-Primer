/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-05 15:21:33
 */
// Exercise 7.40:
// Choose one of the following abstractions (or an abstraction of your own choosing).
// Determine what data are needed in the class. Provide an appropriate set of constructors.
// Explain your decisions.
//
// Exercise 14.5:
// In exercise 7.40 from § 7.5.1 (p. 291) you wrote a sketch of one of the
// following classes. Decide what, if any, overloaded operators your class
// should provide.
//      -   =   <   >   <=  >=  ++  --  <<  >>  ==  !=  +=  -=
// Exercise 14.8:
// Define an output operator for the class you chose in exercise 7.40 from
// § 7.5.1 (p. 291).
//
// Exercise 14.12:
// Define an input operator for the class you used in exercise 7.40 from
// § 7.5.1 (p. 291). Be sure the operator handles input errors.
//
// Exercise 14.15:
// Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291)
// define any of the arithmetic operators? If so, implement them.
// If not, explain why not.
//
//      arithmetic operators :  all non-members
//      +   :   Date + Size
//      -   :   Date - Size
//      -   :   Date - Date
//
// Exercise 14.17:
// Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define
// the equality operators? If so, implement them. If not, explain why not.
//
// Exercise 14.19:
// Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define
// the relational operators? If so, implement them. If not, explain why not.
//
// Exercise 14.25:
// Implement any other assignment operators your class should define.
// Explain which types should be used as operands and why.
//
// Exercise 14.49:
// Regardless of whether it is a good idea to do so, 
// define a conversion to bool for the class from the previous exercise.
#ifndef CP5_CH14_EX14_49_H
#define CP5_CH14_EX14_49_H
#include <iostream>
#include <string>

class Book
{
public:
    friend std::istream &operator>>(std::istream &, Book &);
    friend std::ostream &operator<<(std::ostream &, const Book &);
    friend bool operator==(const Book &, const Book &);
    friend bool operator!=(const Book &, const Book &);
    friend bool operator>(const Book &, const Book &);
    friend bool operator<(const Book &, const Book &);


public:
    Book() = default;
    Book(unsigned isbn, std::string const &name, std::string const &author, std::string const &pubdate)
        : isbn_(isbn), name_(name), author_(author), pubdate_(pubdate) {}
    Book(std::istream &in) { in >> *this; }
    explicit operator bool(){return !(name_.empty());}

public:
    Book &operator=(const Book &);
    Book &operator=(const Book &&) noexcept;

private:
    unsigned isbn_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
};

std::istream &operator>>(std::istream &, Book &);
std::ostream &operator<<(std::ostream &, const Book &);
bool operator==(const Book &, const Book &);
bool operator!=(const Book &, const Book &);
bool operator>(const Book &, const Book &);
bool operator<(const Book &, const Book &);

#endif

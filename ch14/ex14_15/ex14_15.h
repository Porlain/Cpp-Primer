/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-30 17:16:27
 * @See exercise 7.40
 */
#ifndef CP5_CH14_EX14_05_H
#define CP5_CH14_EX14_05_H
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
    friend Book operator+(const Book &, const Book &);
    friend Book operator-(const Book &, const Book &);

public:
    Book() = default;
    Book(unsigned isbn, std::string const &name, std::string const &author, std::string const &pubdate, unsigned number)
        : isbn_(isbn), name_(name), author_(author), pubdate_(pubdate), number_(number) {}
    Book(std::istream &in) { in >> *this; }

public:
    Book &operator+=(const Book &);
    Book &operator-=(const Book &);

private:
    unsigned isbn_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
    unsigned number_;
};
#endif

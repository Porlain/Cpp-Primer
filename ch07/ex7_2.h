#ifndef CP5_ex7_02_h
#define CP5_ex7_02_h

#include <string>
using std::string;
struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &str);
};

// the purpose of & front the function is to modify the object that calls this function
Sales_data &Sales_data::combine(const Sales_data &str){
    units_sold += str.units_sold;
    revenue += str.revenue;
    // return an object which call this function
    return *this;
}

#endif
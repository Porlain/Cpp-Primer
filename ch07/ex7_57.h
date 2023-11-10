/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-10 17:10:01
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */

#ifndef CP5_ex7_57_h
#define CP5_ex7_57_h

#include <string>
using std::string;
class Account
{
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }

private:
    string owner;
    double amount;
    static double interestRate;
    static constexpr double todayRate = 3.15;
    static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();

#endif
/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 14:17:34
 */
#include "binaryquery.h"

std::string BinaryQuery::rep() const
{
    std::cout << "BinaryQuery::rep()\n";
    return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
}
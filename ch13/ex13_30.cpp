/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-27 19:17:09
 */
#include "ex13_30.h"
#include <iostream>

int main()
{
	HasPtr hp1("aaa"),hp2("bbb");
	swap(hp1,hp2);
	std::cout << "main" << std::endl;

	return 0;
}

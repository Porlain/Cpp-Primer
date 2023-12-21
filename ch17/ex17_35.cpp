/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-21 13:56:46
 */
#include <iostream>
#include <cmath>

int main()
{
	std::cout <<"default format: " << sqrt(2.0) << '\n'
		<< "scientific: " << std::scientific << sqrt(2.0) << '\n'
		<< "fixed decimal: " << std::fixed << sqrt(2.0) << '\n'
		<< "hexidecimal: " << std::uppercase << std::hexfloat << sqrt(2.0) << '\n'
		<< "use defaults: " << std::defaultfloat << sqrt(2.0)
		<< "\n\n";

	return 0;
}

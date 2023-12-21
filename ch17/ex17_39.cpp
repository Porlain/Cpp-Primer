/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-21 14:43:44
 */
#include <iostream>
#include <fstream>

int main()
{
	std::fstream inOut("../data/record.txt", std::fstream::ate | std::fstream::in | std::fstream::out);

	if(!inOut)
	{
		std::cerr << "Unable to open file!" << std::endl;
		return EXIT_FAILURE;
	}

	auto end_mark = inOut.tellg();
	inOut.seekg(0, std::fstream::beg);
	size_t cnt = 0;
	std::string line;

	while(inOut && inOut.tellg() != end_mark && getline(inOut, line))
	{
		cnt += line.size() + 1;
		auto mark = inOut.tellg();
		inOut.seekp(0, std::fstream::end);
		inOut << cnt;
		if(mark != end_mark) inOut << " ";
		inOut.seekg(mark);
	}
	inOut.seekp(0, std::fstream::end);
	inOut << "\n";

	return 0;
}

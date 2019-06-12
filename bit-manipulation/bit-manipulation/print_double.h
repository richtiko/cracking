#pragma once
#include<iostream>

void print1(double d)
{
	std::string result = "." ;
	if (d < 0 || d > 1) 
	{
		//std::cout << "ERROR" << std::endl;
		return;
	}
	while (d > 0) 
	{
		d *= 2;
		if (d >= 1) 
		{
			d -= 1;
			result += "1";
		}
		else 
		{
			result += "0";
		}
		if (result.size() > 32) 
		{
			break;
			//std::cout << "ERROR" << std::endl;
			return;
		}
	}
	std::cout << result << std::endl;
}



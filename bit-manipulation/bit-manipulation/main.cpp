#include <iostream>
int insert_bits(int N, int M, int i, int j)
{
	return (~(((1 << (j - i + 1)) - 1) << i) & N) | M << i;
}

#include "print_double.h"

int main() 
{
	int N = 0xDD;
	int M = 0x5;
	//std::cout << std::hex << insert_bits(N, M, 3, 5)<<std::endl;

	print1(0.625);
	print(0.625);
	/*for (double i = 0.000001; i < 1; i += 0.000001) 
	{
		print1(i);
	}*/
	

}
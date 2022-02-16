#include "Dictionary.h"
#include <iostream>

int main()
{
	Dictionary<char, int> inv = Dictionary<char, int>();
	

	inv.addItem(1, 3);
	inv.addItem(1, 3);
	inv.addItem(2, 5);
	inv.addItem(3, 7);
	inv.addItem(4, 9);

	int value;
	inv.remove(3, value);
	std::cout << value << std::endl;

	inv.remove(4);
	std::cout << inv[4];

	std::cout << std::endl;

	if (inv.containsTValue(3))
		std::cout << inv[1];

	std::cout << std::endl;

	if(inv.containsTValue(5))
		std::cout << inv[2];

	std::cout << std::endl;

	int y = inv[1];
	std::cout << y;

	std::cout << std::endl;

	Dictionary<char, int> stor = Dictionary<char, int>();

	stor = inv;

	std::cout << stor.getCount();


}
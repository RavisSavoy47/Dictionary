#include "Dictionary.h"
#include <iostream>

int main()
{
	Dictionary<char, int> inv = Dictionary<char, int>();
	

	inv.addItem('a', 3);
	inv.addItem('d', 5);
	inv.addItem('q', 10);

	int x = 10;
	inv.remove(5);
	inv.remove('q', x);

	if (inv.containsTValue(3))
		std::cout << inv.containsKey('a');

	std::cout << std::endl;

	if (inv.containsTValue(10))
		std::cout << inv.containsKey('d');

	std::cout << std::endl;

	if(inv.containsTValue(5))
		std::cout << inv.containsKey('q');

	std::cout << std::endl;

	int y = inv['a'];

	std::cout << y;

	std::cout << std::endl;

	Dictionary<char, int> stor = Dictionary<char, int>();

	stor = inv;

	std::cout << stor.getCount();


}
#include "Dictionary.h"
#include <iostream>

int main()
{
	Dictionary<char, int> dictionary = Dictionary<char, int>();


	dictionary.addItem('a', 4);
	//dictionary.addItem('a', 4);

	int x = 10;
	dictionary.remove(20, x);


	if(dictionary.containsTValue(4))
	std::cout << "its here " << x;
}
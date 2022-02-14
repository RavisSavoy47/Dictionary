#include "Dictionary.h"
#include <iostream>

int main()
{
	Dictionary<char, int> dictionary = Dictionary<char, int>();
	

	dictionary.addItem('a', 4);
	dictionary.addItem('a', 4);
	dictionary.addItem('d', 5);
	dictionary.addItem('q', 10);

	//int x = 10;
	//dictionary.remove(20, x);	

	if (dictionary.containsTValue(4))
		std::cout << "its here ";

	if (dictionary.containsTValue(10))
		std::cout << "its here ";
		
	if(dictionary.containsTValue(5))
		std::cout << "its here ";
}
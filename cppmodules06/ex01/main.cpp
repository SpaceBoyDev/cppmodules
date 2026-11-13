#include "include/Serializer.hpp"
#include "include/Data.hpp"

#include <iostream>

int	main(void)
{
	Data data;
	data.x = 0;
	data.y = 1;
	data.z = 10;
	data.c = 'h';
	data.str = "que tal";

	std::cout << "Original Data\n"
			<< "Data\nx: " << data.x
			<< "\ny: " << data.y
			<< "\nz: " << data.z
			<< "\nc: " << data.c
			<< "\nstr: " << data.str
			<< std::endl;

	uintptr_t ptr;

	std::cout << "Serializing and Deserializing Data..." << std::endl;
	ptr = Serializer::serialize(&data);

	Data *newData = Serializer::deserialize(ptr);
	
	std::cout << "-----------------------" << std::endl;
	std::cout << "Final data deserialized" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Data\nx: " << newData->x
			<< "\ny: " << newData->y
			<< "\nz: " << newData->z
			<< "\nc: " << newData->c
			<< "\nstr: " << newData->str
			<< std::endl;

	std::cout << "Original Data Ptr: " << &data
			<< "\nDeserial Data Ptr: " << newData
			<< std::endl;

	return (0);
}
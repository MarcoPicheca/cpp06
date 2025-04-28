#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include "Data.hpp"
#include <fstream>
#include <stdint.h>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& copy);
	public:
		Serializer& operator=(const Serializer& copy);
		~Serializer();
		
		/** 
		 * It takes a pointer and converts 
	 * it to the unsigned integer type uintptr_t
	 * 
	 */
		static uintptr_t serialize(Data* ptr);

	/** 
	 * It takes an unsigned integer 
	 * parameter and converts it to a pointer to Data
	 * 
	 */
		static Data* deserialize(uintptr_t raw);
};

#endif
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data obj("Franco");
	Data *obj2;
	uintptr_t ello =  Serializer::serialize(&obj);
	obj2 = Serializer::deserialize(ello);
	std::cout << obj2->getName() << std::endl;
	return 0;
}
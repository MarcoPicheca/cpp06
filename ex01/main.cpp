#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data obj("Franco");
	Data *obj2;
	uintptr_t ello =  Serializer::serialize(&obj);
	obj2 = Serializer::deserialize(ello);
	return 0;
}
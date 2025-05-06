#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void	Base::identify(Base& p)
{
    if (dynamic_cast<A*>(&p))
        std::cout << "Dereferenziato: A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "Dereferenziato: B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "Dereferenziato: C" << std::endl;
    else
        std::cout << "Dereferenziato sconosciuto" << std::endl;
}

void Base::identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Puntatore: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Puntatore: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Puntatore: C" << std::endl;
    else
        std::cout << "Puntatore sconosciuto" << std::endl;
}

Base* Base::generate(void)
{
	size_t	rand_number = 0;
	for (size_t i = 0; i < 2; i++)
		rand_number += rand() % 2;
	switch (rand_number)
	{
		case 0:
			return static_cast<Base*>(new A());
		case 1:
			return static_cast<Base*>(new B());
		case 2:
			return static_cast<Base*>(new C());
		default:
			break;
	}
	return NULL;
}

Base::~Base()
{
}
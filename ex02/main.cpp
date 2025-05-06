#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	B*	l;
	A*	k;
	Base *g;

	srand(time(NULL));
	k = static_cast<A*>(Base::generate());
	l = static_cast<B*>(Base::generate());
	g = Base::generate();
	Base::identify(g);
	Base::identify(*g);
	Base::identify(k);
	Base::identify(*k);
	Base::identify(*l);
	delete g;
	delete k;
	delete l;
	return 1;
}
#include "piechota.h"

#include<iostream>
#include<cstdlib>
using namespace std;

Piechota::Piechota(int dz, int l,string g)
{
	dziala = dz;
	ludzie = l;
	gen = g;
	#ifdef _DEBUG
		cout << "kon: utworzono div piech" << endl;
	#endif  _DEBUG

}

Piechota &Piechota:: operator=(const Piechota &a)
{
	//if (a == this) return *this;
	//else
	{
		dziala = a.dziala;
		ludzie = a.ludzie;
		gen = "Adolf";
		return *this;
	}
}

Piechota::~Piechota()
{
		#ifdef _DEBUG
			cout << "des: koniec miesa armatniego" << endl;
		#endif
}
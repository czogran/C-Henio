#include"propaganda.h"
#include <string>
#include<iostream>
#include<cstdlib>
using namespace std;


Propaganda::Propaganda(int wb, int j, string g)
{
	wygrane_bitwy = wb;
	jency = j;
	general = g;
#ifdef _DEBUG
	cout << "propa kon: jestesmy wspaniali" << endl;
#endif // _DEBUG

}

Propaganda::~Propaganda()
{
	#ifdef _DEBUG
		cout << "propa des: nasza ideologia przetrwa na wieki" << endl;
	#endif // _DEBUG

	
}

void Propaganda::gazeta()
{
	cout << "wygralismy " << wygrane_bitwy << "bitew, wzielismy " << jency << " jencow i gnerela " << general << endl;
}

void Propaganda::wymysl_zwyciestwo(int b, int j, string g)
{
	wygrane_bitwy = b;
	jency = j;
	general = g;
}

Propaganda & Propaganda::operator()(int a, int b, string h)
{
	wygrane_bitwy =wygrane_bitwy+ a;
	jency =jency+ b;
	general = general + " " +h;
	cout << wygrane_bitwy << endl;
	return *this;
}

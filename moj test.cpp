#include "moj test.h"

void tescik()
{
	cout << "TO SA CWICZENIA NAJLEPSZEJ ARMII SWIATA < KTORE POKAZA, ZE JEST ONA GOTOWA NA WSZYTSKO " << endl;
	cout << endl;

	cout << "test konstruktora kopiujacego armii" << endl;
	Armia a(4, 3);
	Armia b = a;// nie wiem jak pokazac ze powstaly nowe jednostki, pokazac ze ich adresy sa rozne? jakies dzialanie na nich? 
	cout << endl;
	
	cout << "operator przypisania" << endl;
	Armia c(1, 3);
	c = a;
	cout << endl;

	cout << "operator []" << endl;
		c["Guderian"];
	cout << endl;

	cout << "operator +" << endl;
		c + 3;
	cout << endl;

	cout << "operator ()a" << endl;
		a(3, 4, "Jodl");
	cout << endl;

	cout << "operator ()b" << endl;
	a("Models", 4, 5);
	cout << endl;

	cout << "operator ==" << endl;
	c == a;
	a == b;
	cout << endl;

	cout << "operator <<" << endl;
	cout << a << endl;
	cout << c << endl;
	cout << endl;

	cout << "operator onwersji"<<endl;
	float q = a;
	cout << "tyle jencow na bitwe: " << q << endl;
	cout << endl;

	cout << "operator <" << endl;
	c < a;
	cout << endl;

	cout << "operator &&" << endl;
	c&&a;
	cout << endl;




}


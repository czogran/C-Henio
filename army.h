#pragma once

#include<iostream>
#include<cstdlib>
#include <string>

using namespace std;


#include "divpanc.h"
#include "piechota.h"
#include "propaganda.h"

class Armia
{
	Piechota *piechota;
	Divpanc *pancerne;
	Propaganda p1;
	int ile_panc;
	int ile_piechota;
	static int nr_armi;
	int nr_tej;
	string wodz;
public:
	Armia(int c, int p);//(int c = 0, int p = 0);
	Armia(int c, int p, string w);
	~Armia();
	Armia(const Armia&a);					// konstrukor kopiujacy, operator przypisania jest te¿ dla Divapanc i Piechota
	

	void propa(int a, int b, string g);
	void zwprop(int a, int b, string g);
	int ile_armii() { return nr_armi; };
	int suma_piech();
	int suma_dzial();
	int suma_czol();
	
	
	Armia &operator+(const int b);								//1 
	friend ostream& operator<< (ostream&, Armia const& );		//2
	Armia  &operator()(int a, int b, string h);					//3a
	Armia  &operator()( string h,int a, int b);					//3b
	Armia &operator=(const Armia &aa);							//4
	void  operator[](string gen);								//5
	bool operator ==(const Armia& a) const;						//6
	bool operator < (const Armia& a)const;						//7 
	void operator &&(const Armia&a);							//8
	inline operator float()const { return p1.jency *1.0f / p1.wygrane_bitwy; } //9
	
};
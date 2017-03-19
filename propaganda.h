#pragma once


#include<string.h>
#include <iostream>
#include <conio.h>
using namespace std;

class Propaganda
{
	int wygrane_bitwy;
	int jency;
	string general;
	friend class Armia;
public:
	Propaganda(int wb = 1, int j = 100, string g = "Paulus");
	~Propaganda();
	void gazeta();
	void wymysl_zwyciestwo(int b, int j, string g);
	int ile_jencow() { return jency; };
	Propaganda  &operator()(int a, int b, string h);

};
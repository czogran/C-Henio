#pragma once


class Divpanc
{
	int czolgi;
	int ludzie;
	
	friend class Armia;
	//friend class Korpus;

public:
	Divpanc(int cz = 10, int l = 40);
	int daj_numer() { nr; };
	Divpanc & operator=(const Divpanc & b);
	static int nr;
	~Divpanc();
};
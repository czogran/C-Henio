#ifndef FUNK_H_INCLUDED
#define FUNK_H_INCLUDED

#define MAX_MSG 100

struct Kolejka
{
    int priorytet;
    char *message;

    struct Kolejka *next;
    struct Kolejka *prev;
};

int wstaw (int prio,char *msg);
char* pobierz();


void poka ();  /// funkcja pomocnicza do wyswietlania priorytetow kolejki
int daj_priorytet(int nr); /// tez pomoc do fucnkji które maja tetsowaæ
#endif // FUNK_H_INCLUDED

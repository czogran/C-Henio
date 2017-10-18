#include "funk.h"
#include <stdio.h>
#include <stdlib.h>


struct Kolejka *head=NULL;
struct Kolejka *last=NULL;
struct Kolejka *current=NULL;

int dlugosc=0;


int wstaw(int prio,char *msg)
{
    struct Kolejka *wsk = (struct Kolejka*) malloc(sizeof(struct Kolejka));
    if (wsk==NULL||dlugosc==MAX_MSG) /// warunek ten jest, bo takie byly zalozenia projektu
    {
        return 0;
    }
    else
    {
        wsk->message=msg;
        wsk->priorytet=prio;

        if (dlugosc==0) /// wstawia 1 element
        {
            head=wsk;
            last=wsk;
        }
        else
        {
            current=head;

            while(current !=last && current->priorytet>prio) ///szuka az nie dojdzie do konca, miejsca gdzie wstawic nowe msg
            {
                current=current->prev;
            }
            if (current==last&&current->priorytet>prio) ///przypadek gdy pojawia się nowy last
            {
                wsk->next=current;
                last=wsk;
                current->prev=wsk;

            }
            else if (prio>=head->priorytet) ///przypadek na nowy head
            {

                head=wsk;
                current->next=wsk;
                wsk->prev=current;
            }
            else ///i wstawianie w srodek
            {
                wsk->prev=current;
                wsk->next=current->next;
                current->next->prev=wsk;
                current->next=wsk;
            }

        }
        ++dlugosc;
        return 1;
    //printf("OK\n");
    }
}



void poka() /// funkcja pomocnicza do wyswietlania priorytetow kolejki
{
    struct Kolejka *ptr = head;
    int licznik=0;

    if(dlugosc !=0)
    {
        printf("\n");
   while(ptr != last)
    {
        if(licznik%10==0)
        {
            printf("\n");
        }
        licznik++;
      printf("%d ",ptr->priorytet);
      ptr = ptr->prev;

    }
    printf("%d ",ptr->priorytet);
    }
}



char* pobierz()///pobiera wiadomosci
{
    if (dlugosc>0)
    {
       char *zwrot;
       zwrot=head->message;
       current=head;
       head=head->prev;
       free(current); ///o usuwaniu mial decydowac user, ale chyba sensowniej po pobraniu wskaznika na msg
       --dlugosc;
       return zwrot;

    }
    else
    {

        return NULL;
    }
}


int daj_priorytet(int nr)/// tez pomoc do fucnkji które maja tetsować
{
    int a=1;
    if(nr<=dlugosc&&nr>0)
    {
        current=head;
        while(a!=nr)
        {
            current=current->prev;
            a++;
        }
        a=current->priorytet;
        return a;
    }
    else
    {
        return -1;
    }

}




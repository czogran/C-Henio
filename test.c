#include "test.h"
#include "funk.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

//#include <cstdio>

void reczny()   ///jakby uzytkonik samemu chcial sprawdzic to ma taka mozliwosc
{
    int indeks;
    int pr;
    char *fmsg;
    char *msg2;
    //printf("\n");

    char **tab = (char**) malloc(10*sizeof(char*));   /// tworzymy tablice na 10 napisow, zalozenie ze uzytkonikowi nie bedzie chcialo sie testowac na wiekszej ilosci
    int i;
    for(i = 0; i < 10; i++)
    {
        tab[i] = (char*) malloc(10*sizeof(char));
        tab[i][0] = 0;

    }
    i=0;

    while(indeks!=3)
    {
    printf("\n1:wstaw\n2:pobierz\n3:skoncz testowanie reczne\n");

    fflush(stdin);
    scanf("%d",&indeks);
    //printf("%d\n",indeks);
    if(indeks==1)
    {

        printf("\npodaj priorytet\n");
        scanf("\n%d",&pr);


        printf("\ndaj wiadomosc\n");

        //result = fgets (napis, max_n, stdin);

       //fgets (tab[i], 33, stdin); //moja porazka nie wiem czemu tu nie dzialalo
       scanf("%s",tab[i]); ///wersja ze wczytuje jeden wyraz do wiadomosci
       i++;

        wstaw(pr, tab[i-1]);
    }
     if(indeks==2)
    {
        //fflush(stdin);
        msg2=pobierz();
        printf("\n");
        printf(msg2);
    }
    if(indeks==3)
    {
        break;
    }
    if(indeks !=1||indeks!=2) /// to jest po to ze sie wywalalo jak sie podawalo litery itp wiec ten if zapobiega temu
    {
        fflush(stdin);
        indeks=0;

    }

    }
}


int my_compare (const void * a, const void * b) ///do funkcji quicksort
{
    int _a = *(int*)a;
    int _b = *(int*)b;
    if(_a > _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}


void automatyczny()
{
    char *wiad="a"; ///ma na celu skasownanie wszystkich poprzednich wiadomosci z kolejki, by moc pozniej porownywac wiadomosci na liczbach, a nie stringach
    while(wiad !=NULL)
    {

       wiad= pobierz();
    }
    int zarodek;

    time_t tt;
    zarodek = time(&tt);
    srand(zarodek);
    int a=0;
    int ilosc;
    ilosc=rand()%99; ///losowanie z zakrseu 99 poniewaz tak zaprojektowalem ten test, szczegoly nizej
    printf("\ntyle bedzie wiadomoscie do testowania:  %d",ilosc);

    char *mes[ilosc];
    int tablica[ilosc]; ///generowana bedzie losowo- ilosc do 99(czyli lacznie 100), gdyz ponad to tablica ma wiecej elementow niz kolejka i po posgrewoaniu nie da sie porownywac element po elemencie
    while(a<ilosc+1) /// plus 1-> roznice w indeksowaniu, kolejka od 1 tablica od 0
    {
        tablica[a]=rand()%50;
        mes[a]=(char)tablica[a];/// rzutowanie int na char by pozniej moc porownywac msg, nie wiem jak inaczej sensownie generowac wiadomosci losowe
        wstaw(tablica[a],mes[a]);
        mes[a]="a";
        a++;

    }
    printf("\ntakie sa priorytety w kolejce\n");
    poka();
    qsort(tablica,ilosc+1,sizeof(int),my_compare); /// by posegregowac tablice
    a=0;
    int pror=0;

    printf("\n takie da nam wypisanie wszystkich priorytetwow:\n");

    while(a<ilosc+1)

    {
        if (a%10==0) ///by drukowac w wierszach i bylo ladnie
        {
            printf("\n");
        }
        printf("%d ",tablica[a]);
        pror=daj_priorytet(a+1);
        if (pror!=tablica[a])
        {
            printf("nie dziala, nr tablicy: %d\n",a);
            break;
        }


        a++;
    }
    //if ((a==(ilosc+1)||a=100)&&((daj_priorytet(a+1)==tablica[a])||(daj_priorytet(100+1)==tablica[100])))
    if (a==100||a==ilosc+1)
    {
        printf("\npriorytety sa OK\n");
    }
    a=0;
    char* pomocnicza;
    printf("let's check pobierz\n");
    while(a<ilosc+10)
    {
        if (a%10==0)
        {
            printf("\n");
        }

        pomocnicza=pobierz();
        if (pomocnicza!=tablica[a])
        {
            printf("nie dziala w tym momencie,  a=%d, ilosc=%d\n", a,ilosc);
            break;
        }

        printf("%d ",pomocnicza);//tu powinno byc %s
        a++;
    }

}


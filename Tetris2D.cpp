#include <iostream>
#include <algorithm>
using namespace std;

int const base = 1<<20;

int tab[2*base];
int lazy[2*base];

int dodaj( int pocz, int kon, int poczatek, int koniec, int id, int wart )
{
  //  cout<<" chce dodac "<<wart<<" na przedziale: "<< pocz<< " "<<kon<<endl;
    if( poczatek <=pocz && koniec >= kon  )
    {
        tab[ id ] = wart;
        lazy[id] = wart;
    //    cout<<"zapisuje bo: "<<pocz<<" "<<kon<<endl;
        return tab[id];
    }


    if( koniec < pocz || poczatek > kon || pocz > kon  ){
        return 0; }



   tab[id] = max( dodaj( pocz, (pocz+kon)/2 , poczatek, koniec, id*2, wart ), max(tab[id], dodaj( (pocz+kon)/2 +1 , kon, poczatek, koniec, id*2 +1, wart) ) );
   // dodaj( pocz, (pocz+kon)/2 , poczatek, koniec, id*2, wart );
  //  dodaj( (pocz+kon)/2 +1 , kon, poczatek, koniec, id*2 +1, wart);

   // tab[id] = max( max( tab[id], tab[id*2] ), tab[id*2 +1] );

  //  cout<<"przedzial: "<<pocz<<" "<<kon<<" wart: "<<tab[id]<<endl;

    return tab[id];
}

int maks( int pocz, int kon, int poczatek, int koniec, int id)
{
  //  cout<<"biore maks z: "<<pocz<<" "<<kon<<endl;
    if( poczatek <= pocz && koniec >= kon)
    {
  //      cout<<"zwracam bo: "<<pocz<<" "<<kon<<" wart: "<<tab[id]<<endl;
        return tab[id];
    }


    if( poczatek > kon || koniec < pocz || pocz>kon ){
        return 0;}

   // cout<<" bede bral maksa na przedziale: "<< pocz <<" "<< (pocz+kon)/2  << " oraz "<< (pocz+kon)/2 +1<<" "<<kon <<endl;
 //   cout<<" przepycham: "<<lazy[id]<<" na przedziale: "<< pocz <<" "<< (pocz+kon)/2  << " oraz "<< (pocz+kon)/2 +1<<" "<<kon <<endl;


    tab[id*2 +1] = max(tab[id*2 +1], lazy[id]);
    tab[id*2] = max( tab[id*2], lazy[id]);

    lazy[id*2 +1] = max(lazy[id*2 +1], lazy[id]);
    lazy[id*2] =  max(lazy[id], lazy[id*2] );

    lazy[id] = 0;

    return max( maks( pocz, (pocz+kon)/2 , poczatek, koniec, id*2 ), maks( (pocz+kon)/2 +1 , kon, poczatek, koniec, id*2 +1 )  );

}

int main()
{
    int szerokosc, klocki;
    int poczatek, dlugosc;
    int koniec;
    int maksik =0;

    for(int i=0; i<2*base; ++i)
    {
        tab[i] = 0;
        lazy[i] = 0;
    }

    cin>>szerokosc>>klocki;



    for(int i=0; i<klocki; ++i)
    {
        cin>>dlugosc>>poczatek;
        poczatek+=1;
        koniec = poczatek+dlugosc-1;

    //    cout<<"szukam PRZEDZIAL: "<<poczatek<<" "<<koniec<<endl;
        maksik = maks(1, base, poczatek, koniec, 1 );
     //   cout<<"dodaje PRZEDZIAL: "<<poczatek<<" "<<koniec <<" +"<<maksik+1<<endl;
        dodaj(1, base, poczatek, koniec, 1, maksik+1);

    }


    cout<<tab[1];

}


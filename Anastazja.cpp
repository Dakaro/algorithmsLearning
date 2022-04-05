#include <iostream>

using namespace std;

int odw[100007];
int ile[100007];
int licz[100007];
int Find(int a)
{
    if(odw[a]!=a){odw[a]=Find(odw[a]);}
    return odw[a];
}

void Unia(int a, int b)
{

   a=Find(a);
    b=Find(b);
    if(licz[b]>licz[a] )
    {
        int c=a;
        a=b;
        b=c;
    }

    if(Find(a)!=Find(b)){
    if(ile[licz[odw[b]]]!=0){ile[licz[odw[b]]]--;
  //  cout<<"zmniejszam ilosc zbiorow: "<<licz[odw[b]]<<" elementowych"<<endl;
    }
    if(ile[licz[odw[a]]]!=0){ile[licz[odw[a]]]--;
 //   cout<<"zmniejszam ilosc zbiorow: "<<licz[odw[a]]<<" elementowych"<<endl;
    }
 //   cout<<"lacze zbiory: "<<licz[odw[a]]<<" ("<<odw[a]<<") + "<<licz[odw[b]]<<"("<<odw[b]<<")"<<endl;
    licz[odw[a]]+=licz[odw[b]];
    ile[licz[odw[a]]]++;
    odw[b]=Find(a);
  //  cout<<"zbior: "<<odw[a]<<"("<<a<<") jest wielkosci: "<<licz[odw[a]]<<" i takich zbiorow jest: "<<ile[licz[odw[a]]]<<endl;

  //  cout<<"reprezentantem: "<<b<<" jest: "<<odw[b]<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int zapytania, stan, a, b, k;
    cin>>zapytania;
    ile[1]=100000;
    for(int i=1; i<=100000; ++i)
    {
        odw[i]=i;
        licz[i]=1;
    }
    for(int q=0; q<zapytania; ++q)
    {
        cin>>stan;
        if(stan==0){
            cin>>a>>b;
            Unia(a,b);
        }
        else{
            cin>>k;
            cout<<ile[k]<<endl;
        }
    }
}
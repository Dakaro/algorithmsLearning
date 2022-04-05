#include <iostream>

using namespace std;

int tab[1007][1007];


int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, zapytania, x1, y1, x2, y2, wynik, maks=0, x;
    cin>>n>>m;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            cin>>x;
            tab[j][i]=tab[j-1][i]+tab[j][i-1]+x-tab[j-1][i-1];
        }
    }
  //  cout<<"MAKS: "<<tab[m][n]<<endl;
    cin>>zapytania;
    for(int i=0; i<zapytania;++i)
    {
        cin>>y1>>x1>>y2>>x2;
        wynik=tab[x2][y2]-tab[x1-1][y2]-tab[x2][y1-1]+tab[x1-1][y1-1 ];
   //     cout<<tab[x2][y2]<<" - "<<tab[x1-1][y2]<<" - "<<tab[x2][y1-1]<<" + "<<tab[x1-1][y1-1]<<" = "<<wynik<<endl;
        if(wynik>maks){maks=wynik;}
    }
    cout<<maks;

}
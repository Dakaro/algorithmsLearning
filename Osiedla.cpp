#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > para;
vector<pair<int, int> > wektor[1000007];
vector<int> spojne[1000007];
vector<int> odwrocone[1000007];
//vector<int> wsteczne[1000007];
vector<int> kolejnosc;
int odw[1000007];
int kraw[1000007];
int ktoro[1000007];
char znak[10000007];
int gle[1000007];
void check(int a, int b, int p)
{
    if(a==para[p].first && b==para[p].second){
        znak[p]='>';
    }
    else{znak[p]='<';}
}

void DFS(int k, int s)
{
    odw[k]=1;
    gle[k]=s;
    for(int i=0; i<wektor[k].size(); ++i)
    {
        if(kraw[wektor[k][i].second]==0 && odw[wektor[k][i].first]==0){
            spojne[k].push_back(wektor[k][i].first);
            odwrocone[wektor[k][i].first].push_back(k);
            kraw[wektor[k][i].second]=1;
            check(k, wektor[k][i].first, wektor[k][i].second);
            DFS(wektor[k][i].first, s+1);
        }
        if(kraw[wektor[k][i].second]==0 && odw[wektor[k][i].first]==1 && gle[wektor[k][i].first]>gle[k]){
            spojne[wektor[k][i].first].push_back(k);
         //   wsteczne[wektor[k][i].first].push_back(k);
            odwrocone[k].push_back(wektor[k][i].first);
            check(wektor[k][i].first, k, wektor[k][i].second);
            kraw[wektor[k][i].second]=1;
        }
    }
}

void przejdz(int k)
{
    odw[k]=2;
    for(int i=0; i<spojne[k].size(); ++i)
    {
        if(odw[spojne[k][i]]!=2)
        {
            przejdz(spojne[k][i]);
        }
    }
    kolejnosc.push_back(k);
}

void podlicz(int k)
{
    odw[k]=3;
    for(int i=0; i<odwrocone[k].size(); ++i)
    {
        if(odw[odwrocone[k][i]]!=3)
        {
            podlicz(odwrocone[k][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int ilosc, krawedzie, a ,b;
    cin>>ilosc>>krawedzie;
    para.push_back({0,0});
    for(int i=1; i<=krawedzie; ++i)
    {
        cin>>a>>b;
        para.push_back({a,b});
        wektor[a].push_back({b, i});
        wektor[b].push_back({a,i});
    }
    for(int i=1; i<=ilosc; ++i)
    {
        if(odw[i]==0)
        {
            DFS(i, 1);
        }
    }

  /*  for(int i=1; i<=ilosc; ++i)
    {
        cout<<" DLA: "<<i<<endl;
        cout<<"drzewo: ";
        for(int j=0; j<spojne[i].size(); ++j)
        {
            cout<<spojne[i][j]<<" ";
        }
        cout<<endl<<"wsteczne: ";
        for(int j=0; j<wsteczne[i].size(); ++j)
        {
            cout<<wsteczne[i][j]<<" ";
        }
        cout<<endl;
    } */

    for(int i=1; i<=ilosc; ++i)
    {
        if(odw[i]!=2)
        {
            przejdz(i);
        }
    }
    int licznik=0;
    reverse(kolejnosc.begin(), kolejnosc.end());
    for(int i=0; i<kolejnosc.size(); ++i)
    {
        int v=kolejnosc[i];
        if(odw[v]!=3)
        {
         //   cout<<"podliczam: "<<v<<endl;
            podlicz(v);
            ++licznik;
        }
    }
    cout<<licznik<<endl;
    for(int i=1; i<=krawedzie; ++i)
    {
        cout<<znak[i];
    }
}
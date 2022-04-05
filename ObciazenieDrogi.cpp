#include <bits/stdc++.h>

using namespace std;

vector<int> wektor[500007];

int odw[500007];
long long wart[500007];
int gle[500007];
int ojciec[500007];
int lca[500007][21];
void DFS(int k, int s)
{
    odw[k]=1;
    gle[k]=s;
    for(int i=0; i<wektor[k].size(); ++i)
    {
        if(odw[wektor[k][i]]==0)
        {
            ojciec[wektor[k][i]]=k;
            DFS(wektor[k][i], s+1);
        }
    }
}
long long maks=0;
void zlicz(int k)
{
    odw[k]=2;
  //  cout<<"jestem: "<<k<<endl;
    for(int i=0; i<wektor[k].size(); ++i)
    {
        if(odw[wektor[k][i]]!=2)
        {
            zlicz(wektor[k][i]);
         //   cout<<"zbieram: "<<wektor[k][i]<<" czyli: "<<wart[wektor[k][i]]<<endl;
            wart[k]+=wart[wektor[k][i]];
          //  cout<<maks<<" vs "<<wart[k]<<endl;
            if(wart[k]>maks){maks=wart[k];}
        }
    }
    if(maks<wart[k]){maks=wart[k];}
  //  cout<<"wart w: "<<k<<" wynosi: "<<wart[k]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    long long ilosc, krawedzie, a,b,c, pocz1=0, pocz2=0, kon=0;
    cin>>ilosc>>krawedzie;
    for(int i=1; i<=ilosc-1; ++i)
    {
        cin>>a>>b;
        wektor[a].push_back(b);
        wektor[b].push_back(a);
    }
    DFS(0,1);

    for(int i=0; i<ilosc; ++i)
    {
        lca[i][0]=ojciec[i];
    }
    for(int k=1; k<=20; ++k)
    {
        for(int i=1; i<=ilosc; ++i)
        {
            lca[i][k]=lca[lca[i][k-1]][k-1];
        }
    }

    for(int i=0; i<krawedzie; ++i)
    {
        cin>>a>>b>>c;
        int temp=0;
        if(gle[a]>gle[b]){
            temp=a;
            a=b;
            b=temp;
        }
        pocz1=a;
        pocz2=b;
        for(int j=20; j>=0; --j)
        {
            if(gle[lca[b][j]]>=gle[a]){b=lca[b][j];}
       //     cout<<"lca: "<<a<<" "<<b<<endl;
        }
        if(a==b){
            kon=a;
        //    cout<<"zapis pojedynczy: "<<pocz2<<" do: "<<kon<<endl;
            wart[kon]-=c;
            wart[pocz2]+=c;
        }
        else{
            for(int j=20; j>=0; --j)
            {
                if(lca[a][j]!=lca[b][j])
                {
                    a=lca[a][j];
                    b=lca[b][j];
                }
            }
            kon=ojciec[a];
        //    cout<<"zapis: "<<pocz2<<" do: "<<kon<<endl;
            wart[pocz1]+=c;
            wart[pocz2]+=c;
            wart[kon]-=(2*(long long)c);
        }
    }
    zlicz(0);
    cout<<maks;


}
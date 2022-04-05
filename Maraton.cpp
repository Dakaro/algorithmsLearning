#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define LONG_LONG_MAX 	9223372036854775807

using namespace std;

vector <pair<int, int> > wektor[300000];
priority_queue< pair<long long, pair<int,int> >, vector< pair<long long, pair<int,int> > >, greater<pair<long long, pair<int,int> > >  > kolejka;

long long odw[300000];


int main() { 

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int miasta, drogi;
    cin>>miasta>>drogi;

    int a,b, waga1, meta;

    for(int i=0; i<200009; ++i)
    {
        odw[i] = LONG_LONG_MAX;
    }

    for(int i=0; i<drogi; ++i)
    {
        cin>>b>>a>>waga1;
        wektor[a].push_back({b,waga1});
    }

    cin>>meta;

    odw[meta] = 0;

  //  cout<<"meta: "<<meta<<endl;
    for(int i=0; i<wektor[meta].size(); ++i)
    {
        kolejka.push( {wektor[meta][i].second, {meta, wektor[meta][i].first}} );
  //      cout<<"wrzucam: "<< wektor[meta][i].second <<" miasto: "<< wektor[meta][i].first<<endl;
    }

    long long maksimum = 0;
    int odpowiedz = 0;

    while( !kolejka.empty() )
    {
        int miastoZ = kolejka.top().second.first;
        int miastoD = kolejka.top().second.second;
        long long waga    = kolejka.top().first;

   //   cout<<"przyszedlem z "<<miastoZ<<" do: "<<miastoD<<" chce zapsiac: "<<waga<<endl;

        kolejka.pop();

        if( odw[miastoD] > waga )
        {


            if( waga > maksimum  )
            {
                maksimum = waga;
                odpowiedz = miastoD;
            }

            if( waga == maksimum && miastoD < odpowiedz )
            {
                odpowiedz = miastoD;
            }

            odw[miastoD] = waga;

            for( int i=0; i<wektor[miastoD].size(); ++i)
            {
                if( odw[ wektor[miastoD][i].first ] == LONG_LONG_MAX ) {
                    kolejka.push({odw[miastoD] + wektor[miastoD][i].second, {miastoD, wektor[miastoD][i].first}});
              //      cout<<"wrzucam: "<< odw[miastoD] + wektor[miastoD][i].second <<" miasto: "<< wektor[miastoD][i].first<<endl;
                }
            }

        }

    }

   // cout<<odp << " " << maks<<endl;
    cout<<odpowiedz<<" "<<maksimum;

}
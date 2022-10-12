#include <iostream>
#include <algorithm>
using namespace std;

long long tab[100007];

int main()
{
    int amount;
    cin >> amount;

    for( int i = 0; i < 100000; ++i ){
        tab[i] = 0;
    }

    int x;
    for( int i = 0; i < amount; ++i ){
        cin >> x;
        tab[ x ] += x;

    }

    int secondIndex = 0;
    int prevIndex = 0;
    for( int i = 0; i <= 100000; ++i ){
        secondIndex = i - 2 < 0 ? 0 : i - 2;
        prevIndex = i - 1 < 0 ? 0 : i - 1;
        tab[ i ] = max( tab[ prevIndex ]  , tab[i] + tab [ secondIndex ] );
    }

    cout << tab[ 100000 ];

}
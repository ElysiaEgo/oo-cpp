#include<bits/stdc++.h>

using namespace std;

int fact_cache[20];

int fact(int num)
{
    // if cache return cache
    if (fact_cache[num - 1]) return fact_cache[num - 1];
    // calc if not cache
    return fact(num - 1) * num;
}

int main()
{
    // init fact_cache
    memset(fact_cache, 0, sizeof(fact_cache));
    // manually set fact(1) = 1
    fact_cache[0] = 1;
    int num;
    cin >> num;
    cout << fact(num) << endl;
    return 0;
}

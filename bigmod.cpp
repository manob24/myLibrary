#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long bigmod(long long b, long long p){
    if(p == 0) return 1;
    if(p%2){
        return ((b%MOD) * (bigmod(b,p-1)))%MOD;
    }
    else{
        long long c = bigmod(b,p/2);
        return ((c%MOD)*(c%MOD))%MOD;
    }
}
#include<bits/stdc++.h>
using namespace std;


#define limit 1000000
vector<int>primes;
int len;
void seive(){
    bool mark[limit+3]={0};
    memset(mark,true,sizeof(mark));
    for(int i = 2; i<limit+1; ++i){
        if(mark[i]){
            for(int j = i*2; j<=limit; j+=i){
                mark[j]=false;
            }
        }
    }
    for(int i = 2; i<=limit; ++i){
        if(mark[i]){
            primes.push_back(i);
        }
    }
    len= primes.size();
}

int segmentedSieve(ll low, ll high){
    int lmt = (int)sqrt(high) + 1;
    int n = high-low+1;
    bool mark[n+1];
    memset(mark,false,sizeof(mark));
    for(int i = 0; i<len; ++i){
        if(primes[i]>lmt)
            break;
        int loLim = (low/primes[i])*primes[i];
        if(loLim < low)
            loLim += primes[i];
        if(loLim == primes[i])
            loLim +=primes[i];

        for(ll j = loLim; j<=high; j+=primes[i]){
                mark[j-low]=true;
        }
    }
    int cnt = 0;
    for(int i = low; i<=high; ++i){
        if(!mark[i]){
            cout<<i<<" ";
        }
    }
    if(low==1)
        --cnt;
    return cnt;
}
#include<bits/stdc++.h>
using namespace std;

bool prime[400006]={0};
vector<int>vt;
int len;
void seive(){
    memset(prime,true,sizeof(prime));
    prime[2]=true;
    for(int i = 2; i<100000; ++i){
        if(prime[i]){
            for(int j = i*2; j<=100000; j+=i){
                prime[j]=false;
            }
        }
    }
    for(int i = 2; i<100000; ++i){
        if(prime[i]){
            vt.push_back(i);
        }
    }
    len= vt.size();
}
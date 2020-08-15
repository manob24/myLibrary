#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[12][2][2][15],len;
char num[12];

ll digitDP(int pos, int isEqual,int allZeroes, int totZero){
	if(pos==len) return totZero;
	ll &ret = dp[pos][isEqual][allZeroes][totZero];
	if(ret!=-1) return ret;
	ret = 0;
	int d = num[pos]-'0';
	int mx = isEqual?d:9;
	for(int i = 0; i<=mx; ++i){
		ret+=digitDP(pos+1,isEqual && i==d,allZeroes && (i==0),totZero+(i==0 && !allZeroes));
	}
	return ret;
}

ll solve(ll a){
	sprintf(num,"%lld",a);
	len = strlen(num);
	memset(dp,-1,sizeof(dp));
	return digitDP(0,1,1,0);
}

#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int>v;
	int n,num;
	scanf("%d",&n);
	for(int i = 0; i<n; ++i){
		scanf("%d",&num);
		vector<int>::iterator iV = lower_bound(v.begin(),v.end(),num);
		if(v.end() == iV) v.push_back(num);
		else
			v[iV-v.begin()] = num;
	}
	printf("LIS = %d\n",v.size());
}
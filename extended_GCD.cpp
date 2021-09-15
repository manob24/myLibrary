 pair<int,int> ex_gcd(int a, int b){
	if(a%b==0)
		return make_pair(0,1);
	pair<int, int> prev = ex_gcd(b, a%b);
	return make_pair(prev.second, prev.first + prev.second * (a/b) ) ;
}
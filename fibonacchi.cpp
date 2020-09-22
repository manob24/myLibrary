ll fib[30][2][2];

void multiply(ll A[2][2], ll B[2][2],ll C[2][2]){
    ll w = ((A[0][0]*B[0][0])%MOD+(A[0][1]*B[1][0])%MOD)%MOD;
    ll x = ((A[0][0]*B[0][1])%MOD+(A[0][1]*B[1][1])%MOD)%MOD;
    ll y = ((A[1][0]*B[0][0])%MOD+(A[1][1]*B[1][0])%MOD)%MOD;
    ll z = ((A[1][0]*B[0][1])%MOD+(A[1][1]*B[1][1])%MOD)%MOD;
    C[0][0]=w;
    C[0][1]=x;
    C[1][0]=y;
    C[1][1]=z;
}

void init(){
    fib[0][0][0]=1;
    fib[0][0][1]=1;
    fib[0][1][0]=1;
    fib[0][1][1]=0;
    for(int i = 1; i<30; ++i){
        multiply(fib[i-1],fib[i-1],fib[i]);
    }

    // for(int i = 0; i<30; ++i){
    //     printf("%lld %lld\n%lld %lld\n",fib[i][0][0],fib[i][0][1],fib[i][1][0],fib[i][1][1]);
    // }
}

void getFib(ll ans[2][2],ll n){
    ans[0][0]=1;
    ans[0][1]=0;
    ans[1][0]=0;
    ans[1][1]=1;

    vector<int>a;
    int i = 0;
    while(n){
        if(n&1){
            a.push_back(i);
        }
        n>>=1;
        ++i;
    }
    int len = a.size();


    for(i = len-1; i>=0; --i){
        multiply(ans,fib[a[i]],ans); 
    }
    //printf("%lld %lld\n%lld %lld\n",ans[0][0],ans[0][1],ans[1][0],ans[1][1]);        
}
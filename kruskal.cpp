struct Edge
{
    int u,v,w;
    Edge(pair<pair<int,int>,int>p){
        u = p.ff.ff;
        v = p.ff.ss;
        w = p.ss;
    }
};

bool operator<(Edge A, Edge B){
    return A.w<B.w;
}

vector<Edge>E;

int p[202];

int find(int x){
    if(p[x]==x) return x;
    return p[x]= find(p[x]);
}
int n,m;

void reset(){
    for(int i = 1; i<=n; ++i){
        p[i]=i;
    }
}

int kruskal(){
    reset();

    sort(E.begin(),E.end());

    int sz = E.size();
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i<sz; ++i){
        if(find(E[i].u)!=find(E[i].v)){
            p[p[E[i].u]]=p[E[i].v];
            ans+=E[i].w;
            ++cnt;
        }
        else{
            E.erase(E.begin()+i);
            --i;
            --sz;
        }
    }
    if(cnt != n-1)
        ans = -1;
    return ans;
}

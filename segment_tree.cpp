

// Call with build(1,1,n);

void build(int at,int L, int R){
	sum[at]=0;
	if(L==R)
	{
		return;
	}
	int mid = (L+R)>>1;
	build(at<<1,L,mid);
	build((at<<1)+1,mid+1,R);
	sum[at]=sum[at<<1]+sum[(at<<1)+1];
}

//call with update(1,1,n,pos,u)

void update(int at, int L, int R, int pos, int u){
	if(L==R){
		sum[at]+=u;
		return;
	}
	int mid = (L+R)>>1;
	if(pos<=mid)
		update(at<<1,L,mid,pos,u);
	else
		update((at<<1)+1,mid+1,R,pos,u);

	sum[at]=sum[at<<1]+sum[(at<<1)+1];
}

//call with query(1,1,n,l,r)

int query(int at, int L, int R, int l, int r){
	if(r<L || R<l ) return 0;
	if(l<=L && R<=r) return sum[at];

	int mid = (L+R)>>1;
	int x = query(at<<1,L,mid,l,r);
	int y = query((at<<1)+1,mid+1,R,l,r);
	return x+y;
}


//Lazy Propagation
//lightoj 1135

struct node{
    int add=0;
    int num[3]={0};
    node(){}
    node(int add,int num[]){
        this->add = add;
        this->num[0] = num[0];
        this->num[1] = num[1];
        this->num[2] = num[2];
    }
   
};

node operator+(node a,const node& b){
    node nd;
    nd.add = 0;
    nd.num[0]=a.num[0]+b.num[0];
    nd.num[1]=a.num[1]+b.num[1];
    nd.num[2]=a.num[2]+b.num[2];
    return nd;
}
node sum[4*MX];

void build(int at,int L, int R){
    sum[at]=node();
    if(L==R)
    {
        sum[at].num[0]=1;
        return;
    }
    int mid = (L+R)>>1;
    build(at<<1,L,mid);
    build((at<<1)|1,mid+1,R);
    sum[at]=sum[at<<1]+sum[(at<<1)|1];
}


void propagate(int at){
    int left = at<<1;
    int right = (at<<1)|1;
    int num[3]={0};

    int add = sum[left].add + sum[at].add;
    int cng = sum[at].add%3;
    for(int i = 0;i<3; ++i){
        num[(i+cng)%3]=sum[left].num[i];
    }
    sum[left]=node(add,num);

    add = sum[right].add + sum[at].add;
    for(int i = 0;i<3; ++i){
        num[(i+cng)%3]=sum[right].num[i];
    }
    sum[right]=node(add,num);
    
    sum[at].add = 0;

}

void update(int at, int L, int R, int l, int r){
    if(r<L || R<l ) return ;
    if(l<=L && R<=r){
        int add = sum[at].add +1;
        int num[3]={0};
        for(int i = 0;i<3; ++i){
            num[(i+1)%3]=sum[at].num[i];
        }
        sum[at]=node(add,num);
        return;
    }
    if(sum[at].add>0) propagate(at);

    int mid = (L+R)>>1;
    update(at<<1,L,mid,l,r);
    update((at<<1)|1,mid+1,R,l,r);
    sum[at]=sum[at<<1]+sum[(at<<1)|1];
}


int query(int at, int L, int R, int l, int r){
    if(r<L || R<l ) return 0;
    if(l<=L && R<=r) return sum[at].num[0];

    if(sum[at].add>0) propagate(at);

    int mid = (L+R)>>1;
    int x = query(at<<1,L,mid,l,r);
    int y = query((at<<1)|1,mid+1,R,l,r);

    sum[at] = sum[at<<1]+sum[(at<<1)|1];
    return x+y;
}

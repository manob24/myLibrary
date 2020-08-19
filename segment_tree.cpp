

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
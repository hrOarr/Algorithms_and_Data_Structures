// query in range between r and l

int _curBit(int x,int k){return (x&(1<<k))>0;}
void _copy(int cur,int prv)
{
	T[cur][0]=T[prv][0];
	T[cur][1]=T[prv][1];
	sm[cur]=sm[prv]+1;
}
int _interval(int l,int r,int f){return (sm[T[r][f]]-sm[T[l][f]]);}
void _insert(int x)
{
	int cur=++nod;
	_copy(cur,rt[tim]);
	rt[++tim]=cur;
	for(int i=25;i>=0;i--)
	{
		int f=_curBit(x,i);
		++nod;
		_copy(nod,T[cur][f]);
		T[cur][f]=nod;
		cur=nod;
	}
}
int _kth(int l,int r,int k) // kth-smallest
{
	l=rt[l-1],r=rt[r];
	int rs=0;
	for(int i=25;i>=0;i--)
	{
		int rt=_interval(l,r,0);
		int f=(rt<k)?1:0;
		if(f)k-=rt,rs+=(1<<i);
		l=T[l][f],r=T[r][f];
	}
	return rs;
}
int _count(int l,int r,int k) // count less than or equal to k
{
	k++;l=rt[l-1],r=rt[r];
	int rs=0;
	for(int i=25;i>=0;i--)
	{
		int f=_curBit(k,i);
		int rt=_interval(l,r,0);
		if(f)rs+=rt;
		l=T[l][f],r=T[r][f];
	}
	return rs;
}
int _maxXor(int l,int r,int k) // max xor with k
{
	l=rt[l-1],r=rt[r];
	int rs=0;
	for(int i=25;i>=0;i--)
	{
		int f=_curBit(k,i);
		int rt=_interval(l,r,1-f);
		int ff=(rt!=0)?1:0;
		if(ff)rs+=(1<<i);
		l=T[l][ff^f],r=T[r][ff^f];
	}
	return rs^k;
}

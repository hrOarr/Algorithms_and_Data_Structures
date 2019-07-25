vector<pair<int,int>> _primeFactor(int n)
{
	vector<pair<int,int>> factor;
	int id=0,p=prim[0];
	while(n!=1&&(p*p<=n))
        {
		int cnt=0;
		while(n%p==0)n/=p,cnt++;
		if(cnt)factor.push_back(make_pair(p,cnt));
		p=prim[++id];
	}
	if(n>1)factor.push_back(make_pair(n,1));
	return factor;
}
int numOfDivisors(int n)
{
  	int id=0,p=prim[id],rs=1;
  	while(n!=1&&(p*p<=n))
        {
    	int cnt=0;
    	while(n%p==0)n/=p,cnt++;
    	rs*=(cnt+1);
    	p=prim[++id];
  	}
 	if(n>1)rs*=2;
	return rs;
}
int sumOfDivisor(int n)
{
	int id=0,p=prim[id],rs=1;
	while(n!=1&&(p*p<=n))
        {
		int cnt=0;
		while(n%p==0)n/=p,cnt++;
		rs*=(powMod(p,cnt+1)-1)/(p-1);
		p=prim[++id];
	}
	if(n>1)rs*=(powMod(n,2)-1)/(n-1);
	return rs;
}

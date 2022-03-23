unordered_map<string,int>dp;
bool ispali(string s,int lo,int hi)
{
	while(lo<hi)
        {
		if(s[lo]!=s[hi])return 0;
		lo++,hi--;
	}
	return 1;
}
string _convert(int a, int b)
{
	return to_string(a)+""+to_string(b);
}
int dfs(string s,int l,int r)
{
	if(l>r)return 0;
	string tm=_convert(l,r);
	if(dp.find(tm)!=dp.end())return dp[tm];
	if(l==r)
        {
		dp[tm]=0;
		return 0;
	}
	if(ispali(s,l,r))
	{
		dp[tm]=0;
		return 0;
	}
	int rt=inf;
	for(int i=l;i<r;i++)
	{
		int lft,rgt;
		lft=rgt=inf;
		string left=_convert(l,i);
		string right=_convert(i+1,r);
		if(dp.find(left)!=dp.end())lft=dp[left];
		if(dp.find(right)!=dp.end())rgt=dp[right];
		if(lft==inf)lft=dfs(s,l,i);
		if(rgt==inf)rgt=dfs(s,i+1,r);
		rt=min(rt,lft+1+rgt);
	}
	dp[tm]=rt;
	return dp[tm];
}

// optimized
memset(P,0,sizeof P);
for(int i=0;i<n;i++){
    P[i][i]=1;
}
for(int i=2;i<=n;i++){
    for(int j=0;j<n-i+1;j++){
	int k=j+i-1;
	if(i==2){
	    P[j][k]=(s[j]==s[k]);
	}
	else{
	    P[j][k]=(s[j]==s[k] && P[j+1][k-1]);
	}
    }
}

int c[n+1];
for(int i=0;i<n;i++){
    if(P[0][i]){
	c[i]=0;
    }
    else{
	c[i]=1e5;
	for(int j=0;j<i;j++){
	    if(P[j+1][i] && 1+c[j]<c[i]){
		c[i]=c[j]+1;
	    }
	}
    }
}

int ternarySearch(int x)
{
        int lo=1,hi=n,md1,md2;
	while(hi>=lo)
        {
		md1=lo+(hi-lo)/3;
		md2=hi-(hi-lo)/3;
		if(A[md1]==x)
			return md1;
		if(A[md2]==x)
			return md2;
		if(x<A[md1])
			hi=md1-1;
		else if(x>A[md2])
			lo=md2+1;
		else
		{
			lo=md1+1;
			hi=md2-1;
		}
	}
	return -1;
}
int main()
{
	cout<<ternarySearch(x)<<"\n";
}

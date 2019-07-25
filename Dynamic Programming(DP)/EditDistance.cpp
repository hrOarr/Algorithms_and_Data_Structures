int min(int x,int y,int z)
{
	return min(min(x,y),z);
}
int editDist(string s1,string s2,int m,int n)
{
	int dp[m+1][n+1];
	for(int i=0; i<=m; i++)
	{
		for(int j=0; j<=n; j++)
		{
			// insert all characters of second string
			if(i==0)
				dp[i][j]=j;
			// remove all characters of second string
			else if(j==0)
				dp[i][j]=i;
			else if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=1+min(dp[i][j-1], // Insert
								dp[i-1][j], // Remove
								dp[i-1][j-1]); // Replace
		}
	}
	return dp[m][n];
}

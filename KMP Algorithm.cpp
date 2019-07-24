void KMP( char *str,char *pat,int len )
{
    int i,j,k;
    memset(Fail,-1,sizeof Fail);
    for(i=1;pat[i];i++)
    {
        for(k=Fail[i-1];k>=0&&pat[i]!=pat[k+1];k=Fail[k])
        {
            if( pat[k+1]==pat[i] )Fail[i] = k+1;
        }
    }
    i = j = 0;
    vec.clear();
    while(str[i])
    {
        if( !pat[j] )
        {
            vec.push_back(i-len);
            j = Fail[j-1]+1;
            continue;
        }
        if( pat[j]==str[i] )++i,++j;
        else if( j==0 )++i;
        else j = Fail[j-1]+1;
    }
    if( !pat[j] )vec.push_back(i-len);
    return ;
}
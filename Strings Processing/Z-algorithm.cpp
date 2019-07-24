void z_algo(string &s,int n)
{
    int L=0,R=0;
    for(int i=1;i<n;i++)
    {
        if(i>R)
        {
            L=R=i;
            while(R<n&&s[R-L]==s[R])R++;
            z[i]=R-L;
            R--;
        }
        else
        {
            int k=i-L;
            if(z[k]<R-i+1)z[i]=z[k];
            else
            {
                L=i;
                while(R<n&&s[R-L]==s[R])R++;
                z[i]=R-L;
                R--;
            }
        }
    }
}
int main()
{
    string s,pat;cin>>s>>pat;
    string ss=pat+"#"+s;
    z_algo(ss,ss.size());
}

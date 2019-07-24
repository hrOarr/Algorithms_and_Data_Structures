void BuildCorasick()
{
    memset(Trie,-1,sizeof Trie);
    for(int i=0;i<N;i++)
    {
        Aho[i] = 0;
        Fail[i] = -1;
    }
    int Nod = 0;
    for(int i=0;i<k;i++)
    {
        string nw = str[i];
        int cur = 0;
        for(int j=0;j<nw.size();j++)
        {
            int x = nw[j]-'a';
            if( Trie[cur][x]==-1 )
                Trie[cur][x] = ++Nod;
            cur = Trie[cur][x];
        }
        Aho[cur] |= (1<<i);
    }

    for(int i=0;i<26;i++)
    {
        if( Trie[0][i]==-1 )
            Trie[0][i] = 0;
    }
    queue<int>q1;
    for(int i=0;i<26;i++)
    {
        if( Trie[0][i]!=0 )
        {
            Fail[ Trie[0][i] ] = 0;
            q1.push(Trie[0][i]);
        }
    }
    while(!q1.empty())
    {
        int u = q1.front();
        q1.pop();
        for(int i=0;i<=26;i++)
        {
            if( Trie[u][i]!=-1 )
            {
                int now = Fail[u];
                while( Trie[now][i]==-1 )now = Fail[now];
                now = Trie[now][i];
                Fail[ Trie[u][i] ] = now;
                Aho[ Trie[u][i] ] |= Aho[now];
                q1.push(Trie[u][i]);
            }
        }
    }
}

int find_state(int cur,int x)
{
    while(Trie[cur][x]==-1)cur = Fail[cur];
    return Trie[cur][x];
}

void QryWords()
{
    BuildCorasick();
    int cur = 0;
    for(int i=0;i<s.size();i++)
    {
        cur = find_state(cur,s[i]-'a');
        if( Aho[cur]==0 )continue;
        for(int j=0;j<k;j++)
        {
            if( Aho[cur]&(1<<j) )
            {
                cout<< "Word "<<str[j]<< " appears from "<<(i-str[j].size()+1)<< " to "<<i<< "\n";
            }
        }
    }
}
void updt(int id,int vl,vector<int>& T) 
{ 
    while(id>0&&id<T.size()) 
    { 
        T[id]+=vl; 
        id+=(id&(-id)); 
    } 
} 
int qry(int id,vector<int>& T) 
{ 
    int rt=0;
    while(id>0) 
    { 
        rt+=T[id]; 
        id-=(id&(-id)); 
    } 
    return rt; 
} 
int findKthSmallest(int k,vector<int> &T) 
{ 
    int lo=0,hi=T.size(); 
    while(lo<hi) 
    { 
        int md=(lo+hi)>>1; 
        if(k<=qry(md,T))hi=md; 
        else lo=md+1; 
    } 
    return lo; 
} 
void _insert(int x,vector<int> &T) 
{ 
    updt(x,1,T); 
} 
void _delete(int x,vector<int> &T) 
{ 
    updt(x,-1,T); 
} 
int findRank(int x,vector<int> &T) 
{ 
    return qry(x,T); 
} 
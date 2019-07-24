const int N = 1e6+6;
struct Node
{
    int vl;
    Node *lft,*rgt;
    Node(){}
    Node(Node *l,Node *r,int val)
    {
        lft = l;
        rgt = r;
        vl  = val;
    }
};
Node *Ver[N];
int arr[N];
void build( Node *cur,int lo,int hi )
{
    if(lo==hi)
    {
        cur->vl += arr[lo];
        return ;
    }
    int mid = (lo+hi)/2;
    cur->lft = new Node(NULL,NULL,0);
    cur->rgt = new Node(NULL,NULL,0);
    build( cur->lft,lo,mid );
    build( cur->rgt,mid+1,hi );
    cur->vl = ( cur->lft->vl + cur->rgt->vl );
    return ;
}
void updt( Node *pre,Node *cur,int lo,int hi,int id,int x )
{
    if(id>hi||id<lo||lo>hi) return ;
    if(lo==hi)
    {
        cur->vl = (pre->vl+x);
        return ;
    }
    int mid = (lo+hi)/2;
    if(id<=mid)
    {
        cur->rgt = pre->rgt;
        cur->lft = new Node(NULL,NULL,0);
        updt(pre->lft,cur->lft,lo,mid,id,x);
    }
    else
    {
        cur->lft = pre->lft;
        cur->rgt = new Node(NULL,NULL,0);
        updt(pre->rgt,cur->rgt,mid+1,hi,id,x);
    }
    cur->vl = ( cur->lft->vl + cur->rgt->vl );
    return ;
}
int qry( Node *cur,int lo,int hi,int l,int r )
{
    if(l>hi||r<lo||lo>hi) return 0;
    if(lo>=l&&hi<=r)      return cur->vl;
    int mid = (lo+hi)/2;
    int r1 = qry( cur->lft,lo,mid,l,r );
    int r2 = qry( cur->rgt,mid+1,hi,l,r );
    return (r1+r2);
}

int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    Node *root = new Node(NULL,NULL,0);
    build(root,1,n);
    Ver[0] = root;
    int q; cin>>q;
    int now = 0;
    while(q--)
    {
        int tp; cin>>tp;
        if(tp==2)
        {
            int vr,l,r;cin>>vr>>l>>r;
            cout<<qry(Ver[vr],1,n,l,r)<< "\n";
        }
        else
        {
            int vr,id,x;cin>>vr>>id>>x;
            Ver[++now] = new Node(NULL,NULL,0);
            //updt(Ver[now-1],Ver[now],1,n,id,xa);
            updt(Ver[vr],Ver[now],1,n,id,x);
        }
    }
    return 0;
}
© 2019 GitHub, Inc.
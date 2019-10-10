#include"bits/stdc++.h"
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
typedef long long int ll;
const ll N=1e6+2,inf=1e9+7;
void _run();
void no(){cout<<"-1\n",exit(0);}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	_run();
	return 0;
}
struct Tree
{
    int cnt4,cnt7,cnt47,cnt74,lz;
}T[4*N];
int n,q;string s;
void _NodCal(int nd,int st,int ed)
{
    T[nd].cnt4=T[2*nd].cnt4+T[2*nd+1].cnt4;
    T[nd].cnt7=T[2*nd].cnt7+T[2*nd+1].cnt7;
    T[nd].cnt47=max(T[2*nd].cnt4+T[2*nd+1].cnt7,max(T[2*nd].cnt4+T[2*nd+1].cnt47,T[2*nd].cnt47+T[2*nd+1].cnt7));
    T[nd].cnt74=max(T[2*nd].cnt7+T[2*nd+1].cnt4,max(T[2*nd].cnt7+T[2*nd+1].cnt74,T[2*nd].cnt74+T[2*nd+1].cnt4));
}
void push_down(int nd,int st,int ed,int vl)
{
    swap(T[nd].cnt47,T[nd].cnt74);
    swap(T[nd].cnt4,T[nd].cnt7);
    if(st!=ed)
    {
        T[2*nd].lz=(T[2*nd].lz+vl)%2;
        T[2*nd+1].lz=(T[2*nd+1].lz+vl)%2;
    }
    T[nd].lz=0;
}
void build(int nod,int st,int ed)
{
    if(st==ed)
    {
        if(s[st-1]=='4')T[nod].cnt4=1;
        else T[nod].cnt7=1;
        return;
    }
    int md=(st+ed)>>1;
    build(2*nod,st,md);build(2*nod+1,md+1,ed);
    _NodCal(nod,st,ed);
}
void updt(int nod,int st,int ed,int l,int r,int vl)
{
    if(T[nod].lz)push_down(nod,st,ed,T[nod].lz);
    if(st>ed||st>r||ed<l)return;
    if(st>=l&&ed<=r)
    {
        swap(T[nod].cnt47,T[nod].cnt74);
        swap(T[nod].cnt4,T[nod].cnt7);
        if(st!=ed)
        {
            T[2*nod].lz=(T[2*nod].lz+vl)%2;
            T[2*nod+1].lz=(T[2*nod+1].lz+vl)%2;
        }
        return;
    }
    int md=(st+ed)>>1;
    updt(2*nod,st,md,l,r,vl);
    updt(2*nod+1,md+1,ed,l,r,vl);
    _NodCal(nod,st,ed);
}
void _run()
{
    cin>>n>>q>>s;
    build(1,1,n);
    while(q--)
    {
        string ss;cin>>ss;
        // non-decreasing subsequences length
        if(ss=="count")cout<<max(T[1].cnt4,max(T[1].cnt7,T[1].cnt47))<<"\n";
        else
        {
            int l,r;cin>>l>>r; // flip 4 to 7 or vice versa
            updt(1,1,n,l,r,1);
        }
    }
}

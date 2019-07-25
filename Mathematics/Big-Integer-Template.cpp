#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef long long ll;
typedef pair<ll,ll> lll;
typedef pair<ll,int> lli;
typedef pair<int,int> ii;
#define EL printf("\n")
#define OK printf("OK")
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a,x) memset(a, x, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
const int base = 1e9;
typedef vector<int> BigInt;
void Set(BigInt &a){
    while((int)a.size()>1&&a.back()==0)a.pop_back();
}
void Print(BigInt a){
    Set(a);
    printf("%d",(a.size()==0)?0:a.back());
    FORD(i,a.size()-2,0)printf("%09d",a[i]); EL;
}
// string to integer
BigInt Integer(string s){
    BigInt rs;
    if(s[0]=='-') return rs;
    if((int)s.size()==0){rs.pb(0);return rs;}
    while((int)s.size()%9!=0)s='0'+s;
    for(int i=0;i<(int)s.size();i+=9){
        int v=0;
        for(int j=i;j<i+9;j++)v=v*10+(s[j]-'0');
        rs.insert(rs.begin(),v);
    }
    Set(rs);
    return rs;
}
BigInt Integer(char c[]){
    string s="";
    FOR(i,0,strlen(c)-1)s=s+c[i];
    return Integer(s);
}
// long long integer
BigInt Integer(ll x){
    string s="";
    while(x>0)s=char(x%10+'0')+s,x/=10;
    return Integer(s);
}
// integer
BigInt Integer(int x){
    return Integer((ll)x);
}
void operator >> (istream &in,BigInt &a){
    string s;
    getline(cin,s);
    a=Integer(s);
}
void operator << (ostream &out,BigInt a){
    Print(a);
}
// less than check
bool operator < (BigInt a,BigInt b){
    Set(a);Set(b);
    if(a.size()!=b.size()) return (a.size()<b.size());
    FORD(i,a.size()-1,0)
        if(a[i]!=b[i]) return (a[i]<b[i]);
    return false;
}
// greater than check
bool operator > (BigInt a,BigInt b){
    return (b < a);
}
// equal to check
bool operator == (BigInt a,BigInt b){
    return (!(a<b)&&!(b<a));
}
// less than equal check
bool operator <= (BigInt a,BigInt b){
    return (a<b||a==b);
}
// greater than equal check
bool operator >= (BigInt a,BigInt b){
    return (b<a||b==a);
}
bool operator < (BigInt a,int b){
    return (a<Integer(b));
}
bool operator > (BigInt a,int b){
    return (a>Integer(b));
}
bool operator == (BigInt a,int b){
    return (a==Integer(b));
}
bool operator >= (BigInt a,int b){
    return (a>=Integer(b));
}
bool operator <= (BigInt a,int b){
    return (a<=Integer(b));
}
BigInt max(BigInt a,BigInt b)
{
    if(a>b) return a;
    return b;
}
BigInt min(BigInt a,BigInt b){
    if(a<b) return a;
    return b;
}
BigInt operator + (BigInt a,BigInt b){
    Set(a);Set(b);
    BigInt rs;
    int carry=0;
    FOR(i,0,max(a.size(),b.size())-1){
        if(i<a.size())carry+=a[i];
        if(i<b.size())carry+=b[i];
        rs.pb(carry%base);
        carry/=base;
    }
    if(carry)rs.pb(carry);
    Set(rs);
    return rs;
}
BigInt operator + (BigInt a,int b){
    return a+Integer(b);
}
BigInt operator ++ (BigInt &a){
    a=a+1;
    return a;
}
void operator += (BigInt &a,BigInt b){
    a=a+b;
}
void operator += (BigInt &a,int b){
    a=a+b;
}
BigInt operator - (BigInt a,BigInt b){
    Set(a);Set(b);
    BigInt rs;
    int carry=0;
    FOR(i,0,a.size()-1){
        carry+=a[i]-(i<b.size()?b[i]:0);
        if(carry<0)rs.pb(carry+base),carry=-1;
        else rs.pb(carry),carry=0;
    }
    Set(rs);
    return rs;
}
BigInt operator - (BigInt a,int b){
    return a-Integer(b);
}
void operator -- (BigInt &a){
    a=a-1;
}
void operator -= (BigInt &a,BigInt b){
    a=a+b;
}
void operator -= (BigInt &a,int b){
    a=a-b;
}
BigInt operator * (BigInt a,BigInt b){
    Set(a);Set(b);
    BigInt rs;
    rs.assign(a.size()+b.size(),0);
    FOR(i,0,a.size()-1){
        ll carry=0ll;
        for(int j=0;j<b.size()||carry>0;j++){
            ll s=rs[i+j]+carry+(ll)a[i]*(j<b.size()?(ll)b[j]:0ll);
            rs[i+j]=s%base;
            carry=s/base;
        }
    }
    Set(rs);
    return rs;
}
BigInt operator * (BigInt a,int b){
    return a*Integer(b);
}
void operator *= (BigInt &a,BigInt b){
    a=a*b;
}
void operator *= (BigInt &a,int b){
    a=a*b;
}
BigInt operator / (BigInt a,BigInt b){
    Set(a);Set(b);
    if(b==Integer(0))return Integer("-1");
    BigInt rs,cur;
    FORD(i,a.size()-1,0){
        cur.insert(cur.begin(),a[i]);
        int x=0,L=0,R=base;
        while(L<=R){
            int mid=(L+R)>>1;
            if(b*Integer(mid)>cur){
                x=mid;
                R=mid-1;
            }
            else L=mid+1;
        }
        cur=cur-Integer(x-1)*b;
        rs.insert(rs.begin(),x-1);
    }
    Set(rs);
    return rs;
}
BigInt operator / (BigInt a,int b){
    Set(a);
    BigInt rs;
    ll cur=0ll;
    FORD(i,a.size()-1,0){
        cur=(cur*(ll)base+(ll)a[i]);
        rs.insert(rs.begin(),cur/b);
        cur%=b;
    }
    Set(rs);
    return rs;
}
void operator /= (BigInt &a,BigInt b){
    a=a/b;
}
void operator /= (BigInt &a,int b){
    a=a/b;
}
BigInt operator % (BigInt a,BigInt b){
    Set(a);Set(b);
    if(b==Integer(0))return Integer("-1");
    BigInt rs;
    FORD(i,a.size()-1,0){
        rs.insert(rs.begin(),a[i]);
        int x=0,L=0,R=base;
        while(L<=R){
            int mid=(L+R)>>1;
            if(b*Integer(mid)>rs){
                x=mid;
                R=mid-1;
            }
            else L=mid+1;
        }
        rs=rs-Integer(x-1)*b;
    }
    Set(rs);
    return rs;
}
int operator % (BigInt a,int b){
    Set(a);
    if(b==0)return -1;
    int rs=0;
    FORD(i,a.size()-1,0)
        rs=(rs*(base%b)+a[i]%b)%b;
    return rs;
}
void operator %= (BigInt &a,BigInt b){
    a=a%b;
}
void operator %= (BigInt &a,int b){
    a=a%Integer(b);
}
BigInt gcd(BigInt a,BigInt b){
    Set(a);Set(b);
    while(b>Integer(0)){
        BigInt r=a%b;
        a=b;b=r;
    }
    Set(a);
    return a;
}
BigInt lcm(BigInt a,BigInt b){
    return (a*b/gcd(a,b));
}
BigInt sqrt(BigInt a){
    BigInt x0=a,x1=(a+1)/2;
    while(x1<x0){
        x0=x1;
        x1=(x1+a/x1)/2;
    }
    return x0;
}
BigInt pow(BigInt a,BigInt b){
    if(b==Integer(0))return Integer(1);
    BigInt tmp=pow(a,b/2);
    if(b%2==0)return tmp*tmp;
    return tmp*tmp*a;
}
BigInt pow(BigInt a,int b){
    return pow(a,(Integer(b)));
}
int log(int n,BigInt a){
    Set(a);
    int rs=0;
    while(a>Integer(1)){
        rs++;a/=n;
    }
    return rs;
}
int main()
{
    BigInt B;cin>>B;
    BigInt A=Integer("123456789");
    BigInt C=Integer(123456789ll);
    int x;x=123456789;
    if(B<=A)cout<<A-B;
    else
    {
        cout<<"-";
        cout<<B-A;
    }
    cout<<A+B;Print(A+x);
    cout<<A*B;Print(A*x);
    cout<<A/B;Print(A/x);
    cout<<A%B;printf("%d\n",A%x);

    C=++A;++B;C+=B+x;
    Print(A);Print(B);Print(C);

    cout<<max(A,B);
    cout<<min(A,B);

    cout<<gcd(A,B);
    cout<<lcm(A,B);

    cout<<sqrt(A);
    printf("%d %d %d\n",log(2,A),log(10,B),log(5,C));

    A=Integer(16);x=12;
    cout<<pow(A,B);
    cout<<pow(A,x);

    return 0;
}

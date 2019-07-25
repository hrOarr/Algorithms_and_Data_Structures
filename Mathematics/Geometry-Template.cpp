#include "bits/stdc++.h"
using namespace std;

#define EPS 1e-9
#define PI  2*acos(-1)
typedef long long int ll;
const int N=1e6+6,inf=1e9+7;
struct _point
{
    double x,y;
    _point():x(0),y(0){}
    _point(const double x,const double y):x(x),y(y){}
    void _input(){
    cin>>x>>y;
    }
    //cross product of two points
    double _crossProduct(_point tmp){
    return x*tmp.y-y*tmp.x;
    }
    double _triangleArea(_point a,_point b){
    return abs((x*(a.y-b.y)+a.x*(b.y-y)+b.x*(y-a.y))/2.0);
    }
    _point& operator=(const _point tmp){
    x=tmp.x,y=tmp.y;return *this;
    }
    _point& operator+=(const _point tmp){
    x+=tmp.x,y+=tmp.y;return *this;
    }
    _point& operator-=(const _point tmp){
    x-=tmp.x,y-=tmp.y;return *this;
    }
    _point& operator*=(const _point tmp){
    x*=tmp.x,y*=tmp.y;return *this;
    }
    _point& operator/=(const _point tmp){
    x/=tmp.x,y/=tmp.y;return *this;
    }
};
struct _line
{
    _point p,q;
    _line(const _point p,const _point q):p(p),q(q){}
    bool _onSegment(_line a,_point mid){
    return (mid.x<=max(a.p.x,a.q.x)&&mid.x>=min(a.p.x,a.q.x)&&mid.y<=max(a.p.y,a.q.y)&&mid.y>=min(a.p.y,a.q.y));
    }
    int _turn(_line a,_point mid){
    double vl=(mid.y-a.p.y)*(a.q.x-mid.x)-(mid.x-a.p.x)*(a.q.y-mid.y);
    if(vl==0)return 0;//co-linear
    return (vl>0)?1:2;//clockwise and counter-clockwise
    }
    //segment intersection
    bool _segmentIntersect(_line tmp){
    int x1=_turn(*this,tmp.p);
    int x2=_turn(*this,tmp.q);
    int x3=_turn(tmp,p);
    int x4=_turn(tmp,q);
    if(x1!=x2&&x3!=x4)return true;
    if(x1==0&&_onSegment(*this,tmp.p))return true;//*this and tmp.p are co-linear
    if(x2==0&&_onSegment(*this,tmp.q))return true;//*this and tmp.q are co-linear
    if(x3==0&&_onSegment(tmp,p))return true;//tmp and p are co-linear
    if(x4==0&&_onSegment(tmp,q))return true;//tmp and q are co-linear
    return false;
    }
};
struct _makeline
{
    double a,b,c;
    _makeline(){}
    _makeline(const double a,const double b,const double c):a(a),b(b),c(c){}
    _makeline(_line tmp)
    {
        a=tmp.p.y-tmp.q.y,b=tmp.q.x-tmp.p.x;
        c=(tmp.p.x*tmp.q.y)-(tmp.q.x*tmp.p.y);
    }
};
//intersection using determinant of two lines ax+bx+c=0
double _determinant(_makeline A,_makeline B){
    return A.a*B.b-A.b*B.a;
}
//line intersection
int _lineIntersect(_makeline A,_makeline B,_point &ret){
    double det=_determinant(A,B);
    if(fabs(det-0)<EPS)
    {
        double p=(A.c-A.a)/A.b,q=(B.c-B.a)/B.b;
        if(p==q)return 2;//same line
        return 0;
    }
    ret={(A.b*B.c-A.c*B.b)/det,(A.c*B.a-A.a*B.c)/det};
    return 1;
}
//circle using three points
_point _circle(_point A,_point B,_point C){
    _point m1,m2,ret;
    m1={(A.x+B.x)/2.0,(A.y+B.y)/2.0};//midpoint of AB segment
    m2={(A.x+C.x)/2.0,(A.y+C.y)/2.0};//midpoint of AC segment
    _makeline aa,bb;
    //gradient,m=(y2-y1)/(x2-x1)
    aa={(A.x-B.x),(A.y-B.y),m1.x*(A.x-B.x)+m1.y*(A.y-B.y)};//derived from y-y1=m(x-x1)
    bb={(A.x-C.x),(A.y-C.y),m2.x*(A.x-C.x)+m2.y*(A.y-C.y)};//derived from y-y1=m(x-x1)
    double det=_determinant(aa,bb);
    ret={(aa.c*bb.b-bb.c*aa.b)/det,(aa.a*bb.c-aa.c*bb.a)/det};
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout<<fixed;
    cout<<setprecision(2);


    return 0;
}

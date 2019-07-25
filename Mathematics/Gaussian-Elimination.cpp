#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n,temp;
    double A[10][10],c,rs[10]={0};
    for(int i=0;i<n;i++)
    {
        cout<<"equation: "<<i+1<< "   ";
        for(int j=0;j<=n;j++)cin>>A[i][j];
    }
    for(int i=n-1;i>0;i--)        // partial pivoting
    {
        if(A[i-1][0]<A[i][0])
        {
            for(int j=0;j<=n;j++)
            {
                double c=A[i][j];
                A[i][j]=A[i-1][j];
                A[i-1][j]=c;
                // swap(A[i][j],A[i-1][j])
            }
        }
    }
    //*************** DISPLAY MATRIX*************//
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
            cout<<A[i][j]<<" ";
        cout<<"\n";
    }
    //********* changing to upper triangular matrix*************//
    //********* Forward elimination process**************//
    for(int k=0;k<n-1;k++)
    {
        for(int i=k;i<n-1;i++)
        {
            double c=(A[i+1][k]/A[k][k]) ;
            for(int j=0;j<=n;j++)
                A[i+1][j]-=c*A[k][j];
        }
    }

     // ************DISPLAYING UPPER TRIANGULAE MATRIX***************//

    cout<<"\n\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
            cout<<A[i][j]<<" ";
        cout<<"\n";
    }
    //***************** Backward Substitution method****************//

    for(int i=n-1;i>=0;i--)
    {
        double c=0;
        for(int j=i;j<=n-1;j++)
            c=c+A[i][j]*rs[j];
        rs[i]=(A[i][n]-c)/A[i][i];
    }

    //******** RESULT DISPLAY *********//
    for(int i=0;i<n;i++)cout<<rs[i]<<"\n";

    return 0;
}

/*
A game is played between two players and there are N piles 
of stones such that each pile has certain number of stones. 
On his/her turn, a player selects a pile and can take any 
non-zero number of stones upto 3 (1,2,3) 
The player who cannot move is considered to lose the game

A Dynamic Programming approach to calculate Grundy Number 
and Mex and find the Winner using Sprague - Grundy Theorem. */

#include<bits/stdc++.h> 
using namespace std; 
int _mex(unordered_set<int>st) 
{
	int mex=0; 
	while(st.find(mex)!=st.end()) 
		mex++; 
	return mex;
}  
int _calGrundy(int n) 
{ 
	Grundy[0]=0; 
	Grundy[1]=1; 
	Grundy[2]=2; 
	Grundy[3]=3; 
	if(Grundy[n]!=-1)return Grundy[n]; 

	unordered_set<int>st; 
	for(int i=1; i<=3; i++) 
			st.insert(_calGrundy(n-i)); 

	Grundy[n]=_mex(st);
	return (Grundy[n]); 
}  
void _winner(int turn,int n) 
{ 
	int xr=Grundy[pile[0]]; 
	for(int i=1; i<=n-1; i++) 
		xr^=Grundy[pile[i]]; 
	if(xr!=0) 
	{ 
		if(turn==1) printf("Player 1 will win\n"); 
		else printf("Player 2 will win\n"); 
	} 
	else
	{ 
		if(turn==1)printf("Player 2 will win\n"); 
		else printf("Player 1 will win\n"); 
	}
}
int main() 
{ 
	int pile[]={3, 4, 5}n=3;
	memset(Grundy,-1,sizeof Grundy); 
	for(int i=0; i<=n-1; i++)_calGrundy(pile[i]); 
	_winner(1,n); 

	return (0); 
} 

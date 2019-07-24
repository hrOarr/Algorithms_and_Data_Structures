int lowerbound(vector<int> &vec,int x)
{
	int lo=0,hi=vec.size();
	while(lo<hi)
        {
		int md=(lo+hi)/2;
		if(x<=vec[md])hi=md;
		else lo=md+1;
	}
	return lo;
}
int upperbound(vector<int> &vec,int x)
{
	int lo=0,hi=vec.size();
	while(lo<hi)
        {
		int md=(lo+hi)/2;
		if(x<vec[md])hi=md;
		else lo=md+1;
	}
	return lo;
}

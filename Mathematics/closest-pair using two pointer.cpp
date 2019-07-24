int _closestPair(vector<pair<int,int> >ptn)
{
	sort(ptn.begin(),ptn.end());
	set<pair<int,int> >st;
	int j=0,n=ptn.size();ll rs=1LL*inf*inf;
	for(int i=0;i<n;i++)
	{
		ll d=ceil(sqrt(rs));
		while(ptn[i].fs-ptn[j].fs>=rs)
			st.erase(mp(ptn[j].sc,ptn[j++].fs));
		auto lo=st.lower_bound(mp(ptn[i].sc-d,ptn[i].fs));
		auto hi=st.upper_bound(mp(ptn[i].sc+d,ptn[i].fs));
		while(lo!=hi)
		{
			int dx=ptn[i].fs-lo->sc;
			int dy=ptn[i].sc-lo->fs;
			rs=min(rs,1LL*dx*dx+1LL*dy*dy);
			lo++;
		}
		st.insert(mp(ptn[i].sc,ptn[i].fs));
	}
	return rs;
}

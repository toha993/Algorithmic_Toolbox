#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include <iomanip>

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void segments(vector<pair<int,int>>seg,int a[],int s,int p)
{
	vector<pair<int,int>>pt,sg;
	for (int i = 0; i < p; ++i)
	{
		pt.push_back({a[i],i});
	}
	for (int i = 0; i < s; ++i)
	{
		sg.push_back({seg[i].first,+1});
		sg.push_back({seg[i].second+1,-1});
	}
	sort(sg.begin(),sg.end(),greater<pair<int,int>>());
	sort(pt.begin(),pt.end());
	int cnt=0,ans[p];
	for (int i = 0; i < p; ++i)
	{
		int x=pt[i].first;
		while(!sg.empty() && sg.back().first<=x)
		{
			cnt +=sg.back().second;
			sg.pop_back();
		}
		ans[pt[i].second]=cnt;
	}
	for (int i = 0; i < p; ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;

}
int main()
{
	int n,t;
	cin >> n >> t;
	vector<pair<int,int>>v;
	for (int i = 0; i < n; ++i)
	{
		int a,b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	int points[t];
	for (int i = 0; i < t; ++i)
	{
		cin >> points[i];
	}
	segments(v,points,n,t);
}
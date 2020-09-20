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


int main()
{
	int t;
	cin >> t;
	vector<pair<int,int>>v;
	while(t--)
	{
		int a,b;
		cin >> a >> b;
		v.push_back({b,a}); 
	}
	sort(v.begin(),v.end());
	int point=v[0].first;
	vector<int>ans;
	ans.push_back(point);
	for (int i = 1; i < v.size(); ++i)
	{
		if(v[i].second>point || v[i].first< point)
		{
			ans.push_back(v[i].first);
			point=v[i].first;
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}
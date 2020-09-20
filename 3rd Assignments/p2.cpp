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
	int t,n;
	cin >> t >> n;
	vector<pair<double,pair<int,int>>>v;
	for (int i = 0; i < t; ++i)
	{
		double xd,p;
		cin >> xd >> p;
		v.push_back({xd/p,{xd,p}});
	}
	sort(v.rbegin(),v.rend());
	double ans=0;
	for (int i = 0; i < v.size() ; ++i)
	{
		if(v[i].second.second<=n)
			{
				ans +=v[i].second.first;
				n -=v[i].second.second;
			}
		else
		{
			ans +=((double)v[i].second.first/v[i].second.second)*n;
			break;
		}
		//cout << n << endl;
	}
	printf("%.4lf\n",ans );
}
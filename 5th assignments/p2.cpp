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
#define INT_MAX 1e9+7
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int dp[1000005];
int main()
{
	int n;
	cin >> n;
	vector<int>v(n+1,INT_MAX);
	v[0]=0;
	v[1]=1;
	list<int>path[n+1];
	path[0].push_back(0);
	path[1].push_back(1);
	for (int i = 2; i <= n; ++i)
	{
		if(i%3==0)
		{
			if(v[i/3] < v[i])
			{
				v[i]=v[i/3]+1;
				path[i]=path[i/3];
				path[i].push_back(i);
			}
		}
		if(i%2==0)
		{
			if(v[i/2]<v[i])
			{
				v[i]=v[i/2]+1;
				path[i]=path[i/2];
				path[i].push_back(i);
			}
		}
		if(v[i-1]<v[i])
		{
			v[i]=v[i-1]+1;
			path[i]=path[i-1];
			path[i].push_back(i);
		}
	}
	cout << v[n]-1 << endl;
	while(!path[n].empty())
	{
		cout << path[n].front() << " ";
		path[n].pop_front();
	}
 	cout << endl;
	
}
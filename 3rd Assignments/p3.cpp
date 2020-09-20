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
	int n,x,t;
	cin >> n >> x >> t;
	vector<int>v;
	int now=0,flag=0,ck=0;
	for (int i = 0; i < t; ++i)
	{
		int p;
		cin >> p;
		v.push_back(p);
	}
	while(now<n)
	{
		if(now+x>=n)
			break;
		int xd=lower_bound(v.begin(),v.end(),now+x+1)-v.begin();
		int ekhn=v[xd-1];
		if(ekhn==now)
		{
			flag=1;
			break;
		}
		now=ekhn;
		ck++;
		//cout << now << endl;
	}
	if(flag)
		cout << -1 <<  endl;
	else
		cout << ck << endl;
}
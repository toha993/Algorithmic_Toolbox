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
	long long ans=0;
	vector<long long>v,q;
	for (int i = 0; i < t; ++i)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < t; ++i)
	{
		int x;
		cin >> x;
		q.push_back(x);
	}
	sort(v.begin(),v.end());
	sort(q.begin(),q.end());
	for (int i = 0; i < t; ++i)
	{
		ans +=(v[i]*q[i]);
	}
	cout << ans << endl;

}
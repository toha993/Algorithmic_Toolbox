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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

template<typename T> using ordered_set =tree<T, null_type , less<T> ,rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
	ordered_set<pair<int,int>>op;
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	long long ans=0;
	for (int i = n-1; i>=0 ; --i)
	{
		ans += op.order_of_key({a[i],-1});
		op.insert({a[i],i});
	}
	cout << ans << endl;

}
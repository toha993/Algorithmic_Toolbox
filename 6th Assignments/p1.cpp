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
#define inf 1000000
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
	int w,n;
	cin >> w >> n;
	vector<int>v(n+5);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	vector<vector<int>>dp(n+1,vector<int>(w+1));

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= w; ++j)
		{
			if(i==0 || j==0)
				dp[i][j]=0;

			else if(j-v[i-1]>=0)
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i-1]]+v[i-1]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	cout << dp[n][w] << endl;
}
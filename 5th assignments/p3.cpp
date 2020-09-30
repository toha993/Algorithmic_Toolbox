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
	string a,b;
	cin >> a >> b;
	int sz=a.length(),sz2=b.length();
	int dp[sz2+5][sz+5]={0};
	dp[0][0]=0;
	for (int i = 1; i <= sz; ++i)
	{
		dp[0][i]=i;
	}
	for (int i = 1; i <= sz2; ++i)
	{
		dp[i][0]=i;
	}
	for (int i = 1; i <= sz2; ++i)
	{
		for (int j = 1; j <= sz; ++j)
		{
			if(b[i-1]==a[j-1])
			{
				dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]));
			}
			else
			{
				dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+1));
			}
		}
	}

	// for (int i = 0; i <=sz2; ++i)
	// {
	// 	for (int j = 0; j <= sz; ++j)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << dp[sz2][sz] << endl;

}
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
	int p,q;
	cin >> p ;
	int a[p];
	for (int i = 0; i < p; ++i)
	{
		cin >> a[i];
	}
	cin >> q;
	int b[q];
	for (int i = 0; i < q; ++i)
	{
		cin >> b[i];
	}

	//int sz=a.length(),sz2=b.length();
	int dp[p+5][q+5];
	// for (int i = 0; i <=p; ++i)
	// {
	// 	for (int j = 0; j <= q; ++j)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }



	for (int i = 0; i <= p; ++i)
	{
		for (int j = 0; j <=q; ++j)
		{
			if(i==0 || j==0)
				{
					dp[i][j]=0;
					continue;
				}
			if(a[i-1]==b[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	
	cout << dp[p][q] << endl;

}
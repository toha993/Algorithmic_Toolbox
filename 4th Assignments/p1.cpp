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
	int a[t];
	for (int i = 0; i < t; ++i)
	{
			/* code */
		cin >> a[i];
	}
	int p;
	cin >> p;
	while(p--)
	{
		int n;
		cin >> n;
		int low=0,high=t,flag=0;
		while(low<=high)
		{
			int mid=low+high;
			mid /=2;
			if(a[mid]==n)
			{
				cout << mid << " ";
				flag=1;
				break;
			}
			if(a[mid]<n)
				low=mid+1;
			else
				high=mid-1;
		}
		if(!flag)
		{
			cout << -1 << " ";
		}
	}
}
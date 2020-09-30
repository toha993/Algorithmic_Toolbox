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
int mew[5][1005];
int gg[]={1,3,4};
int inf=1000005;
int sum(int n,int i)
{
	if(n < 0)
		return inf;
	if(i==3)
	{
		if(n==0)
		{
			return 0;
		}
		else
			return inf;
	}
	if(mew[i][n]!=-1)
		return mew[i][n];
	int f=1+sum(n-gg[i],i);
	int f1=sum(n,i+1);

	mew[i][n]=min(f,f1);

	return mew[i][n];
}

int main()
{
	int n;
	cin >> n;
	memset(mew,-1,sizeof(mew));
	cout << sum(n,0) << endl;

}
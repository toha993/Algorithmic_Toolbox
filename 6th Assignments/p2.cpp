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
int sum=0;
int hbe(int a[],int n,int p,int q,int r)
{
	if(p==0 || q==0 || r==0)
		return 1;
	if(n<0)
		return 0;
	bool first=false;
	first=hbe(a,n-1,p-a[n],q,r);
	bool second=false;
	if(!first && q-a[n]>=0)
		second=hbe(a,n-1,p,q-a[n],r);
	bool third=false;
	if(!first && !second && r-a[n]>=0)
		third=hbe(a,n-1,p,q,r-a[n]);
	return first || second || third;
}
int partition(int a[],int n)
{
	if(n<3)
		return 0;
	return (hbe(a,n-1,sum/3,sum/3,sum/3));
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum +=a[i];
	}
	if(sum%3==0 && partition(a,n))
		cout << 1 << endl;
	else
		cout << 0 << endl;
}
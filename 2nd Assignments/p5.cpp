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
int a[1000000];
int pisamo(long long m)
{
	 a[0]=0;
	 a[1]=1;
	 int ans;
	 for (int i = 2; i <= m*m; ++i)
	 {
	 	a[i]=(a[i-1]%m+a[i-2]%m)%m;
	 	if(a[i]==1 && a[i-1]==0)
	 	{
	 		ans=i-1;
	 		break;
	 	}
	 }
	// cout << ans << endl;
	 return ans;
}
void result(long long p,long long q)
{
	int xd=pisamo(q);
	//cout << xd <<  endl;
	cout << a[p%xd] << endl;

}
int main()
{
	long long p,q;
	cin >> p >> q;
	result(p,q);

}
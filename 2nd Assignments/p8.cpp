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
long long mp[100];
long long pismo(long long p)
{
	mp[0]=0;
	mp[1]=1;
	int xd=p%60;
	if(xd==0)
		return 0;
	for (int i = 2; i <= xd; ++i)
	{
		mp[i]=(mp[i-1]+mp[i-2])%60;
	}
	return mp[xd];
}

int main()
{
	long long a,b;
	cin >> a;
	cout << (pismo(a)*(pismo(a+1)))%10 << endl;

}
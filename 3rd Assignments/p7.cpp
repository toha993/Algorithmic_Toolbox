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
bool comp(string a,string b)
{
	return a+b > b+a;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >>t;
	vector<string>v;
	for (int i = 0; i < t; ++i)
	{
		int p;
		cin >> p;
		v.push_back(to_string(p));
	}
	sort(v.begin(),v.end(),comp);
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i];
	}
	cout << endl;
	return 0;
}
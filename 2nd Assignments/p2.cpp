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

map<int,int>a;
main()
{
    int n;
    cin >> n;
    a[0]=0;
    a[1]=1;
    for (int i = 2; i <= n; ++i)
    {
        a[i]=((a[i-1]%10)+a[i-2]%10)%10;
    }
    cout << a[n] << endl;
}
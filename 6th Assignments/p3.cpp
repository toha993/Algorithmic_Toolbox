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
#include <climits>
#define int long long
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
bool isoperator(char p)
{
	return (p=='+' || p=='-' || p=='*');
}

int mxmm(string s)
{
	vector<int>num;
	vector<char>oprnd;
	string as="";
	for (int i = 0; i < s.size(); ++i)
	{
		if(isoperator(s[i]))
		{
			oprnd.push_back(s[i]);
			num.push_back(atoi(as.c_str()));
			as="";
		}
		else
			as +=s[i];
	}
	num.push_back(atoi(as.c_str()));
	int len=num.size();
	int maxval[len+1][len+1];
	int minval[len+1][len+1];

	for (int i=0; i <len ; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			minval[i][j]=10000000;
			maxval[i][j]=0;
			if(i==j)
				maxval[i][j]=minval[i][j]=num[i];
		}
	}
	for(int p=0;p<len-1;p++)
	{
		for (int i = 0; i <len-p-1 ; ++i)
		{
			int j=i+p+1;
			int minvl=INT_MAX,maxvl=INT_MIN;
			for (int k = i; k <j; ++k)
			{
				int a,b,c,d;
				if(oprnd[k]=='+')
				{
					a=minval[i][k]+minval[k+1][j];
					b=minval[i][k]+maxval[k+1][j];
					c=maxval[i][k]+minval[k+1][j];
					d=maxval[i][k]+maxval[k+1][j];
					
				}
				else if(oprnd[k]=='-')
				{
					a=minval[i][k]-minval[k+1][j];
					b=minval[i][k]-maxval[k+1][j];
					c=maxval[i][k]-minval[k+1][j];
					d=maxval[i][k]-maxval[k+1][j];
				}
				else if(oprnd[k]=='*')
				{
					a=minval[i][k]*minval[k+1][j];
					b=minval[i][k]*maxval[k+1][j];
					c=maxval[i][k]*minval[k+1][j];
					d=maxval[i][k]*maxval[k+1][j];
				}

				minvl=min(minvl,min(a,min(b,min(c,d))));
				maxvl=max(maxvl,max(a,max(b,max(c,d))));
			}
			minval[i][j]=minvl;
			maxval[i][j]=maxvl;
		}
	}
	return maxval[0][len-1];

}

main()
{
	string s;
	cin >> s;
	cout << mxmm(s) << endl;
}
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



int v[100005],g=0;
void partition2(int a[], int low, int mid1,int mid2,int high,int v[]) {
  int i=low,j=mid1,k=mid2,l=low;
  //cout << g++ << endl;
    //cout << i << " " << j << " " << k << " " <<  l << endl;
  // for (int q = 0; q < high; ++q)
  // {
  //   cout << v[q] << " ";
  // }
  // cout << endl;
  while((i<mid1)&&(j<mid2)&&(k<high))
  {
    if(a[i]<a[j])
    {
      if(a[i]<a[k])
      {
        v[l++]=a[i++];
      }
      else
      {
        v[l++]=a[k++];
      }
    }
    else
    {
       if(a[j]<a[k])
      {
        v[l++]=a[j++];
      }
      else
      {
        v[l++]=a[k++];
      }
    }
     // cout << i << " " << j << " " << k << " " <<  l << endl << endl;

  }
  //cout << i << " " << j << " " << k << " " <<  l << endl << endl;
  while(i<mid1 && j<mid2)
  {
    if(a[i]<a[j])
    {
      v[l++]=a[i++];
    }
    else
      v[l++]=a[j++];
  }
  while(i<mid1 && k<high)
  {
    if(a[i]<a[k])
    {
      v[l++]=a[i++];
    }
    else
      v[l++]=a[k++];
  }
   while(j<mid2 && k<high)
  {
    if(a[j]<a[k])
    {
      v[l++]=a[j++];
    }
    else
      v[l++]=a[k++];
  }
  while(i<mid1)
  {
    v[l++]=a[i++];
  }
  while(j<mid2)
  {
    v[l++]=a[j++];
  }
  while(k<high)
  {
    v[l++]=a[k++];
  }
}

void randomized_quick_sort(int v[], int l, int r,int a[]) {
  if (r-l<2) {
    return;
  }

  int mid1=l+(r-l)/3;
  int mid2=l+2*((r-l)/3)+1;
  //cout <<mid1 << " " << mid2 << endl;

  randomized_quick_sort(a, l, mid1,v);
  randomized_quick_sort(a, mid1 ,mid2,v);
  randomized_quick_sort(a,mid2,r,v);
 // cout << l << " " << mid1 << " " << mid2 << " " << r << endl;

  partition2(a,l,mid1,mid2,r,v);
}


void mergeSort(int gArray[], int n) 
{ 
  if (n == 0) 
    return;  
  int fArray[n]; 
  for (int i = 0; i < n; i++) 
    fArray[i] = gArray[i];  
  randomized_quick_sort(fArray, 0, n, gArray);  
  for (int i = 0; i < n; i++) 
    gArray[i] = fArray[i]; 
} 

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i <n; ++i) {
    cin >> a[i];
    //v[i]=a[i];
  }
  mergeSort(a, n);
  for (int i = 0; i <n; ++i) {
      cout << a[i] << ' ';
  }
}

#include <iostream>
#include <iostream>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <iostream> 
#include <queue> 
#include <bits/stdc++.h>
using namespace std; 
int slide(string s, int size,int no,int nz,vector<int> l,int so,int se,int n)
{
  set<pair<pair<int,int>,pair<int,int>>> sew;
  sew.insert(make_pair(make_pair(no,nz),make_pair(so,se)));
  for(int i=size;i<n;i++)
  {
    if(s[i-size]=='1')
    {
      l.erase(l.begin());
      int t=se;
      se=so;
      so=t;
      no-=1;
    }
    else
    {
      nz-=1;
      l[0]-=1;
      se-=1;
    }
    if(s[i]=='1')
    {
      no+=1;
      l.push_back(0);
    }
    else
    {
      nz+=1;
      l[l.size()-1]+=1;
      if(l.size()%2==1)
      {
        se+=1;
      }
      else
      {
        so+=1;
      }
    }
    sew.insert(make_pair(make_pair(no,nz),make_pair(so,se)));
  }
  return sew.size();
}
int substring(string s,int n,int len)
{
  vector<int> l;
  int rt=0,no=0,nz=0,so=0,se=0,cur=0;
  for(int i=0;i<n;i++)
  {
    if (s[i]=='0')
    {
      if (cur%2==0)
        se+=1;
      else
        so+=1;
      rt+=1;
      nz+=1;
    }
    else
    {
      l.push_back(rt);
      rt=0;
            cur+=1;
            no+=1;
        }
    }
    l.push_back(rt);
    return slide(s,n,no,nz,l,so,se,len);
}
void solve()
{
  string s;
  cin>>s;
  int ans=0;
  for(int i=0;i<s.size();i++)
  {
    ans+=substring(s,i+1,s.size());
  }
  cout<<ans<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    int c=0;
    cin>>t;
    while(t--)
    {
      solve();
      c+=1;
    }
    return 0; 
}
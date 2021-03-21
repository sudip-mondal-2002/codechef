#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void sol(){
    ll N,E,H,A,B,C;
    cin>>N>>E>>H>>A>>B>>C;
    vector<ll> ans ;
    vector <ll> temp;
    for (ll i=0;i<=N;i++){
        temp.push_back(i);
    }
    ll temp1=0,temp2=0;
    ll o,k;
    for(ll i=0;i<=N;i++){
        temp1=lower_bound(temp.begin(),temp.end(),(2*N-E-2*i))-(temp.begin());
        temp2=upper_bound(temp.begin(),temp.end(),(H-3*i))-temp.begin()-1;
        if (temp2<temp1 || temp1 == N+1){
            continue;
        }
        if ((temp2==N+1) && (temp2+3>N)){
            continue;
        }
        if (C>A){
            k=(temp1<(N-i)?temp1:(N-i));
        }
        else{
            k=(temp2<(N-i)?temp2:(N-i));
        }
        o=N-k-i;
        if ((k+2*i)>=2*N-E && (k+3*i)<=H){
            ans.push_back(A*o+B*i+C*k);
        }
        
    }
    if (ans.size()==0){
        cout<<"-1\n";
    }
    else{
        ll final_ans =ans[0];
        for (ll i=0; i<ans.size();i++){
            final_ans= min(final_ans,ans[i]);
        }
    cout<< final_ans <<"\n";
    }
}
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ll t;
    cin>>t;
    while(t--){
        sol();
    }
	return 0;
}

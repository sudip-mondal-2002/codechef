#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
bool isp(long n){
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }
 
    return true;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p[1000001];
    p[0] = 0;
    p[1] = 0;
    int count = 0;
    for(int i = 2; i < 1000001; i++){
        if(isp(i)){
            count++;
        }
 
        p[i] = count;
    }
 
    long t;
    cin >> t;
    while(t--){
        long n, k;
        cin >> n >> k;
        if(p[n] > k){
            cout << "Divyam\n";
        } else{
            cout << "Chef\n";
        }
    }
    return 0;
}

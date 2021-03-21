#include<iostream>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long maxm=-1000000000;
        long long minm=1000000000;
        for(int i=0;i<n;i++){
            long long temp;
            cin>>temp;
            if (temp>maxm){
                maxm=temp;
            }
            if (temp<minm){
                minm=temp;
            }
        }
        cout<<(2*(maxm-minm))<<endl;
    }
}

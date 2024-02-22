#include <bits/stdc++.h>
using namespace std;

int digit_sum(long long int n){
    int sum=0;
    while(n){
        sum+=(n%10);
        n/=10;
    }
    return sum;
}


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int t,i,n;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        int m=1,cnt=0;
        while(n>m){
            m+=digit_sum(m);
            cnt++;
        }
        if(m==n)cout<<cnt<<endl;
        else cout<<"-1"<<endl;
    }
}
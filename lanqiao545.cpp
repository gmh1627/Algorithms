#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,i,ans=0;
    cin>>n;
    vector<long long int> ws(n);
    for(i=0;i<n;i++)
        cin>>ws[i];
    sort(ws.begin(),ws.end());
    int sum=0;
    for(i=0;i<n-1;i++){
        ans+=(ws[i]+ws[i+1]);
        ws[i+1]+=ws[i];
    }
    cout<<ans;
}
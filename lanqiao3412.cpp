#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,i,ans;
    cin>>n;
    vector<long long int> ws(n);
    for(i=0;i<n;i++)
        cin>>ws[i];
    sort(ws.begin(),ws.end());
    ans=ws[1]-ws[0];
    for(i=2;i<n;i++)
        ans=min(ans,ws[i]-ws[i-1]);
    cout<<ans;
}
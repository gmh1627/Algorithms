#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,m,k,i,ans=0,p=0,q=0;
    cin>>n>>m>>k;
    vector<long long int> ws(n);
    for(i=0;i<n;i++)
        cin>>ws[i];
    while (p<n&&q<n){
        int num=0;
        for(i=p;i<=q;i++)
            if(ws[i]>=m)
                num++;
        if(num>=k){
            ans+=n-q;
            p++;
        }
        else
            q++;
    }
    cout<<ans;
}
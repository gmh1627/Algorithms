#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,i,j,ans=0,w;
    cin>>w>>n;
    vector<long long int> ws(n);
    for(i=0;i<n;i++)
        cin>>ws[i];
    sort(ws.begin(),ws.end());
    i=0,j=n-1;
    //下述算法较啰嗦
    /*while(ws[i]+ws[j]>w&&j>0)
        j--;
    ans+=(n-j-1);
    for(i=0;j>i;){
        if(ws[i]+ws[j]<=w){
            i++;
            j--;
            ans++;
        }
        else{
            j--;
            ans++;
        }
    }
    if(j==i)
        ans++;*/
     while (i <= j) {
        if (ws[i] + ws[j] <= w) {
            i++;
            j--;
        } 
        else
            j--;
        ans++;
    }
    cout<<ans;
}
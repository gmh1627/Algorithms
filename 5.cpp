#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int t,i,j,m,n,k;
    cin>>t;
    int a[100000];
    for(i=0;i<t;i++){
        cin>>n;
        long long int cnt=0,sum=0;
        for(j=0;j<n;j++){
            cin>>a[j];
            if(!a[j]){
                cnt++;
                a[j]++;                
            }
            sum+=a[j];
        }
        if(!sum)cout<<cnt+1;
        else cout<<cnt<<endl;
    }
}
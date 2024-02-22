#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int t,i,j,m,n,k;
    cin>>t;
    long int a[100000],b[100000];
    for(i=0;i<t;i++){
        int res=0x3f3f3f3f;
        cin>>n>>k;
        for(j=0;j<n;j++)
            cin>>a[j];       
        for(m=1;m<=60;m++){
            int cnt=0;
            for(j=0;j<n;j++)
                b[j]=a[j];
            for(j=0;j<n;j++){
                if(b[j]!=m){
                    for(int h=j;h<=j+k-1 && h<n;h++)b[h]=m;
                    j+=k-1;
                    cnt++;
                }
            }
            res=min(res,cnt);
        }
        cout<<res<<endl;
    } 
    return 0;
}
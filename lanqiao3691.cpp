#include <bits/stdc++.h>
using namespace std;
//判断一个数组的所有数字的二进制表示在特定一位上是否有1
const int N=1e5+9;
int a[N],prefix[35][N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int w=0;w<=30;w++)
        for(int i=1;i<=n;i++)
            prefix[w][i]=prefix[w][i-1]+(a[i]>>w&1);
    while(q--){
        int ans=0,l,r;
        cin>>l>>r;
        for(int w=0;w<=30;w++)
            ans+=(1<<w)*(prefix[w][r]-prefix[w][l-1]?1:0);
        cout<<ans<<endl;
    }
}
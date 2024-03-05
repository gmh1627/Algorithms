#include <bits/stdc++.h>
using namespace std;
//前缀数组求异或和
//因数个数为偶数的数非完全平方数
const int N=1e5+9;
int a[N],prexor[N],cnt[N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        prexor[i]=prexor[i-1]^a[i];
    cnt[0]=1;//prexor[0]=0,是完全平方数
    int ans=n*(n+1)/2;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=200;j++){
            int sq=j*j;
            ans-=cnt[prexor[i]^sq];//x^y=z->z^y=x,因为y^y=0,x^0=x
        }
        cnt[prexor[i]]++;
    }
    cout<<ans;
}
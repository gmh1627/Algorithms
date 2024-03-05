#include <bits/stdc++.h>
using namespace std;

#define mod 9982444353
long long a,b;
long long ksm(long long a,long long b){//快速幂算法,计算a的b次方模mod的结果
    long long res=1;
    while(b){
        if(b&1)
            res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>a>>b;
    cout<<ksm(a,b);
}
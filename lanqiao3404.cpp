#include <bits/stdc++.h>
using namespace std;
long long int m,n,k;

//check函数返回
long long int check(long long int mid){
    long long int res=0;
    for(int i=1;i<=n;i++)
        res+=min(m,mid/i);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    long long int l=1,r=1e14;
    while(l+1!=r){
        long long int mid=(l+r)>>1;
        if(check(mid)<k)
            l=mid;
        else
            r=mid;
    }
    cout<<l;
}
#include <bits/stdc++.h>
using namespace std;
const int n=5e4+9;
long long int i,L,M,N,nums[n];

//check函数返回在最短跳跃距离为mid的情况下最少要移走的石头数
long long int check(long long int mid){
    long long int res=0,lst=0;
    for(int i=1;i<=N;i++){
        if(nums[i]-nums[lst]<mid){
            res++;
            continue;
        }
        lst=i;
    }
    if(L-nums[lst]<mid)
        return M+1;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>L>>N>>M;
    for(i=1;i<=N;i++)
        cin>>nums[i];
    long long int l=0,r=1e9+5;
    while(l+1!=r){
        long long int mid=(l+r)/2;
        if(check(mid)<=M)
            l=mid;
        else
            r=mid;
    }
    cout<<l;
}
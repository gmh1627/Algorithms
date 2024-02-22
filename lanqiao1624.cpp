#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,i,sum=0,num;
    cin>>n;
    priority_queue<long long int> nums;
    for(i=0;i<n;i++){
      cin>>num;
      sum+=num;
      nums.push(num);
    }
    if(sum-nums.top()>=nums.top()-1)cout<<"Yes";
    else cout<<"No";
    return 0;
}
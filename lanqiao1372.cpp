#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,S,i,ans=0,p=0,q=0;
    cin>>n>>S;
    vector<long long int> ws(n);
    for(i=0;i<n;i++)
        cin>>ws[i];
    //下述做法每次求sum都要遍历数组，时间复杂度为O(n^2)
    /*while (p<n&&q<n){
        int sum=0;
        for(i=p;i<=q;i++)
            sum+=ws[i];
        if(sum>=S){
            if(ans)
                ans=min(ans,q-p+1);
            else 
                ans=q-p+1;
            if(q>p)
                p++;
            else if(p==q)
                return 0;
        }
        else 
            q++;   
    }   
    cout<<ans;*/
    //下述做法保存了sum,时间复杂度为O(n)
    long long int ans = LLONG_MAX, sum = 0;
    int p = 0, q = 0;
    while (p < n) {
        while (q < n && sum < S) {
            sum += ws[q++];
        }
        if (sum >= S) {
            ans = min(ans, (long long int)(q - p));
        }
        sum -= ws[p++];
    return 0;
}
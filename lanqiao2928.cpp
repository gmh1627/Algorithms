#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,i,j,x;
    cin>>n>>x;
    string str,ans;
    cin>>str;
    sort(str.begin(), str.end());
    bool all_equal = all_of(str.begin() + 1, str.end(), [&](char c) { return c == str[0]; });
    if(all_equal){
        int newsize=ceil((double)str.size()/x);
        ans=str;
        ans.resize(newsize);
    }
    else if(str[x-1]==str[0])
        ans=str.substr(x-1);
    else if(str[x-1]!=str[0])
        ans=str[x-1];
    cout<<ans;
}
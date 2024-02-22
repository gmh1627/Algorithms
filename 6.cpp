#include <bits/stdc++.h>
using namespace std;
map<char, int> mp{
        {'A', 0},
        {'C', 1},
        {'G', 2},
        {'T', 3}
};
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(mp[a[i]]+mp[b[i]]!=3){
            for(int j=i+1;j<n;j++){
                if(mp[a[i]]+mp[b[j]]==3&&mp[a[j]]+mp[b[i]]==3){
                    swap(b[i],b[j]);
                    break;
                }
            }
            cnt++;
        }
    }
    cout<<cnt;
}
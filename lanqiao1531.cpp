#include <bits/stdc++.h>
using namespace std;
map<string,vector<string>> mp;
vector<string> city;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        if(!mp.count(b))city.push_back(b);
        mp[b].push_back(a);
        
    }
    for(const auto num:city){
        cout<<num<<" "<<mp[num].size()<<endl;
        for(const auto i:mp[num])
            cout<<i<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long int S(long long int n){
    if(!n)return 1;
    else if(!(n%2))return S(n/2);
    else return S(n-1)+1;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n;
    cin>>n;
    cout<<S(n);
}
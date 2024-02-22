#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  stack<char> brackets;
  int n,i;
  cin>>n;
  vector<char> brac2(n);
  for(i=0;i<n;i++)
    cin>>brac2[i];
  for(i=0;i<n;i++){
    if(brac2[i]=='(')brackets.push(brac2[i]);
    else if(brackets.empty()|| brackets.top()!='(') {
        cout<<"No";
        return 0;
    }
    else
      brackets.pop();
  }
  if(brackets.empty())cout<<"Yes";
  else cout<<"No";
  return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    double  n,det=1;
    cin>>n;
    vector<vector<double>> a(n, vector<double>(n));
    
    for(double i=0;i<n;i++)
      for(double j=0;j<n;j++)
        cin>>a[i][j];
    for(double j=0;j<n-1;j++){
      if(!a[0][j]){
        double k;
        for(k=1;k<n;k++){
          if(a[k][j]){
            for(double h=0;h<n;h++)
              a[0][h]+=a[k][h];
            break;
          }
        }
        if(k==n){
            cout<<'0';
            return 0;
        }
      }
    for(double l=j+1;l<n;l++)
      for(double m=n-1;m>=1-1;m--)
        a[l][m]-=a[0][m]*a[l][j]/a[0][j];
    det*=((long long)a[j][j]%998244353);
  }
  det*=((long long)a[n-1][n-1]%998244353);
  cout<<(((long long)det%998244353+998244353)%998244353);  
  return 0;
}

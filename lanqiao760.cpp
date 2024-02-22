#include <iostream>
using namespace std;
int a[100];
int f(int n){
    int res=1;
    for(int i=1;i<=a[n-1]/2;i++){
        a[n]=i;
        res+=f(n+1);
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    a[1]=n;
    cout<<f(2);
    return 0;
}
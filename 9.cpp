#include <bits/stdc++.h>
using namespace std;
//下述做法溢出
/*
long long int npower(long long int k,int n){
    for(int i=1;i<n;i++)
        k*=k;
    return k;
}

int main(){
    long long int n,k,i,flag=0,j,cnt=0;
    cin>>n>>k;
    vector<long long int>nums(n);
    for(i=0;i<n;i++)
        cin>>nums[i];
    for(j=21;j>=0;j--){
        for(i=0;i<n;i++){
            if(npower(k,j)>nums[i])
                continue;
            else if(npower(k,j)==nums[i]){
                nums[i]=0;
                cnt++;
                if(cnt==n){
                    if(!flag)
                        cout<<"Alice";
                    else 
                        cout<<"Bob";
                    return 0;
                }
                flag=1-flag;    
            }
            else if(npower(k,j)<nums[i]){
                nums[i]-=npower(k,j);
                flag=1-flag;
            }
        }
    } 
}*/
int main(){
    long long int n,k,i,flag=0,j,cnt=0;
    cin>>n>>k;
    vector<long long int>nums(n);
    for(i=0;i<n;i++){
        cin>>nums[i];
        cnt+=nums[i]%2;
    }
    if(cnt%2)
        cout<<"Alice";
    else 
        cout<<"Bob";
}
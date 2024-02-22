#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,i,j,sum=0,nums[100][100],nums2[100][100],t,r,c,k,res=0;
    cin>>n>>m>>t;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            nums[i][j]=0;
    for(i=0;i<t;i++){
        cin>>r>>c;
        nums[r][c]=1;
    }
    cin>>k;
    while (k--) {
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                nums2[i][j] = nums[i][j];
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(nums2[i][j])
                    nums[i-1][j]=nums[i+1][j]=nums[i][j+1]=nums[i][j-1]=1;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(nums[i][j])
                res++;
    cout<<res;
}
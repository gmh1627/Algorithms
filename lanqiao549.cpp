#include <bits/stdc++.h>  
using namespace std;  

int main(){  
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);  
    int n, m, i, j, sum = 0;  
    cin >> n >> m;  
    vector<vector<int>> nums(n, vector<int>(m)); // 使用vector替代原生数组
    for(i = 0; i < n; i++)  
        for(j = 0; j < m; j++)  
            cin >> nums[i][j];  
    for(i = 0; i < n; i++){  
        for(j = 0; j < m; j++){  
            int num = 0;  
            if(nums[i][j]) cout << "9 ";  
            else{  
                for(int k = max(0, i - 1); k <= min(n - 1, i + 1); k++){  
                    for(int t = max(0, j - 1); t <= min(m - 1, j + 1); t++){  
                        if(nums[k][t]) num++;  
                    }  
                }  
                cout << num<<" ";  
            }  
             
        }  
        cout << endl; 
    }  
    return 0;
}
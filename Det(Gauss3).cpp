#include<bits/stdc++.h>  // 包含大部分标准库，用于简化编程  
  
#define INL inline    // 宏定义，将INL替换为inline，用于内联函数，提高效率  
#define ll long long  // 宏定义，将ll替换为long long，用于定义长整型变量  
  
using namespace std;   // 使用标准命名空间  
  
const int N=605;       // 常量N，定义矩阵的最大阶数为605  
  
int n,a[N][N],MOD;    // 定义变量：n为矩阵阶数，a为矩阵，MOD为模数  
  
// 读取一个整数  
INL int read()
{   
    int x=0,w=1;   
    char ch=getchar();   
    while((ch<'0'||ch>'9')&&ch!='-') 
        ch=getchar(); // 跳过非数字字符  
    if(ch=='-') 
        w=-1,ch=getchar(); // 处理负数情况  
    while(ch>='0'&&ch<='9') 
        x=(x<<1)+(x<<3)+ch-48,ch=getchar(); // 读取数字并计算  
    return x*w; // 返回结果  
}  
  
// 计算矩阵的行列式值  
INL int sol() 
{   
    int res=1,w=1;   
    for(int i=1;i<=n;i++)
    {  
        for(int j=i+1;j<=n;++j)
        {  
            while(a[i][i])
            { // 当主元不为0时  
                int div=a[j][i]/a[i][i]; // 计算倍数  
                for(int k=i;k<=n;++k) 
                //1ll 是一个字面量整数，用于表示一个 long long 类型的整数，其值为 1
                    a[j][k]=(a[j][k]-1ll*div*a[i][k]%MOD+MOD)%MOD; // 进行高斯消元  
                swap(a[i],a[j]); // 交换行
                w=-w; // 记录交换次数，用于最后计算行列式值的符号  
            }  
            swap(a[i],a[j]); // 交换行，确保主元不为0  
            w=-w; // 记录交换次数  
        }  
    }  
    for(int i=1;i<=n;i++) 
        res=1ll*a[i][i]*res%MOD; // 计算对角线元素乘积  
    res=1ll*w*res; // 根据交换次数确定行列式值的符号  
    return (res+MOD)%MOD; // 返回行列式值模MOD的结果  
}  
  
int main() 
{   
    n=read(); // 读取矩阵阶数  
    MOD=998244353; // 设置模数为998244353  
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) a[i][j]=read(); // 读取矩阵元素  
    int ans=sol(); // 计算行列式值  
    printf("%d\n",ans); // 输出结果  
    return 0; // 程序结束  
}
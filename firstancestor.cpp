//倍增思想找树节点最近的公共祖先
//先找到深度较大的点
//再将其跳到与另外一个点深度相同
//若重合则结束，否则两点一起接着跳
#include<bits/stdc++.h>
using namespace std;
#define maxn 110000
int n, q;

int head[maxn], cnt;
struct Edge{
    int nex, to;
}edge[maxn<<1];

void add(int from, int to){
    edge[++cnt].nex = head[from];
    head[from]=cnt;
    edge[cnt].to= to;
    return ;
}

int dep[maxn], fa[maxn][30];

void dfs(int x, int f){
    dep[x] = dep[f] + 1;
    fa[x][0] = f;
    for (int i = head[x]; i; i = edge[i].nex ){
        int v = edge[i].to;
        if (v == f)
            continue;
        dfs(v, x);
    }
    return ;
}

int lca(int x, int y){
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 20; i >= 0; i -- )
        if (dep[fa[x][i]] >= dep[y])
            x = fa[x][i];
    if (x == y)
        return x;
    for (int i = 20; i >= 0; i -- )
        if (fa[x][i] != fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    return fa[x][0]; 
}

int main(){
    cin>>n;
    for (int i = 1; i <= n - 1; i ++ ){
        int a, b;
        cin>>a>>b;
        add(a, b);add(b, a);
    }
    dfs(1, 0);
    for (int j = 1; j <= 20; ++ j )
        for (int i = 1; i <= n; i ++ )
             fa[i][j] = fa[fa[i][j - 1]][j - 1];
    int q;
    cin>>q;
    while (q -- ){
        int a, b;
        cin>>a>>b;
        cout<<lca(a, b)<<endl;
    }
    return 0;
}
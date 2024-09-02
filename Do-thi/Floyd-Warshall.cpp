/*
 De bai:
 Cho một đồ thị có hướng gồm N đỉnh, được ghi nhớ bởi ma trận trọng số
 Yêu cầu:
 Xác định giữa hai đỉnh bất kỳ x và y chiều dài của đường đi ngắn nhất từ đỉnh x tới đỉnh y và hiển thị ma trận đường đi với với chi phí thấp nhất
 F[i][j] do dai tu i toi j
*/
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int f[1000][1000],n,x;


int main(){
     cin>>n;
     for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
        cin>>x;
        if(x==0 && i!=j) f[i][j]=1e9;
        else f[i][j]=x;
     }
     for(int i=1;i<=n;i++)
      for(int b=1;b<=n;b++)
        for(int a=1;a<=n;a++)
            if(f[a][b]>f[a][i]+f[i][b])
            f[a][b]=f[a][i]+f[i][b];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<f[i][j]<<" ";
            cout<<'\n';
        }
     return 0;
}


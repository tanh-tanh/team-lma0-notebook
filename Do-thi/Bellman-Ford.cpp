/*
de bai:
Cho một đồ thị có hướng liên thông gồm N đỉnh và M cạnh 
có trọng số. Ta định nghĩa một con đường là một dãy các 
đỉnh với tính chất có cạnh nối giữa hai đỉnh đỉnh liên 
tiếp trong dãy đó. Chi phí của một con đường được cho bằng 
tổng chi phí của các cạnh tham gia vào việc hình thành nên 
con đường đó. Ta định nghĩa một chu trình là một con đường
với tính chất rằng phần tử đầu tiên bằng với phần tử cuối cùng
Yêu cầu:
Xác định xem nếu có chu trình với chi phí âm trong đồ thị 
đã cho. Nếu không có, hãy xác định xem chi phí thấp 
nhất của hành trình từ đỉnh số 1 tới các đỉnh số 2, 3,…,N-1, N
*/
#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,d[N];
bool kt;
struct dl   {int x,y,w;};
dl g[N],b;
void dfs(int a){ 
    for(int i=1;i<=n;i++) d[i]=1e9;
    d[a]=0;
    for(int i=1;i<n;i++)   {   
        kt=0;
        for(int j=1;j<=m;j++){ 
            int u=g[j].x,v=g[j].y,duv=g[j].w;
            if(d[v]>d[u]+duv) {   
                kt=1;
                d[v]=d[u]+duv;
            }
        }
        if(kt==0) return;
    }//lần duyệt thứ n đây
    for(int j=1;j<=m;j++){
            int u=g[j].x,v=g[j].y,duv=g[j].w;
            if(d[v]>d[u]+duv) return;
        }
    kt=0;
}

int main(){
     cin>>n>>m;
     for(int i=1;i<=m;i++){
        cin>>b.x>>b.y>>b.w;
        g[i]=b;
     }
     dfs(1);
     //tim kc cach dinh voi dinh 1
     if(kt==1) //ko co duong di
            cout<<"Ciclu negativ!";
    else
     for(int i=2;i<=n;i++)  cout<<d[i]<<" ";
      return 0;
}


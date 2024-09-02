//Cách 1.1: tìm đường đi dài nhất từ s tới các đỉnh khác
void dfstopo(int u)
{
    ed[u]=true;
    for(int v:f[u])
       if(!ed[v]) dfstopo(v);
    luu.push_back(u);
}
//luu lưu thứ tự duyệt dfs từ cuối->đầu
    d[s]=val[s];
    for(int i=luu.size()-1;i>=0;i--)
    {
        int u=luu[i];gt
        for(int v:f[u])
        d[v]=max(d[v],val[v]+d[u]);
    }
//Cách 1.2:dùng bfs
void bfs(int u)
{
    luu.push(u);
    d[u]=val[u];
    ed[u]=true;//đánh dấu đỉnh này đã trong hàng đợi chưa
    while(luu.size())
    {
        u=luu.front();luu.pop();
        ed[u]=false;
        for(int v:f[u])
        if(d[v]<d[u]+val[v])
        {
            d[v]=d[u]+val[v];
            if(ed[v]==true) continue;
            ed[v]=true;
            luu.push(v);
        }
    }
}
//Cách 2:
//tìm đường đi dài nhất từ các đỉnh khác tới s
void dfstopo(int u)
{
    if(d[u]!=-1) return;
    if(GAME[u]) d[u]=val[u]; else d[u]=-1e18;
    for(int v:f[u])
       {
           dfstopo(v);
           d[u]=max(d[u],d[v]+val[u]);
       }
}

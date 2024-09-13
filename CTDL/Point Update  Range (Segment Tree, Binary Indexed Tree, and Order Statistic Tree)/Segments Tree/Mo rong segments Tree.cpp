/*
Mo rong 1:
neu nhu chung ta can tim so lan xuat hien cua max hoac min 
thi ta co the ung dung pii de co the tra ve gia tri max/min hoac 
so lan xuat hien max bang ham combine nhu sau
*/
//day la ham max con min thi tuong tu
pair<int, int > combine(pair<int, int> a, pair<int, int > b){
	//biet .fi la gia tri . se la so luong
	if(a.fi> b.fi) return a;
	if(b.fi > a.fi ) return b;
	return make_pair(a.fi, a.fi+b.fi);
}
/*
Mo rong 2: tim chu so 0 thu k
cho array a1...an tim chu so 0 thu k (hoac update vtri)
ta thay the val[l] bang v[l] v[l] co 2 gia tri la 0 hoac 1
 = 0 neu vi tri l khac 0 va 1 thi nguoc lai
 ung dung prefix sum de tim doan l..r chua it nhat k-pref_sum[l-1] so 0
nen la hau nhu ko doi chi thay doi o ham get
*/
int get(int id, int l, int r, int k){
    if(k > tree[id]) return -1;
    if(l == r){
        return l;
    }
    int mid = (l+r)/2;
    if(tree[id*2] >= k){
        return get(id*2, l, mid, k);
    } else{
        return get(id*2+1, mid+1, r, k-tree[id*2]);
    }

}
/* range update
	update(1,l,r,1,n,val);
 */
void update(int id, int l, int r, int ll, int lr, int val){
    if(l > r) return;
    if(l==ll && r == lr ){
        tree[id]+= val;
    } else{
        int mid = (ll+lr)/2;
        update(2*id,l,min(r,mid),ll, mid,val);
        update(2*id+1,max(l,mid+1),r,mid+1,lr,val);
        tree[id] = tree[2*id]+tree[2*id+1];
    }
}
/* mo rong 3:
2d segment tree 
*/
//-- Build cay bang build_x(1,0,n-1);
void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m-1);
}
//lay du lieu xai sum_x(1,0,n-1,x1,x2,y1,y2);
int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) 
        return 0;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return sum_y(vx, vy*2, tly, tmy, ly, min(ry, tmy))
         + sum_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return sum_y(vx, 1, 0, m-1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry)
         + sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);
}
// update du lieu update_x(1,0,n-1,x,y,val);
void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = new_val;
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(vx*2, lx, mx, x, y, new_val);
        else
            update_x(vx*2+1, mx+1, rx, x, y, new_val);
    }
    update_y(vx, lx, rx, 1, 0, m-1, x, y, new_val);
}
/* vi du: xay dung 1 cay va tra cac truy van
	build: xay dung 1 segment tree 2d
	update: thay doi gia tri tai pos bang val
	get: tra ve gia tri doan l..r
	note: co the thay doi truy van 2 sang yc ma de bai can
*/

vector<int> v,tree(MXn,0);
/*build se dung cay chi can sd 1 lan duy nhat 
bang cach build(1,1,n)
*/
void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		tree[id] = v[l];
	} else {
		int mid = (l+r)/2;
		build(2*id,l,mid);
		build(2*id+1,mid+1,r);
		tree[id] = min(tree[2*id],tree[2*id+1]);
	}
}
/*update se thay doi gia tri tai pos sang val voi dang
update(1,vi tri pos, gia tri, 1,n);
*/
void update(int id, int pos,int val, int l, int r){
	if(l>r || pos<l || pos>r) return;
	if(l == r && r == pos){
		tree[id] = val;
	} else{
		int mid = (l+r)/2;
		update(2*id,pos,val,l,mid);
		update(2*id+1,pos,val,mid+1,r);
		tree[id] = min(tree[2*id],tree[2*id+1]);
	}
}
/*
get se tra vi ve gia tri can truy van trong doan l..r
bang cach get(1,l,r,1,n);
*/
int get(int id, int l, int r,int ll, int lr){
	if(l<=ll && r>= lr ){
		return tree[id];
	}
	if(l>lr || r<ll) return MXN;
	int mid = (ll+lr)/2;
	return min(
		get(2*id,l,min(r,mid),ll, mid),
		get(2*id+1,max(l,mid),r,mid+1,lr)
		);
}

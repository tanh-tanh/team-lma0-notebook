#include<bits/stdc++.h>

using namespace std;

int n,k;
int C1[100][100], C2[100];

int main(){
	//cach thong thuong
	cin >> n >> k;
	for(int i = 0; i <= n; i++){
		C1[i][i] = 1;
		C1[i][0] = 1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < i; j++) C1[i][j] = C1[i-1][j-1] + C1[i-1][j];
	}
	//cach rut gon
	C2[0] = 1;
	for(int i = 1; i<= n; i++){
		for(int j = k; j >= 1; j--) C2[j] += C2[j-1];
	}
	cout << C1[n][k] << " " << C2[k] << endl;
}
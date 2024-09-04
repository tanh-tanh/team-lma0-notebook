#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
const ll MOD = 1e9 + 7;
class Matrix {
public:
	ll A[3][3];
	Matrix() {  //ma tran co so
		A[1][1] = 1, A[1][2] = 0;
		A[2][1] = 0, A[2][2] = 1;
	}
	Matrix(ll n) {   //ma tran fibo
		A[1][1] = 1, A[1][2] = 1;     //F[n+1]  F[n]
		A[2][1] = 1, A[2][2] = 0;     //F[n]    F[n-1]
	}
	friend Matrix operator * (Matrix& a, Matrix& b) {
		Matrix res;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= 2; j++) {
				res.A[i][j] = 0;
				for (int k = 1; k <= 2; k++) {
					res.A[i][j] += a.A[i][k] * b.A[k][j];
					res.A[i][j] %= MOD;
				}
			}
		}
		return res;
	}
};


Matrix I;

Matrix exp(Matrix a, ll b) {
	if (b == 1) return a;
	Matrix x = exp(a, b / 2);
	Matrix k = x * x;
	if (b % 2 == 0) return k;
	else return k * a;
}

int main() {
	cin >> n;
	Matrix a(n);
	Matrix res = exp(a, n);
	cout << res.A[1][2] << endl;
}
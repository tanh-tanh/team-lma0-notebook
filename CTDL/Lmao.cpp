#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n), ans(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		deque<int> dq;
		for (int i = 0; i < k; i++) {
			if (!dq.empty() && a[dq.back()] <= a[i]) {
				dq.push_back(i);
			}
			else dq.push_front(i);
		}
		cout << a[dq.back()] << " ";
		for (int i = k; i < n; i++) {
			while (!dq.empty() && dq.back() <= (i - k)) dq.pop_back();
			if (!dq.empty() && a[dq.back()] <= a[i]) {
				dq.push_back(i);
			}
			else dq.push_front(i);
			cout << a[dq.back()] << " ";
		}
		cout << endl;
	}
}
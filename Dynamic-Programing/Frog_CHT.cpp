#include <iostream>
#include <deque>
#include <vector>
using namespace std;

#define ll long long

ll calculate_cost(int j, int i, vector<ll>& H, ll C) {
    return (H[i] - H[j]) * (H[i] - H[j]) + C;
}

ll slope(int j, int k, vector<ll>& dp, vector<ll>& H) {
    return (dp[j] - dp[k] + H[j] * H[j] - H[k] * H[k] - 1) / (H[j] - H[k]);
}

int main() {
    int N;
    ll C;
    cin >> N >> C;
    
    vector<ll> H(N + 1), dp(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
    
    deque<int> dq;
    dp[1] = 0;
    dq.push_back(1);
    
    for (int i = 2; i <= N; i++) {
        while (dq.size() > 1 && slope(dq[0], dq[1], dp, H) <= 2 * H[i]) {
            dq.pop_front();
        }
        
        int j = dq.front();
        dp[i] = dp[j] + calculate_cost(j, i, H, C);
        
        while (dq.size() > 1 && slope(dq[dq.size() - 2], dq.back(), dp, H) >= slope(dq.back(), i, dp, H)) {
            dq.pop_back();
        }
        
        dq.push_back(i);
    }
    
    cout << dp[N] << endl;
    
    return 0;
}

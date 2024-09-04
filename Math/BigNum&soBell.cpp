#include<bits/stdc++.h>

using namespace std;

//so sanh hai so nguyen lon
bool small(string &num1, string &num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 < n2) return true;
    if (n1 > n2) return false;
    for (int i = 0; i < n1; ++i) {
        if (num1[i] < num2[i]) return true;
        if (num1[i] > num2[i]) return false;
    }
    return false;
}
bool larger(string& num1, string& num2){
    return !(small(num1,num2));
}
bool equal(string& num1, string& num2){
    int n1 = num1.size();
    int n2 = num2.size();
    if(n1 != n2) return false;
    while(n1){
        if(num1[n1] != num2[n1]) return false;
        n1--;
    }
    return true;
}
//tinh tong so nguyen lon
string sum(string &num1, string &num2) {
    string result = "";
    int carry = 0;
    int n1 = num1.size();
    int n2 = num2.size();
    int maxLength = max(n1, n2);
    for (int i = 0; i < maxLength; ++i) {
        int digit1 = (i < n1) ? num1[n1 - 1 - i] - '0' : 0;
        int digit2 = (i < n2) ? num2[n2 - 1 - i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
    if (carry) {
        result.push_back(carry + '0');
    }
    reverse(result.begin(), result.end());
    return result;
}
//tinh hieu so nguyen lon
string diff(const string &num1, const string &num2) {
    string n1 = num1;
    string n2 = num2;
    bool negative = false;
    if (small(n1, n2)) {
        swap(n1, n2);
        negative = true;
    }
    string result = "";
    int borrow = 0;
    int n1Size = n1.size();
    int n2Size = n2.size();
    for (int i = 0; i < n1Size; ++i) {
        int digit1 = n1[n1Size - 1 - i] - '0';
        int digit2 = (i < n2Size) ? n2[n2Size - 1 - i] - '0' : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff + '0');
    }
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    if (negative) {
        result.push_back('-');
    }
    reverse(result.begin(), result.end());
    return result;
}
//nhan so nguyen lon
string multi(string &num1, string &num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    vector<int> result(n1 + n2, 0);
    for (int i = n1 - 1; i >= 0; --i) {
        for (int j = n2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    string product = "";
    for (int num : result) {
        if (!(product.empty() && num == 0)) {
            product.push_back(num + '0');
        }
    }
    return product.empty() ? "0" : product;
}
//chia so nguyen lon
string divide(string &num1, string &num2) {
    if (num2 == "0") {
        return "0";
    }
    string result = "";
    string current = "";
    int n1 = num1.size();
    for (int i = 0; i < n1; ++i) {
        current += num1[i];
        int quotient = 0;
        while (current.size() > 1 && current[0] == '0') {
            current.erase(0, 1);
        }
        while (current.size() > num2.size() || (current.size() == num2.size() && current >= num2)) {
            current = diff(current, num2);
            ++quotient;
        }
        result += (quotient + '0');
    }
    while (result.size() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }
    return result.empty() ? "0" : result;
}
//chia du so nguyen lon
string mod(string &num1, string &num2) {
    if (num2 == "0") {
        return "0";
    }
    string current = "";
    int n1 = num1.size();
    for (int i = 0; i < n1; ++i) {
        current += num1[i];
        while (current.size() > 1 && current[0] == '0') {
            current.erase(0, 1);
        }
        while (current.size() > num2.size() || (current.size() == num2.size() && current >= num2)) {
            current = diff(current, num2);
        }
    }
    return current.empty() ? "0" : current;
}

int main(){
	//tinh so Bell
    vector<vector<string>> C(51, vector<string>(51,"0"));    //C[n][k]
    for (int i = 0; i <= 50; i++) {
        C[i][0] = "1";
        C[i][i] = "1";
    }
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j < i; j++) {
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
        }
    }
    vector<string> Bell(51,"0");
    Bell[0] = "1";
    for (int i = 1; i <= 50; i++) {
        for (int j = 0; j < i; j++) {
            Bell[i] = add(Bell[i],multi(Bell[j], C[i - 1][j]));
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << Bell[n] << endl;
    }
    
}

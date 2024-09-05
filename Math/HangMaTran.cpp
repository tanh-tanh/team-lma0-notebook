#include <bits/stdc++.h>
using namespace std;

// Định nghĩa một ngưỡng để so sánh với 0
const double EPS = 1e-9;

// Hàm tính hạng của ma trận
int matrixRank(vector<vector<double>> mat, int rows, int cols) {
    int rank = 0;
    for (int col = 0; col < cols; ++col) {
        // Tìm hàng có phần tử lớn nhất trong cột hiện tại
        int sel = rank;
        for (int i = rank; i < rows; ++i) {
            if (abs(mat[i][col]) > abs(mat[sel][col])) {
                sel = i;
            }
        }

        // Nếu tất cả các phần tử trong cột đều bằng 0, chuyển sang cột tiếp theo
        if (abs(mat[sel][col]) < EPS)
            continue;

        // Hoán đổi hàng hiện tại với hàng chọn được
        swap(mat[sel], mat[rank]);

        // Chuẩn hóa hàng hiện tại
        double factor = mat[rank][col];
        for (int j = col; j < cols; ++j) {
            mat[rank][j] /= factor;
        }

        // Khử các phần tử ở các hàng dưới và trên hàng hiện tại
        for (int i = 0; i < rows; ++i) {
            if (i != rank && abs(mat[i][col]) > EPS) {
                double factor = mat[i][col];
                for (int j = col; j < cols; ++j) {
                    mat[i][j] -= factor * mat[rank][j];
                }
            }
        }

        // Tăng hạng
        rank++;
    }
    return rank;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);

    int rows, cols;
    cout << "N: ";
    cin >> rows;
    cout << "M: ";
    cin >> cols;

    // Khởi tạo ma trận
    vector<vector<double>> mat(rows, vector<double>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> mat[i][j];
        }
    }

    // Tính hạng ma trận
    int rank = matrixRank(mat, rows, cols);

    cout << "Rank " << rank << "\n";

    return 0;
}

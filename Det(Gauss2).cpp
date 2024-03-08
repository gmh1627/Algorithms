#include <iostream>
#include <vector>

// 获取绝对值
double abs(double a) {
    return a >= 0 ? a : -a;
}

// 高斯消元法求行列式
double determinant(std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    double det = 1.0;

    for (int i = 0; i < n; i++) {
        // 寻找绝对值最大的行，并与第i行交换
        int max_row = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(matrix[j][i]) > abs(matrix[max_row][i])) {
                max_row = j;
            }
        }
        if (max_row != i) {
            for (int k = 0; k < n; k++) {
                std::swap(matrix[i][k], matrix[max_row][k]);
            }
            det = -det;
        }

        // 如果对角元素为0，则行列式为0
        if (abs(matrix[i][i]) < 1e-9) {
            return 0.0;
        }

        det *= (static_cast<int>(matrix[i][i])%998244353);

        // 消元
        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    return static_cast<int>(det)%998244353;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    double det = determinant(matrix);
    std::cout<< det << std::endl;

    return 0;
}

#include <iostream>
#include <vector>

// 计算2x2矩阵的行列式
int determinant2x2(std::vector<std::vector<int>>& matrix) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

// 计算子矩阵
void subMatrix(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& subMat, int row, int col, int size) {
    int p = 0, q = 0;
    for (int i = 0; i < size; ++i) {
        if (i != row) {
            q = 0;
            for (int j = 0; j < size; ++j) {
                if (j != col) {
                    subMat[p][q] = matrix[i][j];
                    q++;
                }
            }
            p++;
        }
    }
}

// 递归计算行列式
int determinant(std::vector<std::vector<int>>& matrix, int size) {
    if (size == 2) {
        return determinant2x2(matrix);
    }

    int det = 0;
    std::vector<std::vector<int>> subMat(size-1, std::vector<int>(size-1, 0));

    int sign = 1;
    for (int i = 0; i < size; ++i) {
        subMatrix(matrix, subMat, 0, i, size);
        det += sign * matrix[0][i] * determinant(subMat, size-1);
        sign = -sign;
    }

    return det;
}

int main() {
    int n;
    std::cout << "Enter the size of the square matrix: ";
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    std::cout << "Enter the elements of the square matrix:" << std::endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int det = determinant(matrix, n);
    std::cout << "Determinant of the matrix is: " << det << std::endl;

    return 0;
}

#include <iostream>
#include <string>

const int base = 26; // 基数，一般选择为26，表示26个小写字母
const int mod = 1e9 + 7; // 取模的值，一般选择为一个大质数

// 计算字符串s的子数组[l, r]的hash值
int calculateHash(const std::string& s, int l, int r) {
    int hashValue = 0;
    int p = 1; // base^0 的值，初始为1

    for (int i = l; i <= r; ++i) {
        char c = s[i];
        hashValue = (hashValue + (c - 'a' + 1) * p) % mod; // 计算当前字符对应的值，并加到hashValue上
        p = (p * base) % mod; // 更新base的幂次值
    }

    return hashValue;
}

int main() {
    std::string str = "abcde";
    int l = 1, r = 3; // 子数组的开始和结束位置
    int hashValue = calculateHash(str, l, r); // 计算子数组的hash值

    std::cout << "Hash value of '" << str.substr(l, r - l + 1) << "': " << hashValue << std::endl;

    return 0;
}
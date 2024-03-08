#include<bits/stdc++.h>
using namespace std;

// 获取 pattern 字符串的最长公共前缀和后缀的长度数组
std::vector<int> getLPS(const std::string& pattern) {
    int len = 0; // 当前匹配的最长公共前缀和后缀的长度
    std::vector<int> lps(pattern.size(), 0); // 存储最长公共前缀和后缀的长度数组

    for (int i = 1; i < pattern.size(); ) {
        if (pattern[i] == pattern[len]) { // 如果当前字符匹配成功
            len++; // 匹配长度加一
            lps[i] = len; // 更新最长公共前缀和后缀的长度
            i++; // 继续匹配下一个字符
        } else {
            if (len != 0) {
                len = lps[len - 1]; // 回溯到前一个字符的最长公共前缀和后缀的长度
            } else {
                lps[i] = 0; // 没有匹配，长度为0
                i++; // 继续匹配下一个字符
            }
        }
    }

    return lps;
}

// 原始的 KMP 算法
void KMP(const std::string& text, const std::string& pattern) {
    std::vector<int> lps = getLPS(pattern); // 获取最长公共前缀和后缀的长度数组
    int i = 0, j = 0; // i 表示文本串的索引，j 表示模式串的索引

    while (i < text.size()) {
        if (pattern[j] == text[i]) { // 如果当前字符匹配成功
            i++; // 继续匹配下一个字符
            j++; // 模式串索引后移
        }

        if (j == pattern.size()) { // 如果模式串完全匹配
            std::cout << "Pattern found at index " << i - j << std::endl; // 输出匹配位置
            j = lps[j - 1]; // 回溯到最长公共前缀和后缀的长度
        } else if (i < text.size() && pattern[j] != text[i]) { // 如果当前字符不匹配
            if (j != 0) {
                j = lps[j - 1]; // 回溯到最长公共前缀和后缀的长度
            } else {
                i++; // 继续匹配下一个字符
            }
        }
    }
}

// 改进的 KMP 算法
void improvedKMP(const std::string& text, const std::string& pattern) {
    std::vector<int> lps = getLPS(pattern); // 获取最长公共前缀和后缀的长度数组
    int i = 0, j = 0; // i 表示文本串的索引，j 表示模式串的索引

    while (i < text.size()) {
        if (pattern[j] == text[i]) { // 如果当前字符匹配成功
            i++; // 继续匹配下一个字符
            j++; // 模式串索引后移
        }

        if (j == pattern.size()) { // 如果模式串完全匹配
            std::cout << "Pattern found at index " << i - j << std::endl; // 输出匹配位置
            j = lps[j - 1]; // 回溯到最长公共前缀和后缀的长度
        } else if (i < text.size() && pattern[j] != text[i]) { // 如果当前字符不匹配
            if (j != 0) {
                j = lps[j - 1]; // 回溯到最长公共前缀和后缀的长度
            } else {
                i++; // 继续匹配下一个字符
            }
        }
    }
}

int main(){
  ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";

    std::cout << "Original KMP Algorithm:" << std::endl;
    KMP(text, pattern);

    std::cout << "\nImproved KMP Algorithm:" << std::endl;
    improvedKMP(text, pattern);

    return 0;
}

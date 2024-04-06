#include <iostream>
#include <vector>
using namespace std;

//摩尔投票算法找出数组中出现次数超过一半的元素
//注意只有在数组中确有出现次数超过一半的元素时，该算法才能正常返回
//也可以再遍历一次来判断找到的元素是否真的出现次数超过一半
//时间复杂度O(n)

int findMajorityElement(vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (candidate == num) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int majorityElement = findMajorityElement(nums);
    
    cout << "Majority Element: " << majorityElement << endl;

    return 0;
}
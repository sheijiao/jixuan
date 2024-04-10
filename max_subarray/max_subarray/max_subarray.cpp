#include <iostream>
#include <vector>
#include <sstream>  // 用于处理逗号分隔的输入

int maxSubarraySum(const std::vector<int>& nums) {
    int n = nums.size();
    int current_sum = 0;
    int max_sum = 0;

    for (int i = 0; i < n; ++i) {
        current_sum = std::max(current_sum + nums[i], 0);
        max_sum = std::max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    std::vector<int> nums;  // 用户输入的整数序列
    std::cout << "请输入整数序列的元素（以逗号分隔，输入非数字结束）：";
    std::string input;
    std::getline(std::cin, input);  // 读取整行输入
    std::istringstream iss(input);
    int num;
    while (iss >> num) {
        nums.push_back(num);
    }

    int result = maxSubarraySum(nums);
    std::cout << "最大子段和为: " << result << std::endl;

    return 0;
}

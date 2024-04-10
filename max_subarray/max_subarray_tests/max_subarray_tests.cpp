#include "pch.h"  // 包含预编译头文件
#include "CppUnitTest.h"
#include "../max_subarray/coked.h"  // 包含您的头文件

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MaxSubarrayTests
{
    TEST_CLASS(MaxSubarrayTests)
    {
    public:
        TEST_METHOD(TestMaxSubarraySum_PositiveNumbers)
        {
            std::vector<int> nums = { 1, 2, 3, 4, 5 };
            int expected = 15;  // 预期的结果
            int actual = maxSubarraySum(nums);
            Assert::AreEqual(expected, actual);  // 验证结果是否为15
        }

        TEST_METHOD(TestMaxSubarraySum_NegativeNumbers)
        {
            std::vector<int> nums = { -2, -4, -6, -8 };
            int expected = 0;  // 预期的结果（因为都是负数）
            int actual = maxSubarraySum(nums);
            Assert::AreEqual(expected, actual);  // 验证结果是否为0
        }

        TEST_METHOD(TestMaxSubarraySum_MixedNumbers)
        {
            std::vector<int> nums = { -2, 11, -4, 13, -5, -2 };
            int expected = 20;  // 预期的结果
            int actual = maxSubarraySum(nums);
            Assert::AreEqual(expected, actual);  // 验证结果是否为20
        }

        // 更多测试用例...
    };
}
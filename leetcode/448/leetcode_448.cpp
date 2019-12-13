/*
leetcode 448 解题方法

给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

示例:

输入:
[4,3,2,7,8,2,3,1]

输出:
[5,6]

解题思路
    将数组元素对应为索引的位置加n
    遍历加n后的数组，若数组元素值小于等于n，则说明数组下标值不存在，即消失的数字

个人理解:
    第一次遍历数组，以数组元素值作为原 数组的下标，将对应下标的元素值加N(n 为数组长度，
    可以是任意数字，但必须必n大)
    这样 没有加N的元素 其 对应的下标就是没有出现过的元素，例如a[i] <= N 
    则i 就是没有出现过的元素，将其放入vector 返回 则得到答案

此题和找出重复字符的题目类似

*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> list = {};
        // if(nums.empty()) return nums;   //不需要，只会加大内存和时间消耗
        for(int i = 0; i < nums.size(); ++i)
        {
            // int index = (nums[i] - 1) % nums.size();
            // nums[index] += nums.size();

            num[(nums[i] - 1) % nums.size()] += nums.size();
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] <= nums.size())
            {
                list.push_back(i + 1);
            }
        }
        return list;
    }
};





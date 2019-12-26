/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:

输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
注意:

数组非空，且长度不会超过20。
初始的数组的和不会超过1000。
保证返回的最终结果能被32位整数存下。
*/
/*
leetcode494 解题方法
*/
/*
方法一:
    同样的采用递归的算法，基本属于暴利拆解运算
    从数组第一个元素开始，使用递归循环下一个几点，直到结束，每次计算下一个元素的值都使用 + 和 - 两种算法
    如果循环到末尾，和 刚好为给定值 则count++; 
    运算时间比较长，是一个比较笨的方法
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0, sum = 0;
        dfsSum(nums, 0, sum, S, count);
        return count;
    }

    void dfsSum(vector<int>& nums, int i, int sum, int S, int& count)
    {
        if (i == nums.size())
        {
            if (sum == S)
               {
                    ++count;
               }
            return;
        }
        dfsSum(nums, i + 1, sum+nums[i], S, count);
        dfsSum(nums, i + 1, sum-nums[i], S, count); 

    } 
};


/*
方法二 
    转化为01背包问题
    暂时看不懂背包问题
*/

/*// java版本
public class Solution {
    int count = 0;
    public int findTargetSumWays(int[] nums, int S) {
        calculate(nums, 0, 0, S);
        return count;
    }
    public void calculate(int[] nums, int i, int sum, int S) {
        if (i == nums.length) {
            if (sum == S)
                count++;
        } else {
            calculate(nums, i + 1, sum + nums[i], S);
            calculate(nums, i + 1, sum - nums[i], S);
        }
    }
};*/

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

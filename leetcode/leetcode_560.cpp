/*
leetcode560 解题方法
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
        遍历数组nums，计算从第0个元素到当前元素的和，用哈希表保存出现过的累积和sum的次数,sum是哈希表的key，value是值，代表出现过。如果sum - k == sum，表示在哈希表中出现过，则代表从当前下标 i 往前有连续的子数组的和为sum。时间复杂度为$O(n)$，空间复杂度为$O(1)$。
        */
        int sum = 0, res = 0;
	    std::unordered_map<int, int> cul;
        cul[0] = 1;
        for (auto &m : nums)
        {
            sum += m;
            res += cul[sum - k];
            // cout << "pre"<< cul[sum] << endl;
            ++cul[sum];
            // cout << "last"<< cul[sum] << endl;
        }
        return res;

        // int res = 0;
        // int size = nums.size();
        // for (int i = 0; i < size; ++i )
        // {
        //     int sum = 0;
        //     for (int j = i; j < size; ++j )
        //     {
        //         sum += nums[j];
        //         res +=( sum == k ? 1:0);
        //     }
        // }
        // return res;
    }
};
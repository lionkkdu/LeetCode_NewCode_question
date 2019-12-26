/*
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
 

示例 2:

输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.
*/

class Solution {
public:
 bool canPartition(vector<int>& nums) {
    	/*int n = nums.size();
    	int c = 0;
    	for(int num : nums)
    		c += num;
       	
       	// 如果c为奇数，不符合条件，返回false
       	if(c & 1)
       		return false;

       	// 
       	std::vector<vector<bool>> dp(nums.size(), std::vector<bool>(c = c>>1 + 1, false));
       	for(int i = 0; i < n; i++)
       		for (int j = 0; j < c; j++)
       		{
       			if (!i)
       			{
       				dp[i][j] = (nums[i] == j);
       			}
       			else
       			{
       				dp[i][j] = dp[i - 1][j]  // 不放第i个元素
       					// 放入第i个元素，分为能放入第i个元素 和 不够放入第i个元素
       					|| (j - nums[i] >= 0 ?dp[i - 1][j - nums[i]] : false ); 
       			}
       		}
       return dp[nums.size() - 1][c];//[0,nums.size()-1]区间和为c*/


 	// 优化过后使用一位数组解决背包问题
 	int n = nums.size();
 	int c = 0;
 	for (int num:nums)
 		c += num;

    // for (int i = 0; i < nums.size(); ++i) {
    //     c += nums[i];
    // }  //慢

    if (c == 0) return false;
 	if (c & 1) return false;
    //  之所以不用vector<bool> 类型，是因为vector<bool>的执行效率实在太低
 	vector<int> dp((c>>=1) + 1, 0);
 	for (int i = 0; i < n; i++)
     {
 		for(int j = c; j >= nums[i]; j--)
 		{
 			if (!i) dp[j] = (nums[i] == j);
 			else dp[j] = dp[j] || dp[j-nums[i]];
 		}
     }
    return (dp[c] == 1 ? true : false);
};



// /**
// 大佬给出的一维数组动态规划有点懵逼。
// 这里先给出二维数组的动态规划，然后给出转化为一维数组的方法。理解起来相信非常容易。
// 所以这里会给出三个版本的代码：
// 二维数组动态规划
// 一维数组动态规划“二维转为一维的中间过程”
// 一维数组动态规划“最终版”
// **/
// // d(i, s) : 是否存在：nums区间[0, i] 中取一些元素，使其和为s
// // d(i, s) = d(i-1, s){不取nums[i]} || d(i-1, s-nums[i]){取nums[i]}
// // max(i) = nums.size()-1
// // max(s) = sum(nums)/2
// 刚开始动态规划不太理解，后来发现：
// 我们求dp第i行的时候dp[i][?]，我们只需要知道dp的i-1行即可dp[i-1][?]。
// 也就是说，按照这个依赖关系，一直往下递推，只要得到第0行即可。
// /*而第0行非常容易求。dp[0][s] = true当且仅当nums[0]==s*/
// //图解：
// //     s0 s1 s2 ...              ...sum 
// // i-1 [  {s-nums[i]}  ...       s    ]
// //   i [               ...       s    ]
// //dp[i][s] = dp[i-1][s] || dp[i-1][s-nums[i]]
// //这里要保证下标i-1>=0，所以第0行可以单独计算。
// //计算方法：i==0时，s用j遍历[0, sum(nums)]区间
// //发现nums[0]==s[j]，则dp[0][j]=true;
// class Solution {
// public:
//   bool canPartition(vector<int>& nums) {
//     int sum = 0;
//     for(int e : nums) sum += e;
//     if(sum & 1) return false;//奇数显然不符合条件
//     vector<vector<bool>> d(nums.size(), vector<bool>((sum>>=1)+1, false));//sum/=2
//     for(int i = 0 ; i < nums.size() ; i++){
//       for(int s = 0 ; s <= sum ; s++){//s range [0, sum(nums)>>1]
//         if(!i) d[i][s] = (nums[i]==s);//i==0要单独求{ nums[0]一个元素和为s }
//         else d[i][s] = d[i-1][s] || (s-nums[i]>=0 ? d[i-1][s-nums[i]] : false);
//       }
//     }
//     return d[nums.size()-1][sum];//[0,nums.size()-1]区间和为sum
//   }
// };
// 优化版本：
// 上面看到，我们求解dp第i行dp[i][?]的时候，只需要知道第i-1行dp[i-1][?]的值即可。
// 也就是说，我们没必要开这么大的二维数组空间，直接开一个一维数组空间保存前一行的值就ok了。
// 下面给出二维转一维的中间过程的代码。在最后会给出清晰的最终代码
// class Solution {
// public:
//   bool canPartition(vector<int>& nums) {
//     int sum = 0;
//     for(int e : nums) sum += e;
//     if(sum & 1) return false;
//     vector<bool> d((sum>>=1)+1, false);//sum/=2
//     for(int i = 0 ; i < nums.size() ; i++){
//       for(int s = sum ; s >= 0 ; s--/*int s = 0 ; s <= sum ; s++*/){//从后往前，因为前面的元素我们已经求过了(i>0时确实已经求过了，i==0时我们求一遍即可，下面的代码也确实给出了i==0的情况)，可以直接用
//         if(!i) d/*[i]*/[s] = (nums[i]==s);//i==0要单独求{ nums[0]一个元素和为s }
//         else d/*[i]*/[s] = d/*[i-1]*/[s] || (s-nums[i]>=0 ? d/*[i-1]*/[s-nums[i]] : false);
//       }
//     }
//     return d/*[nums.size()-1]*/[sum];//[0,nums.size()-1]区间和为sum
//   }
// };
// /*最后，这里给出最简的一维数组动态规划代码*/
// class Solution {
// public:
//   bool canPartition(vector<int>& nums) {
//     int sum = 0;
//     for(int e : nums) sum += e;
//     if(sum & 1) return false;
//     vector<bool> d((sum>>=1)+1, false);//sum/=2
//     for(int i = 0 ; i < nums.size() ; i++){
//       for(int s = sum ; s >= nums[i] ; s--){//从后往前，因为前面的元素我们已经求过了(i>0时确实已经求过了，i==0时我们求一遍即可，下面的代码也确实给出了i==0的情况)，可以直接用
//         if(!i) d[s] = (nums[i]==s);//i==0要单独求{ nums[0]一个元素和为s }
//         else d[s] = d[s] || d[s-nums[i]];
//       }
//     }
//     return d[sum];
//   }
// };


// 题外话 0-1 背包问题  此题也属于0-1背包问题

using namespace std;

class bag01
{
public:
	bag01();
	~bag01();
	
	vector<int> weight(3,1);		//物品重量数组{1500, 3000, 2000}
	vector<int> value(3,2);			//物品价值数组{1, 4, 3}
	const int num = 3;				//背包物品数量 数目
	const int capacity = 4;			//背包容量

	// 构造网格3行4列
	int maxValue[num][capacity] = {};

	// 填充网格
	for(int i = 0; i < num; i++)
	{
		for(int j = 1; j <= capacity; j++)
		{
			if (i == 0)
			{
				maxValue[i][j - 1] = (weight[i] < j ? value[i] : 0);
			}
			else
			{
				int topValue = maxValue[i - 1][j - 1];			// 上一个网格的值
				int thisValue = (weight[i] <= j
					//当前商品的值 + 剩余空间的值
					?(j - weight[i] > 0 ? value[i] + maxValue[i -1][j - weight[i]] : value[i]))  
					:topValue);

				// 返回topValue和maxValue中较大的那个值
				maxValue[i][j -1] = max(topValue, thisValue);
			}
		}
	}
};
// maxValue就是最后得出的值大小的表





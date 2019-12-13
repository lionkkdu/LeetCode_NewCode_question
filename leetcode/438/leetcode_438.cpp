/*
    给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

    字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

    说明：

    字母异位词指字母相同，但排列不同的字符串。
    不考虑答案输出的顺序。
    示例 1:

    输入:
    s: "cbaebabacd" p: "abc"

    输出:
    [0, 6]

    解释:
    起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
    起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
     示例 2:

    输入:
    s: "abab" p: "ab"
 
    输出:
    [0, 1, 2]1

    解释:
    起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
    起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
    起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
*/
/*
leetcode 438 解题方法

这些都是类似题目

76. 最小覆盖子串

438. 找到字符串中所有字母异位词

3. 无重复字符的最长子串
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int left = 0, right = 0;
        unorder_map<char, int> windows;
        unorder_map<char, int> needs;
        int match = 0;
        for(char c : p)
            needs[c]++;

        while(right < s.size())
        {
            char c1 = s[right];
            if (needs[c1].count)
            {
                windows[c1]++;
                if (windows[c1] == needs[c1])
                {
                    match++;
                }
            }

            right++;

            while(match == needs.size())
            {
                // 如果windows的大小和给定结果的needs大小相同,
                // 且从其实位置到结束位置的大小 right - left 也和给定p.size 大小相同,
                // left就是符合题目要求的子串的起始索引,将left加入返回结果中
                if((right - left) == p.size())
                {   
                    // res.push_back(left);
                    res.insert(res.end() -1, left);
                }
                char c2 = s[left];
                if (needs[c2].count)
                {
                    windows[c2]--;
                    if (windows[c2] < needs[c2])
                    {
                        match--;
                    }
                }
                left ++;
            }
        }
        return res;
    }
};






/*
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
*/
/*
leetcode  76 解题方法
 438  3  解法与本体类似
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0; right = 0, min_len = 0, start = 0;
        vector<char> p;
        unordered_map<char, int> windows;
        unordered_map<char, int> needs;
        for (char c:t)
            needs[c]++;

        int match = 0;

        while( right < s.size )
        {
            char c1 = s[right];
            if (needs.count(c1))
            {
                windows[c1]++;
                if (windows[c1] == needs[c1])
                    match++;
            }
            right++;

            while(match == needs.size())
            {
                if (right - left < min_len)
                {
                    start = left;
                    min_len = right - left;    
                }
                char c2 = s[left];
                if (needs.count(c2))
                {
                    windows[c2]--;
                    if (windows[c2] < needs[c2])
                        match--;
                }

                left++;
            }
        }
        return min_len = 0?"":s.substr[start, min_len];
    }
};

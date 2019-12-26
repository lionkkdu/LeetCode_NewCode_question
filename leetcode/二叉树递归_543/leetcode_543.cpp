/*递归调用查询函数
任意一条路径可以被写成两个 箭头（不同方向），每个箭头代表一条从某些点向下遍历到孩子节点的路径。

假设我们知道对于每个节点最长箭头距离分别为 L, RL,R，那么最优路径经过 L + R + 1 个节点。

算法

按照常用方法计算一个节点的深度：max(depth of node.left, depth of node.right) + 1。在计算的同时，
经过这个节点的路径长度为 1 + (depth of node.left) + (depth of node.right) 。搜索每个节点并记录这些路径经过的点数最大值，期望长度是结果 - 1。

自己理解:每个节点到子节点的最大长度都是    子节点最大深度 + 1(父节点自己)
                                        子节点的最大深度 再用递归计算 
                                        结果和之前算出的最大深度作比较,取两者最大值
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxLength = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        dfs(root);
        return maxLength;
    };

    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        else
        {
            int left = dfs(root->left);
            int right = dfs(root->right);
            maxLength = std::max(left+right, maxLength);
            return std::max(left , right) + 1;
        }
  
    };
};
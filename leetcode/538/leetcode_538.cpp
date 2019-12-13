/*
leetcode538 解题方法
初始想法
此题目要求我们在一个二叉搜索树上修改渐进线性数目个节点，所以一个高效的解法应该遍历每个节点一次。解法的关键在于应该按照节点值降序遍历所有节点，同时记录我们已经遍历过的节点值的和，并把这个和加到当前节点的值中。这种遍历树的方法被称作 反序中序遍历 ，它确保我们按我们想要的顺序遍历每一个节点。这个算法的基本思想是遍历一个没有遍历过的节点之前，先将大于点值的点都遍历一遍。这些点都在哪里呢？就在右子树里面。

方法 1：回溯 [Accepted]
想法

一个反序中序遍历的方法是通过递归实现。通过调用栈回到之前的节点，我们可以轻松地反序遍历所有节点。

算法

在递归方法中，我们维护一些递归调用过程中可以访问和修改的全局变量。首先我们判断当前访问的节点是否存在，如果存在就递归右子树，递归回来的时候更新总和和当前点的值，然后递归左子树。如果我们分别正确地递归 root.right 和 root.left ，那么我们就能正确地用大于某个节点的值去更新此节点，然后才遍历比它小的值。

自己理解   由于二叉搜索树是有其规律性的，左子树节点都比根节点小，右子树节点都比根节点大
所以直接按照 右 中 左递归遍历，并在遍历过程中，将之前遍历计算的和重新赋值到当前节点，
返回二叉树，就是最后结果
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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root != nullptr)
        {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};


/*// 最优写法
class Solution 
{
public:
    int num=0;
    TreeNode* convertBST(TreeNode* root) 
    {
        if(!root)
            return nullptr;
        convertBST(root->right);
        root->val =root->val+num;
        num =root->val;
        convertBST(root->left);
        return root;
    }
};*/
/*
给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11

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


struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

/*
递归
	符合条件的第一个节点不一定是根节点，
	符合条件的最后一个节点也不一定就是叶子节点
	从第一个数值开始到最后一个数值，相加为 sum
	即用sum减去路径上节点的值，最后为0 时，为一个解

	用递归将二叉树上每一个节点作为初始节点开始计算一次，
	做一次递归，得出所有解
*/

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
        	return 0;

        return path(root, sum) 
        	+ pathSum(root->left, sum) 
        	+ pathSum(root-right, sum);
    }


    int path(TreeNode* root, int sum){
    	if (root == nullptr)
    		return 0;

    	int res = 0;
    	if(res == sum)
    		res += 1;
    	
    	res += path(root->left, sum - root->value);
    	res += path(root->right, sum - root->value);

    	return res;
    }
};



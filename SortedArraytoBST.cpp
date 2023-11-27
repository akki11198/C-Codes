/*Given an integer array nums where the elements are sorted in ascending order, convert it to a height balanced binary search tree.
#A heightbalanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
#Example 1 :
Input : nums = [ -10, -3, 0, 5, 9 ] 
Output : [ 0, -3, 9, -10, null, 5 ] 
Explanation : [ 0, -10, 5, null, -3, null, 9 ] is also accepted :

Example 2 :
Input : nums = [ 1, 3 ] 
Output : [ 3, 1 ] 
Explanation : [ 1, 3 ] and [ 3, 1 ] are both a height - balanced BSTs.*/

#include <iostream>
#include <vector>
using std::vector;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return nullptr;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        return root;
    }
};

void printTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
}

main()
{
    vector<int> nums;
    int i = 0, n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;
    std::cout << "Enter the elements of the array: ";
    while (i < n)
    {
        int x;
        std::cin >> x;
        nums.push_back(x);
        i++;
    }

    Solution s;
    TreeNode *root = s.sortedArrayToBST(nums);
    printTree(root);
}

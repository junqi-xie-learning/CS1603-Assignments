#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x = 0) 
        :val{ x }, left{ nullptr }, right{ nullptr } { }
};

int height(struct TreeNode *root)
{
    if (!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int path_length(struct TreeNode *root)
{
    if (!root)
        return 0;

    int longest = height(root->left) + height(root->right);
    int longest_left = path_length(root->left);
    int longest_right = path_length(root->right);
    return max(longest, max(longest_left, longest_right));
}

int main()
{
    int number_of_nodes = 0;
    cin >> number_of_nodes;
    TreeNode *node_queue = new TreeNode[number_of_nodes]{ };

    for (int i = 0; i < number_of_nodes; ++i)
    {
        int left = 0, right = 0;
        cin >> left >> right;
        
        node_queue[i].left = left > 0 ? &node_queue[left - 1] : nullptr;
        node_queue[i].right = right > 0 ? &node_queue[right - 1] : nullptr;
    }

    cout << path_length(&node_queue[0]);

    delete[] node_queue;
    return 0;
}
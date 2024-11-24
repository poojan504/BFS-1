/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // to iterate through each level we need the queue to store the nodes on each level
        queue<TreeNode*>tracker;
        vector<vector<int>>result;
        if(!root) return result;
        tracker.push(root);

        while(!tracker.empty())
        {
            int count = tracker.size();
            vector<int>curr;
            for(int i = 0; i <count; i++)
            {
                TreeNode* temp = tracker.front();
                tracker.pop();
                
                curr.push_back(temp->val);
                if(temp->left != NULL)
                    tracker.push(temp->left);
                if(temp->right != NULL)
                    tracker.push(temp->right);
            
            }
            
            result.push_back(curr);
            
        }

        return result;
    }
};
//Time complexity is O(N)
//space complexity is O(N)
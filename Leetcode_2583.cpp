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
    vector<long long> t(TreeNode* root)
    {
        vector<long long> v;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0)
        {
            int size = q.size();
            long long sum = 0;
            while(size > 0)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
                sum+=temp->val;
                size--;
            }

            v.push_back(sum);
        }
        return v;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {

        vector<long long> v = t(root);
        if(k>v.size())
        {
            return -1;
        }
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int i = 0;i<v.size();i++)
        {
            pq.push(v[i]);
            if(pq.size() > k)
            {
                pq.pop();   
            }
        }        
        return pq.top();
    }
};
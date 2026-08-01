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
    void reverse(vector<int>& v ){
        int start = 0 ;
        int end = v.size()-1;
        while(start<end){
            std:: swap(v[start], v[end]);
            start++;
            end-- ;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans ;
        queue<TreeNode*> q;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i =0 ; i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

            }
            ans.push_back(level);
        }
        for( int i = 1 ; i< ans.size(); i=  i+2){
            reverse(ans[i]);
        }
        return ans;
    
    }
};
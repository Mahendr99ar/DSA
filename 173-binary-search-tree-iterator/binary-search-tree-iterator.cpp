class BSTIterator {
public:
    stack<TreeNode*>st;
    void pushLeft(TreeNode* node) {
        while(node){
            st.push(node);
            node=node->left;
        }
    }
    BSTIterator(TreeNode* root){
     pushLeft(root);
    }
    int next() {
        TreeNode* curr=st.top();
        st.pop();
        if(curr->right)
            pushLeft(curr->right);
        return curr->val;
    }
    bool hasNext() {
        return !st.empty();
    }
};


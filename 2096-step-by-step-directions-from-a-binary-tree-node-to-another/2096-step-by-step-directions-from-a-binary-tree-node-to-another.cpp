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
    bool find(TreeNode* n, int val, vector<char>& path) {
        if (n->val == val){
            return true;
        }
        
        if (n->left && find(n->left, val, path)){
            path.push_back('L');
        }else if (n->right && find(n->right, val, path)){
            path.push_back('R');
        }
        
        if(!path.empty()){
            return true;
        }
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<char> root2start, root2dest;
        string upPath = "";
        string downPath = "";
        
        find(root, startValue, root2start);
        find(root, destValue, root2dest);
        
        while (!root2start.empty() && !root2dest.empty() && root2start.back() == root2dest.back()) {
            root2start.pop_back();
            root2dest.pop_back();
        }
        
        for(int i = 0; i < root2start.size(); ++i){
            upPath += 'U';
        }
        
        for(int i = 0; i < root2dest.size(); ++i){
            downPath += root2dest[root2dest.size() - i - 1];
        }
        
        return upPath + downPath;
    }
};
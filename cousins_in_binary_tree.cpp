/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
*/


int x = [](){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<tuple<int, int, TreeNode*>> q;    //parent, level, node
        int prevLevel = 0, level, p1 , p2;
        q.push(make_tuple(-1, 0, root));
        vector<pair<int, int>> levelNodes;//parent, val
               
        while(!q.empty()){
            TreeNode* n = get<2>(q.front());
            level = get<1>(q.front());
            int parentVal = get<0>(q.front());
            q.pop();
            vector<pair<int, int>> *a, *b;
            int check = -1;
            if(level != prevLevel){
                
                prevLevel = level;
                for(const auto itr : levelNodes){
                    if(itr.second == x){
                        p1 = itr.first;
                        check++;
                    }
                    if(itr.second == y){
                        check++;
                        p2 = itr.first; 
                    }
                    if(check == 1 && p1 != p2)
                        return true;
                }
                levelNodes = {make_pair(parentVal, n->val)};
            }
            else{
                levelNodes.push_back(make_pair(parentVal, n->val));
            }
            
            if(n->left != NULL)
                q.push(make_tuple(n->val, level + 1, n->left));
            if(n->right != NULL)
                q.push(make_tuple(n->val, level + 1, n->right));
        }
        int check = -1;
        for(const auto itr : levelNodes){
                    if(itr.second == x){
                        p1 = itr.first;
                        check++;
                    }
                    if(itr.second == y){
                        check++;
                        p2 = itr.first; 
                    }
                    if(check == 1 && p1 != p2)
                        return true;
                }
            return false;
    }
};

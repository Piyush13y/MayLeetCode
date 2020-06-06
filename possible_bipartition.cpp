/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 */
 int x = [](){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();
//Using undirected graph and BFS
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(N + 1);
        vector<int> color(N + 1, 0);
        
        for(auto itr : dislikes){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        
        for(int i = 1; i < N; i++){
            if(color[i] != 0){
                continue;
            }
                    queue<int> q;

            color[i] = 1;
            q.push(i);
            
            while(!q.empty()){
                
                int t = q.front();
                q.pop();
                
                for(auto itr : adj[t]){
                    if(color[t] == color[itr])
                        return false;
                    else if(color[itr] == 0){
                        color[itr] = -color[t];
                        q.push(itr);
                    }
                }
            }
        }
        return true;
    }
};
 

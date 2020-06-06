/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
*/

class Solution 
{
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(0);
    }
    bool detect_cycle(int course_no, vector<vector<int> > &dir_graph, vector<bool> &visited)
    {
        if(visited[course_no] == true)
            return true;
        visited[course_no] = true;
        bool ans = false;
        for(int depn_course: dir_graph[course_no])
        {
            ans |= detect_cycle(depn_course, dir_graph, visited);
            if(ans)
                break;
             visited[depn_course] = false;
        }
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int> > dir_graph(numCourses);
        vector<bool> visited(numCourses, false);
        for(vector<int> v : prerequisites)
        {
            dir_graph[v[1]].push_back(v[0]);//directed graph from v[1] to v[0].
        }
        int i;
        for(i = 0; i <= numCourses - 1; i ++)
        {
            if(detect_cycle(i, dir_graph, visited))
                return false;
            visited[i] = false;
        }
        return true;
    }
};

// Last updated: 6/17/2026, 12:07:39 AM
/*
 * kahn algorithm
 * 
 * Build the Graph: It loops through the prerequisites. For a pair [A, B], it adds B to A's adjacency list (adj[A].push_back(B)) and increments the indegree of B (indegree[B]++).
 * 
 * Initialize the Queue: It looks for all courses with an indegree of 0. These are courses that no other course depends on. It pushes them into the queue.
 * 
 * Process the Queue (BFS): * It pops a node from the queue and increments the finish counter.
 * 
 * It looks at all the neighbors (prerequisites) of the current node.
 * 
 * It "removes" the edge by decrementing the indegree of the neighbor.
 * 
 * If a neighbor's indegree drops to 0, it means all dependent courses have been processed, so it gets pushed into the queue.
 * 
 * Cycle Detection Check: If there is a cycle (e.g., A requires B, and B requires A), those nodes will never reach an indegree of 0, and they will never be added to the queue. Therefore, if the finish count equals numCourses, there were no cycles, and it's possible to finish all courses.
 * 
 * # lwk
 * indegree Array: Keeps track of how many incoming edges each node has. In the context of this specific code, an edge points from a course to its prerequisite. So, the indegree of a node represents how many courses depend on it.
 * 
 * adj (Adjacency List): Represents the graph. If you must take course B before course A (given as [A, B]), the code adds a directed edge A -> B.
 * 
 * q (Queue): Used to process nodes that have an indegree of 0.
*/

1class Solution {
2public:
3    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
4        vector<int> indegree(numCourses, 0);
5        vector<vector<int>> adj(numCourses);
6
7        for (auto& pre : prerequisites) {
8            indegree[pre[1]]++;
9            adj[pre[0]].push_back(pre[1]);
10        }
11
12        queue<int> q;
13        for (int i = 0; i < numCourses; i++)
14            if (indegree[i] == 0)
15                q.push(i);
16        
17        int finish = 0;
18        while (!q.empty()) {
19            int node = q.front();
20            q.pop();
21            finish++;
22            for (int nei : adj[node]) {
23                indegree[nei]--;
24                if (indegree[nei] == 0)
25                    q.push(nei);
26            }
27        }
28        return finish == numCourses;
29    }
30};
// Last updated: 6/14/2026, 2:34:43 PM
1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    vector<Node*> neighbors;
7    Node() {
8        val = 0;
9        neighbors = vector<Node*>();
10    }
11    Node(int _val) {
12        val = _val;
13        neighbors = vector<Node*>();
14    }
15    Node(int _val, vector<Node*> _neighbors) {
16        val = _val;
17        neighbors = _neighbors;
18    }
19};
20*/
21
22class Solution {
23public:
24    Node* cloneGraph(Node* node) {
25       map<Node*, Node*> oldToNew;
26       return dfs(node, oldToNew); 
27    }
28    Node* dfs(Node* node, map<Node*, Node*>& oldToNew) {
29        if (node == nullptr)
30            return nullptr;
31
32        if (oldToNew.count(node))
33            return oldToNew[node];
34        
35        Node* copy = new Node(node->val);
36        oldToNew[node] = copy;
37
38        for (Node* nei : node->neighbors)
39            copy->neighbors.push_back(dfs(nei, oldToNew));
40        
41        return copy;
42    }
43};
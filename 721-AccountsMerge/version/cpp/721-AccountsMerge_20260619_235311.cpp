// Last updated: 6/19/2026, 11:53:11 PM
// remind me to check this up again. holy shit i didn't understand even a singlee bit
1
2class Solution {
3    unordered_map<string, int> emailIdx; // email -> id
4    vector<string> emails;               // set of emails of all accounts
5    unordered_map<int, int> emailToAcc;  // email_index -> account_Id
6    vector<vector<int>> adj;
7    unordered_map<int, vector<string>>
8        emailGroup; // index of acc -> list of emails
9    vector<bool> visited;
10
11public:
12    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
13        int n = accounts.size();
14        int m = 0;
15
16        // Build email index and mappings
17        for (int accId = 0; accId < n; accId++) {
18            vector<string>& account = accounts[accId];
19            for (int i = 1; i < account.size(); i++) {
20                string& email = account[i];
21                if (emailIdx.find(email) == emailIdx.end()) {
22                    emails.push_back(email);
23                    emailIdx[email] = m;
24                    emailToAcc[m] = accId;
25                    m++;
26                }
27            }
28        }
29
30        // Build adjacency list
31        adj.resize(m);
32        for (auto& account : accounts) {
33            for (int i = 2; i < account.size(); i++) {
34                int id1 = emailIdx[account[i]];
35                int id2 = emailIdx[account[i - 1]];
36                adj[id1].push_back(id2);
37                adj[id2].push_back(id1);
38            }
39        }
40
41        visited.resize(m, false);
42        // DFS traversal
43        for (int i = 0; i < m; i++) {
44            if (!visited[i]) {
45                int accId = emailToAcc[i];
46                dfs(i, accId);
47            }
48        }
49
50        // Build result
51        vector<vector<string>> res;
52        for (auto& [accId, group] : emailGroup) {
53            sort(group.begin(), group.end());
54            vector<string> merged;
55            merged.push_back(accounts[accId][0]);
56            merged.insert(merged.end(), group.begin(), group.end());
57            res.push_back(merged);
58        }
59
60        return res;
61    }
62
63private:
64    void dfs(int node, int& accId) {
65        visited[node] = true;
66        emailGroup[accId].push_back(emails[node]);
67        for (int& neighbor : adj[node]) {
68            if (!visited[neighbor]) {
69                dfs(neighbor, accId);
70            }
71        }
72    }
73};
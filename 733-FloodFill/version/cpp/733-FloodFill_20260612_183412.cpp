// Last updated: 6/12/2026, 6:34:12 PM
// recursion and dfs
1class Solution {
2public:
3    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
4                                  int color) {
5        int orig = image[sr][sc];
6
7        int m = image.size();
8        int n = image[0].size();
9        if (orig == color)
10            return image;
11        dfs(image, sr, sc, orig, color);
12        return image;
13    }
14
15private:
16    int m, n;
17    void dfs(vector<vector<int>>& image, int r, int c, int orig, int color) {
18        int m = image.size();
19        int n = image[0].size();
20        if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != orig)
21            return;
22        image[r][c] = color;
23        dfs(image, r + 1, c, orig, color);
24        dfs(image, r - 1, c, orig, color);
25        dfs(image, r, c + 1, orig, color);
26        dfs(image, r, c - 1, orig, color);
27    }
28};
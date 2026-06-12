// Last updated: 6/12/2026, 5:55:44 PM
/*
 * creative af
 * gotta analyse later
*/

1class Solution {
2public:
3    int findJudge(int n, vector<vector<int>>& trust) {
4        //create a vector of n size to store the points of truster , and trusted..
5        //traverrse the trust vector=> 
6        //1. if a truster=> looses point 
7        //2. if a trusted=> gain point
8
9        vector<int> trustPoint(n+1, 0);
10
11        for(int i=0; i<trust.size(); i++){
12            trustPoint[trust[i][0]]--; //truster looses the point
13            trustPoint[trust[i][1]]++;// trusted gain the point
14        }
15
16        for(int i=1; i<=n; i++){
17            if(trustPoint[i] == n-1){ //judge must have a score of n-1
18                return i;
19            }
20        }
21
22        return -1;
23
24    }
25};
// Last updated: 5/20/2026, 4:48:48 PM
1class Solution {
2public:
3    string longestDiverseString(int a, int b, int c) {
4        string res = "";
5        int size = a + b + c;
6        int A = 0, B = 0, C = 0;
7        for (int i = 0; i < size; i++) {
8            if ((a >= b && a >= c && A != 2) || (B == 2 && a > 0) ||
9                (C == 2 && a > 0)) {
10                res += "a";
11                a--, A++, B = 0, C = 0;
12            } else if ((b >= a && b >= c && B != 2) || (A == 2 && b > 0) ||
13                       (C == 2 && b > 0)) {
14                res += "b";
15                b--, B++, A = 0, C = 0;
16            } else if ((c >= a && c >= b && C != 2) || (B == 2 && c > 0) ||
17                       (A == 2 && c > 0)) {
18                res += "c";
19                c--, C++, A = 0, B = 0;
20            }
21        }
22        return res;
23    }
24};
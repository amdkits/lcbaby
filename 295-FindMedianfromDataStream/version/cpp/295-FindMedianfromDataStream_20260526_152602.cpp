// Last updated: 5/26/2026, 3:26:02 PM
1class MedianFinder {
2private:
3    priority_queue<int> firstQ; // max_heap for the first half
4    priority_queue<int, std::vector<int>, std::greater<int>>
5        secQ; // min_heap for the second half
6public:
7    // Adds a number into the data structure.
8    void addNum(int num) {
9        if (firstQ.empty() || (firstQ.top() > num))
10            firstQ.push(num); // if it belongs to the smaller half
11        else
12            secQ.push(num);
13
14        // rebalance the two halfs to make sure the length difference is no
15        // larger than 1
16        if (firstQ.size() > (secQ.size() + 1)) {
17            secQ.push(firstQ.top());
18            firstQ.pop();
19        } else if (firstQ.size() + 1 < secQ.size()) {
20            firstQ.push(secQ.top());
21            secQ.pop();
22        }
23    }
24
25    // Returns the median of current data stream
26    double findMedian() {
27        if (firstQ.size() == secQ.size())
28            return firstQ.empty() ? 0 : ((firstQ.top() + secQ.top()) / 2.0);
29        else
30            return (firstQ.size() > secQ.size()) ? firstQ.top() : secQ.top();
31    }
32};
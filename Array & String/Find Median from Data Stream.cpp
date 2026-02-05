#include <sbits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        this->maxlen = 0;
        this->minlen = 0;
    }

    void addNum(int num) {
        if(maxlen == 0 || maxHeap.top() > num) {
            maxHeap.push(num);
            ++maxlen;
        } else {
            minHeap.push(num);
            ++minlen;
        }

        if(maxlen > minlen + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            ++minlen; --maxlen;
        } else if(minlen > maxlen + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            ++maxlen; --minlen;
        }
    }

    double findMedian() {
        if(maxlen == minlen) return (maxHeap.top() + minHeap.top()) / 2.0;
        else return (maxlen > minlen) ? maxHeap.top() : minHeap.top();
    }

private:
    priority_queue<int> maxHeap;  // left-handed side of the sorted array, greatest number at top()
    priority_queue<int, vector<int>, greater<int>> minHeap;  // right-handed side of the sorted array, smallest number at top()
    int maxlen, minlen;
};

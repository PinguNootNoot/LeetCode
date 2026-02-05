#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    MinStack() {
        /**
        *   Use self-defined equation to memorize every minimum values
        *   push_val = input_val(new_min) * 2 - previous_min
        *   previous_min = new_min * 2 - push_val
        *   input_val = (push_val(top) + previous_min) / 2
        */
    }

    void push(int val) {
        long long value = val;
        long long num;

        if(S.empty()) mini = value;
        if(value < mini) {
            num = value * 2 - mini;
            mini = value;
        } else num = value;
        S.push(num);
    }

    void pop() {
        if(S.top() < mini) mini = mini * 2 - S.top();
        S.pop();
    }

    int top() {
        if(S.top() >= mini) return int(S.top());
        else {
            long long temp = mini * 2 - S.top();
            return int((S.top()+temp) / 2);
        }
    }

    int getMin() {
        return int(mini);
    }

private:
    stack<long long> S;
    long long mini;
};

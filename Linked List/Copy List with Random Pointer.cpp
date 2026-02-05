#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        int length = 0;
        while(head) {
            Node* newNode = new Node(head->val);
            nodes.push_back(newNode);
            if(head->random) {
                Node* tmp = head->random;
                int cnt = 0;
                while(tmp) {
                    ++cnt;
                    tmp = tmp->next;
                }
                rand.push_back(cnt);
            }
            else rand.push_back(INT_MIN);
            ++length;
            head = head->next;
        }

        if(rand[0] != INT_MIN) nodes[0]->random = nodes[length-rand[0]];
        for(int i = 1; i < length; ++i) {
            nodes[i-1]->next = nodes[i];
            if(rand[i] != INT_MIN) nodes[i]->random = nodes[length-rand[i]];
        }
        return nodes[0];
    }

private:
    vector<Node*> nodes;
    vector<int> rand;
};

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto item = cache.find(key);
        if(item != cache.end()) {
            int id = 0;
            while(priority[id++] != key);
            priority.erase(priority.begin()+id-1);
            priority.insert(priority.begin(), key);
            return item->second;
        }
        return -1;
    }

    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            int id = 0;
            while(priority[id++] != key);

            cache.find(key)->second = value;
            priority.erase(priority.begin()+id-1);
            priority.insert(priority.begin(), key);
            return;
        } else if(length < cap) {
            cache.insert(pair<int,int>(key,value));
            ++length;
            priority.insert(priority.begin(),key);
        } else {
            cache.erase(priority[priority.size()-1]);
            cache.insert(pair<int,int>(key,value));
            priority.erase(priority.end()-1);
            priority.insert(priority.begin(), key);
        }
    }

private:
    int cap, length = 0;
    unordered_map<int,int> cache;
    vector<int> priority;
};

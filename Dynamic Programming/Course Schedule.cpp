#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 1) return true;

        vector<unordered_set<int>> graph(numCourses, unordered_set<int>(0));
        vector<bool> visited(numCourses, false);
        unordered_set<int> path;
        int n = prerequisites.size();

        for(int i = 0; i < n; ++i) {
            vector<int> pre = prerequisites[i];
            if(graph[pre[0]].find(pre[1]) != graph[pre[0]].end()) return false;
            graph[pre[1]].insert(pre[0]);
        }
        for(int i = 0; i < numCourses; ++i) {
            path.insert(i);
            if(isCyclic(graph, i, path, visited)) return false;
            path.clear();
        }
        return true;
    }

private:
    bool isCyclic(vector<unordered_set<int>>& graph, int vertex, unordered_set<int>& path, vector<bool>& visited) {
        if(visited[vertex]) return false;
        visited[vertex] = true;

        for(auto it = graph[vertex].begin(); it != graph[vertex].end(); ++it) {
            int neighbor = *it;
            if(path.find(neighbor) != path.end()) return true;
            if(visited[neighbor]) continue;
            path.insert(neighbor);
            if(isCyclic(graph, neighbor, path, visited)) return true;
            path.erase(neighbor);
        }
        return false;
    }
};

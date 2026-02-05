#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct TrieNode {
        char data;
        TrieNode* child[26] = {nullptr};
        bool isWord = false;
    };

public:
    Trie() {
        this->root = new TrieNode;
    }

    void insert(string word) {
        TrieNode* tmp = root;
        int s = word.size();

        for(int i = 0; i < s; ++i) {
            int idx = word[i] - 'a';
            if(!tmp->child[idx]) tmp->child[idx] = new TrieNode;
            tmp = tmp->child[idx];
        }
        tmp->isWord = true;
    }

    bool search(string word) {
        TrieNode* tmp = root;
        int s = word.size();

        for(int i = 0; i < s; ++i) {
            int idx = word[i] - 'a';
            if(!tmp->child[idx]) return false;
            tmp = tmp->child[idx];
        }
        if(tmp->isWord) return true;
        else return false;
    }

    bool startsWith(string prefix) {
        TrieNode* tmp = root;
        int s = prefix.size();

        for(int i = 0; i < s; ++i) {
            int idx = prefix[i] - 'a';
            if(!tmp->child[idx]) return false;
            tmp = tmp->child[idx];
        }
        return true;
    }

private:
    TrieNode* root = nullptr;
};

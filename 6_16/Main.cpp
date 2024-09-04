#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;


class Solution {
public:
    struct cmp {
        bool operator()(const pair<string, int>& left, const pair<string, int>& right) {
            if (left.second != right.second) return left.second > right.second;
            else return left.first < right.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> wordsCount;
        for (auto& word : words) {
            wordsCount[word]++;
        }

        vector<pair<string, int>> vp;
        for (auto& pair : wordsCount) {
            vp.push_back({ pair.first, pair.second });
        }

        sort(vp.begin(), vp.end(), cmp());

        vector<string> ret(k);
        for (int i = 0; i < k; i++) {
            ret.push_back(vp[i].first);
        }

        return ret;
    }
};

void test_1() {
    Solution s1;
    vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
    s1.topKFrequent(words, 2);
}

//int main() {
//    test_1();
//}

struct cmp {
    bool operator()(const pair<string, int>& left, const pair<string, int>& right) {
        if (left.second != right.second) return left.second > right.second;
        else return left.first < right.first;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        if (head == nullptr) return nullptr;
//
//        Node* copyhead = nullptr, * copytail = nullptr;
//        map<Node*, Node*> nodeMap;
//        nodeMap[nullptr] = nullptr;
//
//        Node* cur = head;
//        while (cur) {
//            if (copyhead == nullptr) {
//                copyhead = copytail = new Node(cur->val);
//            }
//            else {
//                copytail->next = new Node(cur->val);
//                copytail = copytail->next;
//            }
//
//            nodeMap[cur] = copytail;
//            cur = cur->next;
//        }
//
//        cur = head;
//        copytail = copyhead;
//        while (cur) {
//            copytail->random = nodeMap[cur->random];
//            cur = cur->next;
//            copytail = copytail->next;
//        }
//
//        return copyhead;
//    }
//};

int main() {
    string sentence;
    getline(cin, sentence);

    map<string, int> words;
    size_t start = 0;
    size_t end = 0;
    while ((end = sentence.find(' ', end)) != string::npos) {
        string word = sentence.substr(start, end - start);
        words[word]++;

        start = end + 1;
        end += 1;
    }

    end = sentence.find('.', start);
    string word = sentence.substr(start, end - start);
    words[word]++;

    vector<pair<string, int>> result;
    for (auto& word : words) {
        result.push_back({ word.first, word.second });
    }

    sort(result.begin(), result.end(), cmp());
    for (auto& word : result) {
        cout << word.first << ":" << word.second << endl;
    }
}
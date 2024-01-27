#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    struct TrieNode* children[26] = {nullptr};
    bool flag = false;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
        for (int i = 0; i < 26; i++) {
            root->children[i] = nullptr;
        }
    }
    void insert(string word) {
        TrieNode* currentNode = root;
        for (char c: word) {
            if (currentNode->children[c-'a'] == nullptr) {
                TrieNode* newNode = new TrieNode();
                currentNode->children[c-'a'] = newNode;
            }
            currentNode = currentNode->children[c-'a'];
        }
        currentNode->flag = true;
    }
    bool search(string word) {
        TrieNode* currentNode = root;
        for (char c: word) {
            if (currentNode->children[c-'a'] != nullptr) {
                currentNode = currentNode->children[c-'a'];
            }
            else {
                return false;
            }
        }
        return (currentNode->flag);
    }
    bool startsWith(string prefix) {
        TrieNode* currentNode = root;
        for (char c: prefix) {
            if (currentNode->children[c-'a'] != nullptr) {
                currentNode = currentNode->children[c-'a'];
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main(void) {
    int numCommands;
    cin >> numCommands;
    vector<string> commands(numCommands);
    for (int i = 0; i < numCommands; i++) {
        cin >> commands[i];
    }
    Trie* obj;
    for (int i = 0; i < numCommands; i++) {
        if (commands[i].compare("Trie") == 0) {
            obj = new Trie();
        }
        else if (commands[i].compare("insert") == 0) {
            string s;
            cin >> s;
            obj->insert(s);
        }
        else if (commands[i].compare("search") == 0) {
            string s;
            cin >> s;
            cout << ((obj->search(s))? "true": "false") << endl;
        }
        else if (commands[i].compare("startsWith") == 0) {
            string s;
            cin >> s;
            cout << ((obj->startsWith(s))? "true": "false") << endl;
        }
        else {
            cout << "Invalid Commands!" << endl;
        }
    }
    return 0;
}
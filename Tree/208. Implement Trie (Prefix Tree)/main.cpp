#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Trie {
public:
    Trie() {
    }
    void insert(string word) {
    }
    bool search(string word) {
    }
    bool startsWith(string prefix) {
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
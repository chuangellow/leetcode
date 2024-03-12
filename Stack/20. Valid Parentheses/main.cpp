#include <iostream>
#include <string>

using namespace std;

struct MyListNode {
    char c;
    std::shared_ptr<MyListNode> next;
    MyListNode(char c): c(c), next(nullptr) {}
};

class MyStack {
private:
    std::shared_ptr<MyListNode> head;
    int len;
public:
    MyStack(): len(0) {
        head = std::make_shared<MyListNode>(-1);
    }
    bool empty() {
        return (len <= 0);
    }
    void push(char c) {
        std::shared_ptr<MyListNode> newNode = std::make_shared<MyListNode>(c);
        newNode->next = head;
        head = newNode;
        len++;
    }
    char top() {
        return head->c;
    }
    char pop() {
        if (empty()) return -1;
        char c = head->c;
        head = head->next;
        len--;
        return c;
    }
};

class Solution {
public:
    int checkBrackets(char c, char brackets[6]) {
        for (int i = 0; i < 6; i++) {
            if (brackets[i] == c) return i;
        }
        return -1;
    }
    bool isValid(string s) {
        char brackets[6] = {'(', '{', '[', ')', '}', ']'};
        std::shared_ptr<MyStack> stack = std::make_shared<MyStack>();
        int len = s.length();
        for (int i = 0; i < len; i++) {
            int ret = checkBrackets(s.at(i), brackets);
            if (ret == -1) continue;
            if (ret < 3) {
                stack->push(s.at(i));
            }
            else {
                char c = stack->pop();
                if (c != brackets[ret-3]) return false;
            }
        }
        return (stack->empty());
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.isValid(s) << endl;
}
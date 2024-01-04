#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
    }
};

int main(void) {
    int numChar;
    cin >> numChar;
    char target;
    cin >> target;
    vector<char> letters(numChar);
    for (int i = 0; i < numChar; i++) {
        cin >> letters.at(i);
    }
    Solution sol;
    cout << sol.nextGreatestLetter(letters, target);
    return 0;
}
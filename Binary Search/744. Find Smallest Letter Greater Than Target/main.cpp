#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        if (letters.at(0) > target || target > letters.at(n-1)) return letters.at(0);
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (unsigned int) (left + right) >> 1;
            if (target >= letters.at(mid)) left = mid + 1;
            else right = mid;
        }
        int letter = letters.at(left);
        return (letter > target)? letter: letters.at(0);
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
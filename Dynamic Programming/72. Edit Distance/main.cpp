#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1Len = word1.length();
        int word2Len = word2.length();
        if (word1Len == 0) return word2Len;
        vector<int> prevRow(word2Len+1, 0);
        vector<int> currentRow(word2Len+1, 0);

        for (int i = 0; i <= word2Len; i++) prevRow[i] = i;

        for (int i = 1; i <= word1Len; i++) {
            currentRow[0] = i;
            for (int j = 1; j <= word2Len; j++) {
                if (word1[i-1] == word2[j-1]) {
                    currentRow[j] = prevRow[j-1];
                } else {
                    currentRow[j] = min({prevRow[j-1], prevRow[j], currentRow[j-1]}) + 1;
                }
            }
            for (int j = 0; j <= word2Len; j++) {
                prevRow[j] = currentRow[j];
            }
        }
        return currentRow[word2Len]; 
    }
};

int main(void) {
    string word1, word2;
    cin >> word1 >> word2;
    Solution sol;
    cout << sol.minDistance(word1, word2) << endl;
    return 0;
}
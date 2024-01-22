#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countDiff(string word1, string word2, int len) {
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (word1[i] != word2[i]) count++;
        }
        return count;
    }
    void getDistance(string word1, int distance, int* minDistance, string word2) {
        if (word1.compare(word2) == 0) {
            *minDistance = min(*minDistance, distance);
            return;
        }
        int len1 = word1.length();
        int len2 = word2.length();
        if (len1 == len2) {
            getDistance(word2, distance+countDiff(word1, word2, len1), minDistance, word2);
            return;
        }
        else if (len1 < len2) {
            for (int pos = 0; pos <= len1; pos++) {
                for (auto c: word2) {
                    string newWord = word1;
                    newWord.insert(pos, 1, c);
                    getDistance(newWord, distance+1, minDistance, word2);
                }
            }
            return;
        }
        else {
            for (int pos = 0; pos < len1; pos++) {
                string newWord = word1;
                newWord.erase(pos, 1);
                getDistance(newWord, distance+1, minDistance, word2);
            }
            return;
        }
    }
    int minDistance(string word1, string word2) {
        int dist = INT32_MAX;
        getDistance(word1, 0, &dist, word2);
        return dist;
    }
};

int main(void) {
    string word1, word2;
    cin >> word1 >> word2;
    Solution sol;
    cout << sol.minDistance(word1, word2) << endl;
    return 0;
}
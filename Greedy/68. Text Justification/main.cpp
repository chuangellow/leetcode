#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int numWords = words.size();
        vector<string> lines;
        int currentIdx = 0;
        while (currentIdx < numWords) {
            int slotCount = 1, currentSize = words[currentIdx].size();
            string line;
            int includeIdx = currentIdx + 1;
            while (includeIdx < numWords && (maxWidth - (currentSize + (int) words[includeIdx].size())) >= (slotCount)) {
                currentSize += words[includeIdx].size();
                slotCount++;
                includeIdx++;
            }
            if (includeIdx < numWords && (maxWidth - (currentSize + (int) words[includeIdx].size())) < (slotCount)) {
                includeIdx--;
                slotCount--;
            }
            int numSpaces = (slotCount == 0)? (maxWidth - currentSize):  (maxWidth - currentSize) / slotCount;
            if (includeIdx >= numWords) {
                int totalSpaces = maxWidth - currentSize;
                for (int i = currentIdx; i < includeIdx; i++) {
                    line += words[i];
                    if (i == includeIdx - 1) {
                        for (int i = 0; i < totalSpaces; i++) {
                            line.push_back(' ');
                        }
                        break;
                    }
                    line += ' ';
                    totalSpaces -= 1;
                }
                lines.push_back(line);
                break;
            }
            int totalSpaces = maxWidth - currentSize;
            int leftHasMoreSpaces = (slotCount > 0)? (maxWidth - currentSize) % slotCount: 0;
            for (int i = currentIdx; i <= includeIdx; i++) {
                line += words[i];
                if (i == includeIdx) {
                    if (totalSpaces >= 0) {
                        for (int j = 0; j < totalSpaces; j++) {
                            line.push_back(' ');
                        }
                    }
                    break;
                }
                if ((i - currentIdx) < leftHasMoreSpaces) {
                    for (int j = 0; j < numSpaces; j++) line.push_back(' ');
                    line.push_back(' ');
                    totalSpaces -= (numSpaces + 1);
                }
                else {
                    for (int j = 0; j < numSpaces; j++) line.push_back(' ');
                    totalSpaces -= numSpaces;
                }
            }
            lines.push_back(line);
            currentIdx = includeIdx + 1;
        }
        return lines;
    }
};

// 1. How to identify the last word in a line?
// - Track the cumulative length of the words we are considering, using intervals.

// 2. How many spaces need to be distributed between words?
// - Number of slots = number of words in the interval - 1
// - Edge case: if there is only one word in the interval, we still need to fill up the remaining spaces.
// - For other cases: distribute (total number of spaces) / (number of slots) to each slot initially.
// - If there are remaining spaces, distribute one space to each slot from left to right until no spaces remain.

// 3. How to handle the last line?
// - Determine if we are processing the last line.
// - Special case: insert a space between each word and fill up the remaining spaces after the last word.

int main(void) {
    int numWords, maxWidth;
    cin >> numWords >> maxWidth;
    vector<string> words(numWords);
    for (int i = 0; i < numWords; i++) cin >> words[i];
    Solution sol;
    vector<string> lines = sol.fullJustify(words, maxWidth);
    for (auto line: lines) {
        cout << line << endl;
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        vector<int> prevRow(len2+1, 0);
        for (int j = 1; j <= len2; j++) prevRow[j] = prevRow[j-1] + int(s2[j-1]);
        if (len1 == 0) return prevRow[len2];
        vector<int> currentRow(len2+1, 0);
        int temp = 0;
        for (int i = 1; i <= len1; i++) {
            temp += int(s1[i-1]);
            currentRow[0] = temp;
            for (int j = 1; j <= len2; j++) {
                if (s1[i-1] == s2[j-1]) currentRow[j] = prevRow[j-1];
                else currentRow[j] = min(prevRow[j] + int(s1[i-1]), currentRow[j-1] + int(s2[j-1]));
            }
            for (int j = 0; j <= len2; j++) prevRow[j] = currentRow[j];
        }
        return currentRow[len2];
    }
};

int main(void) {
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol;
    cout << sol.minimumDeleteSum(s1, s2) << endl;
    return 0;
}
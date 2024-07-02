#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, char> charMap = {
            {1, 'I'},
            {5, 'V'},
            {10, 'X'},
            {50, 'L'},
            {100, 'C'},
            {500, 'D'},
            {1000, 'M'},
        };
        unordered_map<int, string> specialMap = {
            {4, "IV"},
            {9, "IX"},
            {40, "XL"},
            {90, "XC"},
            {400, "CD"},
            {900, "CM"},
        };
        int divisor = 1000;
        string result;
        while (divisor != 0) {
            int quotient = (num / divisor);
            if (quotient != 0) {
                if (specialMap.count(quotient * divisor) != 0) {
                    result.append(specialMap[quotient * divisor]);
                }
                else {
                    int numberWithFive = divisor * 5;
                    if (charMap.count(numberWithFive) != 0 && (quotient / 5) != 0) {
                        int remainder = quotient % 5;
                        result.push_back(charMap[numberWithFive]);
                        for (int i = 0; i < remainder; i++) {
                            result.push_back(charMap[divisor]);
                        }
                    }
                    else {
                        for (int i = 0; i < quotient; i++) {
                            result.push_back(charMap[divisor]);
                        }
                    }
                }
            }
            num = (num % divisor);
            divisor /= 10;
        }
        return result;
    }
};

int main(void) {
    int num;
    cin >> num;
    Solution sol;
    cout << sol.intToRoman(num) << endl;
    return 0;
}
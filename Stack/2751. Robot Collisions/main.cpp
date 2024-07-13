#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int numRobots = positions.size();
        vector<pair<int, int>> sortedPos(numRobots);
        vector<int> sortedHp(numRobots);
        string sortedDir;
        for (int i = 0; i < numRobots; i++) {
            sortedPos[i] = {positions[i], i};
        }
        sort(sortedPos.begin(), sortedPos.end());
        for (int i = 0; i < numRobots; i++) {
            sortedHp[i] = healths[sortedPos[i].second];
            sortedDir.push_back(directions[sortedPos[i].second]);
        }
        stack<pair<pair<int, char>, int>> myStack;
        for (int i = 0; i < numRobots; i++) {
            if (myStack.empty() || !(myStack.top().first.second == 'R' && sortedDir[i] == 'L')) {
                myStack.push({{sortedHp[i], sortedDir[i]}, sortedPos[i].second});
            }
            else {
                myStack.push({{sortedHp[i], sortedDir[i]}, sortedPos[i].second});
                while (!myStack.empty() && myStack.top().first.second == 'L') {
                    pair<pair<int, char>, int> current = myStack.top();
                    myStack.pop();
                    if (myStack.empty() || myStack.top().first.second == 'L') {
                        myStack.push(current);
                        break;
                    }
                    pair<pair<int, char>, int> prev = myStack.top();
                    myStack.pop();
                    if (prev.first.first > current.first.first) {
                        myStack.push({{prev.first.first-1, prev.first.second}, prev.second});
                    }
                    else if (prev.first.first < current.first.first) {
                        myStack.push({{current.first.first-1, current.first.second}, current.second});
                    }
                }
            }
        }
        vector<int> temp(numRobots, -1);
        while (!myStack.empty()) {
            temp[myStack.top().second] = myStack.top().first.first;
            myStack.pop();
        }
        vector<int> result;
        for (auto num: temp) {
            if (num != -1) result.push_back(num);
        }
        return result;
    }
};

int main(void) {
    int numRobots;
    cin >> numRobots;
    vector<int> positions(numRobots), healths(numRobots);
    for (int i = 0; i < numRobots; i++) {
        cin >> positions[i] >> healths[i];
    }
    string directions;
    cin >> directions;
    Solution sol;
    vector<int> result = sol.survivedRobotsHealths(positions, healths, directions);
    for (auto num: result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int numRooms = rooms.size();
        vector<bool> visited(numRooms, false);
        stack<int> s;
        s.push(0);
        visited[0] = true;
        while (!s.empty()) {
            int currentRoom = s.top();
            s.pop();
            for (auto key: rooms[currentRoom]) {
                if (!visited[key]) {
                    s.push(key);
                    visited[key] = true;
                }
            }
        }
        for (auto room: visited) {
            if (!room) return false;
        }
        return true;
    }
};

int main(void) {
    freopen("0.in", "r", stdin);
    string input;
    getline(cin, input);

    vector<vector<int>> rooms;
    stringstream ss(input.substr(1, input.size() - 2));
    string room;
    
    while (getline(ss, room, ']')) {
        if (room.size() > 0 && room[0] == ',') room = room.substr(1);
        if (room.size() > 0 && room[0] == '[') room = room.substr(1);
        stringstream roomStream(room);
        vector<int> keys;
        int key;
        while (roomStream >> key) {
            keys.push_back(key);
            if (roomStream.peek() == ',') roomStream.ignore();
        }
        rooms.push_back(keys);
    }

    Solution sol;
    cout << sol.canVisitAllRooms(rooms) << endl;
    return 0;
}
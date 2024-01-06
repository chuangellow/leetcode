#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>*> table;

    TimeMap() {
    }

    int search(vector<pair<string, int>>& secondLevelTable, int target) {
        int n = secondLevelTable.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (unsigned int) (left + right + 1) >> 1;
            if (secondLevelTable.at(mid).second <= target) left = mid;
            else right = mid - 1;
        }
        return (secondLevelTable.at(left).second <= target)? left: -1;
    }
    void set(string key, string value, int timestamp) {
        if (table.find(key) == table.end()) {
            vector<pair<string, int>>* secondLevelTable = new vector<pair<string, int>>();
            secondLevelTable->push_back(pair(value, timestamp));
            table[key] = secondLevelTable;
            return;
        }
        vector<pair<string, int>>* secondLevelTable = table[key];
        int insertIdx = search(*secondLevelTable, timestamp);
        secondLevelTable->insert(secondLevelTable->begin() + insertIdx + 1, pair(value, timestamp));
        return;
    }
    
    string get(string key, int timestamp) {
        if (table.find(key) == table.end()) return "";
        vector<pair<string, int>>* secondLevelTable = table[key];
        int idx = search(*secondLevelTable, timestamp);
        if (idx == -1) return "";
        return secondLevelTable->at(idx).first;
    }
};

int main(void) {
    int numCommands;
    cin >> numCommands;
    vector<string> commands(numCommands);
    TimeMap* map = nullptr;
    for (int i = 0; i < numCommands; i++) {
        cin >> commands.at(i);
    }
    for (int i = 0; i < numCommands; i++) {
        if (commands.at(i).compare("TimeMap") == 0) {
            if (map != nullptr) {
                delete map;
            }
            map = new TimeMap();
        }
        else if (commands.at(i).compare("set") == 0) {
            string key, value;
            int timeStamp;
            cin >> key >> value >> timeStamp;
            map->set(key, value, timeStamp);
        }
        else if (commands.at(i).compare("get") == 0) {
            string key;
            int timeStamp;
            cin >> key >> timeStamp;
            cout << "Key: " << key << " Value: " << map->get(key, timeStamp) << endl;
        }
        else {
            cout << "Invalid command." << endl;
            return 1;
        }
    }
    delete map;
    return 0;
}
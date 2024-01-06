#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
    }
    
    string get(string key, int timestamp) {
        
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
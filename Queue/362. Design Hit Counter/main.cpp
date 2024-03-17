#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HitCounter {
private:
    vector<int> timeStamps;
    int numHits;
    int interval;
public:
    HitCounter(): numHits(0), interval(300) {
    }
    void hit(int timestamp) {
        timeStamps.push_back(timestamp);
        numHits++;
    }
    int binarySearch(int target) {
        int left = 0, right = numHits-1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (timeStamps[mid] > target) right = mid;
            else left = mid + 1;
        }
        return (timeStamps[left] > target)? left: -1;
    }
    int getHits(int timestamp) {
        if (numHits == 0) return 0;
        int target = timestamp - interval;
        if (target < timeStamps[0]) return numHits;
        if (target >= timeStamps[numHits-1]) return 0;
        int idx = binarySearch(target);
        if (idx == -1) return 0;
        else return numHits - idx;
    }
};

int main(void) {
    int numCommands;
    cin >> numCommands;
    shared_ptr<HitCounter> hitCounter;
    for (int i = 0; i < numCommands; i++) {
        string command;
        cin >> command;
        if (command.compare("HitCounter") == 0) {
            hitCounter = make_shared<HitCounter>();
            cout << "null" << endl;
        }
        else if (command.compare("hit") == 0) {
            int timeStamp;
            cin >> timeStamp;
            hitCounter->hit(timeStamp);
            cout << "null" << endl;
        }
        else if (command.compare("getHits") == 0) {
            int timeStamp;
            cin >> timeStamp;
            cout << hitCounter->getHits(timeStamp) << endl;
        }
        else {
            cout << "Invalid command!!!" << endl;
        }
    }
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <random>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> valToIdxMap;
    vector<int> nums;
    int n;
public:
    RandomizedSet() {
        n = 0;
    }

    void swap(int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    bool insert(int val) {
        if (valToIdxMap.count(val) == 0) {
            valToIdxMap[val] = n;
            nums.push_back(val);
            n += 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (valToIdxMap.count(val) != 0) {
            int idx = valToIdxMap[val];
            valToIdxMap[nums[n-1]] = idx;
            valToIdxMap.erase(val);
            swap(idx, n-1);
            nums.pop_back();
            n -= 1;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        random_device                  rand_dev;
        mt19937                        generator(rand_dev());
        uniform_int_distribution<int>  distr(0, n-1);
        int randIdx = distr(generator);
        return nums[randIdx];
    }
};

int main(void) {
    int numCommands;
    cin >> numCommands;
    for (int i = 0; i < numCommands; i++) {
        string s;
        cin >> s;
        int val;
        RandomizedSet *set;
        if (s.compare("RandomizedSet") == 0) {
            set = new RandomizedSet();
        } 
        else if (s.compare("insert") == 0) {
            cin >> val;
            set->insert(val);
        }
        else if (s.compare("remove") == 0) {
            cin >> val;
            set->remove(val);
        }
        else if (s.compare("getRandom") == 0) {
            cout << set->getRandom() << endl;
        }
        else {
            cout << "Invalid command!!!" << endl;
        }
    }
    return 0;
}
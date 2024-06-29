#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <random>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> idxToValSet;
    unordered_map<int, int> valToIdxSet;
    int id;
public:
    RandomizedSet() {
        id = 0;
    }
    
    bool insert(int val) {
        if (valToIdxSet.count(val) == 0) {
            idxToValSet[id] = val;
            valToIdxSet[val] = id;
            id += 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (valToIdxSet.count(val) != 0) {
            int idx = valToIdxSet[val];
            idxToValSet.erase(idx);
            valToIdxSet.erase(val);
            for (int i = idx + 1; i < id; i++) {
                int nextVal = idxToValSet[i];
                idxToValSet[i-1] = nextVal;
                valToIdxSet[nextVal] = i-1;
            }
            return true;
        }
        return false;
    }
    
    int getRandom() {
        random_device                  rand_dev;
        mt19937                        generator(rand_dev());
        uniform_int_distribution<int>  distr(0, id-1);
        int randIdx = distr(generator);
        return idxToValSet[randIdx];
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
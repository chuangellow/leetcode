#include <iostream>
#include <vector>
#include <string>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
    }
    
    int add(int val) {
    }

    void show() {
    }
};

int main(void) {
    int numCommands;
    cin >> numCommands;
    std::shared_ptr<KthLargest> stream;
    for (int i = 0; i < numCommands; i++) {
        string command;
        cin >> command;
        if (command.compare("KthLargest") == 0) {
            int k, size;
            cin >> k >> size;
            vector<int> nums;
            for (int i = 0; i < size; i++) cin >> nums[i];
            stream = make_shared<KthLargest>(k, nums);
        }
        else if (command.compare("add") == 0) {
            int val;
            cin >> val;
            stream->add(val);
        }
        else if (command.compare("show") == 0) {
            stream->show();
        }
        else {
            cout << "Invalid command!!!" << endl;
        }
    }
}
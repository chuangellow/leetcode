#include <iostream>
#include <vector>
#include <string>

using namespace std;

class KthLargest {
private:
    int k;
    int size;
    vector<int> arr;
public:
    // Time Complexity: O(nlogn)
    KthLargest(int k, vector<int>& nums) : k(k), size(nums.size()) {
        arr.resize(size);
        for (int i = 0; i < size; i++) arr.at(i) = nums.at(i);
        if (size > 1) sort(arr.begin(), arr.end(), greater<>());
    }
    
    // Time Complexity: O(n)
    int add(int val) {
        int insertPos = 0;
        for (; insertPos < size && val < arr.at(insertPos); insertPos++) {}
        arr.insert(arr.begin() + insertPos, val);
        size++;
        return arr.at(k-1);
    }

    void show() {
        for (int i = 0; i < size; i++) {
            cout << arr.at(i) << " ";
        }
        cout << endl;
    }
};

int main(void) {
    int numCommands;
    cin >> numCommands;
    std::shared_ptr<KthLargest> stream = nullptr;
    for (int i = 0; i < numCommands; i++) {
        string command;
        cin >> command;
        if (command.compare("KthLargest") == 0) {
            int k, size;
            cin >> k >> size;
            vector<int> nums(size, 0);
            for (int i = 0; i < size; i++) cin >> nums[i];
            stream = make_shared<KthLargest>(k, nums);
        }
        else if (command.compare("add") == 0) {
            int val;
            cin >> val;
            int kthLargest = stream->add(val);
            cout << kthLargest << endl;
        }
        else if (command.compare("show") == 0) {
            stream->show();
        }
        else {
            cout << "Invalid command!!!" << endl;
        }
    }
}
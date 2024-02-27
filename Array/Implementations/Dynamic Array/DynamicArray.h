#include <cstdlib>

#define size_t int
#define INIT_ARR_SIZE 4096
#define ll long long int

class DynamicArray {
private:
    size_t* arr;
    ll arrSize;
    int resize();
public:
    DynamicArray();
    ~DynamicArray();
    ll size() { return arrSize; };
    size_t& operator[](int index);
};
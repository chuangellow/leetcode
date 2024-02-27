#include <cstdlib>

#define size_t int
#define INIT_ARR_SIZE 4096
#define ll long long int

class DynamicArray {
private:
    size_t* arr;
    int arrSize;
    ll currentMaxSize;
    void resize();
public:
    DynamicArray();
    ~DynamicArray();
};
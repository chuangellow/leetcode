#include <vector>
#include <iostream>
#include <memory>
#include "LinkedList.h"

int main(void) {
    std::shared_ptr<LinkedList> list = std::make_shared<LinkedList>();
    list->insertToHead(1);
    list->insertToTail(2);
    list->insertToHead(3);
    list->traverse();
}
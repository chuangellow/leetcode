#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "LinkedList.h"

void parseInput(std::shared_ptr<LinkedList> list, int numCommands) {
    for (int i = 0; i < numCommands; i++) {
        std::string command;
        std::cin >> command;
        if (command.compare("insertToHead") == 0) {
            int data;
            std::cin >> data;
            list->insertToHead(data);
        }
        else if (command.compare("insertToTail") == 0) {
            int data;
            std::cin >> data;
            list->insertToTail(data);
        }
        else if (command.compare("removeHead") == 0) {
            list->removeHead();
        }
        else if (command.compare("removeTail") == 0) {
            list->removeTail();
        }
        else if (command.compare("traverse") == 0) {
            list->traverse();
        }
        else if (command.compare("insertAfterIdx") == 0) {
            int data, index;
            std::cin >> data >> index;
            list->insertAfterIdx(data, index);
        }
        else {
            std::cout << "Invalid commands!!!" << std::endl;
        }
    }
}

int main(void) {
    std::shared_ptr<LinkedList> list = std::make_shared<LinkedList>();
    int numCommands;
    std::cin >> numCommands;
    parseInput(list, numCommands);
}
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>
#include "LinkedList.h"

void parseInput(std::shared_ptr<LinkedList> list, int numCommands) {
    std::unordered_map<std::string, std::function<void()>> commandMap;

    commandMap["insertToHead"] = [&]() {
        int data;
        std::cin >> data;
        list->insertToHead(data);
    };
    commandMap["insertToTail"] = [&]() {
        int data;
        std::cin >> data;
        list->insertToTail(data);
    };
    commandMap["removeHead"] = [&]() {
        list->removeHead();
    };
    commandMap["removeTail"] = [&]() {
        list->removeTail();
    };
    commandMap["traverse"] = [&]() {
        list->traverse();
    };
    commandMap["insertAfterIdx"] = [&]() {
        int data, index;
        std::cin >> data >> index;
        list->insertAfterIdx(data, index);
    };

    for (int i = 0; i < numCommands; i++) {
        std::string command;
        std::cin >> command;
        auto it = commandMap.find(command);
        if (it != commandMap.end()) {
            it->second();
        } 
        else {
            std::cout << "Invalid command!!!" << std::endl;
        }
    }
}

int main(void) {
    std::shared_ptr<LinkedList> list = std::make_shared<LinkedList>();
    int numCommands;
    std::cin >> numCommands;
    parseInput(list, numCommands);
}
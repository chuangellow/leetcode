#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>
#include "DoubleLinkedList.h"

void parseInput(int numCommands) {
    std::unordered_map<std::string, std::function<void()>> commandMap;
    std::shared_ptr<DoubleLinkedList> list = std::make_shared<DoubleLinkedList>();

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
    commandMap["traverseFromHead"] = [&]() {
        list->traverseFromHead();
    };
    commandMap["traverseFromTail"] = [&]() {
        list->traverseFromTail();
    };
    commandMap["insertAfterIdxFromHead"] = [&]() {
        int data, index;
        std::cin >> data >> index;
        list->insertAfterIdxFromHead(data, index);
    };
    commandMap["insertBeforeIdxFromHead"] = [&]() {
        int data, index;
        std::cin >> data >> index;
        list->insertBeforeIdxFromHead(data, index);
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
    int numCommands;
    std::cin >> numCommands;
    parseInput(numCommands);
}
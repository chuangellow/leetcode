#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>
#include "CircularLinkedList.h"

void parseInput(std::shared_ptr<CircularLinkedList> list, int numCommands) {
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
    commandMap["getData"] = [&]() {
        int index;
        std::cin >> index;
        int data = list->getData(index);
        std::cout << data << std::endl;
    };
    commandMap["traverse"] = [&]() {
        list->traverse();
    };
    commandMap["insertAfterIdx"] = [&]() {
        int data, index;
        std::cin >> data >> index;
        list->insertAfterIdx(data, index);
    };
    commandMap["insertBeforeIdx"] = [&]() {
        int data, index;
        std::cin >> data >> index;
        list->insertBeforeIdx(data, index);
    };
    commandMap["reverse"] = [&]() {
        list->reverse();
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
    std::shared_ptr<CircularLinkedList> list = std::make_shared<CircularLinkedList>();
    int numCommands;
    std::cin >> numCommands;
    parseInput(list, numCommands);
}
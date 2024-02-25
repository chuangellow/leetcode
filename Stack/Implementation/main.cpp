#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>

#include "Stack.h"

void parseInput(int numCommands) {
    std::unordered_map<std::string, std::function<void()>> commandMap;

    std::shared_ptr<Stack> stack = std::make_shared<Stack>();

    commandMap["push"] = [&]() {
        int data;
        std::cin >> data;
        stack->push(data);
    };

    commandMap["pop"] = [&]() {
        if (stack->isEmpty()) {
            std::cout << "The stack is empty!!!" << std::endl;
        }
        else {
            int poppedData = stack->pop();
            std::cout << "Pop: " << poppedData << std::endl;
        }
    };

    commandMap["peek"] = [&]() {
        std::cout << "Peek: " << stack->peek() << std::endl;
    };

    commandMap["printStack"] = [&]() {
        stack->printStack();
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
    return;
}

int main(void) {
    int numCommands;
    std::cin >> numCommands;
    parseInput(numCommands);
}
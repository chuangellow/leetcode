#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>
#include "Queue.h"

void parseInput(int numCommands) {
    std::unordered_map<std::string, std::function<void()>> commandMap;
    std::shared_ptr<Queue> queue = std::make_shared<Queue>();

    commandMap["enqueue"] = [&]() {
        int data;
        std::cin >> data;
        queue->enqueue(data);
    };

    commandMap["dequeue"] = [&]() {
        int data = queue->dequeue();
        std::cout << "dequeue data: " << data << std::endl;
    };

    commandMap["getFront"] = [&]() {
        int data = queue->getFront();
        std::cout << "front data: " << data << std::endl;
    };

    commandMap["showQueue"] = [&]() {
        queue->showQueue();
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
    return 0;
}
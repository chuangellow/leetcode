#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <functional>

using namespace std;

class SnakeGame {
private:
    int width;
    int height;
    int numFoods;
    int currentFoods;
    vector<vector<int>> foods;
    deque<vector<int>> snake;
    unordered_map<string, vector<int>> dirs;
public:
    SnakeGame(int width, int height, vector<vector<int>>& food): width(width), height(height), currentFoods(0), numFoods(food.size()) {
        dirs = {
            {"U", {0, -1}},
            {"L", {-1, 0}},
            {"D", {0, 1}},
            {"R", {1, 0}}
        };
        for (int i = 0; i < numFoods; i++) {
            foods.push_back({food[i][1], food[i][0]});
        }
        snake.push_front({0, 0});
    }

    int move(string direction) {
        vector<int> dir = dirs[direction];
        int x = snake.front()[0] + dir[0];
        int y = snake.front()[1] + dir[1];
        
        if (x < 0 || x >= width || y < 0 || y >= height || 
            (find(snake.begin() + 1, snake.end(), vector<int>{x, y}) != snake.end() && !(x == snake.back()[0] && y == snake.back()[1]))) {
            return -1;
        }
        
        snake.push_front({x, y});
        
        if (currentFoods < numFoods && snake.front() == foods[currentFoods]) {
            currentFoods++; 
        } else {
            snake.pop_back();
        }
        
        return currentFoods;
    }
};

int main(void) {
    int numCommands;
    cin >> numCommands;
    shared_ptr<SnakeGame> game;
    for (int i = 0; i < numCommands; i++) {
        string command;
        cin >> command;
        if (command.compare("SnakeGame") == 0) {
            int width, height, numFood;
            cin >> width >> height >> numFood;
            vector<vector<int>> foods;
            for (int i = 0; i < numFood; i++) {
                vector<int> pos(2);
                cin >> pos[0] >> pos[1];
                foods.push_back(pos);
            }
            game = make_shared<SnakeGame>(width, height, foods);
            cout << "null" << endl;
        }
        else if (command.compare("move") == 0) {
            string direction;
            cin >> direction;
            cout << game->move(direction) << endl;
        }
        else {
            cout << "Invalid command!!!" << endl;
        }
    }
    return 0;
}
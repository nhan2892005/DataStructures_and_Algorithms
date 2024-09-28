/*
A Maze is given as 5*5 binary matrix of blocks and there is a rat initially at the upper left most block i.e., maze[0][0] and the rat wants to eat food which is present at some given block in the maze (fx, fy). In a maze matrix, 0 means that the block is a dead end and 1 means that the block can be used in the path from source to destination. The rat can move in any direction (not diagonally) to any block provided the block is not a dead end.

Your task is to implement a function with following prototype to check if there exists any path so that the rat can reach the food or not:
bool canEatFood(int maze[5][5], int fx, int fy);

Template:

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

class node {
public:
    int x, y;
    int dir;
    node(int i, int j)
    {
        x = i;
        y = j;
  
        // Initially direction
        // set to 0
        dir = 0;
    }
};

Some suggestions: 
- X : x coordinate of the node
- Y : y coordinate of the node
- dir : This variable will be used to tell which all directions we have tried and which to choose next. We will try all the directions in anti-clockwise manner starting from up.

If dir=0 try up direction.
If dir=1 try left direction.
If dir=2 try down direction.
If dir=3 try right direction.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

class node {
public:
    int x, y;
    int dir;
    node(int i, int j)
    {
        x = i;
        y = j;
  
        // Initially direction
        // set to 0
        dir = 0;
    }
};

bool canEatFood(int maze[5][5], int fx, int fy){
    /*TODO*/
    stack<node> s;
    node start(0, 0);
    s.push(start);
    const int rows = 5;
    const int cols = 5;
    bool visited[rows][cols];
    memset(visited, false, sizeof(visited));
    visited[start.x][start.y] = true;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    while (!s.empty()) {
        node current = s.top();
        if (current.x == fx && current.y == fy) {
            return true;
        }

        bool found = false;
        for (int i = 0; i < 4; i++) {
            int newDir = (current.dir + i) % 4;
            int newX = current.x + dx[newDir];
            int newY = current.y + dy[newDir];
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && maze[newX][newY] == 1 && !visited[newX][newY]) {
                visited[newX][newY] = true;
                
                s.push(node(newX, newY));
                current.dir = newDir;
                found = true;
                break;
            }
        }
        if (!found) {
            s.pop();
        }
    }
    return false;
}

int main(){
    int maze[5][5] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 1}
    };
    int fx = 4, fy = 4;
    cout << canEatFood(maze, fx, fy);
    return 0;
}
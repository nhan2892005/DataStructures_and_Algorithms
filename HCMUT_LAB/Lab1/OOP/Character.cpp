/*
In a game, we have class Character to store characters' data.
The class Character is declared as below:
class Character {
protected:
    int hp;
    int x;
    int y;
public:
    // Constructor: set the values of x and y and hp to 0
    Character();

    // Constructor: set the values of hp, x and y to each parameter
    Character(int hp, int x, int y);

    // Set and get hp
    int getHp();
    void setHp(int hp);

    // Set and get x
    int getX();
    void setX(int x);
    
    // Set and get y
    int getY();
    void setY(int y);

    // Get Manhattan distance to other character
    int getManhattanDistTo(Character* other);
};
Your task is to define the constructors and the methods of the class.

Note:
In this task, iostream library has been included, and namespace std is being used. No other libraries are allowed.

For example:

Test	                    
Character ch1(100, 3, 6);
cout << ch1.getHp() << " " << ch1.getX() << " " << ch1.getY();

Result
100 3 6

*/

#include <iostream>
using namespace std;

class Character {
protected:
    int hp;
    int x;
    int y;
public:
    // Constructor: set the values of x and y and hp to 0
    Character();

    // Constructor: set the values of hp, x and y to each parameter
    Character(int hp, int x, int y);

    // Set and get hp
    int getHp();
    void setHp(int hp);

    // Set and get x
    int getX();
    void setX(int x);
    
    // Set and get y
    int getY();
    void setY(int y);

    // Get Manhattan distance to other character
    int getManhattanDistTo(Character* other);
};

Character::Character() {
    hp = 0; 
    x = 0;  
    y = 0;  
}

Character::Character(int hp, int x, int y) {
    this->hp = hp; 
    this->x = x;   
    this->y = y;   
}

int Character::getHp() {
    return hp;
}

void Character::setHp(int hp) {
    this->hp = hp;
}

int Character::getX() {
    return x; 
}

void Character::setX(int x) {
    this->x = x; 
}

int Character::getY() {
    return y; 
}

void Character::setY(int y) {
    this->y = y;
}

int Character::getManhattanDistTo(Character* other) {
    return abs(this->x - other->getX()) + abs(this->y - other->getY());
}

int main() {
    Character ch1(100, 3, 6);
    cout << ch1.getHp() << " " << ch1.getX() << " " << ch1.getY();
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
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

    // Operator =: copy all data from Character other
    void operator=(const Character& other);
    // Operator <: Character a < Character b when a's hp is less than or equal b's hp
    bool operator<(const Character& other);
    // Operator () with zero parameters: print data of the instance with format: hp-x-y
    void operator()();
};

class Player : public Character {
 public:
    Player():Character(){}
    Player(int hp, int x, int y):Character(hp, x, y){}
    void printPlayerData() {
        std::cout << this->getHp() << "-" << this->getX() << "-" << this->getY();
    }
    void moveTo(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

Character::Character() 
:hp(0),x(0),y(0){}
Character::Character(int hp, int x, int y) 
:hp(hp),x(x),y(y){}
int Character::getHp() {return hp;}
void Character::setHp(int hp) {this->hp = hp;}
int Character::getX() {return x;}
void Character::setX(int x) {this->x = x;}
int Character::getY() {return y;}
void Character::setY(int y) {this->y = y;}
int Character::getManhattanDistTo(Character* other) {
    return std::abs(x - other->getX()) + std::abs(y - other->getY());
}

void Character::operator=(const Character& other) {
    hp = other.hp;
    x = other.x;
    y = other.y;
}
bool Character::operator<(const Character& other) {
    return hp <= other.hp;
}
void Character::operator()() {
    std::cout << hp << "-" << x << "-" << y << std::endl;
}


void test_Character();
void test_Character2();
void test_Player();

int main() {
    std::string pathOutput = "output.txt";
    std::ofstream out(pathOutput);

    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    
    std::cout << "Test Character" << std::endl;
    test_Character();
    std::cout << std::endl;

    std::cout << "Test Character2" << std::endl;
    test_Character2();
    std::cout << std::endl;

    std::cout << "Test Player" << std::endl;
    test_Player();
    std::cout << std::endl;
    
    std::cout.rdbuf(coutbuf);
    return 0;
}

void test_Character() {
    Character c1;
    Character c2(10, 1, 1);
    Character c3(20, 2, 2);
    Character c4(30, 3, 3);
    
    std::cout << "Test 1: " << (c1.getHp() == 0 ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 2: " << (c2.getHp() == 10 ? "Passed" : "Failed") << std::endl;

    c1.setHp(5);
    c2.setX(5);
    c3.setY(5);
    std::cout << "Test 3: " << (c1.getHp() == 5 ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 4: " << (c2.getX() == 5 ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 5: " << (c3.getY() == 5 ? "Passed" : "Failed") << std::endl;
    
    std::cout << "Test 6: " << (c2.getManhattanDistTo(&c3) == 2 ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 7: " << (c3.getManhattanDistTo(&c4) == 2 ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 8: " << (c2.getManhattanDistTo(&c4) == 4 ? "Passed" : "Failed") << std::endl;

    c4.setHp(40);
    c4.setX(4);
    c4.setY(4);
    std::cout << "Test 9: " << (c2.getManhattanDistTo(&c4) == 4 ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 10: " << (c3.getManhattanDistTo(&c4) == 2 ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 11: " << (c2.getManhattanDistTo(&c3) == 2 ? "Passed" : "Failed") << std::endl;
}
void test_Character2() {
    Character ch1(100, 3, 6); 
    ch1();
    Character ch21(10, 20, 30); 
    Character ch22(5, 5, 6); 
    std::cout << ((ch21 < ch22) ? "true" : "false") << std::endl;
    Character ch31; 
    Character ch32; 
    std::cout << ((ch31 < ch32) ? "true" : "false") << std::endl;
    Character ch4; 
    ch4();
    std::cout << std::endl;
    ch4 = Character(5, 10, 20); 
    ch4();
    std::cout << std::endl;
    Character(3, 4, 5)();
    std::cout << ((Character(3, 4, 5) < Character(3, 4, 5)) ? "true" : "false") << std::endl;
}

void test_Player() {
    Player p1;
    Player p2(10, 1, 1);
    Player p3(20, 2, 2);
    Player p4(30, 3, 3);
    
    std::cout << "Test 1: " << (p1.getHp() == 0 ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 2: " << (p2.getHp() == 10 ? "Passed" : "Failed") << std::endl;

    p1.setHp(5);
    p2.setX(5);
    p3.setY(5);
    std::cout << "Test 3: " << (p1.getHp() == 5 ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 4: " << (p2.getX() == 5 ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 5: " << (p3.getY() == 5 ? "Passed" : "Failed") << std::endl;
    
    std::cout << "Test 6: " << (p2.getManhattanDistTo(&p4) == 4 ? "Passed" : "Failed") << std::endl;

    p4.setHp(40);
    p4.setX(4);
    p4.setY(4);
    std::cout << "Test 7: " << (p2.getManhattanDistTo(&p4) == 4 ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 8: " << (p3.getManhattanDistTo(&p4) == 3 ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 9: " << (p2.getManhattanDistTo(&p3) == 7 ? "Passed" : "Failed") << std::endl;
}
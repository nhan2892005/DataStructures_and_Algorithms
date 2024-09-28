/*
In the toy store, all toy has a price. Car toy has a price and color, Puzzle toy has a price and size. We have to implement class CarToy and class PuzzleToy which inherit from class Toy.
class ToyBox has a  pointer array to store a list of toys (up to 5 items including car and puzzle) and number of items in the box.
Your task is to implement two function addItem(…) in class ToyBox. If successfully added, the function returns the current number of toys in the box. If the box is full, return -1.

For example:

Test	                                            Result
CarToy car(20000,red);                              This is a car toy
PuzzleToy puzzle(30000,small);                      This is a puzzle toy
car.printType();
puzzle.printType();

CarToy car(20000,red);                              This is a car toy
PuzzleToy puzzle(30000,small);                      This is a puzzle toy
ToyBox box;
box.addItem(car);
box.addItem(puzzle);
box.printBox();

Toy* toy = new CarToy(30000,red);                   This is a car toy
toy->printType();
*/

#include <bits/stdc++.h>
using namespace std;

enum Color
{
    red,
    green,
    blue
};

enum Size
{
    small,
    medium,
    big
};

class Toy
{
protected:
    double price;

public:
    Toy(double price)
    {
        this->price = price;
    }

    virtual void printType() = 0;

    // Thêm destructor ảo
    virtual ~Toy() {}
    
    friend class ToyBox;
};

class CarToy : public Toy
{
private:
    Color color;

public:
    CarToy(double price, Color color) : Toy(price)
    {
        this->color = color;
    }

    void printType()
    {
        cout << "This is a car toy\n";
    }

    friend class ToyBox;
};

class PuzzleToy : public Toy
{
private:
    Size size;

public:
    PuzzleToy(double price, Size size) : Toy(price)
    {
        this->size = size;
    }

    void printType()
    {
        cout << "This is a puzzle toy\n";
    }

    friend class ToyBox;
};

class ToyBox
{
private:
    Toy* toyBox[5];
    int numberOfItems;

public:
    ToyBox()
    {
        numberOfItems = 0;
        for (int i = 0; i < 5; i++)
        {
            toyBox[i] = nullptr; // Khởi tạo các con trỏ toyBox là nullptr
        }
    }

    int addItem(const CarToy& carToy)
    {
        if (numberOfItems >= 5)
            return -1; // Hộp đã đầy

        toyBox[numberOfItems] = new CarToy(carToy); // Cấp phát bộ nhớ cho CarToy
        numberOfItems++;
        return numberOfItems; // Trả về số lượng hiện tại của đồ chơi
    }

    int addItem(const PuzzleToy& puzzleToy)
    {
        if (numberOfItems >= 5)
            return -1; // Hộp đã đầy

        toyBox[numberOfItems] = new PuzzleToy(puzzleToy); // Cấp phát bộ nhớ cho PuzzleToy
        numberOfItems++;
        return numberOfItems; // Trả về số lượng hiện tại của đồ chơi
    }

    void printBox()
    {
        for (int i = 0; i < numberOfItems; i++)
            toyBox[i]->printType();
    }

    ~ToyBox() // Destructor để giải phóng bộ nhớ
    {
        for (int i = 0; i < numberOfItems; i++)
        {
            delete toyBox[i]; // Giải phóng bộ nhớ cho từng món đồ chơi
        }
    }
};

int main()
{
    CarToy car(20000, red);
    PuzzleToy puzzle(30000, small);
    car.printType();
    puzzle.printType();

    CarToy car2(20000, red);
    PuzzleToy puzzle2(30000, small);
    ToyBox box;
    box.addItem(car2);
    box.addItem(puzzle2);
    box.printBox();

    Toy* toy = new CarToy(30000, red);
    toy->printType();

    return 0;
}
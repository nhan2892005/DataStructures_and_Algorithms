/*
In the coordinate plane, we have class Point to store a point with it's x-y coordinate.

Your task in this exercise is to implement functions marked with   * STUDENT ANSWER   *.

Note: For exercises in Week 1, we have #include <bits/stdc++.h> and using namespace std;

For example:

Test	                                                Result
Point A(2, 3);                                          2 3
cout << A.getX() << " " << A.getY();

Point A(2, 3);                                          5
Point B(1, 1);
cout << pow(A.distanceToPoint(B), 2);
*/
#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point()
    {
        x = 0;
        y = 0; 
    }

    Point(double x, double y)
    {
        this->x = x; 
        this->y = y; 
    }

    void setX(double x)
    {
        this->x = x; 
    }

    void setY(double y)
    {
        this->y = y; 
    }

    double getX() const
    {
        return x; 
    }

    double getY() const
    {
        return y;
    }

    double distanceToPoint(const Point& pointA)
    {
        return sqrt(pow(x - pointA.getX(), 2) + pow(y - pointA.getY(), 2)); // Tính khoảng cách
    }
};

/*
In the coordinate plane, a circle is defined by center and radius.

Your task in this exercise is to implement functions marked with *STUDENT ANSWER*.

Note: you can use implemented class Point in previous question
*/

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle()
    {
        center = Point(0, 0); 
        radius = 0;         
    }

    Circle(Point center, double radius)
    {
        this->center = center; 
        this->radius = radius; 
    }

    Circle(const Circle &circle)
    {
        this->center = circle.center; 
        this->radius = circle.radius;
    }
    
    void setCenter(Point point)
    {
        center = point; 
    }

    void setRadius(double radius)
    {
        this->radius = radius;
    }

    Point getCenter() const
    {
        return center;
    }

    double getRadius() const
    {
        return radius;
    }
    
    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
    }
};

int main()
{
    Point A(2, 3);
    cout << A.getX() << " " << A.getY() << endl;

    Point B(1, 1);
    cout << pow(A.distanceToPoint(B), 2) << endl;

    Circle circle;
    circle.printCircle();

    Circle circle2(A, 5);
    circle2.printCircle();

    return 0;
}

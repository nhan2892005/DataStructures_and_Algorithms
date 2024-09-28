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
        /*  
         * STUDENT ANSWER   
         * TODO: set zero x-y coordinate
         */
        x = 0;
        y = 0; 
    }

    Point(double x, double y)
    {
        /*  
         * STUDENT ANSWER
         */
        this->x = x; 
        this->y = y; 
    }

    void setX(double x)
    {
        /*  
         * STUDENT ANSWER
         */
        this->x = x; 
    }

    void setY(double y)
    {
        /*  
         * STUDENT ANSWER
         */
        this->y = y; 
    }

    double getX() const
    {
        /*  
         * STUDENT ANSWER
         */
        return x; 
    }

    double getY() const
    {
        /*  
         * STUDENT ANSWER
         */
        return y;
    }

    double distanceToPoint(const Point& pointA)
    {
        /*  
         * STUDENT ANSWER   
         * TODO: calculate the distance from this point to point A in the coordinate plane
         */
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
        /*  
         * STUDENT ANSWER   
         * TODO: set zero center's x-y and radius
         */
        center = Point(0, 0); 
        radius = 0;         
    }

    Circle(Point center, double radius)
    {
        /*  
         * STUDENT ANSWER
         */
        this->center = center; 
        this->radius = radius; 
    }

    Circle(const Circle &circle)
    {
        /*  
         * STUDENT ANSWER
         */
        this->center = circle.center; 
        this->radius = circle.radius;
    }
    
    void setCenter(Point point)
    {
        /*  
         * STUDENT ANSWER
         */
        center = point; 
    }

    void setRadius(double radius)
    {
        /*  
         * STUDENT ANSWER
         */
        this->radius = radius;
    }

    Point getCenter() const
    {
        /*  
         * STUDENT ANSWER
         */
        return center;
    }

    double getRadius() const
    {
        /*  
         * STUDENT ANSWER
         */
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

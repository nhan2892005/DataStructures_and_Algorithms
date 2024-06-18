// Greastest Common Devisor

// Recursion Solution

#include <iostream>
#include <fstream>

int gdc(int a, int b){

    // Base case
        // gdc(a, 0) = a || gdc(0, b) = b;
    if (a == 0 || b == 0) return a + b;

    // Recursive Case
        // gdc(a, b) = gdc(b, a mod b)
    return gdc(b, a % b);

}

// Drived Code
int main(){

    std::string fileOutput = "/mnt/d/Code space/School/LearningDSA/Recursion/output/gcd.out";

    std::ofstream out(fileOutput);

    // Store buffer of std::cout
    std::streambuf* originalBuffer = std::cout.rdbuf();

    // Redirect std::cout to fileOutput
    std::cout.rdbuf(out.rdbuf());

    // Test a % b = 0
    int a = 10, b = 5;    
    std::cout << "GDC(" << a << ", " << b << ") = " << gdc(a, b) << std::endl;

    // Test a is Prime
    a = 10, b = 3;
    std::cout << "GDC(" << a << ", " << b << ") = " << gdc(a, b) << std::endl;

    // Test b is Prime
    a = 17, b = 36;
    std::cout << "GDC(" << a << ", " << b << ") = " << gdc(a, b) << std::endl;

    // Test a and b are Prime
    a = 17, b = 19;
    std::cout << "GDC(" << a << ", " << b << ") = " << gdc(a, b) << std::endl;

    // Test a and b are not Prime
    a = 36, b = 48;
    std::cout << "GDC(" << a << ", " << b << ") = " << gdc(a, b) << std::endl;

    // Test a is Prime, b % a = 0
    a = 17, b = 34;
    std::cout << "GDC(" << a << ", " << b << ") = " << gdc(a, b) << std::endl;

    // Test b is Prime, a % b = 0
    a = 38, b = 19;
    std::cout << "GDC(" << a << ", " << b << ") = " << gdc(a, b) << std::endl;

    // Reset std::cout buffer
    std::cout.rdbuf(originalBuffer);

    return 0;
}
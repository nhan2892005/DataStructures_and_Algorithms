#include <iostream>
#include <fstream>
#include <string>

int myArrayToInt(char* str, int n){
    if (n == 0){
        return 0;
    }
    if(n == 1){
        return str[0] - '0';
    }
    return myArrayToInt(str, n - 1) * 10 + str[n - 1] - '0';
}
void printHailstone(int number){
    if (number == 1){
        std::cout << number << std::endl;
        return;
    }
    std::cout << number << " ";
    if (number % 2 == 0){
        printHailstone(number / 2);
    } else {
        printHailstone(3 * number + 1);
    }
}

int decimalToBinary(int decimal_number){
    if (decimal_number == 0){
        return 0;
    }
    return decimalToBinary(decimal_number / 2) * 10 + decimal_number % 2;
}
int countWaySumOfSquare(int x, int base = 1){
    int result = base * base;
    if (x - result == 0){
        return 1;
    }
    if (x - result < 0){
        return 0;
    }
    int left = countWaySumOfSquare(x, base + 1);
    int right = countWaySumOfSquare(x - result, base + 1);
    return left + right;
}

void test_myArrayToInt();
void test_printHailstone();
void test_decimalToBinary();
void test_countWaySumOfSquare();

int main() {
    std::string pathOutput = "output.txt";
    std::ofstream out(pathOutput);

    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    
    std::cout << "Test myArrayToInt" << std::endl;
    test_myArrayToInt();
    std::cout << std::endl;

    std::cout << "Test printHailstone" << std::endl;
    test_printHailstone();
    std::cout << std::endl;

    std::cout << "Test decimalToBinary" << std::endl;
    test_decimalToBinary();
    std::cout << std::endl;

    std::cout << "Test countWaySumOfSquare" << std::endl;
    test_countWaySumOfSquare();
    std::cout << std::endl;
    
    std::cout.rdbuf(coutbuf);
    return 0;
}

void test_myArrayToInt() {
    char str[] = "123";
    int n = 3;
    int result = myArrayToInt(str, n);
    std::cout << "Test 1: " << (result == 123 ? "Passed" : "Failed") << std::endl;

    char str2[] = "1234";
    int n2 = 4;
    int result2 = myArrayToInt(str2, n2);
    std::cout << "Test 2: " << (result2 == 1234 ? "Passed" : "Failed") << std::endl;

    char str3[] = "12345";
    int n3 = 5;
    int result3 = myArrayToInt(str3, n3);
    std::cout << "Test 3: " << (result3 == 12345 ? "Passed" : "Failed") << std::endl;
}

void test_printHailstone() {
    int number = 5;
    printHailstone(number);
    std::cout << "Test 1: " << std::endl;

    int number2 = 10;
    printHailstone(number2);
    std::cout << "Test 2: " << std::endl;

    int number3 = 15;
    printHailstone(number3);
    std::cout << "Test 3: " << std::endl;

    int number4 = 32;
    printHailstone(number4);
    std::cout << "Test 4: " << std::endl;

    int number5 = 1001;
    printHailstone(number5);
    std::cout << "Test 5: " << std::endl;
}

void test_decimalToBinary() {
    int decimal_number = 5;
    int result = decimalToBinary(decimal_number);
    std::cout << "Test 1: " << (result == 101 ? "Passed" : "Failed") << std::endl;

    int decimal_number2 = 10;
    int result2 = decimalToBinary(decimal_number2);
    std::cout << "Test 2: " << (result2 == 1010 ? "Passed" : "Failed") << std::endl;

    int decimal_number3 = 15;
    int result3 = decimalToBinary(decimal_number3);
    std::cout << "Test 3: " << (result3 == 1111 ? "Passed" : "Failed") << std::endl;

    int decimal_number4 = 32;
    int result4 = decimalToBinary(decimal_number4);
    std::cout << "Test 4: " << (result4 == 100000 ? "Passed" : "Failed") << std::endl;

    int decimal_number5 = 1001;
    int result5 = decimalToBinary(decimal_number5);
    std::cout << "Test 5: " << (result5 == 1111101001 ? "Passed" : "Failed") << std::endl;
}

void test_countWaySumOfSquare() {
    int x = 100;
    int result = countWaySumOfSquare(x);
    std::cout << result << std::endl;

    int x2 = 10;
    int result2 = countWaySumOfSquare(x2);
    std::cout << result2 << std::endl;

    int x3 = 15;
    int result3 = countWaySumOfSquare(x3);
    std::cout << result3 << std::endl;

    int x4 = 32;
    int result4 = countWaySumOfSquare(x4);
    std::cout << result4 << std::endl;

    int x5 = 1001;
    int result5 = countWaySumOfSquare(x5);
    std::cout << result5 << std::endl;
}
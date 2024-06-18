// Using Recursion to solve Hanoi Tower Problem

#include <iostream>
#include <fstream>

int count;

template<typename PHUCNHAN>
void hanoiTower(int n, PHUCNHAN src, PHUCNHAN aux, PHUCNHAN dest){
    // Base case
        // if only have 1 disk then move it from src to dest
    if (n == 1){
        count++;
        std::cout << "Move disk 1 from " << src << " to " << dest << std::endl;
        return;
    }

    // Recursive case

        // Move n-1 disks from src to aux
    hanoiTower(n - 1, src, dest, aux);

        // Move the nth disk from src to dest
    count++;
    std::cout << "Move disk " << n << " from " << PHUCNHAN(src) << " to " << PHUCNHAN(dest) << std::endl;

        // Move n-1 disks from aux to dest
    hanoiTower(n - 1, aux, src, dest);
}

// Drived Code
int main(){

    std::string fileOutput = "/mnt/d/Code space/School/LearningDSA/Recursion/output/HanoiTowerBasic.out";

    std::ofstream out(fileOutput);

    // Store buffer of std::cout
    std::streambuf* originalBuffer = std::cout.rdbuf();

    // Redirect std::cout to fileOutput
    std::cout.rdbuf(out.rdbuf());

    // Test case N = [1 - 10]
    for (int i = 1; i <= 10; i++){
        count = 0;
        std::cout << "N = " << i << std::endl;
        hanoiTower(i, 'A', 'B', 'C');
        std::cout << "Number of steps: " << count << std::endl;
    }

    // Reset std::cout buffer
    std::cout.rdbuf(originalBuffer);
    return 0;
}


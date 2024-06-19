# Theory about Data Structure and Algorithm

## Part 1: Introduction, Recursion and Time Complexity

### Introduction

- Data: Data is fact that has been translated into a form that is more convenient to calculate, analyze.

  - Qualitative data: descriptive information
  - Quantitativedata: numerical information (numbers).
      - Discrete data can only take certain values(like whole numbers)
      - Continuous data can take any value (with in a range)

- Data type: 
        
    - A set of values
    - A set of operations of values

- Data Structure:

    - A combination of elements in which each is either a data type or another data structure
    - A set of associations or relationships (structure) that holds the data together

- Abstract Datatypes:

    - The concept of abstraction:
      - Users know what a data type can do.
      - How it is done is hidden.
    - Definition:
        - An abstract data type is a data declaration packaged together with the operations that are meaningful for the data type.
          1. Declaration of data.
          2. Declaration of operations.
          3. Encapsulation of data and operations.

- Algorithms: The logical steps to solve problems.

```
Program = Data Structures + Algorithms
```

### Recursion

Recursion is a repetitive process in which an algorithm calls it self.

- Direct: A -> A
- Indirect: A -> B -> A

Two main components of a Recursive Algorithm

1. Basecase (i.e. stopping case)
2. Generalcase (i.e. recursive case)

Properties of all recursive algorithms

- A recursive algorithm solves the large problem by using its solution to a simpler subproblem
- Eventually the sub-problem is simple enough that it can be solved without applying the algorithm to it recursively. 

        -> This is called the base case.

Designing recursive algorithms.

- Every recursive call must either solve a part of the problem or reduce the size of the problem.

- Rules for designing a recursive algorithm
    1. Determine the base case (stopping case).
    2. Then determine the general case (recursive case).
    3. Combine the base case and the general cases into an algorithm.

Limitations of Recursion

- Generally, a recursive algorithms runs more slowly than its nonrecursive implementation
- But, the recursive solution shorter and more understandable.

Some basic recursive algorithms:

- Greatest Common Divisor
  gdc(a, 0) = a
  gdc(0, b) = b
  gdc(a, b) = gdc(b, a mod b) // for all a,b > 0

        ```
            function gdc(int a, int b){ // Find greatest common divisor of a and b

                // Base case to stop recursive
                if (b == 0) return a;
                if (a == 0) return b;

                // Recursive
                return gdb(b, a mod b) 
            }
        ```

- Fibonacci Numbers
  fibo[0] = 1
  fibo[1] = 1
  fibo[i] = fibo[i - 1] + fibo[i - 2]  // For all i >= 2

        ```
            function fibo(int n){ \\ Find fibonacci number at index n

                // Base case
                if (n == 0 || n == 1) return 1;

                // Recursive
                return fibo(n - 1) + fibo(n - 2);
            }
        ```

- Ha Noi Tower: 

  - Basic:
    
    [Tiếng việt]
    Cho 3 cây đinh A, B và C và n chiếc đĩa có kích thước khác nhau. Ban đầu, các chiếc đinh được đặt ở cột A, theo thứ tự lớn nhất ở dưới cùng, nhỏ dần khi đến chiếc đĩa cuối cùng.

    Mục tiêu của bài toán là di chuyển toàn bộ chiếc đĩa từ chiếc đinh A sang chiếc đinh C, sử dụng chiếc đinh B làm trung gian, tuân thủ các quy tắc sau:

      - Chỉ có 3 đinh để di chuyển, không có chiếc đinh thứ 4 nào.

      - Một lần chỉ được di chuyển một đĩa, và chỉ được di chuyển chiếc đĩa nằm trên đỉnh của đinh, không được di chuyển đĩa nằm giữa.
            
      - Một đĩa chỉ có thể được đặt lên một đĩa lớn hơn, tuy nhiên không nhất thiết hai đĩa này phải có kích thước liền kề, tức là đĩa nhỏ nhất có thể nằm trên đĩa lớn nhất.

        Mục tiêu là tìm ra trình tự các bước cần thiết để di chuyển toàn bộ các đĩa từ đinh A sang đinh C theo các quy tắc này.

    [English]
    
    Select three pegs: A, B, and C, and n disks of different sizes. Initially, all the disks are placed on peg A in descending order, with the largest disk at the bottom and the smallest at the top.

    The goal of the problem is to move all the disks from peg A to peg C, using peg B as an intermediary, while adhering to the following rules:

      - Only three pegs are available for the moves; no fourth peg is allowed.

      - Only one disk can be moved at a time, and it must be the top disk on a peg.

      - A disk can only be placed on top of a larger disk, although the two disks do not need to be consecutively sized; the smallest disk can be placed on the largest disk.

    The objective is to find the sequence of moves needed to transfer all disks from peg A to peg C following these rules.

        ```
            function HanoiTower(int numberOfDisk, typename source, typename auxiliary, typename destination){

                // Base case
                if (n == 0) return;

                // Recursive 1 
                HanoiTower(n - 1, source, destination, auxiliary);
                print (Move disk `n` from `source` to `destination`);

                // Recursive 2
                HanoiTower(n - 1, auxiliary, destination, source);
            }
        ```

    * Implement in directory: `./Recursion/Problem/HanoiTowerBasic.cpp`

### Time Complexity

#### Computing Runtime

To gure out how long this simple program would actually take to run on a real computer, we would also need to know things like:
  1. Speed of the Computer
  2. The System Architecture
  3. The Compiler Being Used
  4. Details of the Memory Hierarchy

Problem:

  - Figuring out accurate runtime is a huge mess.
  - In practice, you might not even know some of these details.

Goals:

  - Measure runtime without knowing these details.
  - Get results that work for large inputs.

#### Asymptotic Notation

Ideas:

    All of these issues can multiply run times by (large) constant.

    So measure run time in away that ignores constant multiples.

Problem and Solution:

    Unfortunately, 1 second, 1 hour, 1 year only differ by constant multiples.

    => Consider ASYMPTOTIC RUNTIMES. How does runtime scale with input size.

#### Big-O Notation

Given functions `f(n)` and `g(n)`, we say that `f(n)` is `O(g(n))` or $f \preceq O(g)$ if there are positive constants `c` and $n_0$ such that:

$f(n) ≤ c.g(n),\ \forall n ≥ n_0$

  - Using: We will use Big-O notation to report algorithm runtimes. 
        
        This has several advantages:
        
          - Clarifies Growth Rate
          - Cleans up Notation => Makes algebra easier.
          - Can ignore complicated details.

  - Warning: 
    - Using Big-O loses important information about constant multiples.
    - Big-O is only asymptotic.

    - Example:
    
    | Complexity | Name                  | Input (n)            |
    |------------|-----------------------|----------------------|
    | O(1)       | Constant              | Tùy yêu cầu bài toán |
    | O(√n)      | Tuyến tính (Linear)   | 10¹²                 |
    | O(n)       | Tuyến tính (Linear)   | 10⁸                  |
    | O(n log n) | Linearithmic          | 10⁶                  |
    | O(n√n)     |                       | 2 × 10⁵              |
    | O(n²)      | Hàm luỹ thừa bậc 2    | 10⁴                  |
    | O(n³)      | Hàm luỹ thừa bậc 3    | 500                  |
    | O(n⁴)      | Hàm luỹ thừa bậc 4    | 100                  |
    | O(2ⁿ)      | Hàm số mũ             | 20                   |
    | O(n!)      | Giai thừa (Factorial) | 11                   |

#### Others notation:

For functions $ f, g : \mathbb{N} \rightarrow \mathbb{R}^+ $, we say that:

   * $ f(n) = \Omega(g(n)) $ or $ f \succeq g $ if for some $ c $, $ f(n) \geq c \times g(n) $  

  `f` grows no slower than `g`

   * $ f(n) = \Theta(g(n)) $ or $ f \sim g $ if $ f = O(g) $ and $ f = \Omega(g) $ 

  `f` grows as the same rate as `g`

   * $ f(n) = o(g(n)) $ or $ f \prec g $ if $ \frac{f(n)}{g(n)} \rightarrow 0 $ as $ n \rightarrow \infty$  
  
  `f` grows slower than `g`

### P and NP Problem

  - P: Polynomial (can be solved in polynomial time on a deterministic machine).
  - NP: Nondeterministic Polynomial (can be solved in polynomial time on a nondeterministic machine).
    
    [2-Satisfiability (2-SAT) Problem](https://www.geeksforgeeks.org/2-satisfiability-2-sat-problem/)

    [Graph Coloring](https://www.geeksforgeeks.org/graph-coloring-applications/)

    [Traveling Saleman Problem](https://www.geeksforgeeks.org/traveling-salesman-problem-tsp-implementation/)

  - CoNP: stands for the complement of NP Class. It means if the answer to a problem in Co-NP is No, then there is proof that can be checked in polynomial time.

    [Prime Numbers](https://www.geeksforgeeks.org/prime-numbers/)

    [Integer Factorization](https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/)

  - NP-complete: NP and every other problem in NP is polynomially reducible to it.

    [Vertex Cover](https://www.geeksforgeeks.org/proof-that-vertex-cover-is-np-complete/)

  - NP-Hard: An NP-hard problem is at least as hard as the hardest problem in NP and it is a class of problems such that every problem in NP reduces to NP-hard.
    
    [Halting Problem](https://www.geeksforgeeks.org/halting-problem-in-theory-of-computation/)

    [Qualified Boolean formulas](https://en.wikipedia.org/wiki/True_quantified_Boolean_formula)

    |Complexity Class|	Characteristic feature                                                      |
    |----------------|------------------------------------------------------------------------------|
    |   P            |	Easily solvable in polynomial time.                                         |
    |  	NP           |  Yes, answers can be checked in polynomial time.                             |
    |   Co-NP        |	No, answers can be checked in polynomial time.                              |
    |   NP-hard    	 |  All NP-hard problems are not in NP and it takes a long time to check them.  |
    |   NP-complete  |	A problem that is NP and NP-hard is NP-complete.                            |
    

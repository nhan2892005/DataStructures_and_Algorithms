# Theory about Data Structure and Algorithm

## Part 1: Introduction, Recursion and Time Complexity

### Some definition

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

    * Implement in directory: `./Recursion/HanoiTower/Basic`


    - Advance:
        [Tiếng việt]
        Trò chơi tháp Hà Nội là trò chơi nổi tiếng với những chiếc đĩa có kích thước đôi một khác nhau có lỗ nằm ở giữa, nằm xuyên trên ba chiếc cọc A, B, C.

        Trò chơi bắt đầu bằng trạng thái các đĩa được chồng lên nhau ở cọc A, đĩa nhỏ nằm trên đĩa lớn, tức là đĩa nhỏ nhất được nằm trên cùng, tạo ra một dạng hình nón. Yêu cầu của trò chơi là chuyển toàn bộ số đĩa từ cọc A sang cọc C, tuân theo các quy tắc sau:

        Chỉ sử dụng 3 cọc để chuyển.

        Một lần chỉ được di chuyển một đĩa nằm trên cùng từ cọc này sang cọc khác.

        Một đĩa chỉ được đặt lên một đĩa lớn hơn.

        Trong bài toán này, chúng ta sẽ có n chiếc đĩa, đánh số từ 1 đến n theo thứ tự kích thước đĩa tăng dần. Ban đầu, các đĩa nằm rải rác ở ba cọc nhưng vẫn thỏa mãn điều kiện đĩa nhỏ nằm trên đĩa lớn và mục tiêu là chuyển toàn bộ đĩa thành một chồng đĩa ở cọc C.

        Yêu cầu: Cho trạng thái các đĩa nằm ở các cọc, hãy tìm cách chuyển toàn bộ đĩa thành một chồng đĩa ở cọc C.

        ```
        Input:
        Dòng đầu chứa số nguyên dương n.
        Dòng thứ hai chứa một xâu gồm kí tự, kí tự thứ bằng 'A' hoặc 'B' hoặc 'C' cho biết đĩa thứ i nằm ở cọc A hay cọc B hay cọc C.
        ```
        ```
        Output
        Dòng đầu chứa số nguyên là số lần chuyển đĩa.
        Dòng thứ j (j = 1, 2,..., s) trong dòng tiếp theo, mỗi dòng gồm đúng hai kí tự mô tả một thao tác chuyển đĩa. Cụ thể, kí tự thứ nhất là tên cọc chứa đĩa cần chuyển, kí tự thứ hai là tên cọc mà đĩa chuyển tới.
        ```



#include <iostream>
#include <exception>

template <typename PHUCNHAN>
void swap(PHUCNHAN& lhs, PHUCNHAN& rhs) {
    PHUCNHAN temp = lhs;
    lhs = rhs;
    rhs = temp;
}
template <typename PHUCNHAN>
void min(PHUCNHAN lhs, PHUCNHAN rhs){
    return lhs > rhs ? rhs : lhs;
}
template <typename PHUCNHAN>
class UFDS {
    PHUCNHAN *parent, *size;
public:
    int length;
    UFDS(int length = 0):length(length) {
        parent = new PHUCNHAN[length];
        size = new PHUCNHAN[length];
    }
    const UFDS& operator= (const UFDS& rhs) {
        length = rhs.length;
        parent = new PHUCNHAN[rhs.length];
        size = new PHUCNHAN[rhs.length];
        return *this;
    }
    ~UFDS() {
        delete[] parent;
        delete[] size;
    }
    
    // create a set with a node
    void create_set(PHUCNHAN val) {
        parent[val] = val;
        size[val] = 1;
    }

    // find a set and return its root
    PHUCNHAN find_set(PHUCNHAN val){
        return val == parent[val] ? val : parent[val] = find_set(parent[val]);
    }

    // union two sets
    void union_set(PHUCNHAN left_set, PHUCNHAN right_set) {
        right_set = find_set(right_set);
        left_set = find_set(left_set);
        if (right_set != left_set) {
            // optimize union step base on their size
            if (size[left_set] < size[right_set]) swap<PHUCNHAN>(left_set, right_set);
            parent[right_set] = left_set;
            size[left_set] += size[right_set];
        }
    }

    bool isSameSet(PHUCNHAN left_set, PHUCNHAN right_set) {
        return find_set(left_set) == find_set(right_set);
    }

    void display_tree() {
        for (int i = 0; i < length; i++) {
            std::cout << "Parent of " << i << " is " << parent[i] << std::endl;
        }
        std::cout << std::endl;
    }

};

void checkNode(UFDS<int>* Tree, int Node) {
    if (Node >= Tree->length) throw std::out_of_range("Node must be less than length of tree");
    else
    if (Node < 0) throw std::out_of_range("Node must be greater than 0");
}
int main(){
    std::cout << "Menu\n";
    std::cout << "1. Create sets\n";
    std::cout << "2. Union two sets\n";
    std::cout << "3. Find the root of a node\n";
    std::cout << "4. Check if two nodes are in the same set\n";
    std::cout << "5. Quit\n";
    UFDS<int>* ufds = new UFDS<int>;
    do {
        try {
            int option;
            std::cout << "Enter your option: ";
            std::cin >> option;
            switch (option) {
                case 1: {
                    int length;
                    std::cout << "Enter the number of sets: ";
                    std::cin >> length;
                    ufds = new UFDS<int>(length);
                    for (int i = 0; i < length; i++) {
                        ufds->create_set(i);
                    }
                    ufds->display_tree();
                    break;
                }
                case 2: {
                    int left_set, right_set;
                    std::cout << "Enter the left set: ";
                    std::cin >> left_set;
                    checkNode(ufds, left_set);
                    std::cout << "Enter the right set: ";
                    std::cin >> right_set;
                    checkNode(ufds, right_set);
                    ufds->union_set(left_set, right_set);
                    ufds->display_tree();
                    break;
                }
                case 3: {
                    int node;
                    std::cout << "Enter the node: ";
                    std::cin >> node;
                    checkNode(ufds, node);
                    std::cout << "The root of " << node << " is " << ufds->find_set(node) << std::endl;
                    break;
                }
                case 4: {
                    int left_set, right_set;
                    std::cout << "Enter the left set: ";
                    std::cin >> left_set;
                    checkNode(ufds, left_set);
                    std::cout << "Enter the right set: ";
                    std::cin >> right_set;
                    checkNode(ufds, right_set);
                    if (ufds->isSameSet(left_set, right_set)) {
                        std::cout << left_set << " and " << right_set << " are in the same set.\n";
                    } else {
                        std::cout << left_set << " and " << right_set << " are not in the same set.\n";
                    }
                    break;
                }
                case 5: return 0;
                default: {
                    std::cout << "Invalid option. Try again.\n\n";
                    std::cout << "1. Create sets\n";
                    std::cout << "2. Union two sets\n";
                    std::cout << "3. Find the root of a node\n";
                    std::cout << "4. Check if two nodes are in the same set\n";
                    std::cout << "5. Quit\n";
                }
            }
            
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl << std::endl;
        }
    } while (true);

    return 0;
}
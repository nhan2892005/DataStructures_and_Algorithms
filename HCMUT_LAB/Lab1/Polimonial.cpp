#include <iostream>

class Term {
public:
    double coeff;
    int exp;
    Term* next;
    Term(double coeff, int exp) : coeff(coeff), exp(exp), next(nullptr) {}
};

class Polynomial {
private:
    Term* head;

public:
    Polynomial() : head(nullptr) {}

    // Insert a term into the polynomial
    void insertTerm(double coeff, int exp) {
        if (coeff == 0) return; // Skip zero coefficients

        Term* newTerm = new Term(coeff, exp);

        // If the list is empty, or the new term should be the new head
        if (head == nullptr || head->exp < exp) {
            newTerm->next = head;
            head = newTerm;
            return;
        }

        // Traverse the list to find the correct position
        Term* current = head;
        Term* prev = nullptr;
        while (current != nullptr && current->exp >= exp) {
            if (current->exp == exp) {
                // If the exponent matches, combine the terms
                current->coeff += coeff;
                if (current->coeff == 0) {
                    // Remove the term if the coefficient becomes zero
                    if (prev == nullptr) {
                        head = current->next;
                    } else {
                        prev->next = current->next;
                    }
                    delete current;
                }
                return;
            }
            prev = current;
            current = current->next;
        }

        // Insert the new term into the list
        newTerm->next = current;
        prev->next = newTerm;
    }

    // Print the polynomial
    void print() const {
        Term* current = head;
        while (current != nullptr) {
            std::cout << "[Term: (" << current->coeff << " " << current->exp << ")]" << std::endl;
            current = current->next;
        }
    }

    // Destructor to clean up memory
    ~Polynomial() {
        Term* current = head;
        while (current != nullptr) {
            Term* nextTerm = current->next;
            delete current;
            current = nextTerm;
        }
    }
};

// Example usage
int main() {
    Polynomial* poly = new Polynomial();
    poly->insertTerm(6.0, 2);
    poly->insertTerm(4.0, 5);
    poly->insertTerm(4.0, 3);
    poly->insertTerm(6.0, 5);
    poly->insertTerm(-1.0, 0);
    poly->insertTerm(-6.0, 6);
    poly->insertTerm(6.0, 6);
    poly->print();

    int n = 5;
    int coeff[] = { 1, 2, 3, 4, 5 };
    int exp[] = { 1, 2, 3, 4, 5 };
    Polynomial p1;
    for (int i = 0; i < n; ++i) {
        p1.insertTerm(coeff[i], exp[i]);
    }
    p1.print();

    delete poly;
    return 0;
}

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "ListADT.h"
#include "standard.h"
#include <iostream>
#include <exception>
#include <string>

template <typename PHUCNHAN>
class ArrayList : public ListADT<PHUCNHAN> {
private:
    PHUCNHAN* arr;
    int capacity;
    int length;
    PHUCNHAN* none = new PHUCNHAN;
public:
    // ! Constructor
    ArrayList(int capacity = 1) : capacity(capacity), length(0) {
        arr = new PHUCNHAN[capacity];
    }
    ArrayList(const ArrayList& other) {
        if (this == &other) {
            return;
        }
        this->capacity = other.capacity;
        this->length = other.length;
        this->arr = new PHUCNHAN[capacity];
        for (int i = 0; i < length; i++) {
            this->arr[i] = other.arr[i];
        }
    }
    ArrayList& operator=(const ArrayList& other) {
        if (this != &other) {
            this->capacity = other.capacity;
            this->length = other.length;
            delete[] this->arr;
            this->arr = new PHUCNHAN[capacity];
            for (int i = 0; i < length; i++) {
                this->arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    ~ArrayList() {
        delete[] arr;
        delete none;
    }
    PHUCNHAN* none_val() {
        return none;
    }
    std::string toString() const {
        std::string str = "ArrayList {[";
        for (int i = 0; i < length; i++) {
            str += std::to_string(arr[i]) + " ";
        }
        str += "],";
        str += "Length: " + std::to_string(length) + "}";
        return str;
    }

    // ! Operations
    // * Extend capacity
    void extend_capacity(int wide = 1) {
        this->capacity += wide;
        PHUCNHAN* newArr = new PHUCNHAN[capacity];
        for (int i = 0; i < length; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    // * Insertion
    void insert_head(const PHUCNHAN& item) {
        try{
            if (length == capacity) {
                extend_capacity();
            }
            for (int i = length; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = item;
            length++;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        
    }
    void insert_tail(const PHUCNHAN& item) {
        try {
            if (length == capacity) {
                extend_capacity();
            }
            arr[length] = item;
            length++;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
    void insert_at(const PHUCNHAN& item, int pos) {
        try {
            if (pos < 0 || pos > length) {
                throw std::out_of_range("Invalid position");
            }
            if (length == capacity) {
                extend_capacity();
            }
            for (int i = length; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = item;
            length++;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }

    // * Deletion
    void remove_head() {
        try {
            if (length == 0) {
                throw std::out_of_range("List is empty");
            }
            for (int i = 0; i < length - 1; i++) {
                arr[i] = arr[i + 1];
            }
            length--;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
    void remove_tail() {
        try {
            if (length == 0) {
                throw std::out_of_range("List is empty");
            }
            length--;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
    void remove_at(int pos) {
        try {
            if (pos < 0 || pos >= length) {
                throw std::out_of_range("Invalid position");
            }
            for (int i = pos; i < length - 1; i++) {
                arr[i] = arr[i + 1];
            }
            length--;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }

    // * Access
    void clear() {
        length = 0;
        delete[] arr;
        arr = new PHUCNHAN[capacity];
    }
    int size() const {
        return length;
    }

    // * Indexing
    const PHUCNHAN& operator[](int pos) const {
        try {
            if (pos >= length || pos < -length) {
                throw std::out_of_range("Invalid position");
            }
            if (pos < 0) {
                pos = length + pos;
            }
            return arr[pos];
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        return *none;
    }
    PHUCNHAN& operator[](int pos) {
        try {
            if (pos >= length || pos < -length) {
                throw std::out_of_range("Invalid position");
            }
            if (pos < 0) {
                pos = length + pos;
            }
            return arr[pos];
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        return *none;
    }
    const PHUCNHAN& head() const {
        return arr[0];
    }
    const PHUCNHAN& tail() const {
        return arr[length - 1];
    }

    // * Query
    bool isEmpty() const {
        return length == 0;
    }
    const PHUCNHAN& search(const PHUCNHAN& item) const {
        for (int i = 0; i < length; i++) {
            if (arr[i] == item) {
                return arr[i];
            }
        }
        return *none;
    }
    int search_index_firstElement(const PHUCNHAN& item) const {
        for (int i = 0; i < length; i++) {
            if (arr[i] == item) {
                return i;
            }
        }
        return -1;
    }
    int search_index_lastElement(const PHUCNHAN& item) const {
        for (int i = length - 1; i >= 0; i--) {
            if (arr[i] == item) {
                return i;
            }
        }
        return -1;
    }
    ArrayList<int> search_all_index(const PHUCNHAN& item) const {
        ArrayList<int> index;
        for (int i = 0; i < length; i++) {
            if (arr[i] == item) {
                index.insert_tail(i);
            }
        }
        return index;
    }
    // * Sort options:
    // ? 1: Ascending
    // ? 2: Descending
    // * Sort type:
    // ? 1: Quick sort
    // ? 2: Merge sort
    // ? 3: Counting sort
    // ? 4: Radix sort
    // ? 3: Bubble sort
    // ? 4: Selection sort
    // ? 5: Insertion sort
    // ? 6: Shell sort
    void sort(int options = 1, int type = 1, int left = 0, int right = -1) {
        if (right == -1) {
            right = length - 1;
        }
        switch (type) {
            case 1:
                quick_sort(options, left, right);
                break;
            case 2:
                merge_sort();
                if (options == 2) {
                    reverse();
                }
                break;
            case 3:
                counting_sort(options);
                break;
            case 4:
                radix_sort(options);
                break;
            case 5:
                bubble_sort(options);
                break;
            case 6:
                selection_sort(options);
                break;
            case 7:
                insertion_sort(options);
                break;
            case 8:
                shell_sort(options);
                break;
            default:
                break;
        }
    }
    int partition(int options, int left, int right) {
        PHUCNHAN pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (options == 1) {
                if (arr[j] < pivot) {
                    i++;
                    Swap<PHUCNHAN>(arr[i], arr[j]);
                }
            } else {
                if (arr[j] > pivot) {
                    i++;
                    Swap<PHUCNHAN>(arr[i], arr[j]);
                }
            }
        }
        Swap<PHUCNHAN>(arr[i + 1], arr[right]);
        return i + 1;
    }
    void quick_sort(int options = 1, int left = 0, int right = -1) {
        if (right == -1) {
            right = length - 1;
        }
        if (left < right) {
            int pivot = partition(options, left, right);
            quick_sort(options, left, pivot - 1);
            quick_sort(options, pivot + 1, right);
        }
    }
    void merge(int left, int mid, int right) {
        int size_arr_left = mid - left + 1;
        int size_arr_right = right - mid;
        PHUCNHAN* arr_left = new PHUCNHAN[size_arr_left];
        PHUCNHAN* arr_right = new PHUCNHAN[size_arr_right];
        for (int i = 0; i < size_arr_left; i++) {
            arr_left[i] = arr[left + i];
        }
        for (int i = 0; i < size_arr_right; i++) {
            arr_right[i] = arr[mid + 1 + i];
        }
        int i = 0;
        int j = 0;
        int k = left;
        while (i < size_arr_left && j < size_arr_right) {
            if (arr_left[i] <= arr_right[j]) {
                arr[k] = arr_left[i];
                i++;
            } else {
                arr[k] = arr_right[j];
                j++;
            }
            k++;
        }
        while (i < size_arr_left) {
            arr[k] = arr_left[i];
            i++;
            k++;
        }
        while (j < size_arr_right) {
            arr[k] = arr_right[j];
            j++;
            k++;
        }
        delete[] arr_left;
        delete[] arr_right;
    }
    void merge_sort(int left = 0, int right = -1) {
        if (right == -1) {
            right = length - 1;
        }
        if (left < right) {
            int mid = left + (right - left) / 2;
            merge_sort(left, mid);
            merge_sort(mid + 1, right);
            merge(left, mid, right);
        }
    }
    void counting_sort(int options = 1) {
    }
    void radix_sort(int options = 1) {
    }
    void bubble_sort(int options = 1) {
    }
    void selection_sort(int options = 1) {
    }
    void insertion_sort(int options = 1) {
    }
    void shell_sort(int options = 1) {
    }

    // * Print
    void print(int left = 0, int right = size()) const {
        for (int i = left; i < right; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // * Additional
    void reverse(int left = 0, int right = -1) {
        if (right == -1) {
            right = length - 1;
        }
        for (int i = left; i < (left + right + 1) / 2; i++) {
            Swap<PHUCNHAN>(arr[i], arr[right - i]);
        }
    }
    ArrayList<PHUCNHAN> subList(int left = 0, int right = -1) const {
        if (right == -1) {
            right = length;
        }
        ArrayList<PHUCNHAN> sub(right - left);
        for (int i = left; i < right; i++) {
            sub.insert_tail(arr[i]);
        }
        return sub;
    }
    const PHUCNHAN& min_element(int left = 0, int right = -1) const {
        if (right == -1) {
            right = length;
        }
        PHUCNHAN* min = &arr[left];
        for (int i = left + 1; i < right; i++) {
            if (arr[i] < *min) {
                min = &arr[i];
            }
        }
        return *min;
    }
    const PHUCNHAN& max_element(int left = 0, int right = -1) const {
        if (right == -1) {
            right = length;
        }
        PHUCNHAN* max = &arr[left];
        for (int i = left + 1; i < right; i++) {
            if (arr[i] > *max) {
                max = &arr[i];
            }
        }
        return *max;
    }
    int sum(int left = 0, int right = -1) const {
        if (right == -1) {
            right = length;
        }
        int sum = 0;
        for (int i = left; i < right; i++) {
            sum += arr[i];
        }
        return sum;
    }
    int average(int left = 0, int right = -1) {
        if (right == -1) {
            right = length;
        }
        if (right == -1) {
            right = length;
        }
        return sum(left, right) / (right - left);
    }
};

#endif // ARRAYLIST_H
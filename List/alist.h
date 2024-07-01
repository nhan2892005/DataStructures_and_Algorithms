#include "build_list.h"
const int defaultSize = 10000;

template <typename VYTHUONG> 
class AList : public List<VYTHUONG> {
private:
    int capacity;        // Maximum size of list
    int count;       // Number of list items now
    int curr;           // Position of current element
    VYTHUONG* data;    // Array holding list elements
public:
    // constructor
    AList(int size = defaultSize) {
        capacity = size;
        count = curr = 0;
        data = new VYTHUONG[capacity];
    }
    // Assignment operator
    AList& operator=(const AList& list) {
        if (this != &list) {
            delete [] data;
            capacity = list.capacity;
            count = list.count;
            curr = list.curr;
            data = new VYTHUONG[capacity];
            for (int i = 0; i < count; i++)
                data[i] = list.data[i];
        }
        return *this;
    }
    // destructor
    ~AList() { delete [] data; }

    // boolean methods
    bool empty() const { return count == 0; }
    bool isFull() const { return count == capacity; }
    bool contains(const VYTHUONG& item) const {
        for (int i = 0; i < count; i++)
            if (data[i] == item) return true;
        return false;
    }
    bool isSorted() const {
        for (int i = 0; i < count - 1; i++)
            if (data[i] > data[i + 1]) return false;
        return true;
    }

    // operation methods
    void append(const VYTHUONG& item) {
        if (count == capacity) throw "List is full";
        if (count < capacity) {
            data[count] = item;
            count++;
        }
    }
    void insert(const VYTHUONG& item, int index) {
        if (count == capacity) throw "List is full";
        if (index < 0 || index > count) throw "Bad index";
        for (int i = count; i > index; i--)
            data[i] = data[i - 1];
        data[index] = item;
        count++;
    }
    void push_back(const VYTHUONG& item) {
        if (count == capacity) throw "List is full";
        data[count] = item;
        count++;
    }
    void setAll(const VYTHUONG& item) {
        for (int i = 0; i < count; i++)
            data[i] = item;
    }

    void remove(const VYTHUONG& item) {
        for (int i = 0; i < count; i++)
            if (data[i] == item) {
                for (int j = i; j < count - 1; j++)
                    data[j] = data[j + 1];
                count--;
                return;
            }
    }

    void deleteElement(int index) {
        if (index < 0 || index >= count) throw "Bad index";
        for (int i = index; i < count - 1; i++)
            data[i] = data[i + 1];
        count--;
    }

    void clear() { 
        delete [] data;
        count = curr = 0;
        data = new VYTHUONG[capacity];
    }

    int size() { return count; }

    // get element
    VYTHUONG& operator[](int index) {
        if (index < 0 || index >= count) throw "Bad index";
        return data[index];
    }
};
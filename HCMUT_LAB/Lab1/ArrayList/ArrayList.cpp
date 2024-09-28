/*
Implement methods ensureCapacity, add, size in template class ArrayList representing the array list with type T with the initialized frame. The description of each method is given in the code.

template <class T>
class ArrayList {
protected:
    T* data;        // dynamic array to store the list's items
    int capacity;   // size of the dynamic array
    int count;      // number of items stored in the array
public:
    ArrayList(){capacity = 5; count = 0; data = new T[5];}
    ~ArrayList(){ delete[] data; }
    void    add(T e);
    void    add(int index, T e);
    int     size();
    void    ensureCapacity(int index);
};


For example:

Test	                                            Result
ArrayList<int> arr;                                 [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
int size = 10;                                      10

for(int index = 0; index < size; index++){
    arr.add(index);
}

cout << arr.toString() << '\n';
cout << arr.size();
------------------------------------------------------------------------------------------------
ArrayList<int> arr;                                  [19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
int size = 20;                                       20

for(int index = 0; index < size; index++){
    arr.add(0, index);
}

cout << arr.toString() << '\n';
cout << arr.size() << '\n';
arr.ensureCapacity(5);
*/

/*
Implement methods removeAt, removeItem, clear in template class ArrayList representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.

template <class T>
class ArrayList {
protected:
T* data; // dynamic array to store the list's items
int capacity; // size of the dynamic array
int count; // number of items stored in the array

public:
    ArrayList(){capacity = 5; count = 0; data = new T[5];}
   ~ArrayList(){ delete[] data; }    
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
    void    ensureCapacity(int index);
};
*/

/*
Implement methods Get, set, clear, empty, indexOf, contains in template class ArrayList representing the array list with type T with the initialized frame. The description of each method is given in the code.

template <class T>
class ArrayList {
protected:
    T* data;        // dynamic array to store the list's items
    int capacity;   // size of the dynamic array
    int count;      // number of items stored in the array
public:
    
 ArrayList(){capacity = 5; count = 0; data = new T[5];}
   ~ArrayList(){ delete[] data; }    
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    void    clear();  //remove data and set the list to the initial condition
    T       get(int index);  //get the element at the index, if the index is out of range, "throw std::out_of_range("index is out of range");"
    void    set(int index, T e);  //set the index position in the list with the value e 
    int     indexOf(T item);  //get the first index of item in the list, else return -1
    bool    contains(T item);   //check if the item is in the list
    T       removeAt(int index);
    bool    removeItem(T item);
 
};
Notice: You just have to implement the methods: set, get, clear, empty, indexOf, contains. Other methods have been implemented already.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
class ArrayList {
protected:
    T* data;        // dynamic array to store the list's items
    int capacity;   // size of the dynamic array
    int count;      // number of items stored in the array
public:
    ArrayList(){capacity = 5; count = 0; data = new T[5];}
    ~ArrayList(){ delete[] data; }
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
    void    ensureCapacity(int index);
    string  toString(){
        stringstream ss;
        ss << "[";
        for(int i = 0; i < count; i++){
            ss << data[i];
            if(i < count - 1){
                ss << ", ";
            }
        }
        ss << "]";
        return ss.str();
    }
};

/*
For exercise 1
*/

template<class T>
void ArrayList<T>::ensureCapacity(int cap) {
    if (cap > capacity) {
        int new_capacity = std::max(cap, static_cast<int>(capacity * 1.5));
        T* new_data = new T[new_capacity];

        std::copy(data, data + count, new_data);

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
}

template<class T>
void ArrayList<T>::add(T e) {
    ensureCapacity(count + 1);
    data[count] = e;
    count++;
}

template<class T>
void ArrayList<T>::add(int index, T e) {
    if (index < 0 || index > count) {
        throw std::out_of_range("Index is out of range!");
    }

    ensureCapacity(count + 1);

    for (int i = count; i > index; --i) {
        data[i] = data[i - 1];
    }

    data[index] = e;
    count++;
}

template<class T>
int ArrayList<T>::size() {
    return count;
}

// For exercise 2

template<class T>
T ArrayList<T>::removeAt(int index) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("index is out of range");
    }
    T removedValue = data[index];
    for (int i = index; i < count - 1; i++) {
        data[i] = data[i + 1];
    }
    count--; 
    return removedValue;
}

template<class T>
bool ArrayList<T>::removeItem(T item) {
    for (int i = 0; i < count; i++) {
        if (data[i] == item) {
            removeAt(i); 
            return true;
        }
    }
    return false; 
}


template<class T>
void ArrayList<T>::clear() {
    if (data != nullptr) {
        delete[] data;
    }
    capacity = 5;
    count = 0;
    data = new T[capacity]; 
}

// For exercise 3

template <class T>
bool ArrayList<T>::empty() {
    return count == 0;
}

template <class T>
void ArrayList<T>::clear() {
    delete[] data;
    capacity = 5;
    count = 0;
    data = new T[capacity]; 
}

template <class T>
T ArrayList<T>::get(int index) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index is out of range");
    }
    return data[index];
}

template <class T>
void ArrayList<T>::set(int index, T e) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index is out of range");
    }
    data[index] = e;
}

template <class T>
int ArrayList<T>::indexOf(T item) {
    for (int i = 0; i < count; i++) {
        if (data[i] == item) {
            return i; 
        }
    }
    return -1;
}

template <class T>
bool ArrayList<T>::contains(T item) {
    return indexOf(item) != -1; 
}

int main() {
    ArrayList<int> arr;
    int size = 10;

    for (int index = 0; index < size; index++) {
        arr.add(index);
    }

    cout << arr.toString() << '\n';
    cout << arr.size();

    return 0;
}
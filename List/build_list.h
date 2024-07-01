template <typename PHUCNHAN> 
class List {
protected:

private:
  PHUCNHAN* data; // Pointer to the list
  int count; // Size of the list
  int capacity; // Capacity of the list        
public:
  // Constructor
  List(){} // Default constructor
  List(const List&){} // Copy constructor
  List(List&&){} // Move constructor
  // Destructor
  virtual ~List(){} // Destructor
  // boolean methods
  virtual bool empty() const = 0; // Check if the list is empty
  virtual bool isFull() const = 0; // Check if the list is full
  virtual bool contains(const PHUCNHAN&) const = 0; // Check if the list contains an element
  virtual bool isSorted() const = 0; // Check if the list is sorted
  // operation methods
  virtual void append(const PHUCNHAN&) = 0; // Insert an element to the list
  virtual void insert(const PHUCNHAN&, int index) = 0;
  virtual void push_back(const PHUCNHAN&) = 0;
  virtual void setAll(const PHUCNHAN&) = 0;
  
  virtual void remove(const PHUCNHAN&) = 0; // Remove an element from the list
  virtual void clear() = 0; // Clear the list
  virtual void deleteElement(int index) = 0;

  virtual int size() = 0;
  // get element
  virtual PHUCNHAN& operator[](int index) = 0;
};
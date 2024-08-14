#ifndef List_ADT
#define List_ADT

template <typename PHUCNHAN>
class ListADT {
    private:
    ListADT(const ListADT& other) {} // * Copy constructor
    ListADT& operator=(const ListADT& other) {} // * Assignment operator

    protected:

    public:
    // ! Constructor
    ListADT() {}
    virtual ~ListADT() {}

    // ! Operations
    // * Insertion
    virtual void insert_head(const PHUCNHAN& item) = 0;
    virtual void insert_tail(const PHUCNHAN& item) = 0;
    virtual void insert_at(const PHUCNHAN& item, int pos) = 0;

    // * Deletion
    virtual void remove_head() = 0;
    virtual void remove_tail() = 0;
    virtual void remove_at(int pos) = 0;
    
    // * Access
    virtual void clear() = 0;
    virtual int size() const = 0;

    // * Indexing
    virtual const PHUCNHAN& operator[](int pos) const = 0;
    virtual const PHUCNHAN& head() const = 0;
    virtual const PHUCNHAN& tail() const = 0;

    // * Query
    virtual bool isEmpty() const = 0;
    virtual const PHUCNHAN& search(const PHUCNHAN& item) const = 0;
    virtual void sort(int options=0, int type=0, int left=0, int right=0) = 0;

    // * Print
    virtual void print(int left, int right) const = 0;
};

#endif
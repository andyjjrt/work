class Array{
public:
    Array();
    ~Array();
    void insert(int val);
    int search(int val);
private:
    int capacity;
    int size;
    int* arr;
};

class HashTablePlus{
public:
    // Constructor
    HashTablePlus(int n);

    // Destructor
    ~HashTablePlus();

    // Insert a val to HashTable
    void insert(int val);

    // Search val is in HashTable or not
    int search(int val);
private:
    // Hash function;
    int hash(int val);

    Array **hashtable;
    int size;

};
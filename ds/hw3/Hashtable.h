#include <list>

class HashTable{
public:
    // Constructor
    HashTable(int n);

    // Destructor
    ~HashTable();

    // Insert a val to HashTable
    void insert(int val);

    // Search val is in HashTable or not
    int search(int val);
private:
    // Hash function;
    int hash(int val);

    std::list<int> *hashtable;
    int size;
};
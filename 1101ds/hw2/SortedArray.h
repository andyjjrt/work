using namespace std;

class SortedArray{
public:

    // Construtor
    SortedArray(int max_length);

    // Destructor
    ~SortedArray();

    // Insert value into the sorted array
    void insert(int value);

    // Print the sorted array
    void print();

    // Search in the sorted array (Public interface)
    int search(int value);
private:
    int* array;
    int MAX_LENGTH;
    int length;

    // Recursive function of search
    int search_(int low, int high, int key);
};
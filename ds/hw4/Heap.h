#include <vector>

class Heap{
public:
    Heap() { heap.resize(1); }
    Heap(int n) { heap.resize(n + 1); }
    void BuildMinHeap(std::vector<double> array);
    double ExtractMin();
    void DecreaseKey(int index, double newKey);
    bool IsHeapEmpty() { return (heap.size() < 1); }
private:
    std::vector<std::pair<int, double>> heap;
    void swap(std::pair<int, double> &p1, std::pair<int, double> &p2);
    int FindPosition(int node);
    void MinHeapify(int node, int length);
};
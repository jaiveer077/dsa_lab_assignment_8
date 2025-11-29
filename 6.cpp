#include <iostream>
using namespace std;
class PriorityQueue
{
    int heap[100];
    int size;
    void heapifyDown(int i)
    {
        int largest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;
        if (largest != i)
        {
            int t = heap[i];
            heap[i] = heap[largest];
            heap[largest] = t;
            heapifyDown(largest);
        }
    }
    void heapifyUp(int i)
    {
        int p = (i - 1) / 2;
        while (i > 0 && heap[p] < heap[i])
        {
            int t = heap[p];
            heap[p] = heap[i];
            heap[i] = t;
            i = p;
            p = (i - 1) / 2;
        }
    }

public:
    PriorityQueue() { size = 0; }
    void insert(int v)
    {
        heap[size] = v;
        heapifyUp(size);
        size++;
    }
    int getMax()
    {
        if (size == 0)
            return -1;
        return heap[0];
    }
    int extractMax()
    {
        if (size == 0)
            return -1;
        int m = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return m;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};
int main()
{
    PriorityQueue pq;
    pq.insert(30);
    pq.insert(10);
    pq.insert(50);
    pq.insert(40);
    pq.insert(20);
    pq.display();
    cout << pq.getMax() << endl;
    cout << pq.extractMax() << endl;
    pq.display();
}
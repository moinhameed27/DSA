/*
Queues are a type of container adaptors that operate in a first in first out (FIFO) type of arrangement. Elements are inserted at 
the back (end) and are deleted from the front.
*/

#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    int capacity;
    T *data;
    int front;
    int rear;
    int numOfElements;
    void reSize(int);

public:
    Queue();
    Queue(const Queue<T> &);
    Queue<T>& operator=(const Queue<T> &);
    ~Queue();

    void enqueue(T);
    T dequeue();
    T queueFront();
    T queueRear();
    bool isFull();
    bool isEmpty();
    int getCapacity();
    int getNumberOfElements();
};

template<typename T>
Queue<T>::Queue()
{
    data = nullptr;
    capacity = front = rear = numOfElements = 0;
}

template<typename T>
Queue<T>::Queue(const Queue &other)
{
    capacity = other.capacity;
    front = other.front;
    rear = other.rear;
    numOfElements = other.numOfElements;
    data = new T[capacity];
    for (int i = 0; i < capacity; i++)
        data[i] = other.data[i];
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T> &other)
{
    if (this == &other)
        return *this;

    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
    }

    capacity = other.capacity;
    front = other.front;
    rear = other.rear;
    numOfElements = other.numOfElements;
    data = new T[capacity];
    for (int i = 0; i < capacity; i++)
        data[i] = other.data[i];

    return *this;
}

template<typename T>
Queue<T>::~Queue()
{
    if (!data)
        return;

    delete[] data;
    data = nullptr;
    capacity = front = rear = numOfElements = 0;
}

template<typename T>
void Queue<T>::reSize(int newSize)
{
    T *temp = new T[newSize];
    for (int i = 0; i < numOfElements; i++)
        temp[i] = data[(front + i) % capacity];

    delete[] data;
    capacity = newSize;
    data = temp;
    front = 0;
    rear = numOfElements;
}

template<typename T>
void Queue<T>::enqueue(T val)
{
    if (isFull())
        reSize(capacity == 0 ? 1 : capacity * 2);

    data[rear] = val;
    rear = (rear + 1) % capacity;
    numOfElements++;
}

template<typename T>
T Queue<T>::dequeue()
{
    if (isEmpty())
        exit(0);

    T val = data[front];
    front = (front + 1) % capacity;
    numOfElements--;

    if (numOfElements > 0 && numOfElements == capacity / 4)
        reSize(capacity / 2);

    return val;
}

template<typename T>
T Queue<T>::queueFront()
{
    if (isEmpty())
        exit(0);
    return data[front];
}

template<typename T>
T Queue<T>::queueRear()
{
    if (isEmpty())
        exit(0);
    return data[(rear - 1 + capacity) % capacity];
}

template<typename T>
bool Queue<T>::isFull()
{
    return numOfElements == capacity;
}

template<typename T>
bool Queue<T>::isEmpty()
{
    return numOfElements == 0;
}

template<typename T>
int Queue<T>::getCapacity() { return capacity; }

template<typename T>
int Queue<T>::getNumberOfElements() { return numOfElements; }

int main()
{
    Queue<int> q;
    cout << "---------Enqueueing Elements---------" << endl;
    for (int i = 1; i <= 12; i++)
    {
        q.enqueue(i);
        if(q.isFull())
            cout << "isFull : true" << endl;
        cout << "Capacity : " << q.getCapacity() << endl;
        cout << "Number of Elements : " << q.getNumberOfElements() << endl;
        cout << "Front of Queue : " << q.queueFront() << endl;
        cout << "Rear of Queue : " << q.queueRear() << endl;
        cout << endl;
    }

    cout << "---------Dequeuing Elements---------" << endl;
    while (!q.isEmpty())
    {
        cout << q.dequeue() << endl;
        cout << "Capacity : " << q.getCapacity() << endl;
        cout << "Number of Elements : " << q.getNumberOfElements() << endl;
        if (!q.isEmpty())
        {
            cout << "Front of Queue : " << q.queueFront() << endl;
            cout << "Rear of Queue : " << q.queueRear() << endl;
        }
        cout << endl;
    }

    return 0;
}

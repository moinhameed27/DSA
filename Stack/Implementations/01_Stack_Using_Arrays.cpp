/*
Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, where a new element is added at one 
end (top) and an element is removed from that end only. 
*/

#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    int capacity;
    T *data;
    int top;
    void reSize(int);

public:
    Stack();
    Stack(const Stack<T> &);
    Stack<T>& operator=(const Stack<T> &);
    ~Stack();

    void push(T);
    T pop();
    T stackTop();
    bool isFull();
    bool isEmpty();
    int getCapacity();
    int getNumberOfElements();
};

template<typename T>
Stack<T>::Stack()
{
    capacity = 0;
    data = nullptr;
    top = 0;
}

template<typename T>
Stack<T>::Stack(const Stack &other)
{
    capacity = other.capacity;
    top = other.top;
    data = new T[capacity];
    for (int i = 0; i < top; i++)
        data[i] = other.data[i];
}

template<typename T>
Stack<T>& Stack<T> ::operator=(const Stack<T> &other)
{
    if (this == &other)
        return *this;

    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
    }

    capacity = other.capacity;
    top = other.top;
    data = new T[capacity];
    for (int i = 0; i < top; i++)
        data[i] = other.data[i];

    return *this;
}

template<typename T>
Stack<T> ::~Stack()
{
    if (!data)
        return;

    delete[] data;
    data = nullptr;
    capacity = 0;
    top = 0;
}

template<typename T>
void Stack<T> ::reSize(int newSize)
{
    T *temp = new T[newSize];
    for (int i = 0; i < top; i++)
        temp[i] = data[i];

    delete[] data;
    capacity = newSize;
    data = new T[capacity];
    data = temp;
}

template<typename T>
void Stack<T>::push(T val)
{
    if (isFull())
        reSize(capacity == 0 ? 1 : capacity * 2);
    data[top++] = val;
}

template<typename T>
T Stack<T>::pop()
{
    if (isEmpty())
        exit(0);

    int val = data[--top];
    if (top > 0 && top == capacity / 4)
        reSize(capacity / 2);

    return val;
}

template<typename T>
T Stack<T>::stackTop()
{
    if (isEmpty())
        exit(0);
    return data[top - 1];
}

template<typename T>
bool Stack<T>::isFull()
{
    return top == capacity;
}

template<typename T>
bool Stack<T>::isEmpty()
{
    return top == 0;
}

template<typename T>
int Stack<T>::getCapacity() { return capacity; }

template<typename T>
int Stack<T>::getNumberOfElements() { return top; }

int main()
{
    Stack<int> s;
    cout << "---------Pushing Elements---------" << endl;
    for (size_t i = 1; i <= 12; i++)
    {
        s.push(i);
        if(s.isFull())
            cout << "isFull : true" << endl;
        cout << "Capacity : " << s.getCapacity() << endl;
        cout << "Number of Elements : " << s.getNumberOfElements() << endl;
        cout << "Top of Stack : " << s.stackTop() << endl;
        cout << endl;
    }

    cout << "---------Popping Elements---------" << endl;
    while (!s.isEmpty())
    {
        cout << s.pop() << endl;
        cout << "Capacity : " << s.getCapacity() << endl;
        cout << "Number of Elements : " << s.getNumberOfElements() << endl;
        cout << "Top of Stack : " << s.stackTop() << endl;
        cout << endl;
    }

    return 0;
}
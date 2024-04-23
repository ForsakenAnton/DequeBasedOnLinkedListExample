#include <iostream>
using namespace std;

template <typename T>
struct Node 
{
    T data;
    Node* next;
    Node* prev;
    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Deque
{
private:
    Node<T>* front; // Перший елемент черги
    Node<T>* rear;  // Останній елемент черги

public:
    Deque() : front(nullptr), rear(nullptr) 
    {
    }

    ~Deque() 
    {
        while (!isEmpty()) 
        {
            dequeueFront();
        }
    }

    bool isEmpty() const 
    {
        return front == nullptr;
    }

    void enqueueFront(const T& value) 
    {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else 
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void enqueueRear(const T& value) 
    {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) 
        {
            front = rear = newNode;
        }
        else 
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void dequeueFront() 
    {
        if (isEmpty()) 
        {
            cerr << "Deque is empty. Cannot dequeue from front." << endl;

            return;
        }

        Node<T>* temp = front;
        front = front->next;
        if (front != nullptr) 
        {
            front->prev = nullptr;
        }
        else 
        {
            rear = nullptr;
        }

        delete temp;
    }

    void dequeueRear() 
    {
        if (isEmpty()) 
        {
            cerr << "Deque is empty. Cannot dequeue from rear." << endl;

            return;
        }
        Node<T>* temp = rear;
        rear = rear->prev;
        if (rear != nullptr) 
        {
            rear->next = nullptr;
        }
        else 
        {
            front = nullptr;
        }
        delete temp;
    }

    T& peekFront() const 
    {
        if (isEmpty()) 
        {
            cerr << "Deque is empty." << endl;
            
            static T dummy;

            return dummy;
        }

        return front->data;
    }

    T& peekRear() const 
    {
        if (isEmpty()) 
        {
            cerr << "Deque is empty." << endl;

            static T dummy;

            return dummy;
        }

        return rear->data;
    }

    void display() const 
    {
        if (isEmpty()) 
        {
            cout << "Deque is empty." << endl;
            return;
        }

        Node<T>* current = front;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() 
{
    Deque<int> myDeque;

    myDeque.enqueueFront(1);
    myDeque.enqueueFront(2);
    myDeque.enqueueRear(3);

    cout << "Front of the deque: " << myDeque.peekFront() << endl;
    cout << "Rear of the deque: " << myDeque.peekRear() << endl;

    cout << "Deque elements: ";
    myDeque.display();

    myDeque.dequeueFront();
    cout << "After dequeue from front:" << endl;
    cout << "Front of the deque: " << myDeque.peekFront() << endl;
    cout << "Deque elements: ";
    myDeque.display();

    myDeque.dequeueRear();
    cout << "After dequeue from rear:" << endl;
    cout << "Rear of the deque: " << myDeque.peekRear() << endl;
    cout << "Deque elements: ";
    myDeque.display();

    return 0;
}

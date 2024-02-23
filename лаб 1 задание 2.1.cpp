#include <iostream>
using namespace std;

struct Node {
public:
    double val;
    Node* next;
    Node(double value) {
        val = value;
        next = nullptr;
    }
};

struct turn {
    int Size = 0;
    Node* first;

    turn() {
        first = nullptr;
    }
    bool is_empty() {
        return first == nullptr;
    }

    void enqueue(double value) {
        if (first == nullptr) {
            first = new Node(value);
        }
        else {
            Node* current = first;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(value);
           
        }
            Size++;
    }
    void dequeue() {
        Node* current = first;
        first = first->next;
        delete current;


         Size--;
    }
    void print() {
        if (is_empty() == true) {
            first = nullptr;
        }
        Node* current = first;
        while (current) {
            cout << current->val << " " << endl;
            current = current->next;
        }
        cout << endl;

    }
    int GetSize() {
        return Size;
    }
    Node* operator[] (const int index) {
        Node* current = first;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }
};
int main() {
    setlocale(LC_ALL, "RU");
    turn l;
    l.enqueue(2.1);
    l.enqueue(2.1);
    l.enqueue(5.3);
    cout << "Первый вызов" << endl;
    l.print();
    l.dequeue();
    l.enqueue(4.9);
    cout << "Второй вызов" << endl;
    l.print();
    double res = 0;
    for (int i = 0; i < l.GetSize(); i++) {
        res += l[i]->val;
    }
    cout << "Сумма: " << res;
}
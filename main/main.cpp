#include <iostream>

using  namespace std;

template <typename G>
struct Nodo {
    G dato;
    Nodo* next;
    explicit Nodo(G _dato) : dato(_dato), next(nullptr) {
    }
};
template <typename T>
class Lista {
private:
    Nodo<T>* head;
public:
    explicit Lista(Nodo<T>* _head):head(_head) {}
    T front() {
        return head->dato;
    } // Retorna el elemento al comienzo
    T back() {
        Nodo<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->dato;

    } // Retorna el elemento al final
    void push_front(T elemento) {
        auto* new_node = new Nodo<T>(elemento);
        new_node->next = head;
        head = new_node;

    } // Agrega un elemento al comienzo
    void push_back(T elemento) {
        auto* new_node = new Nodo<T>(elemento);
        Nodo<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    } // Agrega un elemento al final
    void pop_front() {
        Nodo<T>* temp = head;
        head = head->next;
        delete temp;
    } // Remueve el elemento al comienzo
    void pop_back() {
        if (head->next == nullptr) {
            delete head;
        }else {
            Nodo<T>* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }

    } // Remueve el elemento final

};

int main() {
    auto* head = new Nodo(5);
    Lista<int> lista1 = Lista(head);
    lista1.push_back(10);
    lista1.push_back(15);
    lista1.push_front(20);
    lista1.pop_front();
    lista1.pop_back();
    cout << lista1.front() << endl;
    cout << lista1.back() << endl;

    return 0;
}
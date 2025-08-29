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
        Nodo<T>* new_node = new Nodo<T>(elemento);
        new_node->next = head;
        head = new_node;

    } // Agrega un elemento al comienzo
    void push_back(T elemento) {
        Nodo<T>* new_node = new Nodo<T>(elemento);
        Nodo<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    } // Agrega un elemento al final
    T pop_front() {

    } // Remueve el elemento al comienzo
    T pop_back() {

    } // Remueve el elemento final

};

int main() {
    Nodo<int>* head = new Nodo(5);
    Lista<int> lista1 = Lista(head);
    lista1.push_back(10);
    lista1.push_back(15);
    cout << lista1.front() << endl;
    cout << lista1.back() << endl;

    return 0;
}
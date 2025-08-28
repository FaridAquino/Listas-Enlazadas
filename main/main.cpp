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
        while (temp-> next != nullptr) {
            temp = temp->next;
        }
        return temp->dato;

    } // Retorna el elemento al final
    void push_front(T) {

    } // Agrega un elemento al comienzo
    void push_back(T); // Agrega un elemento al final
    T pop_front(); // Remueve el elemento al comienzo
    T pop_back(); // Remueve el elemento final

};

int main() {
    Nodo<int> head = Nodo(5);
    Lista lista1 = Lista(&head);

    return 0;
}
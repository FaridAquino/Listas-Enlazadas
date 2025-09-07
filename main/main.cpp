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
    ~Lista() { clear(); }
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

    T& operator [] (int indice) {
        int contador=0;
        Nodo<T>* p1=head;

        while (contador!=indice and p1!=nullptr) {
            p1=p1->next;
            contador++;
        }

        if (p1==nullptr) {
            throw std::out_of_range("Indice fuera de rango");
        }

        return p1->dato;
    }
      
	//verificar si una lista esta vacia o no
    bool empty(){
        if (head == NULL){
            return true;
        }else{
            return false;
        }
    }

    //retornar tamaño de la lista
    int size(){
        Nodo<T>* temp = head;
        int N = 0;
        while(temp != NULL){
            N++;
            temp = temp->next;
        }
        return N;
    }

    //eliminar todos los nodos de la lista
    void clear(){
        while(head != NULL){
            Nodo<T>* temp = head;
            head = head->next;
            delete temp;
        }
        head = NULL;
    }

    //funcion de ordenamiento (insertion sort)
    void sort() {
        if (!head || !head->next) return;
        Nodo<T> dummy(T{});
        dummy.next = head;

        Nodo<T>* ord  = head;
        Nodo<T>* temp = head->next;

        while (temp != nullptr) {
            if (ord->dato <= temp->dato) {
                ord = temp;
                temp = temp->next;
            } else {
                Nodo<T>* prev = &dummy;
                while (prev->next != nullptr && prev->next->dato <= temp->dato) {
                    prev = prev->next;
                }
                ord->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
                temp = ord->next;
            }
        }
        head = dummy.next;
    }

    // invertir lista
    void reverse() {
        Nodo<T>* cab = nullptr;
        Nodo<T>* temp = head;

        while (temp != nullptr) {
            Nodo<T>* forward = temp->next;
            temp->next = cab;
            cab = temp;
            temp = forward;
        }
        head = cab;
    }

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

#include <iostream>

struct Nodo {
    int dato;
    Nodo* next;
};
template <typename T>
class Lista {
private:
    Nodo* head;
public:
    explicit Lista(Nodo* _head):head(_head) {}


};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
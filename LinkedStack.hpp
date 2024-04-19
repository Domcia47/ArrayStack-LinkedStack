#ifndef LINKEDSTACK_HPP // include guard
#define LINKEDSTACK_HPP

#include <stdexcept>
template <typename T>
class LinkedStack {
public:
    LinkedStack(); //kostruktor
    void push(T x); //wstawia na stos
    T pop(); //zdejmuje ze stosu
    int size(); //zwraca rozmiar
    bool empty(); //sprawdza czy stos jest pusty
    T check(); //zwraca element z wierzchu stosu

private:
    //struktura odpowiedzialana za tworzenie węzłów
    struct Node {
        T val; //wartość przechoywana w węźle
        Node* next; //wskaźnik na kolejny węzeł
        Node(T val) : val(val), next(nullptr) {}//konstruktor, który przyjmuje jako argument wartość dla nowego węzła
    };

    Node* top;//wskaźnik na ostatni węzeł
    int elem_num;//liczba elementów na stosie
};

//IMPLEMENTACJE

template <typename T>
LinkedStack<T>::LinkedStack() : top(nullptr), elem_num(0) {}//konstruktor tworzący nowy stos, brak elementów top ustawiony na nullptr

template <typename T>
void LinkedStack<T>::push(T val) {
    Node* newNode = new Node(val);//dynamiczne tworzenie nowego węzła przechowującego wartość val
    if (top == nullptr) {//jeśli stos nie miał elementów nowy węzęł staje się topem
        top = newNode;
        elem_num++; //zwiększ liczbę elementów na stosie
    } else {
        newNode->next = top;//ustawienia wskaźnika next nowego węzła na adres poprzedniego topu
        top = newNode;//adres nowego węzła staje się nowym topem
        elem_num++;//zwiększ liczbę elementów na stosie
    }
}

template <typename T>
T LinkedStack<T>::pop() {
    if (top != nullptr) {//sprawdza czy stos nie jest pusty
        T value = top->val;//przypisanie wartości przechowywanej w węźle wskazywanym przez top do zmiennej value
        top = top->next;//przepięcie wskaźnika top na niższy element stosu
        elem_num--;//zmniejsz liczbę elementow na stosie
        return value;//zwrócenie wartości
        
    }
    throw std::out_of_range("Cannot pop from empty stack");
}

template <typename T>
int LinkedStack<T>::size() {
    return elem_num;//zwróć liczbę elementów
}

template <typename T>
bool LinkedStack<T>::empty() {
    return size() == 0;//jeśli liczb elementów 0 to stos jest pusty
}

template <typename T>
T LinkedStack<T>::check() {
    if (top != nullptr) {
        return top->val; //zwróć wartość elementu wskazywanego przez top
    }
    throw std::out_of_range("Cannot check value on empty stack");
}
#endif

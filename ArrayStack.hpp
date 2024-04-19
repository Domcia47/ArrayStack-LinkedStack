#ifndef ARRAYSTACK_HPP // include guard
#define ARRAYSTACK_HPP

#include <stdexcept>

template <typename T>
class ArrayStack {
public:
    ArrayStack(int capacity);//konstruktor przyjmujący głębokość stosu
    ArrayStack();//konstuktor bezargumentowy
    //funkcja dodająca element na stos
    void push(T value) {
        if (top == capacity) {//stos ma już maksymalną ilośc elementów, zwróć błąd
            throw std::out_of_range("ArrayStack overflow");
        }
        data[top] = value;//przpisz tablicy wartość w komórce o indeksie top
        top++;//zwiększ top
        
    }
    T pop() {
        if (top == 0) {//stos jest pusty, nie można nic ściągnać
            throw std::out_of_range("ArrayStack is empty. Cannot pop.");
        }
        return data[--top];
    }
    int size() {
        return top;//indeks top odpowiada liczbie elementów na stosie
    }
    bool empty() {
        return size() == 0;//jeśłi rozmiar 0 stos jest pusty
    }
    ~ArrayStack() {
        delete[] data;//destruktor zwalania pamięć, która przechowywała tablicę z elemetnami
    }
    T check(){
        return data[top-1];//zwraca wartość najwyższego elementu
    }

private:
    T* data;//wskaźnik, który będzie wskazywał na stworzoną tablicę, dynamiczna alokacja pamięci
    int top;//przechowuje indeks pierwszej wolnej komórki z góry
    int capacity;//przechowuje pojemność stosu
};

//konstruktor z argumentem przypisuje wskazaną wartość do capacity, ustawia top na 0, wskaźnik data na nową tablicę
template <typename T>
ArrayStack<T>::ArrayStack(int capacity) : data(new T[capacity]), top(0), capacity(capacity) {}
//konstruktor bezargumentowy
template <typename T>
ArrayStack<T>::ArrayStack() : data(nullptr), top(0), capacity(0) {}

#endif

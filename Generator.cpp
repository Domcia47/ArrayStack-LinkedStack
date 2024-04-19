#include <iostream>
#include <string>
#include <ctime>
//#include "ArrayStack.hpp"

int main(int argc, const char *argv[]) {
    //inicjalizacja generatora liczb losowych
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    //sprawdzenie czy podano argument wywołania programu
    if (argc < 2) {
        std::cerr << "No arguments." << std::endl;
        return 1;
    }

    std::string argument = argv[1]; //wczytanie argumentu wywołania programu do zmiennej

    int n; //zmienna do przechowywania liczby operacji do wygenerowania
    n = std::stoi(argument); //przypisanie zmiennej argument zamienionej ze string na int

    //sprawdzenie czy argument spełnia warunki zadania
    if(n>1000000){
        std::cout<<"Argument out of range."<<std::endl;
        return 1;
    }

    //wypisanie liczby generowanych operacji dla programu Stack.cpp
    std::cout << n;

    for (int i = 0; i < n; ++i) {
        int operation = std::rand() % 3; //losowanie typu operacji 0, 1, lub 2

        if (operation == 0) {
        //dla wylosowanego 0 operacja typu "D"
            std::cout << "D" << std::endl;
            
        } else if (operation == 1) {
        //dla wylosowanego 1 operacja typu "S"
            std::cout << "S " << std::endl;
        } 
        else {
        //dla wylosowanego 2 operacja typu "A x"
            int value = std::rand() % 1000001;  //losowanie liczby naturalnej od 0 do 10^6
            std::cout << "A " << value << std::endl; //wypisanie operacji A x
        }
    }

    return 0;
}

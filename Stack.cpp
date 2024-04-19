#include <iostream>
#include "ArrayStack.hpp"
#include "LinkedStack.hpp"


int main(){
    std::ios_base::sync_with_stdio(false);
    
    int n;//zmienna przechowująca liczbę operacji
    int x;//zmienna do wczytywania liczby do położenia na stosie
    std::string s;//zmienna do przechowywania symbolu operacji
    std::cin>>n;//wczytaj liczbę operacji
    
    //sprawdzenie czy wczytana wartość spełnia warunki zadania
    if(n>1000000){
        std::cout<<"Argument out of range."<<std::endl;
        return 1;
    }

    
    LinkedStack<int> stack; //utwórz stos
    //ArrayStack<int> stack(1000000);//utwórz stos
    

    for(int i =0; i<n;i++){
        std::cin>>s;//wczytaj znak odpowiadający operacji

        //jeżeli wczytano 'D' wypisz 'EMPTY' jeśli stos jest pusty lub wypisz element z wierzchu stosu wywołując pop()
        if(s=="D"){
            
            if(stack.empty()) std::cout << "EMPTY"<<std::endl;
            else  std::cout<< stack.pop()<<std::endl;
            
        }
        //jeżeli wczytano 'S' wypisz ilość elementów na stosie wywołując metodę size()
        else if(s=="S") {
            
            std::cout << stack.size()<<std::endl;
        }
        //jeżeli wczytano 'A' wczytaj kolejny znak do zmiennej x i umieść go na stosie wywołując push(x)
        else if(s=="A"){

            std::cin >> x;
            
            stack.push(x);
        }
        //w innym przypadku wczytane polecenie jest błędne 
        else{
            std::cout<<"Błędne polecenie.";
            return 1;
        }
    }
}

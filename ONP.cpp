#include "ArrayStack.hpp"
#include "LinkedStack.hpp"
#include <iostream>
#include <sstream>
#include <string>

//funkcja sprawdzająca czy dany char jest operatorem
bool isSymbol(char c){
    return  (c == '+' || c == '-' || c == '*' || c == '/'|| c =='('||c ==')');
}


std::string toONP(std::string s){
   
    //LinkedStack<char> stack; //utworzenie stosu do przechowywania znaków
    ArrayStack<char> stack(100);
    std::istringstream stream(s);//stringstream do wydobycia fragmentów stringa rozdzielonych spacją
    std::string sign; //zmienna na pojedyncze znaki i liczby
    std::string output; //zmienna przechowująca wynik
    
    while(stream>>sign){ //wczytuj do sign dopóki coś jest w stream
        
        //jeżeli nie jest symbolem - jest liczbą, przenieś na wyjście
        if(!isSymbol(sign[0])){
           
            output+=sign;
            output+=' ';
        }
        //nawias otwierający zawsze trafia na stos
        else if(sign[0]=='('){
            stack.push(sign[0]);
        }
        //nawias zamykający powoduje ściaganie ze stosu aż do nawiasu otiwerającego
        else if(sign[0]==')'){
            
            while(!stack.empty()){
                char top_elem = stack.pop();
                //nawiasów nie wypisujemy na wyjściu
                if(top_elem!='(') {
                    output+=top_elem;
                    output+=' ';
                }
                else break;
            }
        }
        else{
            //nadanie priorytetu znakom
            int currentpriority;
            if(sign[0]=='+'||sign[0]=='-') currentpriority = 1;
            else if(sign[0]=='*'||sign[0]=='/') currentpriority = 2;
            else throw std::invalid_argument("Wrong input");
            
            //w przypadku plusa i minusa nie moze być znaku o mniejszym priorytecie na stosie poza '(',
            //więc ściągamy znaki ze stosu przed położeniem
            while(currentpriority==1){
                    //jeśli stos jest pusty połóż znak
                    if(stack.empty()){
                        
                        stack.push(sign[0]);
                        break;
                    }
                    //jeśli na stosie jest '(' połóż znak
                    else if(stack.check()=='('){
                        
                        stack.push(sign[0]);
                        break;
                    }
                    //jeśli na stosie jest coś innego zdejmij ze stosu
                    else if(stack.check()!='(') {
                        
                        output+=stack.pop();
                        output+=' ';
                        //break;
                    }
                
                    else {
                        throw std::runtime_error("An unspecified runtime error occurred.");
                    }
            }
            //dla '*' i '/'
            while(currentpriority == 2){
                //jeśli stos pusty połóż znak
                if(stack.empty()){
                    stack.push(sign[0]);
                    break;
                }
                char top_elem = stack.check();
                //jeśli na wierzchu stosu jest operator o niższym priorytecie połóż operator
                if(top_elem=='+'||top_elem=='-'){
                    stack.push(sign[0]);
                    break;
                }
                //jeśli na wierzchu stosu jest operator o takim samym priorytecie zdejmuj ze stosu
                else if(top_elem=='*'||top_elem=='/'){
                    output+=stack.pop();
                    output+=' ';
                }
                //jeśli na wierzchu stosu jest '(' połóż operator
                else if(top_elem=='('){
                    stack.push(sign[0]);
                    break;
                }
            }
        }
    }
    output.pop_back();//usuń spację z końca wyniku
    return output;//zwróć wynikowy string
}

int main(){
    std::string expression;
    std::getline(std::cin, expression);
    std::cout<<toONP(expression);
    std::cout<<std::endl;

}
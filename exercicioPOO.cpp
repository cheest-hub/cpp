/*Aula 15/06
prof: Erika
exemplo de objeto
*/
#include <iostream>
#include <string>


class Cino {
private:
    std::string nome;

public:
    Cino(std::string nome) {
        this->nome = nome;

    }

    void chamar() {
        std::cout << this->nome << " estao chamando" << std::endl;

    }
};

int main() {

Cino alert1("porta Principal");
Cino alert2("janela");

alert1.chamar();
alert2.chamar();

return 0;
}
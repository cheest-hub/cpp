/*Aula 15/06
prof: Erika
aula de POO 
*/
#include <iostream>
#include <string>


class Cachorro {
private:
    std::string nome;

public:
    Cachorro(std::string nome) {
        this->nome = nome;

    }

    void latir() {
        std::cout << this->nome << " diz: Au Au!" << std::endl;

    }
};

int main() {

Cachorro c1("Rex");
Cachorro c2("Bob");

c1.latir();
c2.latir();

return 0;
}
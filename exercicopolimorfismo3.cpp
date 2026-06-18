/*Aula 17/06
prof: Erika
exercicio clase tipos e polimorfismo
*/
#include <iostream>
#include <windows.h>

class Funcionario {

protected:
    double salarioBase;

public:
    Funcionario(double salario) : salarioBase(salario) {}

    virtual void mostrarSalario() {

        std::cout << "Salario do funcionario: R$" << salarioBase << std::endl;
    }

};  

class Gerente : public Funcionario {
public:

    Gerente(double salario) : Funcionario(salario) {}

    void mostrarSalario() override {
        double salarioComBonus = salarioBase * 1.20; // 20% de acréscimo
        std::cout << "Salario do Gerente: R$ " << salarioBase <<" + bônus de 20% = R$ " << salarioComBonus << std::endl;
    }
};

int main(){

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Funcionario f1(3000.0);
    Gerente g1(5000.0);

    f1.mostrarSalario();
    g1.mostrarSalario();

    return 0;
}
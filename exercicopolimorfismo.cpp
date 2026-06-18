/*Aula 17/06
prof: Erika
exercicio clase tipos e polimorfismo
*/
#include <iostream>
#include <string>

using namespace std;

class Pessoa {
protected:
    string nome;

public:
    Pessoa(string n) : nome(n) {}
    
    virtual void falar() { 
        cout << nome << " está falando." << endl;
    }
};


class Professor : public Pessoa {
private:
    string disciplina;

public:
    Professor(string n, string d) : Pessoa(n), disciplina(d) {}

    void falar() override { 
        cout << "Professor(a) " << nome << " está ensinando " << disciplina << "." << endl;
    }
};

class Aluno : public Pessoa {
private:
    int matricula;

public:
    Aluno(string n, int m) : Pessoa(n), matricula(m) {}

    void falar() override {
        cout << "Aluno(a) " << nome << " (matrícula: " << matricula << ") está aprendendo." << endl;
    }
};

void fazerFalar(Pessoa* p) {
    p->falar();
}

int main() {

    // Pessoa p("Maria");
    // Professor prof("Carlos", "Matematica");
    // Aluno aluno("Ana", 201);

    // p.falar();
    // prof.falar();
    // aluno.falar();   

    
    Pessoa* p1 = new Pessoa("João");
    Pessoa* p2 = new Professor("Ricardo", "Física");
    Pessoa* p3 = new Aluno("Marina", 202);


    fazerFalar(p1);
    fazerFalar(p2);
    fazerFalar(p3);

    delete p1;
    delete p2;
    delete p3;

    return 0;
}

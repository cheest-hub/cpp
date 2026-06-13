//exerciço de localização de dados utilizando short int, interagindo com dados e espaço de memoria.
#include <iostream>
using namespace std;

int main() {

    short int * pi  = new short int;
    *pi = 1001;
    cout << " Valor inteiro = " << * pi <<endl;
    cout << " Localização = " << pi << endl << endl;

    float *pf = new float;
    *pf = 123.32;
    cout << " (Float) Valor ponto-flutuante = " << * pf << endl;
    cout << " (Float) Localização = " << pf << endl << endl;

    double *pd = new double;
    *pd = 500.35;
    cout << " (Double) Valor doble = " << * pd << endl;
    cout << " (Doble) Localização = " << pd << endl << endl;

    cout << " (int4byes) Tamanho de pi = " << sizeof(pi) << endl;
    cout << " (int4byes) Tamanho de *pi = " << sizeof(*pi) << endl;
    cout << " (Float8byte) Tamanho de pf = " << sizeof(pf) << endl;
    cout << " (Float8byte) Tamanho de *pf = " << sizeof(*pf) << endl;
    cout << " (Double8byte) Tamanho de pd = " << sizeof(pd) << endl;
    cout << " (Double8byte) Tamanho de *pd = " << sizeof(*pd) << endl;
    
    

    return 0;
}

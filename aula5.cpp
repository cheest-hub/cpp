#include <iostream>
#include <vector>

using namespace  std;

int main(){
    vector<int> valores;
    valores.push_back(10);
    valores.push_back(20);
    valores.push_back(30);

    cout << "Primeiro: " << valores[0] << endl;

    cout << "Tamanho: " << valores.size() << endl;

    cout << "Elementos: ";

    for(int i = 0; i < valores.size(); i++){

        cout << valores[i] << " ";

    }

    cout << endl;

    valores.pop_back();

    cout << "Apos remover: ";

    for (int x : valores){

        cout << x << " ";

    }

    cout << endl;

    return 0;



}

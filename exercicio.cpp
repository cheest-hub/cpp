#include <iostream>
using namespace std;

void trocar(int *a, int *b){
    if (a == b) return;
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int x = 10;
    int y = 20;

    cout << "Antes: x = " << x << ", y = " << y << endl;

    trocar(&x, &y);

    cout << "Depois: x = " << x << ", y = " << y << endl;

    return 0;
}
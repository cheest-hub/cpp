#include <stdio.h>

int main() {
    int numero;
    unsigned long long fatorial = 1; // Usamos 'long long' porque o fatorial cresce muito rápido!

    printf("=== CALCULO DE FATORIAL EM C ===\n");
    printf("Digite um numero inteiro positivo: ");
    
    // %d é o especificador de formato para números inteiros (int)
    // O '&' é obrigatório no scanf para indicar o endereço da variável
    scanf("%d", &numero);

    // Validação básica: fatorial não existe para números negativos
    if (numero < 0) {
        printf("[ERRO] Nao existe fatorial de numero negativo.\n");
    } else {
        // Estrutura de repetição para multiplicar os números de 1 até o número digitado
        for (int i = 1; i <= numero; i++) {
            fatorial *= i; // O mesmo que: fatorial = fatorial * i;
        }

        // %llu é o especificador para 'unsigned long long'
        printf("O fatorial de %d (%d!) eh: %llu\n", numero, numero, fatorial);
    }

    return 0;
}
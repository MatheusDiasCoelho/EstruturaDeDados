#include <stdio.h>
#include <string.h>

int comparacoes = 0; // Vari�vel para contar o n�mero de compara��es
int trocas = 0;     // Vari�vel para contar o n�mero de trocas

// Fun��o de compara��o personalizada para o Quicksort
int comparar_strings(const void *a, const void *b) {
    comparacoes++;
    return strcmp(*(const char **)a, *(const char **)b);
}

// Fun��o auxiliar para trocar duas strings no vetor
void trocar(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
    trocas++;
}

// Fun��o Quicksort
void quicksort(char *arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int indice_pivo = esquerda;
        char *pivo = arr[direita];

        for (int i = esquerda; i < direita; i++) {
            if (comparar_strings(&arr[i], &pivo) < 0) {
                trocar(&arr[i], &arr[indice_pivo]);
                indice_pivo++;
            }
        }

        trocar(&arr[indice_pivo], &arr[direita]);

        quicksort(arr, esquerda, indice_pivo - 1);
        quicksort(arr, indice_pivo + 1, direita);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "lim�o", "manga",
        "abacate", "kiwi", "cereja", "morango", "p�ssego", "goiaba", "melancia",
        "framboesa", "amora", "caqui", "figo", "papaya"
    };
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    // Use a fun��o Quicksort para ordenar o vetor de palavras
    quicksort(arr, 0, tamanho - 1);

    // Calcula a mediana
    char mediana[256]; // Supomos que nenhuma palavra ter� mais de 255 caracteres
    if (tamanho % 2 == 1) {
        // Tamanho �mpar - a mediana � o elemento central
        strcpy(mediana, arr[tamanho / 2]);
    } else {
        // Tamanho par - a mediana � a m�dia dos dois elementos centrais
        char *elemento1 = arr[(tamanho - 1) / 2];
        char *elemento2 = arr[tamanho / 2];
        
        // Concatena os elementos centrais para calcular a m�dia
        strcpy(mediana, elemento1);
        strcat(mediana, " e ");
        strcat(mediana, elemento2);
    }

    // Imprime a mediana
    printf("Mediana: %s\n", mediana);

    // Imprima o n�mero de compara��es e trocas
    printf("N�mero de compara��es: %d\n", comparacoes);
    printf("N�mero de trocas: %d\n", trocas);

    return 0;
}


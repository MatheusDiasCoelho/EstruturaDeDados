#include <stdio.h>
#include <string.h>

int comparacoes = 0; // Variável para contar o número de comparações
int trocas = 0;     // Variável para contar o número de trocas

// Função de comparação personalizada para o Quicksort
int comparar_strings(const void *a, const void *b) {
    comparacoes++;
    return strcmp(*(const char **)a, *(const char **)b);
}

// Função auxiliar para trocar duas strings no vetor
void trocar(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
    trocas++;
}

// Função Quicksort
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
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limão", "manga",
        "abacate", "kiwi", "cereja", "morango", "pêssego", "goiaba", "melancia",
        "framboesa", "amora", "caqui", "figo", "papaya"
    };
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    // Use a função Quicksort para ordenar o vetor de palavras
    quicksort(arr, 0, tamanho - 1);

    // Calcula a mediana
    char mediana[256]; // Supomos que nenhuma palavra terá mais de 255 caracteres
    if (tamanho % 2 == 1) {
        // Tamanho ímpar - a mediana é o elemento central
        strcpy(mediana, arr[tamanho / 2]);
    } else {
        // Tamanho par - a mediana é a média dos dois elementos centrais
        char *elemento1 = arr[(tamanho - 1) / 2];
        char *elemento2 = arr[tamanho / 2];
        
        // Concatena os elementos centrais para calcular a média
        strcpy(mediana, elemento1);
        strcat(mediana, " e ");
        strcat(mediana, elemento2);
    }

    // Imprime a mediana
    printf("Mediana: %s\n", mediana);

    // Imprima o número de comparações e trocas
    printf("Número de comparações: %d\n", comparacoes);
    printf("Número de trocas: %d\n", trocas);

    return 0;
}


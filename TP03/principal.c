#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
    FILE *file;
    int n;

    // Abra o arquivo para leitura
    file = fopen("poligono.txt", "r");

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    // Leia o número de vértices
    fscanf(file, "%d", &n);

    // Aloque memória para armazenar as coordenadas dos vértices
    Ponto *pontos = (Ponto *)malloc(n * sizeof(Ponto));

    if (pontos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Leia as coordenadas dos vértices
    for (int i = 0; i < n; i++) {
        fscanf(file, "%f %f", &pontos[i].X, &pontos[i].Y);
    }

    // Feche o arquivo
    fclose(file);

    // Calcule a área da região poligonal
    double area = calcularArea(pontos, n);

    // Imprima a área calculada
    printf("A área da região poligonal é: %.2lf\n", area);

    // Libere a memória alocada
    free(pontos);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
    FILE *file;
    int n;

    // Abra o arquivo para leitura
    file = fopen("poligono.txt", "r");

    if (file == NULL) {
        printf("N�o foi poss�vel abrir o arquivo.\n");
        return 1;
    }

    // Leia o n�mero de v�rtices
    fscanf(file, "%d", &n);

    // Aloque mem�ria para armazenar as coordenadas dos v�rtices
    Ponto *pontos = (Ponto *)malloc(n * sizeof(Ponto));

    if (pontos == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        return 1;
    }

    // Leia as coordenadas dos v�rtices
    for (int i = 0; i < n; i++) {
        fscanf(file, "%f %f", &pontos[i].X, &pontos[i].Y);
    }

    // Feche o arquivo
    fclose(file);

    // Calcule a �rea da regi�o poligonal
    double area = calcularArea(pontos, n);

    // Imprima a �rea calculada
    printf("A �rea da regi�o poligonal �: %.2lf\n", area);

    // Libere a mem�ria alocada
    free(pontos);

    return 0;
}


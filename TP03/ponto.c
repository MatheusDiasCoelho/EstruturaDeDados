#include "ponto.h"
#include <math.h>

double calcularArea(Ponto *pontos, int n) {
    double area = 0.0;

    for (int i = 0; i < n - 1; i++) {
        area += (pontos[i].X * pontos[i + 1].Y - pontos[i + 1].X * pontos[i].Y);
    }

    area += (pontos[n - 1].X * pontos[0].Y - pontos[0].X * pontos[n - 1].Y);

    return 0.5 * fabs(area); // Valor absoluto e metade da área
}


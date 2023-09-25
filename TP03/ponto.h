#ifndef PONTO_H
#define PONTO_H

typedef struct {
    float X;
    float Y;
} Ponto;

double calcularArea(Ponto *pontos, int n);

#endif


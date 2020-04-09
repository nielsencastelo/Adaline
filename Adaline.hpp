#ifndef ADALINE_H
#define ADALINE_H
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;
class Adaline
{
    private:
        double w[3];
        double y = 0;
        double N = 0.1;
        const int BIAS = -1;
        const int MAX_EPOCAS = 1000;
        double erro_max    = 1E-9;
        double erro_global;
        double eqm_ant, eqm_atual;
        int operacao = 0;
        int e [4][8]= {
			{ 0, 0, 0, 0, 1, 1, 0, 1 },
			{ 0, 1, 1, 0, 0, 1, 1, 0 },
			{ 1, 0, 1, 0, 0, 1, 1, 0 },
			{ 1, 1, 1, 1, 0, 0, 0, 1 }
			};
    public:
        Adaline(int op);
        int executar(int x1, int x2);
        bool treinar();
        void corrigirPeso(int exemplo, int saida);
        void testar();
        double eqm();
};
#endif // PERCEPTRON_H

#include "Adaline.hpp"

Adaline::Adaline(int op)
{
    srand( (unsigned)time(NULL) );

    if ((op >= 0) && (op < 6))
    {
        operacao = op + 2;
    }
    for (int i = 0; i < 3; i++)
    {
        w[i] = -1 + ( rand() % 1 ); // [-1,1]
    }
}
void Adaline::corrigirPeso(int exemplo, int saida)
{
    w[0] = w[0] + (N * (e[exemplo][operacao] - saida) * (BIAS));
    w[1] = w[1] + (N * (e[exemplo][operacao] - saida) * e[exemplo][0]);
	w[2] = w[2] + (N * (e[exemplo][operacao] - saida) * e[exemplo][1]);
}

double Adaline::eqm()
{
    double er = 0;
    double u[4];

    for (int i = 0; i < 4; i++)
    {
        u[i] = ((BIAS) * w[0]) + (e[i][0] * w[1]) + (e[i][1] * w[2]);
        er = er + pow(e[i][operacao] - u[i], 2);
    }
    return er /4;
}
bool Adaline::treinar()
{
    int epoca = 0;
    bool treinou;
    while(true)
    {
        eqm_ant = eqm();
		for (int i = 0; i < 4; i++)
		{
            int s = executar(e[i][0], e[i][1]);
			if (s != e[i][operacao])
			{
                corrigirPeso(i, s);
                treinou = false;
            }
        }
		epoca++;
		eqm_atual = eqm();
        erro_global = pow((eqm_atual - eqm_ant),2);
        cout << erro_global << endl;

		if (erro_global < erro_max)
        {
            treinou = true;
            break;
        }

        if (epoca == MAX_EPOCAS)
            break;
    }

    cout << "The algorithm trained " << epoca  << " epochs..." << endl;

	if (treinou == false)
	{
        cout << "The algorithm could not converge..." << endl;
	}
    return treinou;
}
void Adaline::testar()
{
    bool sair = false;
    while (!sair)
    {
        cout << "-- Please enter 9 to exit --" << endl;
        cout << "x1 : ";

        int x1;
        cin >> x1;
        if (x1 == 9)
        {
            sair = true;
        } else
        {
            cout << "x2 : ";
            int x2;
            cin >> x2;

			int y = executar(x1, x2);
            cout << " y : "  << y << endl;
        }
    }
}
int Adaline::executar(int x1, int x2)
{
    // Somatorio NET
    y = ((BIAS) * w[0]) + (x1 * w[1]) + (x2 * w[2]);
	// Funcao de Transferencia
	if (y > 0)
    {
        return 1;
    }
    return 0;
}

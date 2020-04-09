#include "Adaline.hpp"
#include <cstdlib>
void menu(void);

int main()
{
    setlocale(LC_ALL,"Portuguese");
    system("cls");
    menu();

    bool erro = false;
    int op;
    cin >> op;

    erro = ((op < 0) || (op > 5));

    if (!erro)
    {
        Adaline p(op);
		if (p.treinar())
		{
            p.testar();
        }
    }

    cout << "want to continue? <1 for Yes and 0 for no>";
    cin >> op;

    if (op == 1)
        main();
    return 0;
}
void menu()
{
    cout << "Use: Adaline<operation>" << endl;
	cout << "operation:" << endl;
	cout << "\t0 - OR" << endl;
	cout << "\t1 - AND" << endl;
	cout << "\t2 - NOR" << endl;
	cout << "\t3 - NAND" << endl;
	cout << "\t4 - XOR" << endl;
	cout << "\t5 - XNOR" << endl;
}

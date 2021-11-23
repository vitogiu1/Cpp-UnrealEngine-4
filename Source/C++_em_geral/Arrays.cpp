#include <iostream>
#include "Arrays.h"

using namespace std;
int Arrays_API::mainArrays()
{
	//Cria um array com um total de 5 valores:
	//do 0 até o 4
	int MeuArray[5] = { -20, 30, 92, 5, 49 };

	//Faz a mesma coisa que o for de baixo, porém de forma mais simples
	//apenas pegando o elemento com a expressão ":" redirecionada para o array "MeuArray
	for (int element : MeuArray)
	{
		cout << element << endl;
	}

	//Cria uma estrutura de repetição (for)
	//que nessa estrtura, primeiramente é criado a variável "i" do tipo inteiro com o valor 0
	// depois, é verificado se essa variável "i" é menor que 5, se essa condição for verdadeira
	// ele adiciona um na variável i, se não, a variável i, será 4, e a estrutura de repetição, acaba por ai.
	for (int i = 0; i < 5; i++)
	{
		cout << MeuArray[i] << endl;
	}

	return 0;
}
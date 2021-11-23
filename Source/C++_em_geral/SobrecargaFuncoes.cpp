#include <iostream>
#include "SobrecargaFuncoes.h"

//Criando a função Multiplicacao int
int Multiplicacao(int NumA, int NumB)
{
	return NumA * NumB;
}

//Criando a função com o mesmo nome da anterior, porém com tipo, e argumentos diferentes
//(Sobrecarga de função)
float Multiplicacao(float NumA, float NumB)
{
	return NumA * NumB;
}


using namespace std;
int SobrecargaFuncoes_API::mainSobrecarga()
{
	//Definindo duas variaveis do tipo inteiro
	int NumeroInteiroA, NumeroInteiroB;

	//Definindo duas variaveis do tipo float
	float NumeroFloatA, NumeroFloatB;

	//Definindo um valor inteiro
	int valor = 1;

	//Se a variável acima for igual (=) a um (1) Será feito a conta de numeros do tipo int (inteiro)
		if (valor == 1)
		{
			cout << "Digite o primeiro numero inteiro: "; //Envia no console a frase "Digite o primeiro numero inteiro: "
			cin >> NumeroInteiroA; //Ele irá esperar que você insira um numero do tipo Inteiro

			cout << "Digite o segundo numero inteiro: "; //Envia no console a frase "Digite o segundo numero inteiro: "
			cin >> NumeroInteiroB; //Ele irá esperar que você insira um numero do tipo Inteiro

			//Irá enviar no console o resultado da multiplicação do valor inteiro
			cout << "Resultado da multiplicação de numeros inteiros: " << NumeroInteiroA << " e " << NumeroInteiroB << " resulta em: " << Multiplicacao(NumeroInteiroA, NumeroInteiroB) << endl;
		}
		//Já se a variável "valor" for igual a dois (2) será feito a conta dos numeros do tipo float
		else if (valor == 2)
		{
			cout << "Digite o primeiro numero float: "; //Envia no console a frase "Digite o primeiro numero float: "
			cin >> NumeroFloatA; //Ele irá esperar que você insira um numero do tipo float

			cout << "Digite o segundo numero float: ";//Envia no console a frase "Digite o segundo numero float: "
			cin >> NumeroFloatB; //Ele irá esperar que você insira um numero do tipo float

			//Irá enviar no console o resultado da multiplicação do valor float
			cout << "Resultado da multiplicação de numeros float: " << NumeroFloatA << " e " << NumeroFloatB << " resulta em: " << Multiplicacao(NumeroFloatA, NumeroFloatB) << endl;
		}

	return 0;
}

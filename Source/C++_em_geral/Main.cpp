#include <iostream>
#include "SobrecargaFuncoes.h"
#include "Structs.h"

int main()
{ 
	//Variavel do tipo inteiro que irá dizer qual classe que será executada
	int classeQueIraLigar = 2;

	//Se a variável "classeQueIraLigar" for igual a 1, então a classe que será executada é a "Structs"
	if (classeQueIraLigar == 1)
	{
		Structs_API::mainStructs();
	}
	//Se a variavel "classeQueIraLigar" for igual a 2, então a classe que será executada é a "SobrecargaFuncoes"
	else if (classeQueIraLigar == 2)
	{
		SobrecargaFuncoes_API::mainSobrecarga();
	}
	 return 0;
}
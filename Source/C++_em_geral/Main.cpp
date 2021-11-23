#include <iostream>
#include "SobrecargaFuncoes.h"
#include "Structs.h"
#include "Arrays.h"

int main()
{ 
	int classeQueIraLigar = 3;
	if (classeQueIraLigar == 1)
	{
		Structs_API::mainStructs();
	}
	else if (classeQueIraLigar == 2)
	{
		SobrecargaFuncoes_API::mainSobrecarga();
	}
	else if (classeQueIraLigar == 3)
	{
		Arrays_API::mainArrays();
	}
	 return 0;
}
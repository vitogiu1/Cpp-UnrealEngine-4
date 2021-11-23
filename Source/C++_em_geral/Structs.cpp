#include <iostream>
#include "Structs.h"
using namespace std;

//Declara a struct, que será o modelo de criação da variável
//As structs podem se assemelhar com classes
//podendo assim como as classes, criar funções etc.
struct Coordenadas
{
	float x;
	float y;
	float z;
};
//Função que não irá retornar nada (por isso void), e como parâmetro, temos uma variável
//do tipo Coordenadas (a struct criada acima)
//Logo, devera ser colocado como argumento, uma variável, do modelo da nossa struct

//Espaco3d é uma variável local desta função, logo, ela só irá existir, para essa função
void imprimirCoordenadas(Coordenadas Espaco3d)
{
	cout << "X = " << Espaco3d.x << "\n" << "Y = " << Espaco3d.y << "\n" << "Z = " << Espaco3d.z << endl;
}

int Structs_API::mainStructs()
{
	//Cria de fato uma variável do tipo struct coordenadas
	struct Coordenadas Ponto3D;

	//Agora definimos os valores que definimos como modelo na criação da struct
	Ponto3D.x = 45.f;
	Ponto3D.y = -90.f;
	Ponto3D.z = 180.f;

	//Chama a função imprimirCoordendas enviando como argumento, a variável Coordenadas
	//Que seria nossa Struct
	//Assim como solicitado nos parâmetros da função
	imprimirCoordenadas(Ponto3D);

	cin.get();

	return 0;
}

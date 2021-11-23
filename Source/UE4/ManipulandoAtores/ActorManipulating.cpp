#include "ActorManipulating.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Engine/Engine.h"

// Sets default values
AActorRotation::AActorRotation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Definindo as variaveis que serão utilizadas na função Tick()
	TempoExecucaoZ = 0.0f;
	AlturaDeltaZ = 0.0f;
	NovaLocalizacaoZ = FVector(0.f, 0.f, 0.f);

	TempoExecucaoX = 0.0f;
	MovimentoDeltaX = 0.0f;
	NovaLocalizacaoX = FVector(0.f, 0.f, 0.f);

	TempoExecucaoY = 0.0f;
	MovimentoDeltaY = 0.0f;
	NovaLocalizacaoY = FVector(0.f, 0.f, 0.f);

	//Definindo a esfera de colisão da pedra
	PedraColisao = CreateDefaultSubobject<USphereComponent>(TEXT("RAIZ"));
	PedraColisao->InitSphereRadius(100.f);
	PedraColisao->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = PedraColisao;

	//Criando a static mesh para a pedra, para que seja possivel
	//aplicar uma mesh no ator
	PedraVisivel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pedra"));
	ConstructorHelpers::FObjectFinder<UStaticMesh>Pedra(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Rock.SM_Rock'"));


	//Criando a particula de fogo
	ParticulaDeFogo = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particula Fogo"));

	ParticulaDeFogo->SetupAttachment(PedraVisivel);

	ParticulaDeFogo->bAutoActivate = true;

	ConstructorHelpers::FObjectFinder<UParticleSystem>Fogo(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));

	//Se for criado a mesh e a particula de fogo com sucesso, os attachments 
	//Irão ser aplicado nos atores
	if (Pedra.Succeeded() && Fogo.Succeeded())
	{
		PedraVisivel->SetStaticMesh(Pedra.Object);

		ParticulaDeFogo->SetTemplate(Fogo.Object);
		PedraVisivel->SetRelativeLocation(FVector(0.f, 0.f, -60.f));
	}
	PedraVisivel->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AActorRotation::BeginPlay()
{
	Super::BeginPlay();
	//Testando o TArray
	//Abaixo ele irá criar um TArray, e adicionar 5 valores a essa aray
	TArray<int32>MyArrayUnreal; //Cria um TArray com o nome MyArrayUnreal
	MyArrayUnreal.Add(-20);  //Adicionando o valor -20 a array
	MyArrayUnreal.Add(30); //Adicionando o valor 30 a array
	MyArrayUnreal.Add(-40); //Adicionando o valor -40 a array
	MyArrayUnreal.Add(50); //Adicionando o valor 50 a array
	MyArrayUnreal.Add(-60); //Adicionando o valor -60 a array

	for (int32 element : MyArrayUnreal) //Vai pegar todos os elementos do Tarray
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT(" %d "), element), false);
		//Irá enviar na tela do jogo na unreal, todos os valores, da TArray, durante 5 segundos, na cor laranja.
	}

	//Pegando valores Randômicos
	float RotRandom = FMath::RandRange(-90.f, 90.f); //Numero randômico do tipo float de -90 até 90
	float PosRandom = FMath::RandRange(-5.f, 5.f);  //Numero randômico do tipo float de -5 até 5
	float ScaleRandom = FMath::RandRange(0.05f, 0.2f); //Numero randômico do tipo float de 0.05 até 0.2

	//Com essa função, ele irá mudar de forma randômica a posição e tamanho do(s) ator(es)
	//Toda vez que o jogo iniciar, pois esse código está dentro do evento BeginPlay()
	FTransform NewTransform = FTransform(FRotator(RotRandom, PosRandom, ScaleRandom), FVector(PosRandom, PosRandom, PosRandom), FVector(ScaleRandom, ScaleRandom, ScaleRandom));
	AddActorLocalTransform(NewTransform);
}

// Called every frame
void AActorRotation::Tick(float DeltaTime)
{
	//Abaixo estamos modificando a posição do ator, nas posições x, y, z
	Super::Tick(DeltaTime);
	NovaLocalizacaoZ = this->GetActorLocation();
	AlturaDeltaZ = FMath::Sin(TempoExecucaoZ + DeltaTime) - FMath::Sin(TempoExecucaoZ);
	NovaLocalizacaoZ.Z += AlturaDeltaZ * 30.f;
	TempoExecucaoZ += DeltaTime;
	this->SetActorLocation(NovaLocalizacaoZ);

	NovaLocalizacaoX = this->GetActorLocation();
	MovimentoDeltaX = FMath::Sin(TempoExecucaoX + DeltaTime) - FMath::Sin(TempoExecucaoX);
	NovaLocalizacaoX.X += MovimentoDeltaX * 30.f;
	TempoExecucaoX += DeltaTime;
	this->SetActorLocation(NovaLocalizacaoX);

	NovaLocalizacaoY = this->GetActorLocation();
	MovimentoDeltaY = FMath::Sin(TempoExecucaoY + DeltaTime) - FMath::Sin(TempoExecucaoY);
	NovaLocalizacaoY.Y += MovimentoDeltaY * 30.f;
	TempoExecucaoY += DeltaTime;
	this->SetActorLocation(NovaLocalizacaoY);


	//A cada frame, a rotação do ator será modificada, pois estamos utilizando o DeltaTime como multiplicação
	// ele pega seus frames por segundos (FPS) e divide por 1, e ainda estou aumentando mais a velocidade
	// Com uma variavel do tipo float, que pode ser inserida por meio da unreal engine
	//Se essa variável do tipo float for igual a zero(0) o objeto não irá girar, pois
	// <numero> * 0 = 0
	AddActorLocalRotation(FRotator(0.f, 50.f, 0.f) * DeltaTime * Velocidade);
}
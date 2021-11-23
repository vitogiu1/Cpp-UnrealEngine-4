#include "ActorRotation.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"


AActorRotation::AActorRotation()
{

	PrimaryActorTick.bCanEverTick = true;
	TempoExecucaoZ = 0.0f;
	AlturaDeltaZ = 0.0f;
	NovaLocalizacaoZ = FVector(0.f, 0.f, 0.f);


	TempoExecucaoX = 0.0f;
	MovimentoDeltaX = 0.0f;
	NovaLocalizacaoX = FVector(0.f, 0.f, 0.f);

	TempoExecucaoY = 0.0f;
	MovimentoDeltaY = 0.0f;
	NovaLocalizacaoY = FVector(0.f, 0.f, 0.f);

	PedraColisao = CreateDefaultSubobject<USphereComponent>(TEXT("RAIZ"));
	PedraColisao->InitSphereRadius(100.f);
	PedraColisao->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = PedraColisao;

	PedraVisivel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pedra"));

	ParticulaDeFogo = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particula Fogo"));

	ParticulaDeFogo->SetupAttachment(PedraVisivel);

	ParticulaDeFogo->bAutoActivate = true;
	ConstructorHelpers::FObjectFinder<UParticleSystem>Fogo(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));

	ConstructorHelpers::FObjectFinder<UStaticMesh>Pedra(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Rock.SM_Rock'"));

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
	
}

// Called every frame
void AActorRotation::Tick(float DeltaTime)
{
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


	AddActorLocalRotation(FRotator(0.f, 50.f, 0.f) * DeltaTime * Velocidade);
	
}


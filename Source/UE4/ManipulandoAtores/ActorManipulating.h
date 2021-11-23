// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorManipulating.generated.h"

UCLASS()
class MANIPULANDOATORES_API AActorRotation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorRotation();

private:
	UPROPERTY(EditAnywhere, Category = "ComponentObject")
		UStaticMeshComponent* PedraVisivel;

	UPROPERTY(EditAnywhere, Category = "ComponentObject")
		class USphereComponent* PedraColisao;

	UPROPERTY(EditAnywhere, Category = "ComponentObject")
		UParticleSystemComponent* ParticulaDeFogo;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Velocidade Do Giro")
		float Velocidade;

private:
	float TempoExecucaoZ;
	float AlturaDeltaZ;
	FVector NovaLocalizacaoZ;

	//Se der errado, excluir
	float TempoExecucaoX;
	float MovimentoDeltaX;
	FVector NovaLocalizacaoX;

	float TempoExecucaoY;
	float MovimentoDeltaY;
	FVector NovaLocalizacaoY;
};

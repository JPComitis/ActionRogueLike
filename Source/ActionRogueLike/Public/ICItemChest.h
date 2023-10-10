// ICItemChest.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ICGamePlayInterface.h"
#include "ICItemChest.generated.h"

class UStaticMeshComponent;

UCLASS()
class ACTIONROGUELIKE_API AICItemChest : public AActor, public IICGamePlayInterface
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AICItemChest();

protected:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* BaseMesh;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* LidMesh;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Implement the Interact function from the interface
    virtual void Interact_Implementation(APawn* InstigatorPawn) override;
};
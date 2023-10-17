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

    UPROPERTY(EditAnywhere)
    float TargetPitch;

    void Interact_Implementation(APawn* InstigatorPawn);
   

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

    AICItemChest();

};

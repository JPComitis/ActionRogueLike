#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h" // Include for URadialForceComponent
#include "ICExplosiveBarrel.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ACTIONROGUELIKE_API AICExplosiveBarrel : public AActor
{
    GENERATED_BODY()

public:
    AICExplosiveBarrel();

protected:
    UPROPERTY(EditAnywhere)
    UStaticMeshComponent* StaticMesh;

    // Add Radial Force Component declaration
    UPROPERTY(VisibleAnywhere)
    URadialForceComponent* RadialForce;

    // Function declaration for the hit event
    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
        FVector NormalImpulse, const FHitResult& Hit);

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
};

#include "ICExplosiveBarrel.h"
#include "Components/StaticMeshComponent.h"

AICExplosiveBarrel::AICExplosiveBarrel()
{
    PrimaryActorTick.bCanEverTick = true;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    RootComponent = StaticMesh;  // Set the StaticMesh as the root component

    // Set up other initialization if needed

    // Set up collision response
    StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    StaticMesh->OnComponentHit.AddDynamic(this, &AICExplosiveBarrel::OnHit);
}

void AICExplosiveBarrel::BeginPlay()
{
    Super::BeginPlay();

    // Your additional initialization code, if any
}

void AICExplosiveBarrel::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Your per-frame update code, if any
}

void AICExplosiveBarrel::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    FVector NormalImpulse, const FHitResult& Hit)
{
    // Handle the hit event here
    // You can add any logic you want when the static mesh is hit
}

#include "ICExplosiveBarrel.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/RadialForceComponent.h"

AICExplosiveBarrel::AICExplosiveBarrel()
{
    PrimaryActorTick.bCanEverTick = true;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    RootComponent = StaticMesh;  // Set the StaticMesh as the root component

    // Set up other initialization if needed

    // Set up collision response
    StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    StaticMesh->OnComponentHit.AddDynamic(this, &AICExplosiveBarrel::OnHit);

    // Add Radial Force Component
    RadialForce = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForce"));
    RadialForce->SetupAttachment(StaticMesh);
    RadialForce->Radius = 500.0f; // Set the radius of the radial force
    RadialForce->bImpulseVelChange = true;
    RadialForce->bAutoActivate = false; // Radial force should not be automatically activated
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

    // Add fire impulse
    StaticMesh->AddImpulse(NormalImpulse * 1000.0f); // You can adjust the multiplier as needed

    // Activate Radial Force
    RadialForce->FireImpulse();
}

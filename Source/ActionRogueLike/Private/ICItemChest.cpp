


#include "ICItemChest.h"
#include "Components/StaticMeshComponent.h"


AICItemChest::AICItemChest()
{
    PrimaryActorTick.bCanEverTick = true;

    BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
    RootComponent = BaseMesh;

    LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
    LidMesh->SetupAttachment(BaseMesh);

    TargetPitch = -50;
}

void AICItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
    LidMesh->SetRelativeRotation(FRotator(TargetPitch, 0, 0));
}

void AICItemChest::BeginPlay()
{
    Super::BeginPlay();
}

void AICItemChest::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

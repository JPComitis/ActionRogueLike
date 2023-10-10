// ICItemChest.cpp
#include "ICItemChest.h"
#include "Components/StaticMeshComponent.h"

AICItemChest::AICItemChest()
{
    PrimaryActorTick.bCanEverTick = true;

    BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
    RootComponent = BaseMesh;

    LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
    LidMesh->SetupAttachment(BaseMesh);
}

void AICItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
    // Implement the interaction logic here
    // For example, you can open the chest, spawn items, etc.
}

void AICItemChest::BeginPlay()
{
    Super::BeginPlay();
}

void AICItemChest::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
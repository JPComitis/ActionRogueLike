#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ICCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class ACTIONROGUELIKE_API AICCharacter : public ACharacter
{
    GENERATED_BODY()

protected:

    UPROPERTY(EditAnywhere)
    TSubclassOf<AActor> ProjectileClass;

public:
    // Sets default values for this character's properties
    AICCharacter();

protected:

    UPROPERTY(EditAnywhere, Category = "Jumping")
    float JumpZVelocity = 500.0f; // Adjust this value to control jump height

    UPROPERTY(VisibleAnywhere)
    USpringArmComponent* SpringArmComp;

    UPROPERTY(VisibleAnywhere)
    UCameraComponent* CameraComp;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    void MoveForward(float Value);

    void MoveRight(float Value);

    void Jump(); 

    void PrimaryAttack();

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};

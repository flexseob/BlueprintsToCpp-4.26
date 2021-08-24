// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharactor.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AFirstPersonCharactor::AFirstPersonCharactor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFirstPersonCharactor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstPersonCharactor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstPersonCharactor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AFirstPersonCharactor::Forward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &AFirstPersonCharactor::Right);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Grab"), EInputEvent::IE_Pressed, this, &AFirstPersonCharactor::Grab);
	PlayerInputComponent->BindAction(TEXT("Release"), EInputEvent::IE_Released, this, &AFirstPersonCharactor::Release);
}

void AFirstPersonCharactor::Forward(float AxisValue)
{
	GetCharacterMovement()->AddInputVector(GetActorForwardVector() * AxisValue);
}


void AFirstPersonCharactor::Right(float AxisValue)
{
	GetCharacterMovement()->AddInputVector(GetActorRightVector() * AxisValue);
}

void AFirstPersonCharactor::Grab()
{
	GetGrabber()->Grab();
}

void AFirstPersonCharactor::Release()
{
	GetGrabber()->Release();
}



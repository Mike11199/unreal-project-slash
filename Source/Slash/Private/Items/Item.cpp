#include "Items/Item.h"
#include "Slash/DebugMacros.h"
#include "Components/SphereComponent.h"
#include "Characters/SlashCharacter.h"

AItem::AItem()
{ 	
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());

}

void AItem::BeginPlay()
{
	Super::BeginPlay();	

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItem::OnSphereEndOverlap);

	//int32 AvgInt = Avg<int32>(1, 3);
	//UE_LOG(LogTemp, Warning, TEXT("Avg of 1 and 3: %d"), AvgInt);

	//float AvgFloat = Avg<float>(3.45f, 9.34f);
	//UE_LOG(LogTemp, Warning, TEXT("Avg of 3.45 and 9.34: %f"), AvgFloat);


	//UE_LOG(LogTemp, Warning, TEXT("Begin play called2!"));
	//
	//if (GEngine) {
	//	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Green, FString("Item OnScreen Message!"));
	//}

	//UWorld* World = GetWorld();


	//if (World) {		
	//	DrawDebugLine(World, Location, Location + Forward * 100.f, FColor::Red, true, -1.f, 0, 1.f);
	//}	


	//if (World) {
	//	FVector Location = GetActorLocation();
	//	DrawDebugSphere(World, Location, 25.f, THIRTY, FColor::Red, false, 30.f);
	//}	


	//SetActorLocation(FVector(0.f, 0.f, 100.f));
	//SetActorRotation(FRotator(0.f, 45.f, 0.f));
	//FVector Location = GetActorLocation();
	//FVector Forward = GetActorForwardVector();

	// technically don't need ; as macros have it in slash.h
	//DRAW_SPHERE(Location);
	//DRAW_LINE(Location, Location + Forward * 100.f);
	//DRAW_POINT(Location + Forward * 100.f);
	//DRAW_VECTOR(Location, Location + Forward * 100.f);



}

float AItem::TransformedSin()
{	
	return Amplitude* FMath::Sin(RunningTime * TimeConstant);  // multiply by amplitude to set wave height and multiply runningtime to speed up wave (frequency)
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

void AItem::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//const FString OtherActorName = OtherActor->GetName();
	//if (GEngine) {
	//	GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Red, OtherActorName);
	//}

	ASlashCharacter* SlashCharacter = Cast<ASlashCharacter>(OtherActor);
	if (SlashCharacter) 
	{
		SlashCharacter->SetOverlappingItem(this);
	}

}

void AItem::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//const FString OtherActorName = FString("Ending Overlap with: ") + OtherActor->GetName();
	//if (GEngine) {
	//	GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Red, OtherActorName);
	//}
	ASlashCharacter* SlashCharacter = Cast<ASlashCharacter>(OtherActor);
	if (SlashCharacter)
	{
		SlashCharacter->SetOverlappingItem(nullptr);
	}
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Movement rate in units of cm/s
	//float MovementRate = 50.f;
	//float RotationRate = 45.f;

	//MovementRate * DelaTime (cm/s) * (s/frame)  = (cm/ frame) so 50 cm/s regardless of frame rate
	//AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));  // every frame add 1 to actor's location
	//AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));


	RunningTime += DeltaTime;

	//float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);  // multiply by amplitude to set wave height and multiply runningtime to speed up wave (frequency)
	//AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, DeltaZ));

	//DRAW_SPHERE_SingleFrame(GetActorLocation());
	//DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

	//FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	//DRAW_POINT_SingleFrame(AvgVector);


	//UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);

	//if (GEngine) {
	//	FString Name = GetName();
	//	FString Message = FString::Printf(TEXT("Item Name: %s"), *Name);
	//	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Green, Message);
	//	//UE_LOG(LogTemp, Warning, TEXT("Item Name: %s"), *Name);
	//}

}


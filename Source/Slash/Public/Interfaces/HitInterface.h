#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HitInterface.generated.h"

UINTERFACE(MinimalAPI)
class UHitInterface : public UInterface
{
	GENERATED_BODY()
};


class SLASH_API IHitInterface
{
	GENERATED_BODY()
	
public:
	// - Virtual function designed to be overriden in the child class.  e.g - so sword doesn't have to know details of how a thing reacts to a hit
	// - Otherwise a sword would need to know what was hit and call a different function for each type of object hit
	UFUNCTION(BlueprintNativeEvent)
    void GetHit(const FVector& ImpactPoint, AActor* Hitter);
};

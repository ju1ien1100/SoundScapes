// AudioEmitterSettings.h

#pragma once

#include "CoreMinimal.h"
#include "GameFrameworks/Actor.h"
#include "Componentes/PrimitiveComponent.h"
#include "PhysicalMaterials/PhysicalMaterial.h"

/**
 * Holds settings for an individual audio emitter.
 */
class SPATIALAUDIOPLUGIN_API AudioEmitterSettings
{
public:
    // Constructor
    AudioEmitterSettings();


    void SetPosition(const FVector& NewPosition);
    void SetOwner(AActor* NewOwner);
    void SetMaterial(UPhysicalMaterial* NewMaterial);
    void SetMass(float NewMass);
    void SetShape(FVector NewShape);
    void SetDensity(float NewDensity);

    FVector GetPosition() const;
    UPhysicalMaterial* GetMaterial() const;
    float GetMass() const;
    FVector GetShape() const;
    float GetDensity() const;


private:
    FVector Position;
    AActor* Owner;
    UPhysicalMaterial* Material;
    float Mass;
    FVector Shape;
    float Density;  
};

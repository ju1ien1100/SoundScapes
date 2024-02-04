// AudioEmitterSettings.h

#pragma once

#include "CoreMinimal.h"

/**
 * Holds settings for an individual audio emitter.
 */
class SPATIALAUDIOPLUGIN_API AudioEmitterSettings
{
public:
    // Constructor
    AudioEmitterSettings();

    // Setters
    void SetVolume(float NewVolume);
    void SetPitch(float NewPitch);
    void SetPosition(const FVector& NewPosition);

    // Getters
    float GetVolume() const;
    float GetPitch() const;
    FVector GetPosition() const;

private:
    float Volume;
    float Pitch;
    FVector Position;
};

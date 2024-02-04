// AudioListenerSettings.h

#pragma once

#include "CoreMinimal.h"

/**
 * Holds settings for the audio listener.
 */
class SPATIALAUDIOPLUGIN_API AudioListenerSettings
{
public:
    // Constructor
    AudioListenerSettings();

    // Setters
    void SetPosition(const FVector& NewPosition);
    void SetOrientation(const FRotator& NewOrientation);

    // Getters
    FVector GetPosition() const;
    FRotator GetOrientation() const;

private:
    FVector Position;
    FRotator Orientation;
};

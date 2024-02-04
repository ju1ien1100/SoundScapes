// AudioEnvironmentSettings.h
#pragma once

#include "CoreMinimal.h"

/**
 * Holds settings for environmental audio effects.
 */
class SPATIALAUDIOPLUGIN_API AudioEnvironmentSettings
{
public:
    // Constructor
    AudioEnvironmentSettings();

    // Setter methods for the settings
    void SetReverbLevel(float NewReverbLevel);
    void SetEchoDelay(float NewEchoDelay);
    void SetOcclusionFactor(float NewOcclusionFactor);

    // Getter methods for the settings
    float GetReverbLevel() const;
    float GetEchoDelay() const;
    float GetOcclusionFactor() const;

private:
    // Reverb, echo, occlusion settings, etc.
    float ReverbLevel;
    float EchoDelay;
    float OcclusionFactor;
};
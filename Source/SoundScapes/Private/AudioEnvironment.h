#pragma once

#include "CoreMinimal.h"
#include "AudioEnvironmentSettings.h"

/**
 * Manages and applies environmental audio properties.
 */
class SPATIALAUDIOPLUGIN_API AudioEnvironment
{
public:
    // Constructor
    AudioEnvironment();

    // Applies the environmental settings to the audio engine or a specific area
    void ApplySettings(const AudioEnvironmentSettings& Settings);

    // Update environmental effects dynamically
    void UpdateReverbLevel(float NewReverbLevel);
    void UpdateEchoDelay(float NewEchoDelay);
    void UpdateOcclusionFactor(float NewOcclusionFactor);

    // More functions...

private:
    AudioEnvironmentSettings EnvironmentSettings;
    // Other private properties related to the environmental effects...
};

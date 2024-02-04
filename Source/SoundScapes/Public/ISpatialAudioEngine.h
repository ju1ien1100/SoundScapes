#pragma once

#include "SpatialAudioSettings.h"

/**
 * Interface for spatial audio engines.
 */
class ISpatialAudioEngine
{
public:
    virtual ~ISpatialAudioEngine() {}

    // Initializes the engine with specific settings
    virtual void Initialize(const SpatialAudioSettings& Settings) = 0;

    // Processes the audio for a single frame
    virtual void ProcessAudioFrame() = 0;

    // Updates the engine settings dynamically
    virtual void UpdateSettings(const SpatialAudioSettings& NewSettings) = 0;

    // Shuts down the engine and cleans up resources
    virtual void Shutdown() = 0;
};
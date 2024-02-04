#pragma once

#include "CoreMinimal.h"
#include "AudioEngineSettings.h"

/**
 * SpatialAudioEngine class manages the spatial audio simulation.
 */
class SPATIALAUDIOPLUGIN_API SpatialAudioEngine
{
public:
    SpatialAudioEngine();
    virtual ~SpatialAudioEngine();

    // Initializes the engine with settings
    virtual void Initialize(const AudioEngineSettings& Settings);

    // Main processing function for audio frames
    virtual void ProcessAudioFrame();

    // Updates engine settings dynamically
    virtual void UpdateSettings(const AudioEngineSettings& NewSettings);

    // Shuts down the engine, releasing resources
    virtual void Shutdown();

protected:
    // Helper methods for internal use
    void AllocateResources();
    void DeallocateResources();
    void ApplyAudioEnvironment();
    void ProcessEmitters();
    void ProcessListener();

private:
    AudioEngineSettings CurrentSettings;
    // Additional internal state variables as needed
};
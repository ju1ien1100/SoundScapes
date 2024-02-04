#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AudioEnvironmentSettings.h"
#include "AudioEmitterSettings.h"
#include "AudioListenerSettings.h"
#include "OptimizationSettings.h"

/**
 * SpatialAudioSettings encapsulates all settings related to the spatial audio engine.
 */
class SPATIALAUDIOPLUGIN_API SpatialAudioSettings
{
public:
    // Environmental acoustic properties
    AudioEnvironmentSettings EnvironmentSettings;

    // Sound source properties
    TArray<AudioEmitterSettings> EmitterSettings;

    // Listener properties, assuming a single listener for simplicity
    AudioListenerSettings ListenerSettings;

    // Optimization settings for the audio engine
    OptimizationSettings EngineOptimizationSettings;

    // Constructor
    SpatialAudioSettings();

    // Functions to adjust settings dynamically, demonstrating selective processing
    void SetEnvironmentReverb(const FReverbSettings& NewReverbSettings);
    void AddEmitter(const FAudioEmitterSettings& NewEmitterSettings);
    void UpdateListenerPosition(const FVector& NewPosition);

    // Optimization-related functions
    void AdjustProcessingLevelOfDetail(float DistanceToListener);
    void CullAndVirtualizeEmitters(float ListenerThreshold);

private:
    // Internal functions for optimization
    void UpdateEmitterProcessing();
    void ApplySelectiveProcessing();
};

SpatialAudioSettings::SpatialAudioSettings()
{
    // Initialize with default settings or load from a configuration
}

void SpatialAudioSettings::SetEnvironmentReverb(const FReverbSettings& NewReverbSettings)
{
    EnvironmentSettings.ReverbSettings = NewReverbSettings;
    // Apply changes immediately or flag for deferred processing
    ApplySelectiveProcessing();
}

void SpatialAudioSettings::AddEmitter(const FAudioEmitterSettings& NewEmitterSettings)
{
    EmitterSettings.Add(NewEmitterSettings);
    // Recalculate emitter processing based on new emitter's properties
    UpdateEmitterProcessing();
}

void SpatialAudioSettings::UpdateListenerPosition(const FVector& NewPosition)
{
    ListenerSettings.Position = NewPosition;
    // Adjust processing based on listener's new position
    CullAndVirtualizeEmitters(ListenerSettings.CullingThreshold);
}

void SpatialAudioSettings::AdjustProcessingLevelOfDetail(float DistanceToListener)
{
    // Adjust processing based on distance to listener
    // Placeholder for implementation

}

void SpatialAudioSettings::CullAndVirtualizeEmitters(float ListenerThreshold)
{
    // Determine which emitters to process fully, which to virtualize, and which to cull
    // Placeholder for implementation
}

void SpatialAudioSettings::UpdateEmitterProcessing()
{
    // Adjust emitter processing based on new or updated emitters
    // Placeholder for implementation
}

void SpatialAudioSettings::ApplySelectiveProcessing()
{
    // Apply or defer processing based on current optimization settings and engine state
    // Placeholder for implementation
}
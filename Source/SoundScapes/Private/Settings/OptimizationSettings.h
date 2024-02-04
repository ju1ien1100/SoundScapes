#pragma once

#include "CoreMinimal.h"

/**
 * Holds settings for optimizing the spatial audio engine's performance.
 */
class SPATIALAUDIOPLUGIN_API OptimizationSettings
{
public:
    // Constructor
    OptimizationSettings();

    // Setters for optimization parameters
    void SetMaxAudioSources(int32 NewMaxAudioSources);
    void SetDistanceThreshold(float NewDistanceThreshold);
    void SetQualityLevel(EAudioQualityLevel NewQualityLevel);

    // Getters for optimization parameters
    int32 GetMaxAudioSources() const;
    float GetDistanceThreshold() const;
    EAudioQualityLevel GetQualityLevel() const;

private:
    // The maximum number of audio sources to process simultaneously
    int32 MaxAudioSources;

    // The distance threshold for audio source processing
    float DistanceThreshold;

    // The quality level of audio processing
    EAudioQualityLevel QualityLevel;
};

// Corresponding methods would be defined in OptimizationSettings.cpp

// Enum to define audio quality levels
enum class EAudioQualityLevel
{
    Low,
    Medium,
    High
};

// Default constructor implementation
OptimizationSettings::OptimizationSettings()
    : MaxAudioSources(32), // Example default value
    DistanceThreshold(1000.0f), // Example default value in Unreal units
    QualityLevel(EAudioQualityLevel::Medium) // Example default value
{
    // Constructor body can be empty if defaults are set in the initializer list
}

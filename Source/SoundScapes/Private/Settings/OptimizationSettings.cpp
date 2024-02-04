#include "OptimizationSettings.h"

// Constructor implementation
OptimizationSettings::OptimizationSettings()
    : MaxAudioSources(32), // Set the default max audio sources
    DistanceThreshold(1000.0f), // Set the default distance threshold
    QualityLevel(EAudioQualityLevel::Medium) // Set the default quality level
{
    // Empty constructor - Initialization is done via the initializer list
}

// Set the maximum number of audio sources to be processed
void OptimizationSettings::SetMaxAudioSources(int32 NewMaxAudioSources)
{
    MaxAudioSources = NewMaxAudioSources;
}

// Set the distance threshold for audio source processing
void OptimizationSettings::SetDistanceThreshold(float NewDistanceThreshold)
{
    DistanceThreshold = NewDistanceThreshold;
}

// Set the quality level for audio processing
void OptimizationSettings::SetQualityLevel(EAudioQualityLevel NewQualityLevel)
{
    QualityLevel = NewQualityLevel;
}

// Get the current maximum number of audio sources allowed
int32 OptimizationSettings::GetMaxAudioSources() const
{
    return MaxAudioSources;
}

// Get the current distance threshold for audio source processing
float OptimizationSettings::GetDistanceThreshold() const
{
    return DistanceThreshold;
}

// Get the current quality level of audio processing
EAudioQualityLevel OptimizationSettings::GetQualityLevel() const
{
    return QualityLevel;
}
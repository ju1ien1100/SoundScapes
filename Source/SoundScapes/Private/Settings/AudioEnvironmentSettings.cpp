// AudioEnvironmentSettings.cpp
#include "AudioEnvironmentSettings.h"

AudioEnvironmentSettings::AudioEnvironmentSettings()
    : ReverbLevel(0.5f), EchoDelay(0.25f), OcclusionFactor(0.75f) {}

void AudioEnvironmentSettings::SetReverbLevel(float NewReverbLevel)
{
    ReverbLevel = NewReverbLevel;
}

void AudioEnvironmentSettings::SetEchoDelay(float NewEchoDelay)
{
    EchoDelay = NewEchoDelay;
}

void AudioEnvironmentSettings::SetOcclusionFactor(float NewOcclusionFactor)
{
    OcclusionFactor = NewOcclusionFactor;
}

float AudioEnvironmentSettings::GetReverbLevel() const
{
    return ReverbLevel;
}

float AudioEnvironmentSettings::GetEchoDelay() const
{
    return EchoDelay;
}

float AudioEnvironmentSettings::GetOcclusionFactor() const
{
    return OcclusionFactor;
}
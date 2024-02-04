#include "AudioEmitterSettings.h"

// Constructor implementation
AudioEmitterSettings::AudioEmitterSettings()
    : Volume(1.0f), // Default volume
    Pitch(1.0f), // Default pitch
    Position(FVector::ZeroVector) // Default position
{
    // Constructor body can be empty if defaults are set in the initializer list
}

// Set the volume of the audio emitter
void AudioEmitterSettings::SetVolume(float NewVolume)
{
    Volume = NewVolume;
}

// Set the pitch of the audio emitter
void AudioEmitterSettings::SetPitch(float NewPitch)
{
    Pitch = NewPitch;
}

// Set the position of the audio emitter
void AudioEmitterSettings::SetPosition(const FVector& NewPosition)
{
    Position = NewPosition;
}

// Get the volume of the audio emitter
float AudioEmitterSettings::GetVolume() const
{
    return Volume;
}

// Get the pitch of the audio emitter
float AudioEmitterSettings::GetPitch() const
{
    return Pitch;
}

// Get the position of the audio emitter
FVector AudioEmitterSettings::GetPosition() const
{
    return Position;
}
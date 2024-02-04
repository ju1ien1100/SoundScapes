#include "AudioListenerSettings.h"

// Constructor implementation
AudioListenerSettings::AudioListenerSettings()
    : Position(FVector::ZeroVector), // Default position at the origin
    Orientation(FRotator::ZeroRotator) // Default orientation with no rotation
{
    // Constructor body can be empty if defaults are set in the initializer list
}

// Set the position of the audio listener
void AudioListenerSettings::SetPosition(const FVector& NewPosition)
{
    Position = NewPosition;
}

// Set the orientation of the audio listener
void AudioListenerSettings::SetOrientation(const FRotator& NewOrientation)
{
    Orientation = NewOrientation;
}

// Get the position of the audio listener
FVector AudioListenerSettings::GetPosition() const
{
    return Position;
}

// Get the orientation of the audio listener
FRotator AudioListenerSettings::GetOrientation() const
{
    return Orientation;
}
#include "AudioEmitter.h"



// Constructor implementation
AudioEmitter::AudioEmitter()
    : AudioClip(nullptr), bIsPlaying(false), bIsLooping(false)
{
    // Initialize with default settings or specific requirements
}

// Initialize the emitter with specific settings
void AudioEmitter::Initialize(const AudioEmitterSettings& Settings)
{
    EmitterSettings = Settings;
    // Additional initialization code...
}

// Destructor implementation
AudioEmitter::~AudioEmitter()
{
    // Code for cleanup or releasing resources
}
// Plays the audio associated with the emitter
void AudioEmitter::Play()
{
    if (AudioClip && !bIsPlaying)
    {
        // Code to play the sound
        bIsPlaying = true;
    }
}

// Stops the audio
void AudioEmitter::Stop()
{
    if (bIsPlaying)
    {
        // Code to stop the sound
        bIsPlaying = false;
    }
}

// Updates the emitter's position, volume, and pitch based on the settings
void AudioEmitter::Update(const AudioEmitterSettings& Settings)
{
    EmitterSettings = Settings;
    // Code to update the sound source properties
}

// Set the audio clip for the emitter
void AudioEmitter::SetAudioClip(USoundBase* NewAudioClip)
{
    AudioClip = NewAudioClip;
    // Additional code if needed...
}

// Set the emitter to loop audio
void AudioEmitter::SetLooping(bool bIsLooping)
{
    this->bIsLooping = bIsLooping;
    // Additional code if needed...
}
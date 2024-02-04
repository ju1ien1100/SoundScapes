#pragma once

#include "CoreMinimal.h"
#include "AudioEmitterSettings.h"
#include "Sound/SoundBase.h"

/**
 * Represents an audio source in 3D space.
 */
class SPATIALAUDIOPLUGIN_API AudioEmitter
{
public:
    // Constructor
    AudioEmitter();

    // Initializes the emitter with specific settings
    void Initialize(const AudioEmitterSettings& Settings);

    // Plays the audio associated with the emitter
    void Play();

    // Stops the audio
    void Stop();

    // Updates the emitter's position, volume, and pitch based on the settings
    void Update(const AudioEmitterSettings& Settings);

    // Setters for audio source properties
    void SetAudioClip(USoundBase* NewAudioClip);
    void SetLooping(bool bIsLooping);

    // More functions and properties...

private:
    AudioEmitterSettings EmitterSettings;
    USoundBase* AudioClip;
    bool bIsPlaying;
    bool bIsLooping;
    // More private properties and helper functions...
};

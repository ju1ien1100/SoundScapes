#include "AudioListener.h"

// Sets default values
AudioListener::AudioListener()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AudioListener::BeginPlay()
{
    Super::BeginPlay();

    // Initial update of listener settings
    UpdateListenerSettings();
}

// Called every frame
void AudioListener::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Update the listener settings each frame
    UpdateListenerSettings();
}

// Updates the listener settings based on the current actor's position and orientation
void AudioListener::UpdateListenerSettings()
{
    FVector NewPosition = GetActorLocation();
    FRotator NewOrientation = GetActorRotation();

    ListenerSettings.SetPosition(NewPosition);
    ListenerSettings.SetOrientation(NewOrientation);

    // Here you would typically pass the updated settings to the audio engine
    // For example, if you have a global audio manager:
    // GlobalAudioManager::GetInstance()->UpdateListenerSettings(ListenerSettings);
}
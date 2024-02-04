#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AudioListenerSettings.h"

/**
 * Represents the listener in the 3D audio environment.
 */
class SPATIALAUDIOPLUGIN_API AudioListener : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AudioListener();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:
    AudioListenerSettings ListenerSettings;

    // Updates the listener settings based on the current actor's position and orientation
    void UpdateListenerSettings();
};
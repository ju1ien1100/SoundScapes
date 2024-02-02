#include "SpatialAudioEngine.h"
#include "Math/UnrealMathUtility.h" // For FMath functions
#include "Sound/SoundWave.h"
#include "Kismet/GameplayStatics.h"
#include "DSP/ConvolutionReverb.h"



SpatialAudioEngine::SpatialAudioEngine() {
    // Constructor initialization logic
    ImpulseResponse = LoadImpulseResponse();
}

SpatialAudioEngine::~SpatialAudioEngine() {
    Shutdown(); // Ensure all resources are properly released
}

void SpatialAudioEngine::Initialize(const AudioEngineSettings& Settings) {
    CurrentSettings = Settings;
    AllocateResources();
    // Apply initial settings, set up the audio environment, etc.
    // More complex initialization code here
}

void SpatialAudioEngine::ProcessAudioFrame() {
    // Process spatial audio each frame
    ApplyAudioEnvironment();
    ProcessEmitters();
    ProcessListener();
}

void SpatialAudioEngine::UpdateSettings(const AudioEngineSettings& NewSettings) {
    CurrentSettings = NewSettings;
    // Update settings and reallocate resources as needed
    // More complex settings update code here
}

void SpatialAudioEngine::Shutdown() {
    DeallocateResources();
    // Clean up and shutdown logic here
}

void SpatialAudioEngine::AllocateResources() {
    // Allocate or reallocate memory/resources based on CurrentSettings
    // More complex resource allocation logic here
}

void SpatialAudioEngine::DeallocateResources() {
    // Properly deallocate any dynamically allocated resources
    // More complex resource deallocation logic here
}

void SpatialAudioEngine::ApplyAudioEnvironment() {
    // Apply environmental effects based on CurrentSettings.EnvironmentSettings
    // More complex environmental effect application logic here
}

void SpatialAudioEngine::ProcessEmitters() {
    // Iterate over all audio emitters, applying spatial processing
    for (AudioEmitterSettings& emitter : CurrentSettings.EmitterSettings) {
        FVector listenerPosition = CurrentSettings.ListenerSettings.Position;
        FVector emitterPosition = emitter.GetPosition();
        float distance = FVector::Dist(listenerPosition, emitterPosition);

        // Perform optimized attenuation calculations
        float attenuation = CalculateAttenuation(distance, emitter, CurrentSettings.EnvironmentSettings);
        emitter.SetVolume(attenuation * emitter.GetVolume());

        // Apply reverb, echo, and other environmental effects
        ApplyEnvironmentalEffects(emitter, CurrentSettings.EnvironmentSettings);
    }
}

void SpatialAudioEngine::ProcessListener() {
    // Update the listener's position and orientation based on CurrentSettings.ListenerSettings
    // Listener update logic here
}

float SpatialAudioEngine::CalculateAttenuation(float Distance, const AudioEmitterSettings& EmitterSettings, const AudioEnvironmentSettings& EnvSettings) {
    // Calculate attenuation using a more complex model, such as the logarithmic attenuation
    float attenuation = FMath::Clamp(1.0f - FMath::Loge(Distance / EnvSettings.AttenuationDistance), 0.0f, 1.0f);

    // Factor in occlusion, reverb, and other environmental effects
    attenuation *= (1.0f - EnvSettings.GetOcclusionFactor());

    // Further attenuation based on other environmental factors
    return attenuation;
}

void SpatialAudioEngine::ApplyEnvironmentalEffects(AudioEmitterSettings& EmitterSettings, const AudioEnvironmentSettings& EnvSettings) {
    // Apply reverb using a convolution reverb algorithm with impulse responses
    float reverbAmount = EnvSettings.GetReverbLevel();
    ApplyConvolutionReverb(EmitterSettings, reverbAmount);

    // Apply echo using a delay line algorithm with feedback and filtering
    float echoAmount = EnvSettings.GetEchoDelay();
    ApplyEcho(EmitterSettings, echoAmount);
}

void SpatialAudioEngine::ApplyConvolutionReverb(AudioEmitterSettings& EmitterSettings, float ReverbAmount) {
    // Initialize the preset with your impulse response
    USubmixEffectConvolutionReverbPreset* ConvolutionReverbPreset = NewObject<USubmixEffectConvolutionReverbPreset>();
    ConvolutionReverbPreset->InitSettings(ImpulseResponse);

    // Apply the preset to the emitter's submix
    EmitterSettings.GetAudioComponent()->SetSubmixSend(ConvolutionReverbPreset->Submix, ReverbAmount);
}

// For echo, you will need to implement a delay line with a feedback loop
// This is a simplified example and doesn't represent actual Unreal Engine code
void SpatialAudioEngine::ApplyEcho(AudioEmitterSettings& EmitterSettings, float EchoAmount) {
    // Example delay line implementation
    TArray<float> DelayLine;
    float FeedbackAmount = EchoAmount; // Set based on EchoAmount
    float FilterCoefficient = 1 / EchoAmount; // Set based on desired echo characteristics

    for (int32 i = 0; i < EmitterSettings.AudioData.Num(); ++i) {
        float InputSample = EmitterSettings.AudioData[i];
        float DelayedSample = DelayLine.Last(0.0f); // Get the last sample in the delay line
        float OutputSample = InputSample + DelayedSample * FeedbackAmount;

        // Apply a simple low-pass filter
        OutputSample = FMath::Lerp(DelayedSample, OutputSample, FilterCoefficient);

        DelayLine.Add(OutputSample);
        EmitterSettings.AudioData[i] = OutputSample;

        // Keep the delay line at a fixed size
        if (DelayLine.Num() > MaxDelayLineSize) {
            DelayLine.RemoveAt(0);
        }
    }
}

USoundWave* SpatialAudioEngine::LoadImpulseResponse() {
    // Load the impulse response from a file or other source
    return Cast<USoundWave>(UGameplayStatics::LoadAssetFromPath(TEXT("ImpulseResponse.wav")));
}

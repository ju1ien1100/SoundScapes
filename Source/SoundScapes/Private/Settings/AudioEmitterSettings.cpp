#include "AudioEmitterSettings.h"

// Constructor implementation
AudioEmitterSettings::AudioEmitterSettings()
    : Volume(1.0f), // Default volume
    Pitch(1.0f), // Default pitch
    Position(FVector::ZeroVector) // Default position
{
    // Constructor body can be empty if defaults are set in the initializer list
}

// Set the position of the audio emitter
void AudioEmitterSettings::SetPosition(const FVector& NewPosition)
{
    Position = NewPosition;
}

void AudioEmitterSettings::SetOwner(AActor* NewOwner)
{
    if (IsValid(NewOwner)) {
		Owner = NewOwner;
		SetPosition(Owner->GetActorLocation());
	}
    else {
		Owner = nullptr;
	
	}
}


void AudioEmitterSettings::SetMaterial()
{
    AActor* Owner = GetOwner();
    if (IsValid(Owner)) {
        UPhysicalMaterial* Material = Owner->GetMaterial();
        if (IsValid(Material)) {
			Material = NewMaterial;
		}
    }

}

void AudioEmitterSettings::SetMass()
{
    AActor* Owner = GetOwner();
    if (IsValid(Owner)) {
        float Mass = Owner->GetMass();
        if (Mass > 0) {
        Mass = NewMass;
        }
    }

}

void AudioEmitterSettings::SetShape()
{
	AActor* Owner = GetOwner();
    if (IsValid(Owner)) {
		UPrimitiveComponent* Shape = Owner->GetShape();
        if (IsValid(Shape)) {
			Shape = NewShape;
		}
	}

}

void AudioEmitterSettings::SetDensity(float NewDensity)
{
    AActor* Owner = GetOwner();
    if (IsValid(Owner)) {
        Density = Owner->GetDensity();
    }
}

float AudioEmitterSettings::GetDensity() const
{
	return Density;
}

AActor* AudioEmitterSettings::GetOwner() const
{
	return Owner;
}

UPrimitiveComponent* AudioEmitterSettings::GetShape() const
{
	return Shape;
}

UPhysicalMaterial* AudioEmitterSettings::GetMaterial() const
{
	return Material;
}

float AudioEmitterSettings::GetMass() const
{
	return Mass;
}



// Get the position of the audio emitter
FVector AudioEmitterSettings::GetPosition() const
{
    return Position;
}
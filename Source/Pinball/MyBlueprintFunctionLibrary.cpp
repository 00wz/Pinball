// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

FRotator UMyBlueprintFunctionLibrary::DeltaShortest(FRotator A, FRotator B)
{
	FQuat AQuat(A);
	FQuat BQuat(B);

	//FQuat Result = AQuat - BQuat;
	FQuat Result = BQuat.Inverse() * AQuat;
	
	return Result.Rotator();

}

FQuat UMyBlueprintFunctionLibrary::DeltaQuat(FQuat A, FQuat B)
{
	//return  A - B;
	//qDelta = qTo * qFrom.inverse()
	return A * B.Inverse();
	//return B.Inverse() * A;
}

FQuat UMyBlueprintFunctionLibrary::RotatorToQuat(FRotator A)
{
	return FQuat(A);
}

FQuat UMyBlueprintFunctionLibrary::LerpQuat(FQuat A, FQuat B, float Alpha)
{
	return FMath::Lerp(A, B, Alpha);
}

FQuat UMyBlueprintFunctionLibrary::DivideQuat(FQuat A, float Scale)
{
	return  (A / Scale).GetNormalized();
}

FQuat UMyBlueprintFunctionLibrary::SphericalScaleQuat(const FQuat& Quat, float Slerp)
{
	return FQuat::Slerp/*FullPath*/(FQuat::Identity, Quat, Slerp);
}

FVector UMyBlueprintFunctionLibrary::GetRotateVector(FRotator A)
{
	return A.Euler();
}

FQuat UMyBlueprintFunctionLibrary::GetRotationQuat(USceneComponent* sceneComponent)
{
	return sceneComponent -> GetComponentTransform().GetRotation();
}

FQuat UMyBlueprintFunctionLibrary::TransformQuat(FTransform Transform, FQuat Quat)
{
	return Transform.TransformRotation(Quat);
}

FQuat UMyBlueprintFunctionLibrary::GetQuatFromAxisAngle(FVector Axis, float AngleRad)
{
	return FQuat(Axis, AngleRad);
}

void UMyBlueprintFunctionLibrary::AddWorldRotatoin(USceneComponent *sceneComponent, const FQuat& DeltaRotation, bool bSweep)
{
	sceneComponent -> AddWorldRotation(DeltaRotation, bSweep);
}

void UMyBlueprintFunctionLibrary::SetWorldRotatoin(USceneComponent* sceneComponent, const FQuat& NewRotation,
	bool bSweep)
{
	sceneComponent -> SetWorldRotation(NewRotation, bSweep);
}

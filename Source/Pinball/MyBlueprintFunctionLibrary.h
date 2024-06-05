// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PINBALL_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, Category = "Rotator")
	static FRotator DeltaShortest(FRotator A, FRotator B);
	
	UFUNCTION(BlueprintPure, Category = "Quaternion")
	static FQuat DeltaQuat(FQuat A, FQuat B);
	
	UFUNCTION(BlueprintPure, Category = "Quaternion")
	static FQuat RotatorToQuat(FRotator A);
	
	UFUNCTION(BlueprintPure, Category = "Quaternion")
	static FQuat LerpQuat(FQuat A, FQuat B, float Alpha);
	
	UFUNCTION(BlueprintPure, Category = "Quaternion")
	static FQuat DivideQuat(FQuat A, float Scale);
	
	UFUNCTION(BlueprintPure, Category = "Quaternion")
	static FQuat SphericalScaleQuat(const FQuat &Quat, float Slerp);
	
	UFUNCTION(BlueprintPure, Category = "Rotator")
	static FVector GetRotateVector(FRotator A);
		
	UFUNCTION(BlueprintPure, Category = "Quaternion")
	static FQuat GetRotationQuat(USceneComponent *sceneComponent);
		
	UFUNCTION(BlueprintCallable, Category = "Quaternion")
	static void AddWorldRotatoin(USceneComponent *sceneComponent, const FQuat& DeltaRotation, bool bSweep=false);		

	UFUNCTION(BlueprintCallable, Category = "Quaternion")
	static void SetWorldRotatoin(USceneComponent *sceneComponent, const FQuat& NewRotation, bool bSweep=false);
};

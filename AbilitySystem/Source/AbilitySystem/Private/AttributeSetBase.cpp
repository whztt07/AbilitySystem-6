// Fill out your copyright notice in the Description page of Project Settings.

#include "AttributeSetBase.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffect.h"
#include "ObjectMacros.h"

UAttributeSetBase::UAttributeSetBase()
	: Health(200.0f)
{

}

void UAttributeSetBase::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data)
{
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health)))
	{
		UE_LOG(LogTemp, Warning, TEXT("Ouch, I Took some damage, now my health is: %f"), Health.GetCurrentValue());
	}
}

#include "Entity.h"

namespace Sunspear
{

IComponent* Entity::FindComponent(const RTTI* inRTTI)
{
	return const_cast<IComponent*>(static_cast<const Entity*>(this)->FindComponent(inRTTI));;
}

const IComponent* Entity::FindComponent(const RTTI* inRTTI) const
{
	for (auto& c : mComponents)
		if (c->IsA(inRTTI))
			return c.get();

	return nullptr;
}

}

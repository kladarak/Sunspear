#pragma once

#include <vector>
#include <memory>

#include "Core/RTTI.h"

namespace Sunspear
{
	class IComponent
	{
		DECLARE_RTTI_ROOT(IComponent)
	};

	class Entity
	{
	public:
		IComponent* FindComponent(const RTTI* inRTTI);
		const IComponent* FindComponent(const RTTI* inRTTI) const;

		template<typename T, typename... Args>
		T& CreateComponent(Args&&... inArgs)
		{
			auto c = std::make_unique<T>(std::forward<Args>(inArgs)...);
			mComponents.push_back(std::move(c));
			return static_cast<T&>(*mComponents.back());
		};

		template<typename T>
		T* FindComponent()
		{
			return static_cast<T*>(FindComponent(T::StaticGetType()));
		}

		template<typename T>
		const T* FindComponent() const
		{
			return static_cast<const T*>(FindComponent(T::StaticGetType()));
		}

	private:
		std::vector<std::unique_ptr<IComponent>> mComponents;
	};
}

#include "Entity.h"

#include <assert.h>

namespace
{
	using namespace Sunspear;

	class ComponentA : public IComponent
	{
		DECLARE_RTTI(ComponentA, IComponent)
	};

	class ComponentB : public IComponent
	{
		DECLARE_RTTI(ComponentB, IComponent)
	};

	class ComponentC : public ComponentA
	{
		DECLARE_RTTI(ComponentC, ComponentA)
	};
}

void DoEntityUnitTests()
{
	Entity e;

	auto& a = e.CreateComponent<ComponentA>();
	auto& b = e.CreateComponent<ComponentB>();
	auto& c = e.CreateComponent<ComponentC>();

	// Note, C is an A, but due to order of
	// insertion, A is found first when looking for A
	// rather than finding C (which also matches)
	assert(e.FindComponent<ComponentA>() == &a);
	assert(e.FindComponent<ComponentB>() == &b);
	assert(e.FindComponent<ComponentC>() == &c);
}

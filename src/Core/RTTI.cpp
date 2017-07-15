#include <stdafx.h>
#include "RTTI.h"
#include <assert.h>

namespace Sunspear
{

namespace
{
	class BaseA
	{
		DECLARE_RTTI_ROOT(BaseA)
	};

	class DerivedA : public BaseA
	{
		DECLARE_RTTI(DerivedA, BaseA)
	};

	class DerivedA2 : public DerivedA
	{
		DECLARE_RTTI(DerivedA2, DerivedA)
	};

	class BaseB
	{
		DECLARE_RTTI_ROOT(BaseB)
		//DECLARE_RTTI_ROOT(BaseA) // Test correct class type compiler assertion
		//DECLARE_RTTI(BaseB, BaseB) // Test compiler error for using wrong macro
	};

	class DerivedB : public BaseB
	{
		DECLARE_RTTI(DerivedB, BaseB)
		//DECLARE_RTTI(DerivedA, BaseA) // Test correct class type compiler assertion
		//DECLARE_RTTI(DerivedB, BaseA) // Test correct base type compiler assertion
		//DECLARE_RTTI(DerivedB, DerivedB)
	};

	template<typename T>
	void CheckAllTypes(bool isBaseA, bool isDerivedA, bool isDerivedA2,  bool isBaseB, bool isDerivedB)
	{
		T t;

		assert(t.IsA<BaseA>() == isBaseA);
		assert(t.IsA<DerivedA>() == isDerivedA);
		assert(t.IsA<DerivedA2>() == isDerivedA2);
		assert(t.IsA<BaseB>() == isBaseB);
		assert(t.IsA<DerivedB>() == isDerivedB);

		assert(!!t.AsA<BaseA>() == isBaseA);
		assert(!!t.AsA<DerivedA>() == isDerivedA);
		assert(!!t.AsA<DerivedA2>() == isDerivedA2);
		assert(!!t.AsA<BaseB>() == isBaseB);
		assert(!!t.AsA<DerivedB>() == isDerivedB);
	}
}

void RTTI::StaticRunUnitTests()
{
	CheckAllTypes<BaseA>	(true,	false,	false,	false,	false);
	CheckAllTypes<DerivedA>	(true,	true,	false,	false,	false);
	CheckAllTypes<DerivedA2>(true,	true,	true,	false,	false);
	CheckAllTypes<BaseB>	(false,	false,	false,	true,	false);
	CheckAllTypes<DerivedB>	(false,	false,	false,	true,	true);
}

}

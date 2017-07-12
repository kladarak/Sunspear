#pragma once

#include <string>

namespace Sunspear
{
	class RTTI
	{
	public:
		explicit RTTI(std::string&& inClassName, const RTTI* inParent = nullptr)
			: mParent(inParent)
			, mClassName(std::move(inClassName))
		{
		}

		RTTI(const RTTI&) = delete;
		RTTI(RTTI&&) = delete;
		RTTI& operator=(const RTTI&) = delete;
		RTTI& operator=(RTTI&&) = delete;

		bool IsA(const RTTI* inType) const { return this == inType || (mParent && mParent->IsA(inType)); }
		const std::string& GetClassName() const { return mClassName; }

		static void StaticRunUnitTests();

	private:
		const RTTI* mParent = nullptr;
		std::string mClassName;
	};
}

#define DECLARE_RTTI_ROOT(classname) \
public: \
static					const RTTI*	StaticGetType()					{ static const RTTI sType(#classname); return &sType; }	\
virtual					const RTTI*	GetType() const					{ return StaticGetType(); } \
						bool		IsA(const RTTI* inType) const	{ return GetType()->IsA(inType); } \
template<typename T>	bool		IsA() const						{ return IsA(T::StaticGetType()); } \
template<typename T>	T*			AsA()							{ return IsA<T>() ? (T*) (this) : nullptr; } \
template<typename T>	const T*	AsA() const						{ return IsA<T>() ? (const T*) (this) : nullptr; }

#define DECLARE_RTTI(classname, baseClass) \
public: \
static	const RTTI*	StaticGetType()				{ static const RTTI sType(#classname, baseClass::StaticGetType()); return &sType; }	\
virtual	const RTTI* GetType() const override	{ return StaticGetType(); }

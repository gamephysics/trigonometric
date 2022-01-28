#pragma once

//=============================================================================
// TYPEDEFS
//=============================================================================
typedef	unsigned long long  UInt64;
typedef   signed long long  Int64;
typedef		  unsigned int	UInt32;
typedef			signed int  Int32;
typedef unsigned short int  UInt16;
typedef   signed short int  Int16;
typedef       unsigned char UInt8;
typedef         signed char SByte;
typedef       unsigned char	Byte;

namespace core
{
	
	template <typename _Ty>
	bool InBounds(_Ty const& v, _Ty const& Min, _Ty const& Max)
	{
		return v<Min ? false : v>Max ? false : true;
	}

	template <typename _Ty> 
	_Ty  Abs(_Ty  a)
	{
		return (((a) < 0) ? -(a) : (a));
	}

};
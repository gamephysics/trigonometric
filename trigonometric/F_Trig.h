#pragma once

//============================================================================
// MATH CONSTANTS
//============================================================================
static const float F_PI					= 3.14159265358979323846f;	// 180¡Æ
static const float F_2PI				= 6.28318530717958647692f;	// 360
static const float F_PI_3_QUATER		= 2.356194490192344928845f;	// 135¡Æ
static const float F_PI_HALF			= 1.57079632679489661923f;	// 90¡Æ
static const float F_PI_1_QUATER		= 0.785398163397448309615f;	// 45¡Æ
static const float F_DEG_TO_RAD			= 0.017453292519943295769f;	// 0.01745329251994329576923690768489f;	
static const float F_RAD_TO_DEG			= 57.29577951308232087679f;	// 57.295779513082320876798154814105f;	


//============================================================================
// MATH INLNES
//============================================================================
inline float rad2deg(float radians)	{	return (radians)* F_RAD_TO_DEG;		}
inline float deg2rad(float degrees)	{	return (degrees)* F_DEG_TO_RAD;		}


//--------------------------------------------------------------------
// Code	: F_Trig
// Desc	: 
//--------------------------------------------------------------------
class F_Trig
{
public:
	static const Int32	SIN_TABLE_SIZE = 181;
	static const Int32	ACOS_TABLE_SIZE = 278;
	static float		SIN_TABLE[SIN_TABLE_SIZE];		// 0.5¡Æ Resolution Table (0 ~ 90¡Æ)
	static Byte			ACOS_TABLE[ACOS_TABLE_SIZE];		// Variable Resolution Table

public:
	//========================================================
	// Trig : These expect Deg to be between 0.0f and 360.0f
	//========================================================
	static float Sin(Int32 deg);
	static float Cos(Int32 deg);
	static float Tan(Int32 deg);
	//========================================================
	// Inverse 
	//========================================================
	static float ASin(float num);
	static float ACos(float num);
	static float ATan2(float opp, float adj);

};

//============================================================================--------
// MATH SIN/COS
// trigonometry functions are different, it's depends on compilers.
//============================================================================--------
//Rounding a number avoiding truncation:
inline Int32 FLOAT_TO_ROUNDUP_INTEGER(float input)
{
	return (Int32)(input + 0.5f);
}

inline Int32 RADIANS_TO_DEGREES_10_INTEGER(float radians)
{
	return (radians > 0) ? (Int32)(rad2deg(radians) + 0.5f) * 10 : (Int32)(rad2deg(radians) - 0.5f) * 10;
}

inline float F_Sin(float Rad)			{	return F_Trig::Sin(RADIANS_TO_DEGREES_10_INTEGER(Rad));	}
inline float F_Cos(float Rad)			{	return F_Trig::Cos(RADIANS_TO_DEGREES_10_INTEGER(Rad));	}
inline float F_Tan(float Rad)			{	return F_Trig::Tan(RADIANS_TO_DEGREES_10_INTEGER(Rad));	}
inline float F_Asin(float Val)			{	return F_Trig::ASin(Val);		}
inline float F_Acos(float Val)			{	return F_Trig::ACos(Val);		}
inline float F_Atan2(float y, float x)	{	return F_Trig::ATan2(y, x);		}
inline float F_SQRT(float Val)			{	return std::sqrt(Val);			}
inline float F_CEIL(float Val)			{	return std::ceil(Val);			}
inline float F_POWF(float b, float e)	{	return (float)std::pow(b, e);	}	
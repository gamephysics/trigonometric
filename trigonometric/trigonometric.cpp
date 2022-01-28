#include "trigonometric.h"


/// <summary>
/// 서버 클라이언트 즉 Windows, IOS, Android 의 전투연산이 정확하게 일치해야하는 경우가 아니라면
/// 사용할 필요는 없습니다. 성능이 std::sin 함수가 호출부하가 더 적다고  생각합니다.
/// <summary>
int main()
{
	static const float SIN_PRECISION = 0.0000005663f;	// sin cos value = ( -1 ~ 1 )
	static const float TAN_PRECISION = 0.0003585816f;	// 

	static const float ASIN_PRECISION= 0.0003585816f;	// 0.02054521229109925 degree
	static const float ATAN_PRECISION= 0.0140836250F;	// 0.8069322727469358  degree

	// SIN 함수 정밀도 비교
	for (float i = -360; i < (360 + 360); i += 1.0f)
	{
		auto Rad = deg2rad(i);
		auto Std = sin(Rad);
		auto Fix = F_Sin(Rad);

		assert(core::Abs(Std - Fix) < SIN_PRECISION);
	}

	// COS 함수 정밀도 비교
	for (float i = -360; i < (360 + 360); i += 1.0f)
	{
		auto Rad = deg2rad(i);
		auto Std = cos(Rad);
		auto Fix = F_Cos(Rad);

		assert(core::Abs(Std - Fix) < SIN_PRECISION);
	}
	
	// TAN 함수 정밀도 비교
	for (float i = -360; i <= 360; i += 1.0f)
	{
		auto Rad = deg2rad(i);
		auto Std = tan(Rad);
		auto Fix = F_Tan(Rad);
				
		assert(core::Abs(Std - Fix) < TAN_PRECISION);
	}
	
	// ASIN 함수 정밀도 비교
	for (float i = -1; i < 1; i += 0.5f)
	{
		auto Std = asin(i);
		auto Fix = F_Asin(i);

		assert(core::Abs(Std - Fix) <  ASIN_PRECISION);
	}

	// ACOS 함수 정밀도 비교
	for (float i = -1; i < 1; i += 0.5f)
	{
		auto Std = acos(i);
		auto Fix = F_Acos(i);

		assert(core::Abs(Std - Fix) < ASIN_PRECISION);
	}

	// ATAN2 함수 정밀도 비교
	for (float i = -100; i < 100; i += 0.5f)
	{
		for (float j = -100; j < 100; j += 0.5f)
		{
			auto Std = atan2(j, i);
			auto Fix = F_Atan2(j, i);

			assert(core::Abs(Std - Fix) < ATAN_PRECISION);
		}
	}

}
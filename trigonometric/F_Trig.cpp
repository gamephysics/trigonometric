#include "trigonometric.h"

//============================================================================
//  PRIVATE FUNCTIONS
//============================================================================
//Sin Lookup table
float F_Trig::SIN_TABLE[F_Trig::SIN_TABLE_SIZE] = {
	0.000000000f,	0.00872653536f,	0.0174524058f,	0.0261769500f,	0.0348994955f,	0.0436193869f,	0.0523359589f,	0.0610485412f,	0.0697564706f,	0.0784590989f,	0.0871557370f,	0.0958457515f,	0.104528464f,
	0.113203213f,	0.121869348f,	0.130526200f,	0.139173105f,	0.147809401f,	0.156434476f,	0.165047601f,	0.173648179f,	0.182235524f,	0.190808997f,	0.199367926f,	0.207911700f,	0.216439620f,
	0.224951044f,	0.233445361f,	0.241921902f,	0.250380009f,	0.258819044f,	0.267238379f,	0.275637358f,	0.284015357f,	0.292371690f,	0.300705791f,	0.309017003f,	0.317304641f,	0.325568140f,
	0.333806872f,	0.342020124f,	0.350207388f,	0.358367950f,	0.366501212f,	0.374606580f,	0.382683456f,	0.390731126f,	0.398749083f,	0.406736642f,	0.414693236f,	0.422618270f,	0.430511087f,
	0.438371152f,	0.446197808f,	0.453990489f,	0.461748600f,	0.469471574f,	0.477158755f,	0.484809607f,	0.492423564f,	0.500000000f,	0.507538378f,	0.515038073f,	0.522498548f,	0.529919267f,
	0.537299633f,	0.544639051f,	0.551936984f,	0.559192896f,	0.566406250f,	0.573576450f,	0.580702960f,	0.587785244f,	0.594822764f,	0.601814985f,	0.608761430f,	0.615661502f,	0.622514665f,
	0.629320383f,	0.636078179f,	0.642787576f,	0.649448037f,	0.656059027f,	0.662620068f,	0.669130623f,	0.675590158f,	0.681998372f,	0.688354552f,	0.694658399f,	0.700909257f,	0.707106769f,
	0.713250458f,	0.719339788f,	0.725374341f,	0.731353700f,	0.737277329f,	0.743144870f,	0.748955727f,	0.754709542f,	0.760405958f,	0.766044438f,	0.771624565f,	0.777145922f,	0.782608151f,
	0.788010716f,	0.793353319f,	0.798635542f,	0.803856850f,	0.809017003f,	0.814115524f,	0.819152057f,	0.824126184f,	0.829037547f,	0.833885849f,	0.838670552f,	0.843391478f,	0.848048091f,
	0.852640152f,	0.857167304f,	0.861629128f,	0.866025448f,	0.870355666f,	0.874619722f,	0.878817141f,	0.882947564f,	0.887010872f,	0.891006529f,	0.894934356f,	0.898794055f,	0.902585268f,
	0.906307817f,	0.909961283f,	0.913545489f,	0.917060077f,	0.920504808f,	0.923879504f,	0.927183867f,	0.930417597f,	0.933580399f,	0.936672211f,	0.939692616f,	0.942641497f,	0.945518553f,
	0.948323667f,	0.951056540f,	0.953716934f,	0.956304729f,	0.958819747f,	0.961261690f,	0.963630438f,	0.965925813f,	0.968147635f,	0.970295727f,	0.972369909f,	0.974370062f,	0.976296008f,
	0.978147626f,	0.979924679f,	0.981627166f,	0.983254910f,	0.984807730f,	0.986285627f,	0.987688363f,	0.989015877f,	0.990268052f,	0.991444826f,	0.992546141f,	0.993571877f,	0.994521916f,
	0.995396197f,	0.996194720f,	0.996917307f,	0.997564077f,	0.998134792f,	0.998629510f,	0.999048233f,	0.999390841f,	0.999657333f,	0.999847710f,	0.999961913f,	1.00000000f
};

// acos lookup table is split into three parts, which has a higher accuracy nearer acos(1).
//	- 0 to 0.9 is done in steps of 0.0079 rads.    (1/127)
//	- 0.9 to 0.99 is done in steps of 0.0008 rads. (0.01/127)
//	- 0.99 to 1 is done in steps of 0.0002 rads.   (0.01/64)
Byte F_Trig::ACOS_TABLE[F_Trig::ACOS_TABLE_SIZE] = {
  255, 254, 252, 251, 250, 249, 247, 246, 245, 243, 242, 241, 240, 238, 237, 236, 234, 233, 232, 231, 229, 228, 227, 225, 224, 223,
  221, 220, 219, 217, 216, 215, 214, 212, 211, 210, 208, 207, 206, 204, 203, 201, 200, 199, 197, 196, 195, 193, 192, 190, 189, 188,
  186, 185, 183, 182, 181, 179, 178, 176, 175, 173, 172, 170, 169, 167, 166, 164, 163, 161, 160, 158, 157, 155, 154, 152, 150, 149,
  147, 146, 144, 142, 141, 139, 137, 135, 134, 132, 130, 128, 127, 125, 123, 121, 119, 117, 115, 113, 111, 109, 107, 105, 103, 101,
  98, 96, 94, 92, 89, 87, 84, 81, 79, 76, 73, 73, 73, 72, 72, 72, 71, 71, 71, 70, 70, 70, 70, 69, 69, 69, 68, 68, 68, 67, 67, 67,
  66, 66, 66, 65, 65, 65, 64, 64, 64, 63, 63, 63, 62, 62, 62, 61, 61, 61, 60, 60, 59, 59, 59, 58, 58, 58, 57, 57, 57, 56, 56, 55,
  55, 55, 54, 54, 53, 53, 53, 52, 52, 51, 51, 51, 50, 50, 49, 49, 48, 48, 47, 47, 47, 46, 46, 45, 45, 44, 44, 43, 43, 42, 42, 41,
  41, 40, 40, 39, 39, 38, 37, 37, 36, 36, 35, 34, 34, 33, 33, 32, 31, 31, 30, 29, 28, 28, 27, 26, 25, 24, 23, 23, 23, 23, 22, 22,
  22, 22, 21, 21, 21, 21, 20, 20, 20, 19, 19, 19, 19, 18, 18, 18, 17, 17, 17, 17, 16, 16, 16, 15, 15, 15, 14, 14, 13, 13, 13, 12,
  12, 11, 11, 10, 10, 9, 9, 8, 7, 6, 6, 5, 3, 0
};

//--------------------------------------------------------------------
// Class: Sin()
// Desc	: The functions for Sin and Cos use lookup table to determine the Sin or Cos value of the input angle.
//	Input for these functions are scaled up 10 times. e.g. -450 = -45.0 deg
//  - Both functions return a value between -1 and 1. (e.g. input: -450, output -> -0.7071)
//--------------------------------------------------------------------
float F_Trig::Sin(Int32 deg)
{
	float result = 0;
	while (deg < 0)		{ deg += 3600; }
	while (deg >= 3600) { deg -= 3600; }

	//0 and 90 degrees.
	if ((deg >= 0) && (deg <= 900))
	{
		result = SIN_TABLE[deg / 5];
		//assert(core::InBounds<Int32>(deg / 5, 0, F_Trig::SIN_TABLE_SIZE));
	}
	//90 and 180 degrees.
	else if ((deg > 900) && (deg <= 1800))
	{
		result = SIN_TABLE[(1800 - deg) / 5];
		//assert(core::InBounds<Int32>((1800 - deg) / 5, 0, F_Trig::SIN_TABLE_SIZE));
	}
	//180 and 270 degrees.
	else if ((deg > 1800) && (deg <= 2700))
	{
		result = -SIN_TABLE[(deg - 1800) / 5];
		//assert(core::InBounds<Int32>((deg - 1800) / 5, 0, F_Trig::SIN_TABLE_SIZE));
	}
	//270 and 360 degrees.
	else if ((deg > 2700) && (deg <= 3600))
	{
		result = -SIN_TABLE[(3600 - deg) / 5];
		//assert(core::InBounds<Int32>((3600 - deg) / 5, 0, F_Trig::SIN_TABLE_SIZE));
	}
	//
	else
	{		
		//assert(false && "Overflow Degree 0~360");
	}

	return result;
}

//--------------------------------------------------------------------
// Class: Cos()
// Desc	: The functions for Sin and Cos use lookup table to determine the Sin or Cos value of the input angle.
//	Input for these functions are scaled up 10 times. e.g. -450 = -45.0 deg
//  - Both functions return a value between -1 and 1. (e.g. input: -450, output -> -0.7071)
//--------------------------------------------------------------------
float F_Trig::Cos(Int32 deg)
{
	float result = 0;
	while (deg < 0)		{ deg += 3600; }
	while (deg >= 3600) { deg -= 3600; }

	//0 and 90 degrees.
	if ((deg >= 0) && (deg <= 900))
	{
		result = SIN_TABLE[(900 - deg) / 5];
		//assert(core::InBounds<Int32>((900 - deg) / 5, 0, F_Trig::SIN_TABLE_SIZE));
	}
	//90 and 180 degrees.
	else if ((deg > 900) && (deg <= 1800))
	{
		result = -SIN_TABLE[(deg - 900) / 5];
		//assert(core::InBounds<Int32>((deg - 900) / 5, 0, F_Trig::SIN_TABLE_SIZE));
	}
	//180 and 270 degrees.
	else if ((deg > 1800) && (deg <= 2700))
	{
		result = -SIN_TABLE[(2700 - deg) / 5];
		//assert(core::InBounds<Int32>((2700 - deg) / 5, 0, F_Trig::SIN_TABLE_SIZE));
	}
	//270 and 360 degrees.
	else if ((deg >= 2700) && (deg <= 3600))
	{
		result = SIN_TABLE[(deg - 2700) / 5];
		//assert(core::InBounds<Int32>((deg - 2700) / 5, 0, F_Trig::SIN_TABLE_SIZE));
	}
	//
	else 
	{
		//assert(false && "Overflow Degree 0~360");
	}

	return result;
}

//--------------------------------------------------------------------
// Class: Tan()
// Desc	: tan(x) = sin(x) / cos(x) 
//--------------------------------------------------------------------
float F_Trig::Tan(Int32 deg)
{
	Int32 Sign = 0;
	while (deg < 0)		{ deg += 3600;	++Sign; }
	while (deg >= 3600) { deg -= 3600;	++Sign; }

	auto c = Cos(deg);
	if (c == 0)
	{
		if ((Sign % 2) == 0)
		{
			if (deg < 1800)	return (-22877332.f); 
			else			return (-83858280.f);
		}
		else
		{
			if (deg < 1800)	return (83858280.f); 
			else			return (22877332.f);
		}
	}

	return (Sin(deg) / c);
}

//--------------------------------------------------------------------
// Class: ASin()
// Desc	: asin(x)= pi/2 - acos(x) 
//--------------------------------------------------------------------
float F_Trig::ASin(float num)
{
	return F_PI_HALF - ACos(num);
}

//--------------------------------------------------------------------
// Class: ACos()
// Desc	: The ACos function uses a lookup table for corresponding output. 
// Output data are stored as byte values (0 - 255), they are scaled down to float number (0.0 - 1.0) for output.
//--------------------------------------------------------------------
float F_Trig::ACos(float num)
{
#define DEC4 10000

	float rads = 0;
	bool negative = false;

	//Get sign of input
	if (num < 0) { negative = true;	num = -num; }
	//num between 0 and 0.9.
	if ((num >= 0) && (num < 0.9))
	{
		rads = (float)ACOS_TABLE[FLOAT_TO_ROUNDUP_INTEGER(num * DEC4 / 79.f)] * 0.00616f;
		//assert(core::InBounds<Int32>(FLOAT_TO_ROUNDUP_INTEGER(num * DEC4 / 79.f), 0, F_Trig::ACOS_TABLE_SIZE));
	}
	//num between 0.9 and 0.99.
	else if ((num >= 0.9) && (num < 0.99))
	{
		rads = (float)ACOS_TABLE[FLOAT_TO_ROUNDUP_INTEGER((num * DEC4 - 9000.f) / 8.f) + 114] * 0.00616f;
		//assert(core::InBounds<Int32>(FLOAT_TO_ROUNDUP_INTEGER((num * DEC4 - 9000.f) / 8.f) + 114, 0, F_Trig::ACOS_TABLE_SIZE));
	}
	//num between 0.99 and 1.0.
	else if ((num >= 0.99) && (num <= 1))
	{
		rads = (float)ACOS_TABLE[FLOAT_TO_ROUNDUP_INTEGER((num * DEC4 - 9900.f) / 2.f) + 227] * 0.00616f;
		//assert(core::InBounds<Int32>(FLOAT_TO_ROUNDUP_INTEGER((num * DEC4 - 9900.f) / 2.f) + 227, 0, F_Trig::ACOS_TABLE_SIZE));
	}

	//Account for the negative sign if required.
	if (negative) { rads = F_PI - rads; }
	return rads;
}

//--------------------------------------------------------------------
// Class: ATan2()
// Desc	: atan(x) = asin(x/sqrt(1 + x*x)).
//		  atan(x) = (pi/2) - acos(x)
//--------------------------------------------------------------------
float F_Trig::ATan2(float y, float x)
{
	float hypt = F_SQRT(x * x + y * y);
	float rad = ACos(x / hypt);

	if (y < 0) { rad = -rad; }
	return rad;
}

#define Xcoef (0.001)
#define Ycoef (0.004)
#define LynxXcoef (0.003)
#define LynxYcoef (0.008)

class cfgRecoils
{
//	#include "cfgRecoilsLegacy.hpp"

	class Default;

	//	muzzleOuter[]	= x,y,a,b = { horizontal axis, vertical axis, horizontal magnitude, vertical magnitude }; plot: ((p+x)/a)^2 + ((q+y)/b)^2 = 1;
	//	muzzleInner[]	= x,y,a,b = { horizontal axis, vertical axis, horizontal magnitude, vertical magnitude }; plot: ((p+x)/a)^2 + ((q+y)/b)^2 = 1;
	//	kickBack[]		= min&max = { minimum, maximum };

	/*---------------------------------------------------------------------------
		Default recoil configuration
	---------------------------------------------------------------------------*/
	class Kord_recoil_base: Default
	{					//	x_		y|		a>		b^
		muzzleOuter[]	= { 5.0,	5.0,	5.0,	5.0 };
		muzzleInner[]	= { 0,		0,		0.1,	0.1	};
		kickBack[]		= { 5.0,	5.0 };
		permanent		= 2.0;
		temporary		= 0.01;
	};

	/*---------------------------------------------------------------------------
		Adjustments from the default recoil configuration
	---------------------------------------------------------------------------*/
	class Kord_recoil: Default
	{
		muzzleOuter[]	= { 0.5,	2.0,	0.5,	1.0 };
		muzzleInner[]	= { 0,		0,		0.1,	0.1	};
		kickBack[]		= { 0.1,	0.15 };
		permanent		= 1;
		temporary		= 0.01;
	};
	class Kord_recoil_prone: Kord_recoil
	{
		muzzleOuter[]	= { 0.5,	2.0,	0.5,	1.0 };
		muzzleInner[]	= { 0,		0,		0.1,	0.1	};
		kickBack[]		= { 0.06,	0.09 };
		permanent		= 0.6;
		temporary		= 0.01;
	};
};

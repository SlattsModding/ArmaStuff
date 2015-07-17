#define private		0
#define protected		1
#define public		2

#define true	1
#define false	0

class CfgPatches {
	class Kord_test {
		units[]={};
		weapons[]={};
		requiredVersion=1;
        requiredAddons[] = {"a3_sounds_f"};
	};
};

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class SlotInfo;
class MuzzleSlot;
class CowsSlot;
class PointerSlot;
class UnderBarrelSlot;

#include "cfgMagazines.h" /// specific magazines for this rifle
#include "cfgRecoils.h" /// specific recoil patterns for this rifle

class CfgWeapons
{
	class Rifle_Base_F;
	class Rifle_Long_Base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
	};
	class Kord_bipod: Rifle_Long_Base_F
	{
		scope = public;
		bullet1[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_01",0.7943282,1,15};
		bullet2[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_02",0.7943282,1,15};
		bullet3[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_03",0.7943282,1,15};
		bullet4[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_04",0.7943282,1,15};
		bullet5[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_01",0.7943282,1,15};
		bullet6[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_02",0.7943282,1,15};
		bullet7[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_03",0.7943282,1,15};
		bullet8[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_04",0.7943282,1,15};
		bullet9[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_01",0.7943282,1,15};
		bullet10[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_02",0.7943282,1,15};
		bullet11[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_03",0.7943282,1,15};
		bullet12[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_04",0.7943282,1,15};
		soundBullet[] = {"bullet1",0.083,"bullet2",0.083,"bullet3",0.083,"bullet4",0.083,"bullet5",0.083,"bullet6",0.083,"bullet7",0.083,"bullet8",0.083,"bullet9",0.083,"bullet10",0.083,"bullet11",0.083,"bullet12",0.083};

		reloadAction = "GestureReloadM200";
        handAnim[] = {"OFP2_ManSkeleton","\Kord_test\data\anim\KORDmk4.rtm"};

		model="\Kord_test\KORD.p3d";
		displayName = "Kord with 6T19";

		//bipod
           deployedPivot    = "bipod";       /// what point should be used to be on surface while unfolded
           hasBipod         = true;          /// a weapon with bipod obviously has a bipod
           soundBipodDown[] = {"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_AAF_down",db-3, 1, 20}; /// sound of unfolding the bipod
           soundBipodUp[]   = {"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_AAF_up",db-3, 1, 20}; /// sound of folding the bipod

		discreteDistance[] = {50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900};
		discreteDistanceInitIndex = 5;
		dexterity = 0.2;
		picture="\Kord_test\data\ui\gear_kord_x_ca.paa";
		UiPicture = "\A3\weapons_f\data\UI\icon_mg_CA.paa";
		cursor = "mg";
		cursorAim = "EmptyCursor";
		reloadMagazineSound[] = {"Kord_test\data\sfx\Reload.wss",0.0562341,1,10};
		modes[] = {manual, close, short, medium, far};
		selectionFireAnim = "muzzleFlash";
		recoil = "Kord_recoil";
		recoilProne = "Kord_recoil_prone";
		class manual: Mode_FullAuto
		{
			sounds[] = {"StandardSound", "SilencedSound"};
			class BaseSoundModeType
			{
 				weaponSoundEffect = "DefaultRifle";
 				closure1[]={"A3\sounds_f\weapons\closure\closure_rifle_2", db-12, 1,10};
 				closure2[]={"A3\sounds_f\weapons\closure\closure_rifle_3", db-12, 1,10};
 				soundClosure[]={closure1,0.5, closure2,0.5};
 			};

 			class StandardSound : BaseSoundModeType
 			{
				begin1[] = {"Kord_test\data\sfx\DSHK_a1",db-5,1,130};
				begin2[] = {"Kord_test\data\sfx\DSHK_a2",db-5,1,130};
				begin3[] = {"Kord_test\data\sfx\DSHK_a3",db-5,1,130};
				begin4[] = {"Kord_test\data\sfx\DSHK_a4",db-5,1,130};
				begin5[] = {"Kord_test\data\sfx\DSHK_a1",db-5,1,130};
				begin6[] = {"Kord_test\data\sfx\DSHK_a2",db-5,1,130};
				begin7[] = {"Kord_test\data\sfx\DSHK_a3",db-5,1,130};
				begin8[] = {"Kord_test\data\sfx\DSHK_a4",db-5,1,130};
				soundBegin[] = {"begin1",0.125,"begin2",0.125,"begin3",0.125,"begin4",0.125,"begin5",0.125,"begin6",0.125,"begin7",0.125,"begin8",0.125};
 			};

			class SilencedSound: BaseSoundModeType {
				begin1[] = {"A3\sounds_f\weapons\silenced\silent-18",1.0,1,300};
				begin2[] = {"A3\sounds_f\weapons\silenced\silent-19",1.0,1,300};
				begin3[] = {"A3\sounds_f\weapons\silenced\silent-11",1.0,1,300};
				soundBegin[] = {"begin1",0.333,"begin2",0.333,"begin3",0.333};
			};
			reloadTime = 0.09;
			dispersion=0.001; //0.005;
			drySound[] = {"Kord_test\data\sfx\Dry",0.000316228,1,10};

			soundContinuous = 0;
			soundBurst = false;
			minRange=0;minRangeProbab=0.30;
			midRange=5;midRangeProbab=0.58;
			maxRange=10;maxRangeProbab=0.04;
			showToPlayer = true;
		};
		class close: manual
		{
			burst = 10;
			aiRateOfFire = 0.5;
			aiRateOfFireDistance = 50;
			minRange=10;minRangeProbab=0.05;
			midRange=20;midRangeProbab=0.58;
			maxRange=50;maxRangeProbab=0.04;
			showToPlayer = false;
		};
		class short: close
		{
			burst = 8; //Rg 6;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 300; //Rg 200;
			minRange=50;minRangeProbab=0.05;
			midRange=150;midRangeProbab=0.58; //Rg 100;
			maxRange=300;maxRangeProbab=0.04; //Rg 200;
		};
		class medium: close
		{
			burst = 12; //Rg 8;
			aiRateOfFire = 3; //Rg 4;
			aiRateOfFireDistance = 600; //Rg 400;
			minRange=200;minRangeProbab=0.05;
			midRange=400;midRangeProbab=0.58; //Rg 300;
			maxRange=600;maxRangeProbab=0.04; //Rg 400;
		};
		class far: close
		{
			burst = 16; //Rg 7;
			aiRateOfFire = 5; //Rg 7;
			aiRateOfFireDistance = 1000; //Rg 600;
			minRange=400;minRangeProbab=0.05;
			midRange=600;midRangeProbab=0.4; //Rg 500;
			maxRange=900;maxRangeProbab=0.01; //Rg 600;
		};
		aiDispersionCoefY=21.0; // 7
		aiDispersionCoefX=21.0;

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 500;
			class MuzzleSlot: SlotInfo
			{
				compatibleItems[] = {};
			};
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {};		
			};	
		};
		magazines[]={"50Rnd_KORD_127x108_mag","50Rnd_KORD_127x108_mag_Tracer"};
		class Library {libTextDesc = "Russian Machine Gun";};
		//descriptionShort = "PKM";
	};
};

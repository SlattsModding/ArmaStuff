class CfgMagazines
{
	class Default;

	class CA_Magazine;

	class 50Rnd_KORD_127x108_mag: CA_Magazine 
	{
		scope = public; /// or 2, to be precise
		displayName = "12.7x108mm KORD mag";
		picture = "\Kord_test\data\ui\m_pk_ca.png"; /// just some icon
		ammo = B_127x108_Ball;
		count = 50; /// 30 rounds is enough
		initSpeed = 860; /// standard muzzle speed
		tracersEvery = 0; /// disable tracers by default
		lastRoundsTracer = 4; /// tracers to track low ammo
		descriptionShort = "Used to shoot test MIGHTY KORD bullets"; /// on mouse-over in Inventory
		mass = 150;
	};

	class 50Rnd_KORD_127x108_mag_Tracer: 50Rnd_KORD_127x108_mag /// a magazine full of tracer rounds
	{
		tracersEvery = 1; /// moar tracers
		lastRoundsTracer = 50; /// tracers everywhere
		displayName = "12.7x108mm KORD mag Tracer";
		descriptionShort = "Used to shoot test MIGHTY KORD TRACER bullets";
		displaynameshort = "Tracers";
	};
};

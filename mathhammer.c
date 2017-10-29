// Joshua Skootsky, 2018
#include <stdio.h>
#include "random64.h"



double shoot( double weapon[4], double target[4]) {
	
	// bs 3+ hits on 3, 4, 5 6 = 4 of 6 can hit.
	double canHit = 6 - weapon[0] + 1;
	double hits = canHit/ (float) 6; // cast to double
	printf("This is how many shots hit %lf\n", hits);	

	double woundPower = weapon[1]/ (double) target[0];
	double canWound;
	
	if (woundPower < 1) {
		canWound = 2;
	}
	
	if (woundPower < 1 && weapon[1] <= 2*target[0]) {
		canWound = 1;
	}
	if (woundPower == 1) {
		canWound = 3;
	}
	if (woundPower > 1) {
		canWound = 4;
	}
	if (woundPower > 1 && weapon[1] >= 2*target[0]) {
		canWound = 5;
	}

	double wounds = canWound/ (double) 6;

	printf("Here is number of wounds %lf\n", hits * wounds);

	wounds = hits * wounds;

	double  save =  target[1];
	printf("Save before checking ap is %lf\n", save);
	
	double invulsave = target[2];
	save = save + (double) weapon[2]; // the |ap| of the weapon
	printf("Save after ap is %lf\n", save);
	if (save < invulsave) {
		save = invulsave;
	}
	if (save >= 7) {
		save = 7;
	}
	printf("Save after checking invul is %lf\n", save);
	double canUnsave = save - 1;
	double unsaved = wounds * canUnsave / (float) 6;			
	
	// multi wound weapons
	
	if (weapon[3] <= target[3]) {
		unsaved = unsaved * weapon[3];	
	}
	printf("Here is how many unsaved wounds there are %lf\n", unsaved);
	
	return unsaved;


}


int main()
{
	// bs, str, |ap|, wounds
	double bolter[4] = {3,4, 0 ,1};
	double lascannon[4] = {3, 9, 4, 1};
	double plasma_std[4] = {3, 7, 3, 1};
	double plasma_sup[4] = {3, 8, 3, 2};
	double shuricat[4] = {4, 4, 0.5, 1};
	// toughness, save, invul save, wounds
	double guardian[4] = {3, 5, 0, 1};
	double marine[4] = {4, 3, 0, 1};
	double heavy_vehicle[4] = {8, 3, 5, 10};
	double termie[4] = {4, 2, 5, 2}; 

	printf("We will test 40k weapons according to 8th edition rules\n");
	
	printf("Here is one marine w/ bolter shooting at another marine\n");

	printf("Now let's have a marine shoot another one with a lascannon!\n");
	shoot(lascannon, marine);

	printf("Now shoot a lascannon at a T8 vehicle with a 5++ save\n");
	shoot(lascannon, heavy_vehicle);	

	printf("Heresy breaks out! Battle brother Spartacus turns a plasma gun on his fellow marine!\n");
	shoot(plasma_std, marine);

	printf("More heresy! He shoots a brother wearing tactical dreadnought armor!");
	shoot(plasma_std, termie);	

	printf("Supercharged plasma, by marine, at marine\n");
	shoot(plasma_sup, marine);
	
	printf("Supercharged plasma, by marine, at termie\n");
	shoot(plasma_sup, termie);

	printf("A guardian shoots at a marine with his shuricat!\n");
	shoot(shuricat, marine);

	printf("A marine shoots at a guardian!\n");
	shoot(bolter, guardian);

	return 0;

	// test weapons against marines and toughness 3 vehicles
	

}

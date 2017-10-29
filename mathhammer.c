// Joshua Skootsky, 2018
#include <stdio.h>
#include "random64.h"



double shoot( int weapon[4], int target[4]) {
	
	// bs 3+ hits on 3, 4, 5 6 = 4 of 6 can hit.
	int canHit = 6 - weapon[0] + 1;
	double hits = canHit/ (float) 6; // cast to double
	

	double woundPower = weapon[1]/target[0];
	int canWound;
	
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

	double wounds = canWound/ (float) 6;

	double saves;
	
	
	

	return hits*wounds;


}


int main()
{
	// bs, str, ap, wounds
	int bolter[4] = {3,4, (-1) ,1};
	// toughness, save, invul save, wounds
	int marine[4] = {4, 3, 0, 1};

	printf("We will test 40k weapons according to 8th edition rules\n");
	
	printf("Here is one bolter shooting at a marine with no armor");
	double wounds = shoot(bolter, marine);
	printf("Here is the number of wounds %lf \n", wounds);


	return 0;

	// test weapons against marines and toughness 3 vehicles
	

}

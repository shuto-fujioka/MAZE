#include "Texture_Lib.h"
#include "GameScene.h"
#include "DirectX_Lib.h"
#include "DirectInput_Lib.h"
#include "proto.h"
#include "Stage.h"
#include "Player.h"
#include <stdio.h>



//óéâ∫éûä‘
int   falltime = 0;
//èdóÕåWêî
float GravityFactor = 0.1;


void FallInit() {

	falltime = 0;
	LeftFlag = true;
	RightFlag = true;
	FallFlag = true;
}

void Fallcheck() {
	LeftFlag = false;
	RightFlag = false;
	FallFlag = false;
}

void FallControl(float* y) {
	
	falltime++;

	*y += falltime * GravityFactor;

}



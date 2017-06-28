#include "Texture_Lib.h"
#include "GameScene.h"
#include "DirectX_Lib.h"
#include "DirectInput_Lib.h"
#include "proto.h"
#include "Stage.h"
#include <stdio.h>
#include "Player.h"
#include "StartDoor.h"
#include "EndDoor.h"

void LeftTurn(float* y, float* x) {
	int xNUM;
	int yNUM;

	xNUM = (*x - 430) / TIPSIZE;
	yNUM = (*y - 80) / TIPSIZE;


	*y = (14 - xNUM) * TIPSIZE + 80;
	*x = yNUM      * TIPSIZE + 430;

}

void RightTurn(float* y, float* x) {
	int xNUM;
	int yNUM;

	xNUM = (*x - 430) / TIPSIZE;
	yNUM = (*y - 80) / TIPSIZE;


	*y = xNUM        * TIPSIZE + 80;
	*x = (14 - yNUM) * TIPSIZE + 430;

}
void Turn(float* y, float* x) {
	int xNUM;
	int yNUM;

	xNUM = (*x - 430) / TIPSIZE;
	yNUM = (*y - 80) / TIPSIZE;


	*y = (14 - yNUM) * TIPSIZE + 80;
	*x = (14 - xNUM) * TIPSIZE + 430;

}

int KeyCheck(float x, float y) {

	int xNUM;
	int yNUM;

	xNUM = (x - 430) / TIPSIZE;
	yNUM = (y - 80) / TIPSIZE;

	return map[yNUM][xNUM];
}
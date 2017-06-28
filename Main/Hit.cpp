#include "Texture_Lib.h"
#include "GameScene.h"
#include "DirectX_Lib.h"
#include "DirectInput_Lib.h"
#include "proto.h"
#include "Player.h"
#include <stdio.h>
#include "Stage.h"

int HitCheck(float x, float y) {

	int xNUM;
	int yNUM;

	xNUM = (x - 430) / TIPSIZE;
	yNUM = (y - 80) / TIPSIZE;

	return map[yNUM][xNUM];
}

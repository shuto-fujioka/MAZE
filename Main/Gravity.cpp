#include "Texture_Lib.h"
#include "GameScene.h"
#include "DirectX_Lib.h"
#include "DirectInput_Lib.h"
#include "proto.h"
#include "Stage.h"
#include "Player.h"
#include <stdio.h>



//��������
int   falltime = 0;
//�d�͌W��
float GravityFactor = 0.1;

void FallInit() {
	falltime = 0;
}

void FallControl(float* y) {
	
	falltime++;

	*y += falltime * GravityFactor;

}



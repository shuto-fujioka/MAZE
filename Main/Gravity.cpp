#include "Texture_Lib.h"
#include "GameScene.h"
#include "DirectX_Lib.h"
#include "DirectInput_Lib.h"
#include "proto.h"
#include "Stage.h"
#include "Player.h"
#include <stdio.h>


PLAYER_STATE Player;
CUSTOMVERTEX desu;
bool LandFlag = 0;
void TexTurn(CUSTOMVERTEX* pVertex, double angle);

void Gravity() {

	if (Key[A] == RELEASE) {
		for (int i = 0; i < 4; i++) {
		}
	}
}

void TexTurn(CUSTOMVERTEX * pVertex, double angle)
{

}

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



void TexTurn(CUSTOMVERTEX* pVertex, double angle) {
	float cx, cy;
	float rad;

	rad = D3DXToRadian(angle);

	cx = (pVertex[0].x + pVertex[1].x) / 2.0f;
	cy = (pVertex[0].y + pVertex[3].y) / 2.0f;
	for (int i = 0; i < 4; i++) {
		//’†S‚ðŒ´“_‚É
		pVertex[i].x -= cx;
		pVertex[i].y -= cy;


		pVertex[i].x = pVertex[i].x * cos(rad)
			- pVertex[i].y * sin(rad);
		pVertex[i].y = pVertex[i].x * sin(rad)
			+ pVertex[i].y * cos(rad);

		pVertex[i].x += cx;
		pVertex[i].y += cy;

	}

}


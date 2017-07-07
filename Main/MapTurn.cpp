#include "Texture_Lib.h"
#include "GameScene.h"
#include "DirectX_Lib.h"
#include "DirectInput_Lib.h"
#include "proto.h"
#include "Stage.h"
#include <stdio.h>
#include "Player.h"
#include "StartDoor.h"
#include "KeyControl.h"
#include "EndDoor.h"



void TexRotate(CUSTOMVERTEX pVertex[], double angle) {
	float cx, cy,ctu,ctv;
	float rad;
	CUSTOMVERTEX copyVertex;

	rad = D3DXToRadian(angle);

	cx = (pVertex[0].x + pVertex[1].x) / 2.0f;
	cy = (pVertex[0].y + pVertex[3].y) / 2.0f;
	
	for (int i = 0; i < 4; i++) {
		//’†S‚ðŒ´“_‚É
		pVertex[i].x -= cx;
		pVertex[i].y -= cy;

		copyVertex = pVertex[i];

		pVertex[i].x = copyVertex.x * cos(rad)
			- copyVertex.y * sin(rad);
		pVertex[i].y = copyVertex.x * sin(rad)
			+ copyVertex.y * cos(rad);

		pVertex[i].x += cx;
		pVertex[i].y += cy;
	}

}






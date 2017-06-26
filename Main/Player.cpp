#include "Texture_Lib.h"
#include "GameScene.h"
#include "DirectX_Lib.h"
#include "DirectInput_Lib.h"
#include "proto.h"
#include <stdio.h>
#include"Stage.h"

#define MOVE_SPEED 2.5f

struct PLAYER_STATE
{
	float x, y, scale;
};

LPDIRECTINPUTDEVICE8  pKeyDevice = NULL;

PLAYER_STATE		  g_Player = { 520.f, 695.f, 15.f };
bool				  g_moveRight = true;
float				  g_tu[4] = { 0,0.033,0.066,0.099 };
float				  g_tv[2] = {0,0.055};
int count = 0;
int animecount = 0;
int tvcount  = 1;

//0.09375	//0.1277
//0		0.055


void PlayerDraw(void) {
	CUSTOMVERTEX player[4]
	{
		{ g_Player.x - g_Player.scale, g_Player.y - g_Player.scale, 1.f, 1.f, 0xFFFFFFFF, g_tu[animecount] , 0.f + g_tv[tvcount] },
		{ g_Player.x + g_Player.scale, g_Player.y - g_Player.scale, 1.f, 1.f, 0xFFFFFFFF, g_tu[animecount] + g_tu[1] , 0.f + g_tv[tvcount] },
		{ g_Player.x + g_Player.scale, g_Player.y + g_Player.scale, 1.f, 1.f, 0xFFFFFFFF, g_tu[animecount]+ g_tu[1], 0.055f + g_tv[tvcount] },
		{ g_Player.x - g_Player.scale, g_Player.y + g_Player.scale, 1.f, 1.f, 0xFFFFFFFF, g_tu[animecount] , 0.055f + g_tv[tvcount] }
	};

	g_pD3Device->SetTexture(0, g_pTexture[PLAYER_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, player, sizeof(CUSTOMVERTEX));

}

void PlayerControl() {
	KeyCheck(VK_LEFT, LEFT);
	KeyCheck(VK_RIGHT, RIGHT);

	if (Key[LEFT] == ON) {
		g_Player.x -= MOVE_SPEED;

		count++;

		if (count > 15) {
			animecount++;
			count = 0;
		}

		if (animecount >= 4) {
			animecount = 0;
		}
		tvcount = 0;
	}

	if (Key[RIGHT] == ON) {
		g_Player.x += MOVE_SPEED;
		count++;

		if (count > 15) {
			animecount++;
			count = 0;
		}

		if (animecount >= 4) {
			animecount = 0;
		}
		tvcount = 1;
	}
}
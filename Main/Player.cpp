#include "Texture_Lib.h"
#include "GameScene.h"
#include "DirectX_Lib.h"
#include "DirectInput_Lib.h"
#include "proto.h"
#include "Player.h"
#include <stdio.h>
#include "Stage.h"
#include "PlayerTurn.h"
#include "StageControl.h"
#include "Gravity.h"
#include "Hit.h"
#include "KeyControl.h"

#define MOVE_SPEED 5.0f

LPDIRECTINPUTDEVICE8  pKeyDevice = NULL;

PLAYER_STATE		  g_Player = { TIPSIZE*14 + 410.f, 692.f, 20.f };
bool				  g_moveRight = true;
//—Ž‰ºƒtƒ‰ƒO
bool FallFlag = true;

bool DrawFlag = true;

bool LeftFlag = true;
bool RightFlag = true;

float				  g_tu[4] = { 0,0.033,0.066,0.099 };
float				  g_tv[2] = { 0,0.058 };
int count = 0;
int animecount = 0;
int tvcount  = 0;

//0.09375	//0.1277
//0		0.055


void PlayerDraw(void) {

	if (!DrawFlag) return;

	CUSTOMVERTEX player[4]
	{
		{ g_Player.x - g_Player.scale, g_Player.y - g_Player.scale, 1.f, 1.f, 0xFFFFFFFF, g_tu[animecount] , 0.f + g_tv[tvcount] },
		{ g_Player.x + g_Player.scale, g_Player.y - g_Player.scale, 1.f, 1.f, 0xFFFFFFFF, g_tu[animecount] + g_tu[1] , 0.f + g_tv[tvcount] },
		{ g_Player.x + g_Player.scale, g_Player.y + g_Player.scale, 1.f, 1.f, 0xFFFFFFFF, g_tu[animecount] + g_tu[1], 0.055f + g_tv[tvcount] },
		{ g_Player.x - g_Player.scale, g_Player.y + g_Player.scale, 1.f, 1.f, 0xFFFFFFFF, g_tu[animecount] , 0.055f + g_tv[tvcount] }
	};
		g_pD3Device->SetTexture(0, g_pTexture[PLAYER_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, player, sizeof(CUSTOMVERTEX));
	}

void PlayerControl() {

	if(HitCheck(g_Player.x - 5, g_Player.y + g_Player.scale) == 1) 
	{
		FallInit();
	}
	else
	{
		Fallcheck();
		FallControl(&g_Player.y);
	}

	if (Key[A] == PUSH) {
		if (FallFlag == true) {
			LeftStageTurn(&g_Player.y, &g_Player.x);
			LeftTurn(&g_Player.y, &g_Player.x);
		}
	}
	
	if (Key[D] == PUSH) {
		if (FallFlag == true) {
			RightStageTurn(&g_Player.y, &g_Player.x);
			RightTurn(&g_Player.y, &g_Player.x);
		}
	}

	if (Key[W] == PUSH) {
		if (FallFlag == true) {
			StageTurn(&g_Player.y, &g_Player.x);
			Turn(&g_Player.y, &g_Player.x);
		}
	}
	if (Key[LEFT] == ON) {
		if (LeftFlag == true && FallFlag == true) {
			if (HitCheck(g_Player.x - g_Player.scale + 7.5, g_Player.y - g_Player.scale) == 1) {

			}
			else
			{
				g_Player.x -= MOVE_SPEED;
			}

			count++;

			if (count > 1) {
				animecount++;
				count = 0;
			}

			if (animecount >= 4) {
				animecount = 0;
			}
			tvcount = 0;
		}
	}

	if (Key[RIGHT] == ON) {
		if (RightFlag == true && FallFlag == true) {
			if (HitCheck(g_Player.x + g_Player.scale - 12.5, g_Player.y) == 1) {

			}
			else
			{
				g_Player.x += MOVE_SPEED;
			}
			count++;

			if (count > 1) {
				animecount++;
				count = 0;
			}

			if (animecount >= 4) {
				animecount = 0;
			}
			tvcount = 1;
		}
	}
	if (Key[UP] == PUSH) {
		if (HitCheck(g_Player.x ,g_Player.y) == 4) {
			EndDoorControl();
		}
	}
}


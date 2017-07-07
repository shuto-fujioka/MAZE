#include "Stage.h"
#include "DirectX_Lib.h"
#include "KeyControl.h"
#include "proto.h"
#include "EndDoor.h"
#include "Render.h"
#include "Player.h"
#include "MapTurn.h"
#include "Hit.h"

float				  g_DoaTu[2] = { 0,0.5 };
int DoaCount = 0;
int DoaAnimeCount = 1;

bool EndDoorInit(void) {
	return true;
}

void EndDoorDraw(int x, int y) {

	static float a = 0;

	//ドア2のチップの頂点情報
	CUSTOMVERTEX g_mapTip4[] =
	{
		{ 430.0f, 80.0f , 0.5f, 1.0f, 0xFFFFFFFF, g_DoaTu[DoaAnimeCount], 0.0f },
		{ 475.0f, 80.0f , 0.5f, 1.0f, 0xFFFFFFFF, g_DoaTu[DoaAnimeCount] + g_DoaTu[1], 0.0f },
		{ 475.0f, 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, g_DoaTu[DoaAnimeCount] + g_DoaTu[1], 1.0f },
		{ 430.0f, 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, g_DoaTu[DoaAnimeCount], 1.0f },
	};

	CUSTOMVERTEX drawMapVertex[4];
	for (int i = 0; i < 4; i++)
	{
		drawMapVertex[i] = g_mapTip4[i];
	}

	for (int i = 0; i < 4; i++)
	{
		drawMapVertex[i].x += (x * TIPSIZE);
		drawMapVertex[i].y += (y * TIPSIZE);
	}

	if (Key[A] == PUSH) {
		if (FallFlag == true) {
			a -= 90;
		}
		if (a == 360) {
			a = 0;
		}
	}
	if (Key[D] == PUSH) {
		if (FallFlag == true) {
			a += 90;
		}
		if (a == 360) {
			a = 0;
		}
	}
	if (Key[W] == PUSH) {
		if (FallFlag == true) {
			a += 180;
		}
		if (a == 360) {
			a = 0;
		}
	}
	TexRotate(drawMapVertex, a);
	// テクスチャをステージに割り当てる
	g_pD3Device->SetTexture(0, g_pTexture[DOA2_TEX]);
	// 描画
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawMapVertex, sizeof(CUSTOMVERTEX));
}

void EndDoorControl(void) {

	if (HitCheck(g_Player.x, g_Player.y) == 4) {
		DoaCount++;

		DoaCount++;

		if (DoaCount >= 1) {
			DoaAnimeCount++;
			DoaCount = 0;
		}

		if (DoaAnimeCount >= 2) {
			DoaAnimeCount = 0;
		}

		if (DoaAnimeCount == 0) {
			DrawFlag = false;
		}

	}
}

void EndDoorFree(void) {

}

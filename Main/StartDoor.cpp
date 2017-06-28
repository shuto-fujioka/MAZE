#include "Stage.h"
#include "DirectX_Lib.h"
#include "Render.h"
#include "StartDoor.h"

//ドア１のチップの頂点情報
CUSTOMVERTEX g_StartDoaVertex1[] =
{
	{ 430.0f   , 80.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 475.0f, 80.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
	{ 475.0f, 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
	{ 430.0f   , 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};

bool StartDoaInit(void) {
	return true;
}

void StartDoaDraw(int x, int y) {
	CUSTOMVERTEX drawMapVertex[4];
	for (int i = 0; i < 4; i++)
	{
		drawMapVertex[i] = g_mapTip2[i];
	}

	for (int i = 0; i < 4; i++)
	{
		drawMapVertex[i].x += (x * TIPSIZE);
		drawMapVertex[i].y += (y * TIPSIZE);
	}

	// テクスチャをステージに割り当てる
	g_pD3Device->SetTexture(0, g_pTexture[DOA_TEX]);
	// 描画
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawMapVertex, sizeof(CUSTOMVERTEX));
}

void StartDoaControl(void) {

}

void StartDoaFree(void) {

}

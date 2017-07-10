#include "Texture_Lib.h"
#include "GameScene.h"
#include "DirectX_Lib.h"
#include "DirectInput_Lib.h"
#include "proto.h"
#include "Player.h"
#include <stdio.h>
#include "Render.h"
#include "GameClear.h"
#include"Stage.h"

//ステージのチップの頂点情報
CUSTOMVERTEX g_mapTip1[] =
{
	{ 430.0f, 80.0f , 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 475.0f, 80.0f , 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
	{ 475.0f, 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
	{ 430.0f, 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};
//ステージ2のチップの頂点情報
CUSTOMVERTEX g_stageTip2[] =
{
	{ 430.0f, 80.0f , 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 475.0f, 80.0f , 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
	{ 475.0f, 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
	{ 430.0f, 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};
// コインのチップの頂点情報
CUSTOMVERTEX g_mapTip2[] =
{
	{ 430.0f, 80.0f , 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 475.0f, 80.0f , 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
	{ 475.0f, 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
	{ 430.0f, 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};

void Render()
{
	//頂点情報を入れる--------------------------------------
	CUSTOMVERTEX backGround[4]
	{
		{ 0.f,      0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1920.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1920.f,1080.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f,   1080.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f },
	};

	//描画の開始
	g_pD3Device->BeginScene();

	g_pD3Device->SetTexture(0, g_pTexture[BACKGROUND_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));
	g_pD3Device->SetTexture(0, g_pTexture[STAGE_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, g_mapTip1, sizeof(CUSTOMVERTEX));
	MapDraw();
	PlayerDraw();
	GameClearRender();

	//描画の終了
	g_pD3Device->EndScene();
	//表示
	g_pD3Device->Present(NULL, NULL, NULL, NULL);
	//頂点に入れるデータを設定
	g_pD3Device->SetFVF(D3DFVF_CUSTOMVERTEX);
}

#include "Texture_Lib.h"
#include "GameScene.h"
#include "DirectX_Lib.h"
#include "DirectInput_Lib.h"
#include "proto.h"
#include "Player.h"
#include <stdio.h>
#include "Render.h"
#include"Stage.h"


void GameClearRender() {
	CUSTOMVERTEX GameClear[4]
	{
		{ 0.f,      0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1920.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1920.f,1080.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f,   1080.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f },
	};
	if (ClearFlag == false) {
		

		g_pD3Device->SetTexture(0, g_pTexture[GAMECLEAR_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, GameClear, sizeof(CUSTOMVERTEX));

		//描画の終了
		g_pD3Device->EndScene();
		//表示
		g_pD3Device->Present(NULL, NULL, NULL, NULL);
		//頂点に入れるデータを設定
		g_pD3Device->SetFVF(D3DFVF_CUSTOMVERTEX);
	}
}
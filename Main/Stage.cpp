#include "Texture_Lib.h"
#include "GameScene.h"
#include "DirectX_Lib.h"
#include "DirectInput_Lib.h"
#include "proto.h"
#include "Stage.h"
#include <stdio.h>
#include "Player.h"

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dxguid.lib")
#define SAFE_RELEASE(p) {if(p){(p)->Release(); (p)=NULL;}}



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow);


// マップチップのデータを格納してる二次元配列
int map[MAP_HEIGHT][MAP_WIDTH];



// Csvの読み込み関数
void MapLoad(const char* mapdata)
{
	FILE*  fp;
	fopen_s(&fp, mapdata, "r");

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			fscanf_s(fp, "%d,", &map[i][j], _countof(map));
		}
	}
}
void MapDraw()
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (map[y][x] == 1)
			{
				CUSTOMVERTEX drawMapVertex[4];
				for (int i = 0; i < 4; i++)
				{
					drawMapVertex[i] = g_mapTip1[i];
				}

				for (int i = 0; i < 4; i++)
				{
					drawMapVertex[i].x += (x * TIPSIZE);
					drawMapVertex[i].y += (y * TIPSIZE);
				}
				// テクスチャをステージに割り当てる
				g_pD3Device->SetTexture(0, g_pTexture[STAGE_TEX]);
				// 描画
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawMapVertex, sizeof(CUSTOMVERTEX));
			}
			else if (map[y][x] == 2)
			{
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
				g_pD3Device->SetTexture(0, g_pTexture[COIN_TEX]);
				// 描画
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawMapVertex, sizeof(CUSTOMVERTEX));
			}
			else if (map[y][x] == 3)
			{
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
			else if (map[y][x] == 4)
			{
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
				g_pD3Device->SetTexture(0, g_pTexture[DOA2_TEX]);
				// 描画
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawMapVertex, sizeof(CUSTOMVERTEX));
			}
		}
	}
}

void LeftTurn(float* y, float* x) {
	int xNUM;
	int yNUM;

	xNUM = (*x - 430) / TIPSIZE;
	yNUM = (*y - 80)  / TIPSIZE;

	//map[y][x] = change[x][14-y];

	//*y = xNUM * TIPSIZE+80;
	//*x = (14 - yNUM) * TIPSIZE+430;

	*y = (14-xNUM) * TIPSIZE + 80 ;
	*x = yNUM      * TIPSIZE + 430;

}

void RightTurn(float* y, float* x) {
	int xNUM;
	int yNUM;

	xNUM = (*x - 430) / TIPSIZE;
	yNUM = (*y - 80) / TIPSIZE;


	*y = xNUM        * TIPSIZE + 80 ;
	*x = (14 - yNUM) * TIPSIZE + 430;

}
void Turn(float* y, float* x) {
	int xNUM;
	int yNUM;

	xNUM = (*x - 430) / TIPSIZE;
	yNUM = (*y - 80) / TIPSIZE;


	*y = (14 - yNUM) * TIPSIZE + 80;
	*x = (14 - xNUM) * TIPSIZE + 430;

}

int KeyCheck(float x, float y) {

	int xNUM;
	int yNUM;

	xNUM = (x - 430) / TIPSIZE;
	yNUM = (y - 80) / TIPSIZE;

	return map[yNUM][xNUM];
}
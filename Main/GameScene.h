#pragma once

#include <windows.h>
#include <mmsystem.h>

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#pragma comment(lib, "winmm.lib")

enum TEXTURE
{
	BACKGROUND_TEX,
	STAGE_TEX,
	STAGE1_TEX,
	PLAYER_TEX,
	COIN_TEX,
	DOA_TEX,
	DOA2_TEX,
	TEXMAX,
	GAMECLEAR_TEX
};

// マップチップのデータを格納してる二次元配列
extern int map[MAP_HEIGHT][MAP_WIDTH];

//Directx関係----------------------------
extern LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	        //	画像の情報を入れておく為のポインタ配列
extern IDirect3DDevice9*	  g_pD3Device;		            //	Direct3Dのデバイス
extern D3DPRESENT_PARAMETERS  g_D3dPresentParameters;		//	パラメータ
extern D3DDISPLAYMODE		  g_D3DdisplayMode;
extern IDirect3D9*			  g_pDirect3D;		            //	Direct3Dのインターフェイス
//---------------------------------------





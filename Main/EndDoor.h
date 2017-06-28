#pragma once


#include <d3dx9.h>
#include"GameScene.h"


extern LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	        //	画像の情報を入れておく為のポインタ配列
extern IDirect3DDevice9*	  g_pD3Device;		            //	Direct3Dのデバイス
extern D3DPRESENT_PARAMETERS  g_D3dPresentParameters;		//	パラメータ
extern D3DDISPLAYMODE		  g_D3DdisplayMode;
extern IDirect3D9*			  g_pDirect3D;		            //	Direct3Dのインターフェイス

bool EndDoaInit(void);

void EndDoaDraw(int x, int y);

void EndDoaControl(void);

void EndDoaFree(void);


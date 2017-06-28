#pragma once


#include <d3dx9.h>
#include"GameScene.h"


extern LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	        //	�摜�̏������Ă����ׂ̃|�C���^�z��
extern IDirect3DDevice9*	  g_pD3Device;		            //	Direct3D�̃f�o�C�X
extern D3DPRESENT_PARAMETERS  g_D3dPresentParameters;		//	�p�����[�^
extern D3DDISPLAYMODE		  g_D3DdisplayMode;
extern IDirect3D9*			  g_pDirect3D;		            //	Direct3D�̃C���^�[�t�F�C�X

bool EndDoaInit(void);

void EndDoaDraw(int x, int y);

void EndDoaControl(void);

void EndDoaFree(void);


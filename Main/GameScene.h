#include <windows.h>
#include <mmsystem.h>

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#pragma comment(lib, "winmm.lib")

enum TEXTURE
{
	BACKGROUND_TEX,
	STAGE_TEX,
	PLAYER_TEX,
	COIN_TEX,
	TEXMAX,
};

//Directx�֌W----------------------------
extern LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	        //	�摜�̏������Ă����ׂ̃|�C���^�z��
extern IDirect3DDevice9*	  g_pD3Device;		            //	Direct3D�̃f�o�C�X
extern D3DPRESENT_PARAMETERS  g_D3dPresentParameters;		//	�p�����[�^
extern D3DDISPLAYMODE		  g_D3DdisplayMode;
extern IDirect3D9*			  g_pDirect3D;		            //	Direct3D�̃C���^�[�t�F�C�X
//---------------------------------------





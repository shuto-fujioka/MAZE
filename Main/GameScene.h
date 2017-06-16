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

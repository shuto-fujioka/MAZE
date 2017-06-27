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


// �}�b�v�`�b�v�̃f�[�^���i�[���Ă�񎟌��z��
int map[MAP_HEIGHT][MAP_WIDTH];

//�X�e�[�W�̃`�b�v�̒��_���
CUSTOMVERTEX g_mapTip1[] =
{
	{ 430.0f   , 80.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 475.0f, 80.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
	{ 475.0f, 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
	{ 430.0f   , 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};
// �R�C���̃`�b�v�̒��_���
CUSTOMVERTEX g_mapTip2[] =
{
	{ 430.0f   , 80.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 475.0f, 80.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
	{ 475.0f, 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
	{ 430.0f   , 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};
//�h�A�P�̃`�b�v�̒��_���
CUSTOMVERTEX g_mapTip3[] =
{
	{ 430.0f   , 80.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 475.0f, 80.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
	{ 475.0f, 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
	{ 430.0f   , 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};
//�h�A2�̃`�b�v�̒��_���
CUSTOMVERTEX g_mapTip4[] =

{
	{ 430.0f   , 80.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 475.0f, 80.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
	{ 475.0f, 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
	{ 430.0f   , 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};
void Render()
{
	//���_��������--------------------------------------
	CUSTOMVERTEX backGround[4]
	{
		{ 0.f,      0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1920.f,   0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1920.f,1080.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f,   1080.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f },
	};

	//�`��̊J�n
	g_pD3Device->BeginScene();

	g_pD3Device->SetTexture(0, g_pTexture[BACKGROUND_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));
	g_pD3Device->SetTexture(0, g_pTexture[STAGE_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, g_mapTip1, sizeof(CUSTOMVERTEX));
	MapDraw();
	PlayerDraw();

	//�`��̏I��
	g_pD3Device->EndScene();
	//�\��
	g_pD3Device->Present(NULL, NULL, NULL, NULL);
	//���_�ɓ����f�[�^��ݒ�
	g_pD3Device->SetFVF(D3DFVF_CUSTOMVERTEX);
}

// Csv�̓ǂݍ��݊֐�
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
				// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
				g_pD3Device->SetTexture(0, g_pTexture[STAGE_TEX]);
				// �`��
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

				// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
				g_pD3Device->SetTexture(0, g_pTexture[COIN_TEX]);
				// �`��
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

				// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
				g_pD3Device->SetTexture(0, g_pTexture[DOA_TEX]);
				// �`��
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

				// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
				g_pD3Device->SetTexture(0, g_pTexture[DOA2_TEX]);
				// �`��
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawMapVertex, sizeof(CUSTOMVERTEX));
			}
		}
	}
}
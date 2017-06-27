#include "Texture_Lib.h"
#include "GameScene.h"
#include "DirectX_Lib.h"
#include "DirectInput_Lib.h"
#include "proto.h"
#include "Stage.h"
#include <stdio.h>


int change[MAP_HEIGHT][MAP_WIDTH];

void MapLoad(const char* mapdata);




void StageControl() {
	int y;
	int x;

	for (y = 0; y < MAP_HEIGHT; y++) {
		for (x = 0; x < MAP_WIDTH; x++) {
			change[y][x] = map[y][x];
		}
	}
	//A�L�[��������Ă�ꍇ...���ɉ��
	if (Key[A] == PUSH) {
		
		for (y = 0; y < MAP_HEIGHT; y++) {
			for (x = 0; x < MAP_WIDTH; x++) {
				map[y][x] = change[x][14-y];
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
		//D�L�[��������Ă�ꍇ...�E�ɉ��
		if (Key[D] == PUSH) {
			for (int y = 0; y < MAP_HEIGHT; y++) {
				for (int x = 0; x < MAP_WIDTH; x++) {
					map[y][x] = change[14-x][y];
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
		//W�L�[��������Ă�ꍇ...180�x���
		if (Key[W] == PUSH) {

			for (y = 0; y < MAP_HEIGHT; y++) {
				for (x = 0; x < MAP_WIDTH; x++) {
					map[y][x] = change[14-y][14-x];
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
	}
	
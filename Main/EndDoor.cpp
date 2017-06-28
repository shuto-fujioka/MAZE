#include "Stage.h"
#include "DirectX_Lib.h"
#include "EndDoor.h"
#include "Render.h"

//�h�A�P�̃`�b�v�̒��_���
CUSTOMVERTEX g_EndDoaVertex1[] =
{
	{ 430.0f   , 80.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 475.0f, 80.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
	{ 475.0f, 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
	{ 430.0f   , 125.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};

bool EndDoaInit(void) {
	return true;
}

void EndDoaDraw(int x, int y) {
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

void EndDoaControl(void) {

}

void EndDoaFree(void) {

}

#pragma once

#include "Texture_Lib.h"
#include "DirectInput_Lib.h"

//�X�e�[�W�̃`�b�v�̒��_���
extern CUSTOMVERTEX g_mapTip1[];

// �R�C���̃`�b�v�̒��_���
extern CUSTOMVERTEX g_mapTip2[];

//�h�A�P�̃`�b�v�̒��_���
extern CUSTOMVERTEX g_mapTip3[];

//�h�A2�̃`�b�v�̒��_���
extern CUSTOMVERTEX g_mapTip4[];

// Csv�̓ǂݍ��݊֐�
void MapLoad(const char* mapdata);

void LeftTurn(float* y,float* x);

void RightTurn(float* y, float* x);

void Turn(float* y, float* x);

int KeyCheck(float y, float x);

//ooooooo
void KeyCheck(int VK, KEYKIND st);

extern KEYSTATE Key[KEYMAX];

extern int PreKey[KEYMAX];

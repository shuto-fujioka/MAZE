#pragma once

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

//ooooooo
void KeyCheck(int VK, KEYKIND st);

extern KEYSTATE Key[KEYMAX];

extern int PreKey[KEYMAX];
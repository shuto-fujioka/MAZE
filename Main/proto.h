#pragma once

// Render�̉���֐�
void Render();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow);

//csv�̃v���g�^�C�v�錾
void MapLoad(const char* mapdata);

void MapDraw();

void KeyControl();

void StageControl();

void PlayerControl();
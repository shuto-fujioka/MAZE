#pragma once

// Renderの解放関数
void Render();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow);

//csvのプロトタイプ宣言
void MapLoad(const char* mapdata);

void MapDraw();

void KeyControl();

void StageControl();

void PlayerControl();
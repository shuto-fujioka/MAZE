#pragma once

//ステージのチップの頂点情報
extern CUSTOMVERTEX g_mapTip1[];

// コインのチップの頂点情報
extern CUSTOMVERTEX g_mapTip2[];

//ドア１のチップの頂点情報
extern CUSTOMVERTEX g_mapTip3[];

//ドア2のチップの頂点情報
extern CUSTOMVERTEX g_mapTip4[];

// Csvの読み込み関数
void MapLoad(const char* mapdata);

//ooooooo
void KeyCheck(int VK, KEYKIND st);

extern KEYSTATE Key[KEYMAX];

extern int PreKey[KEYMAX];
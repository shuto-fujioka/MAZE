/**
 * @file	Texture_Lib.h
 * @brief	テクスチャ関係ヘッダ
 * @author	morimoto
 */
#ifndef TEXTURE_LIB_H
#define TEXTURE_LIB_H
#define MAP_HEIGHT 14
#define MAP_WIDTH 15



//------------------------------------------------------------
// Include
//------------------------------------------------------------
#include <dinput.h>
#include <D3D9.h>
#pragma comment (lib,"D3d9.lib")


/**
 * 頂点構造体
 */
typedef struct CUSTOMVERTEX
{
	float           x, y, z;	//!< 位置情報.
	float           rhw;		//!< 頂点変換値.
	D3DCOLOR        color;		//!< 頂点カラー.
	float           tu, tv;		//!< テクスチャ座標.
} CUSTOMVERTEX, *LPCUSTOMVERTEX;


/**
 * Textureをロードする関数
 * @param[in] name ロードする画像ファイルの名前
 * @param[out] pTexture 画像をロードする場所
 * @param[in] pD3Device デバイスのオブジェクト
 * @return 成功した場合は0を、失敗した場合は1を返す。
 */
int TexLoad(const char* name, LPDIRECT3DTEXTURE9* pTexture, IDirect3DDevice9* pD3Device);

/**
 * Textureをロードする関数
 * @param[in] name ロードする画像ファイルの名前
 * @param[out] pTexture 画像をロードする場所
 * @param[in] pD3Device デバイスのオブジェクト
 * @param[in] alpha 抜き色のアルファ
 * @param[in] red 抜き色の赤
 * @param[in] grren 抜き色の緑
 * @param[in] blue 抜き色の青
 * @return 成功した場合は0を、失敗した場合は1を返す
 */
int TexLoadEX(const char* name, LPDIRECT3DTEXTURE9* pTexture, IDirect3DDevice9* pD3Device, int alpha, int red, int grren, int blue);

/**
 * 画像の拡縮の関数
 * @param[out] pVertex 拡縮する頂点
 * @param[in] x x軸の拡縮の倍率
 * @param[in] y y軸の拡縮の倍率
 */
void TexScaling(CUSTOMVERTEX* pVertex, double x, double y);

/**
 * 回転の関数
 * @param[out] pVertex 回転する頂点
 * @param[in] angle マイナスが左回転・プラスが右回転
 */
void TexTurn(CUSTOMVERTEX* pVertex, double angle);

/**
 * 画像のセット関数
 * @param[in] pD3Device 描画するためにデバイスのオブジェクト
 * @param[in] pTexture 画像をセットする関数
 */
void TexSet(IDirect3DDevice9* pD3Device, LPDIRECT3DTEXTURE9 pTexture);

/**
 * 画像の描画関数
 * @param[in] pD3Device 描画するためにデバイスのオブジェクト
 * @param[in] Vertex 表示する画像のパラメーターを渡す。
 */
void TexDraw(IDirect3DDevice9* pD3Device, CUSTOMVERTEX* pVertex);

/**
 * 画像のセット&描画関数
 * @param[in] pD3Device 描画するためにデバイスのオブジェクト
 * @param[in] Vertex 表示する画像のパラメーターを渡す。
 * @param[in] pTexture 画像をセットする関数
 */
void TexSetDraw(IDirect3DDevice9* pD3Device, LPDIRECT3DTEXTURE9 pTexture, CUSTOMVERTEX* pVertex);

/**
 * 描画するための準備関数
 * @param[in] pD3Device デバイスのオブジェクトを渡す。
 */
void DrawReady(IDirect3DDevice9* pD3Device);


/**
 * 描画の終了関数
 * @param[in] pD3Device デバイスのオブジェクトを渡す。
 */
void EndScene(IDirect3DDevice9* pD3Device);



#endif // TEXTURE_LIB_H

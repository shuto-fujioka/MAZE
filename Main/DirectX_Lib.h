/**
 * @file	DirectX_Lib.h
 * @brief	DirectX関係ヘッダ
 * @author	morimoto
 */
#ifndef DIRECTX_LIB_H
#define DIRECTX_LIB_H

 //------------------------------------------------------------
 // Include
 //------------------------------------------------------------
#include <d3dx9.h>
#include <d3dx9tex.h>


/**
 * Directxの初期化関数
 * @param[out] pDirect3D Directxのオブジェクトを格納する変数
 * @param[in] hWnd ウィンドウハンドル  
 * @param[out] pD3Device デバイスのオブジェクトを格納する変数
 */
void InitDX(LPDIRECT3D9* pDirect3D, HWND hWnd, LPDIRECT3DDEVICE9* pD3Device);



#endif // DIRECTX_LIB_H

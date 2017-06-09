/**
 * @file	DirectX_Lib.h
 * @brief	DirectX�֌W�w�b�_
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
 * Directx�̏������֐�
 * @param[out] pDirect3D Directx�̃I�u�W�F�N�g���i�[����ϐ�
 * @param[in] hWnd �E�B���h�E�n���h��  
 * @param[out] pD3Device �f�o�C�X�̃I�u�W�F�N�g���i�[����ϐ�
 */
void InitDX(LPDIRECT3D9* pDirect3D, HWND hWnd, LPDIRECT3DDEVICE9* pD3Device);



#endif // DIRECTX_LIB_H

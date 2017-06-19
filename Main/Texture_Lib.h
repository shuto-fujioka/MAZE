/**
 * @file	Texture_Lib.h
 * @brief	�e�N�X�`���֌W�w�b�_
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
 * ���_�\����
 */
typedef struct CUSTOMVERTEX
{
	float           x, y, z;	//!< �ʒu���.
	float           rhw;		//!< ���_�ϊ��l.
	D3DCOLOR        color;		//!< ���_�J���[.
	float           tu, tv;		//!< �e�N�X�`�����W.
} CUSTOMVERTEX, *LPCUSTOMVERTEX;


/**
 * Texture�����[�h����֐�
 * @param[in] name ���[�h����摜�t�@�C���̖��O
 * @param[out] pTexture �摜�����[�h����ꏊ
 * @param[in] pD3Device �f�o�C�X�̃I�u�W�F�N�g
 * @return ���������ꍇ��0���A���s�����ꍇ��1��Ԃ��B
 */
int TexLoad(const char* name, LPDIRECT3DTEXTURE9* pTexture, IDirect3DDevice9* pD3Device);

/**
 * Texture�����[�h����֐�
 * @param[in] name ���[�h����摜�t�@�C���̖��O
 * @param[out] pTexture �摜�����[�h����ꏊ
 * @param[in] pD3Device �f�o�C�X�̃I�u�W�F�N�g
 * @param[in] alpha �����F�̃A���t�@
 * @param[in] red �����F�̐�
 * @param[in] grren �����F�̗�
 * @param[in] blue �����F�̐�
 * @return ���������ꍇ��0���A���s�����ꍇ��1��Ԃ�
 */
int TexLoadEX(const char* name, LPDIRECT3DTEXTURE9* pTexture, IDirect3DDevice9* pD3Device, int alpha, int red, int grren, int blue);

/**
 * �摜�̊g�k�̊֐�
 * @param[out] pVertex �g�k���钸�_
 * @param[in] x x���̊g�k�̔{��
 * @param[in] y y���̊g�k�̔{��
 */
void TexScaling(CUSTOMVERTEX* pVertex, double x, double y);

/**
 * ��]�̊֐�
 * @param[out] pVertex ��]���钸�_
 * @param[in] angle �}�C�i�X������]�E�v���X���E��]
 */
void TexTurn(CUSTOMVERTEX* pVertex, double angle);

/**
 * �摜�̃Z�b�g�֐�
 * @param[in] pD3Device �`�悷�邽�߂Ƀf�o�C�X�̃I�u�W�F�N�g
 * @param[in] pTexture �摜���Z�b�g����֐�
 */
void TexSet(IDirect3DDevice9* pD3Device, LPDIRECT3DTEXTURE9 pTexture);

/**
 * �摜�̕`��֐�
 * @param[in] pD3Device �`�悷�邽�߂Ƀf�o�C�X�̃I�u�W�F�N�g
 * @param[in] Vertex �\������摜�̃p�����[�^�[��n���B
 */
void TexDraw(IDirect3DDevice9* pD3Device, CUSTOMVERTEX* pVertex);

/**
 * �摜�̃Z�b�g&�`��֐�
 * @param[in] pD3Device �`�悷�邽�߂Ƀf�o�C�X�̃I�u�W�F�N�g
 * @param[in] Vertex �\������摜�̃p�����[�^�[��n���B
 * @param[in] pTexture �摜���Z�b�g����֐�
 */
void TexSetDraw(IDirect3DDevice9* pD3Device, LPDIRECT3DTEXTURE9 pTexture, CUSTOMVERTEX* pVertex);

/**
 * �`�悷�邽�߂̏����֐�
 * @param[in] pD3Device �f�o�C�X�̃I�u�W�F�N�g��n���B
 */
void DrawReady(IDirect3DDevice9* pD3Device);


/**
 * �`��̏I���֐�
 * @param[in] pD3Device �f�o�C�X�̃I�u�W�F�N�g��n���B
 */
void EndScene(IDirect3DDevice9* pD3Device);



#endif // TEXTURE_LIB_H

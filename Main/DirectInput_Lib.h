/**
 * @file	DirectInput_Lib.h
 * @brief	DirectInput�֌W�w�b�_
 * @author	morimoto
 */
#ifndef DIRECTINPUT_LIB_H
#define DIRECTINPUT_LIB_H

//------------------------------------------------------------
// Include
//------------------------------------------------------------
#include <dinput.h>


/**
 * �L�[�{�[�h�̏�ԗ񋓎q
 */
enum KEYSTATE
{
	PUSH,		//!< �����ꂽ.
	RELEASE,	//!< �����ꂽ.
	ON,			//!< �����������Ă���.
	OFF			//!< �Ȃɂ�����ĂȂ�.
};

/**
 * �L�[�{�[�h�̎�ޗ񋓎q
 */
enum KEYKIND
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	FIRE,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	SPACE,
	ESC,
	LSHIFT,
	RSHIFT,
	KEYMAX
};


/**
 * �}�E�X�̏�ԍ\����
 */
typedef struct
{
	bool IsLeftClick, IsRightClick;	//!< �N���b�N���(�N���b�N����Ă����true).
	int lx, ly, lz;					//!< �}�E�X�̈ړ���.

} MOUSEKIND;



//------------------------------------------------------------
// Functions
//------------------------------------------------------------

/**
 * DirectInput�̏�����
 * @return ���������ꍇ��S_OK���A���s�����ꍇ�̓G���[�R�[�h��Ԃ�
 */
HRESULT InitDinput();

/**
 * DirectInput�̃L�[�{�[�h�f�o�C�X�̏�����
 * @param[in] hWnd �E�B���h�E�n���h��
 * @return ���������ꍇ��S_OK���A���s�����ꍇ�̓G���[�R�[�h��Ԃ��B
 */
HRESULT InitDinputKey(HWND hwnd);

/**
 * DirectInput�̃}�E�X�̏�����
 * @param[in] hWnd �E�B���h�E�n���h��
 * @return ���������ꍇ��S_OK���A���s�����ꍇ�̓G���[�R�[�h��Ԃ��B
 */
HRESULT InitDinputMouse(HWND hwnd);



/**
 * Directinput���g�����L�[��Ԃ̃`�F�b�N
 * @param[out] Key �`�F�b�N�����L�[�̏�Ԃ��i�[����A�h���X
 * @param[in] DIK �`�F�b�N����L�[��DIK
 */
void KeyCheckDinput(KEYSTATE* Key, int DIK);

/**
 * Directinput���g�����}�E�X�̏�ԃ`�F�b�N
 * @param[out] Mouse	�`�F�b�N�����}�E�X�̏�Ԃ��i�[����A�h���X
 */
void MouseCheck(MOUSEKIND* Mouse);



/**
 * DirectInput�̃����[�X�֐�
 */
void ReleaseDinput();

/**
 * Dinput�̃L�[�f�o�C�X�̃����[�X�֐�
 */
void ReleaseKey();

/**
 * �}�E�X�̉��
 */
void ReleaseMouse();



#endif // DIRECTINPUT_LIB_H

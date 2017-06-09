/**
 * @file	DirectInput_Lib.h
 * @brief	DirectInput関係ヘッダ
 * @author	morimoto
 */
#ifndef DIRECTINPUT_LIB_H
#define DIRECTINPUT_LIB_H

//------------------------------------------------------------
// Include
//------------------------------------------------------------
#include <dinput.h>


/**
 * キーボードの状態列挙子
 */
enum KEYSTATE
{
	PUSH,		//!< 押された.
	RELEASE,	//!< 離された.
	ON,			//!< 押し続けられている.
	OFF			//!< なにもされてない.
};

/**
 * キーボードの種類列挙子
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
 * マウスの状態構造体
 */
typedef struct
{
	bool IsLeftClick, IsRightClick;	//!< クリック情報(クリックされていればtrue).
	int lx, ly, lz;					//!< マウスの移動量.

} MOUSEKIND;



//------------------------------------------------------------
// Functions
//------------------------------------------------------------

/**
 * DirectInputの初期化
 * @return 成功した場合はS_OKを、失敗した場合はエラーコードを返す
 */
HRESULT InitDinput();

/**
 * DirectInputのキーボードデバイスの初期化
 * @param[in] hWnd ウィンドウハンドル
 * @return 成功した場合はS_OKを、失敗した場合はエラーコードを返す。
 */
HRESULT InitDinputKey(HWND hwnd);

/**
 * DirectInputのマウスの初期化
 * @param[in] hWnd ウィンドウハンドル
 * @return 成功した場合はS_OKを、失敗した場合はエラーコードを返す。
 */
HRESULT InitDinputMouse(HWND hwnd);



/**
 * Directinputを使ったキー状態のチェック
 * @param[out] Key チェックしたキーの状態を格納するアドレス
 * @param[in] DIK チェックするキーのDIK
 */
void KeyCheckDinput(KEYSTATE* Key, int DIK);

/**
 * Directinputを使ったマウスの状態チェック
 * @param[out] Mouse	チェックしたマウスの状態を格納するアドレス
 */
void MouseCheck(MOUSEKIND* Mouse);



/**
 * DirectInputのリリース関数
 */
void ReleaseDinput();

/**
 * Dinputのキーデバイスのリリース関数
 */
void ReleaseKey();

/**
 * マウスの解放
 */
void ReleaseMouse();



#endif // DIRECTINPUT_LIB_H

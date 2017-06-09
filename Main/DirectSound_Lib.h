/**
 * @file	DirectSound_Lib.h
 * @brief	DirectSound関係ヘッダ
 * @author	morimoto
 */
#ifndef DIRECTXSOUND_LIB_H
#define DIRECTXSOUND_LIB_H


/**
 * 音声操作列挙子 
 */
enum SOUND_OPERATION
{
	PLAY,		//!< サウンドの再生.
	STOP,		//!< サウンドの停止.
	LOOP,		//!< サウンドのループ再生.
	RESET,		//!< サウンドのリセット.
	STOP_RESET	//!< サウンドの停止とリセット.
};


/**
 * DirectSoundの初期化
 * @param[in] hWnd ウィンドウハンドル
 * @param[out] pDS8 DirectSoundオブジェクト
 * @return 成功した場合はS_OKを、失敗した場合はエラーコードを返す
 */
HRESULT InitDSound(HWND hWnd, IDirectSound8** pDS8);

int SoundLoad(HWND hWnd, char* filename, IDirectSound8** pDS8, IDirectSoundBuffer8** pDSBuffer);

void SoundOperation(IDirectSoundBuffer8* pDSBuffer, SOUND_OPERATION operation);

bool OpenWave(TCHAR* filepath, WAVEFORMATEX &waveFormatEx, char** ppData, DWORD &dataSize);


#endif // DIRECTXSOUND_LIB_H

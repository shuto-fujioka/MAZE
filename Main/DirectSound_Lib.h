/**
 * @file	DirectSound_Lib.h
 * @brief	DirectSound�֌W�w�b�_
 * @author	morimoto
 */
#ifndef DIRECTXSOUND_LIB_H
#define DIRECTXSOUND_LIB_H


/**
 * ��������񋓎q 
 */
enum SOUND_OPERATION
{
	PLAY,		//!< �T�E���h�̍Đ�.
	STOP,		//!< �T�E���h�̒�~.
	LOOP,		//!< �T�E���h�̃��[�v�Đ�.
	RESET,		//!< �T�E���h�̃��Z�b�g.
	STOP_RESET	//!< �T�E���h�̒�~�ƃ��Z�b�g.
};


/**
 * DirectSound�̏�����
 * @param[in] hWnd �E�B���h�E�n���h��
 * @param[out] pDS8 DirectSound�I�u�W�F�N�g
 * @return ���������ꍇ��S_OK���A���s�����ꍇ�̓G���[�R�[�h��Ԃ�
 */
HRESULT InitDSound(HWND hWnd, IDirectSound8** pDS8);

int SoundLoad(HWND hWnd, char* filename, IDirectSound8** pDS8, IDirectSoundBuffer8** pDSBuffer);

void SoundOperation(IDirectSoundBuffer8* pDSBuffer, SOUND_OPERATION operation);

bool OpenWave(TCHAR* filepath, WAVEFORMATEX &waveFormatEx, char** ppData, DWORD &dataSize);


#endif // DIRECTXSOUND_LIB_H

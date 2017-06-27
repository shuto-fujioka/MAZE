#include "Texture_Lib.h"
#include "GameScene.h"
#include "DirectX_Lib.h"
#include "DirectInput_Lib.h"
#include "proto.h"
#include "Stage.h"
#include <stdio.h>

void KeyCheck(int VK, KEYKIND st);

// キー情報を格納する変数
KEYSTATE Key[KEYMAX];

int PreKey[KEYMAX] = { 0 };

int KeyState[4] = { 0 };
void KeyControl() {
	//キーチェック
	KeyCheck('D', D);
	KeyCheck('A', A);
	KeyCheck('W', W);
	KeyCheck(VK_LEFT, LEFT);
	KeyCheck(VK_RIGHT, RIGHT);

}
void KeyCheck(int VK, KEYKIND st) {
	if ((GetKeyState(VK) & 0x8000) != 0) {
		if (PreKey[st] == 0) {
			Key[st] = PUSH;
		}
		else {
			Key[st] = ON;
		}
		PreKey[st] = 1;
	}
	else {

		if (PreKey[st] == 0) {
			Key[st] = OFF;
		}
		else {
			Key[st] = RELEASE;
		}
		PreKey[st] = 0;
	}
}
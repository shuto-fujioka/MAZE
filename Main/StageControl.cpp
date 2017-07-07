#include "Texture_Lib.h" 
#include "GameScene.h"
#include "DirectX_Lib.h"
#include "DirectInput_Lib.h"
#include "proto.h"
#include "Stage.h"
#include "Render.h"
#include "KeyControl.h"
#include <stdio.h>


int change[MAP_HEIGHT][MAP_WIDTH];

void MapLoad(const char* mapdata);

void LeftStageTurn(float* py, float* px) {
	int y;
	int x;
	//A�L�[��������Ă�ꍇ...���ɉ��
	for (y = 0; y < MAP_HEIGHT; y++) {
		for (x = 0; x < MAP_WIDTH; x++) {
			map[y][x] = change[x][14 - y];
		}
	}
			
}
void RightStageTurn(float* py, float* px) {
	int y;
	int x;

	//D�L�[��������Ă�ꍇ...�E�ɉ��
		for (int y = 0; y < MAP_HEIGHT; y++) {
			for (int x = 0; x < MAP_WIDTH; x++) {
				map[y][x] = change[14 - x][y];
				
			}
		}
}
void StageTurn(float* py, float* px){
	int y;
	int x;

	//W�L�[��������Ă�ꍇ...180�x���
		for (y = 0; y < MAP_HEIGHT; y++) {
			for (x = 0; x < MAP_WIDTH; x++) {
				map[y][x] = change[14 - y][14 - x];
				
			}
		}
	}



void StageControl() {
	int y;
	int x;

	for (y = 0; y < MAP_HEIGHT; y++) {
		for (x = 0; x < MAP_WIDTH; x++) {
			change[y][x] = map[y][x];
		}
	}
}
		

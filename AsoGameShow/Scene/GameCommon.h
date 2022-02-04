#pragma once


//マップのチップのサイズ
#define CHIP_SIZE_X 124
#define CHIP_SIZE_Y 96

#define PLAYER_SIZE_X 32
#define PLAYER_SIZE_Y 32
#define PLAYER_A_SIZE_X 64
#define PLAYER_A_SIZE_Y 64

#define ENEMY_X_1 423
#define ENEMY_Y_1 221
#define ENEMY_X_2 437
#define ENEMY_Y_2 297
#define ENEMY_X_3 310
#define ENEMY_Y_3 317
#define ENEMY_X_4 190
#define ENEMY_Y_4 361


enum DIR		//向き管理用
{
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_MAX
};


class GameCommon
{
};


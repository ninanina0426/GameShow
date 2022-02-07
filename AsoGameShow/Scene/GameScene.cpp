#include <DxLib.h>
#include "GameScene.h"



GameScene::GameScene()
{
    Init();
    DrawOwnScn();
}

GameScene::~GameScene()
{
}

bool GameScene::IsEnemy1(void)
{
    return mEnemy.mEnemy1;
}

bool GameScene::IsEnemy2(void)
{
    return mEnemy.mEnemy2;
}

bool GameScene::IsEnemy3(void)
{
    return mEnemy.mEnemy3;
}

bool GameScene::IsEnemy4(void)
{
    return mEnemy.mEnemy4;
}

bool GameScene::IsEPush1(void)
{
    return mEnemy.mPush;
}

bool GameScene::IsEPush2(void)
{
    return mEnemy.mPush2;
}

bool GameScene::IsEPush3(void)
{
    return mEnemy.mPush3;
}

bool GameScene::IsEPush4(void)
{
    return mEnemy.mPush4;
}

int GameScene::GetEvent(Vector2 pos)
{
    int chipID = mStage.GetMapChip(pos);

    return chipID;
}



uniquBaseScn GameScene::Update( uniquBaseScn own)
{

    //当たり判定----------------------------------------------------------------
    Vector2 playerPos;
    Vector2 enemyPos;
    DIR GetDIR;
    Vector2 enemySize;
    Vector2 playerSize;
    Vector2 ShotPos;
   

    playerPos = mPlayer.Update();
    enemyPos = mEnemy.Update(playerPos);
    enemySize = mEnemy.GetSize();
    GetDIR = mPlayer.GetDIR();
    playerSize = mPlayer.GetSiz();
    ShotPos = mEnemy.GetShotPos();

    mMapOffset = mStage.Update(playerPos);

    if (mEnemy.mEnemy1)
    {
        if ((playerPos.y_ - playerSize.y_ / 2 < enemyPos.y_ + ENEMY_Y_1+ enemySize.y_ / 2) &&
            (enemyPos.y_+ ENEMY_Y_1 - enemySize.y_ / 2 < playerPos.y_ + playerSize.y_ / 2) &&
            (playerPos.x_ - playerSize.x_ / 2 < enemyPos.x_+ ENEMY_X_1 + enemySize.x_ / 2) &&
            (enemyPos.x_+ ENEMY_X_1 - enemySize.x_ / 2 < playerPos.x_ + playerSize.x_ / 2))
        {
            if (CheckHitKey(KEY_INPUT_N))
            {
                mEnemy.mEnemy1 = false;
                mEnemy.mPush = true;
                mEnemy.mCnt = +15;
            }
        }

    }
    if (mEnemy.mEnemy2)
    {
        if ((playerPos.y_ - playerSize.y_ / 2 < enemyPos.y_ + ENEMY_Y_2 + enemySize.y_ / 2) &&
            (enemyPos.y_ + ENEMY_Y_2 - enemySize.y_ / 2 < playerPos.y_ + playerSize.y_ / 2) &&
            (playerPos.x_ - playerSize.x_ / 2 < enemyPos.x_ + ENEMY_X_2 + enemySize.x_ / 2) &&
            (enemyPos.x_ + ENEMY_X_2 - enemySize.x_ / 2 < playerPos.x_ + playerSize.x_ / 2))
        {
            if (CheckHitKey(KEY_INPUT_N))
            {
                mEnemy.mEnemy2 = false;
                mEnemy.mPush2 = true;
                mEnemy.mCnt2 = +15;
            }
        }

    }
    if (mEnemy.mEnemy3)
    {
        if ((playerPos.y_ - playerSize.y_ / 2 < enemyPos.y_ + ENEMY_Y_3 + enemySize.y_ / 2) &&
            (enemyPos.y_ + ENEMY_Y_3 - enemySize.y_ / 2 < playerPos.y_ + playerSize.y_ / 2) &&
            (playerPos.x_ - playerSize.x_ / 2 < enemyPos.x_ + ENEMY_X_3 + enemySize.x_ / 2) &&
            (enemyPos.x_ + ENEMY_X_3 - enemySize.x_ / 2 < playerPos.x_ + playerSize.x_ / 2))
        {
            if (CheckHitKey(KEY_INPUT_N))
            {
                mEnemy.mEnemy3 = false;
                mEnemy.mPush3 = true;
                mEnemy.mCnt3 = +15;
            }
        }

    }
    if (mEnemy.mEnemy4)
    {
        if ((playerPos.y_ - playerSize.y_ / 2 < enemyPos.y_ + ENEMY_Y_4 + enemySize.y_ / 2) &&
            (enemyPos.y_ + ENEMY_Y_4 - enemySize.y_ / 2 < playerPos.y_ + playerSize.y_ / 2) &&
            (playerPos.x_ - playerSize.x_ / 2 < enemyPos.x_ + ENEMY_X_4 + enemySize.x_ / 2) &&
            (enemyPos.x_ + ENEMY_X_4 - enemySize.x_ / 2 < playerPos.x_ + playerSize.x_ / 2))
        {
            if (CheckHitKey(KEY_INPUT_N))
            {
                mEnemy.mEnemy4 = false;
                mEnemy.mPush4 = true;
                mEnemy.mCnt4 = +15;
            }
        }

    }
    //---------------------------------------------------------------------------

    DrawOwnScn();

   /* mStage.SetMap();*/

    return std::move(own);
}



void GameScene::DrawOwnScn()
{
    SetDrawScreen(gameScene_);
    ClsDrawScreen();

    DrawBox(0, 0, 640, 480, 0x000000, true);
   

    mStage.Draw();

    mEnemy.Draw();
    //プレイヤーの描画
    mPlayer.Draw(mMapOffset);

    DrawGraph(0, 0, bg_, true);

    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();//画面消す
    //シーンの内容の描画を行う
    DrawBox(0, 0, 1080, 800, 0xffffff, true);
    DrawGraph(90, 10, gameScene_, true);
   
    
    
}

bool GameScene::Init(void)
{

    gameScene_ = MakeScreen(620, 480, 255);

    bg_ = LoadGraph("image/add2.png");


    mStage.Init();
    mPlayer.init(this);
    mEnemy.init(this);
    

    return true;
}

bool GameScene::Release(void)
{
    mStage.Release();
    mPlayer.Release();
    mEnemy.Release();

    return true;
}

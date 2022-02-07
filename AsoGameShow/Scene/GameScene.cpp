#include <DxLib.h>
#include "GameScene.h"
#include "../tmx/TmxObj.h"
//#include "common/ImageMng.h"
//#include "Obj/Player.h"


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
   /* for (const auto& obj : objList_)
    {
        obj->Update(tmxobj_);
    }*/
   
    //当たり判定----------------------------------------------------------------
    Vector2 playerPos;
    Vector2 enemyPos;
    DIR GetDIR;
    Vector2 enemySize;
    Vector2 playerSize;

   

    playerPos = mPlayer.Update();
    enemyPos = mEnemy.Update();
    enemySize = mEnemy.GetSize();
    GetDIR = mPlayer.GetDIR();
    playerSize = mPlayer.GetSiz();

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
    
    if (CheckSoundFile()!=1)
    {
        printf("なってないよ\n");
    }
    return std::move(own);
}



void GameScene::DrawOwnScn()
{
    SetDrawScreen(gameScene_);
    ClsDrawScreen();
    /*auto tileSize = tmxobj_.GetTileSize();
    auto WoldSize = tmxobj_.GetWoldArea();
    for (const auto& layer: tmxobj_.GetMapData())
    {
       
        for (int y = 0; y < WoldSize.y_; y++)
        {
            for (int x = 0; x < WoldSize.x_; x++)
            {
                if (y * WoldSize.x_ + x < layer.second.size())
                {
                    int gid = layer.second[y * WoldSize.x_ + x] - tmxobj_.GetFirstGID();
                    if (gid >= 0)
                    {
                        DrawGraph(x * tileSize.x_, y * tileSize.y_, lpImageMng.GetID("test.png")[gid], true);

                    }
                }
                  
            }
        }
    }*/
    DrawBox(0, 0, 640, 480, 0x000000, true);
   

    mStage.Draw();

    mEnemy.Draw();
    //プレイヤーの描画
    mPlayer.Draw(mMapOffset);

    DrawGraph(0, 0, bg_, true);

    PlaySoundMem(BGM_, DX_PLAYTYPE_LOOP, true);
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();//画面消す
    //シーンの内容の描画を行う
    DrawBox(0, 0, 1080, 800, 0xffffff, true);
    DrawGraph(90, 10, gameScene_, true);
   
    
    
}

bool GameScene::Init(void)
{
    //Image_ = lpImageMng.GetID("imageA")[1];
    //Image_ = LoadGraph("image/imageA.png");
    //tmxobj_.LoadTSX("./tmx/map.tsx");
    //obj.InitObj(ObjType::P1);
    //obj2.InitObj(ObjType::P2);
    //obj.obj_ = ObjType::P1;
    //obj2.obj_ = ObjType::P2;
    gameScene_ = MakeScreen(620, 480, 255);
     //tmxobj_.LoadTMX("./tmx/map.tmx");
    tmxobj_.LoadTMX("./tmx/test.tmx");
    bg_ = LoadGraph("image/add2.png");
    /*objList_.emplace_back(std::make_unique<Player>(CntType::KEY));
    objList_.emplace_back(std::make_unique<Player>(CntType::PAD));*/
    //AnimMng anim;
   // anim.AnimInit();

    mStage.Init();
    mPlayer.init(this);
    mEnemy.init(this);
    BGM_ = LoadSoundMem("./music/Electric_Equipment_Connection.mp3");

    return true;
}

bool GameScene::Release(void)
{
    mStage.Release();
    mPlayer.Release();
    mEnemy.Release();

    return true;
}

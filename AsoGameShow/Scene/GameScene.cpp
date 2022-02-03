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

uniquBaseScn GameScene::Update( uniquBaseScn own)
{
   /* for (const auto& obj : objList_)
    {
        obj->Update(tmxobj_);
    }*/
   
    DrawOwnScn();
    
    mPlayer.Update();

    mEnemy.Update();
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
    DrawGraph(0, 0, bg_, true);

    mEnemy.Draw();
    //プレイヤーの描画
    mPlayer.Draw();

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
    bg_ = LoadGraph("./image/kannsei.png");
    /*objList_.emplace_back(std::make_unique<Player>(CntType::KEY));
    objList_.emplace_back(std::make_unique<Player>(CntType::PAD));*/
    //AnimMng anim;
   // anim.AnimInit();

    mPlayer.init(this);
    mEnemy.init(this);
    BGM_ = LoadSoundMem("./music/Electric_Equipment_Connection.mp3");

    return true;
}

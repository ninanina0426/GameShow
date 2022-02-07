#pragma once
#include <memory>
#include <list>
#include"Player.h"
#include"Enemy.h"
#include"Stage.h"
#include"Chat.h"
#include "BaseScene.h"




class GameScene :
    public BaseScene
{
public:
    GameScene();
    ~GameScene();

    bool IsEnemy1(void);    //敵が生きているか
    bool IsEnemy2(void);
    bool IsEnemy3(void);
    bool IsEnemy4(void);

    bool IsEPush1(void);
    bool IsEPush2(void);
    bool IsEPush3(void);
    bool IsEPush4(void);

    //チップ座標を受け取りマップチップ番号を返す
    int GetEvent(Vector2 pos);
   
private:
    uniquBaseScn Update( uniquBaseScn own) override;
    void DrawOwnScn() override;
    bool Init(void) override;
    bool Release(void);//インスタンスの開放
    SceneID GetSceneID(void) override { return SceneID::Game; };
    Player mPlayer;
    Enemy mEnemy;
    Stage  mStage;
<<<<<<< HEAD
    Chat mChat;
    /*std::list<std::unique_ptr<Obj>> objList_;*/
=======
>>>>>>> 0b2f29a0d7c9b31a6fd6ae28b7a1d2717b3f43b4
    int gameScene_;
    Vector2 mMapOffset;
    int bg_;
<<<<<<< HEAD
    int BGM_;
    TmxObj tmxobj_;
    //chat
    bool mIsChat;
=======


    
>>>>>>> 0b2f29a0d7c9b31a6fd6ae28b7a1d2717b3f43b4
};


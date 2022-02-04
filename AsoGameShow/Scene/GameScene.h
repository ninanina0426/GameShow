#pragma once
#include <memory>
#include <list>
#include"Player.h"
#include"Enemy.h"
#include "BaseScene.h"
#include "../tmx/TmxObj.h"

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


   
private:
    uniquBaseScn Update( uniquBaseScn own) override;
    void DrawOwnScn() override;
    bool Init(void) override;
    SceneID GetSceneID(void) override { return SceneID::Game; };
    Player mPlayer;
    Enemy mEnemy;
    /*std::list<std::unique_ptr<Obj>> objList_;*/
    int gameScene_;

    int bg_;
    int BGM_;
    TmxObj tmxobj_;
    
};


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

    bool IsEnemy1(void);    //ìGÇ™ê∂Ç´ÇƒÇ¢ÇÈÇ©
    bool IsEnemy2(void);
    bool IsEnemy3(void);
    bool IsEnemy4(void);

    bool IsEPush1(void);
    bool IsEPush2(void);
    bool IsEPush3(void);
    bool IsEPush4(void);


   
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


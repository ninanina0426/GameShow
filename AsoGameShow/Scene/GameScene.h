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

    bool IsEnemy1(void);    //�G�������Ă��邩
    bool IsEnemy2(void);
    bool IsEnemy3(void);
    bool IsEnemy4(void);

    bool IsEPush1(void);
    bool IsEPush2(void);
    bool IsEPush3(void);
    bool IsEPush4(void);

    //�`�b�v���W���󂯎��}�b�v�`�b�v�ԍ���Ԃ�
    int GetEvent(Vector2 pos);
   
private:
    uniquBaseScn Update( uniquBaseScn own) override;
    void DrawOwnScn() override;
    bool Init(void) override;
    bool Release(void);//�C���X�^���X�̊J��
    SceneID GetSceneID(void) override { return SceneID::Game; };
    Player mPlayer;
    Enemy mEnemy;
    Stage  mStage;
    Chat mChat;
    /*std::list<std::unique_ptr<Obj>> objList_;*/

    int gameScene_;
    Vector2 mMapOffset;
    int bg_;
    //chat
    bool mIsChat;

};


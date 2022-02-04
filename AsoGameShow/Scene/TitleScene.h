#pragma once
#include "BaseScene.h"
class TitleScene :
    public BaseScene
{
public:
    TitleScene();
    ~TitleScene();
private:
    uniquBaseScn Update( uniquBaseScn own) override;
    void DrawOwnScn() override;
    bool Init(void) override;
    SceneID GetSceneID(void) override { return SceneID::Title; };
   

    //�O���t�B�b�N�֌W
    int Image_;
    int count;
};


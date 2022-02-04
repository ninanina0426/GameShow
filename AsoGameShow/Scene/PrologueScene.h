#pragma once
#include <string>
#include "common/Vector2.h"
#include "BaseScene.h"

class PrologueScene :
    public BaseScene
{
public:
    PrologueScene();
    ~PrologueScene();
private:
    uniquBaseScn Update(uniquBaseScn own) override;
    void DrawOwnScn() override;
    bool Init(void) override;
    SceneID GetSceneID(void) override { return SceneID::PrologueScene; };

    void ChatDrow(std::string name);
    bool Prologue(void);
    //グラフィック関係
    Vector2 pos_;
    Vector2 Downsize_;
    bool Flag_;
    std::string name_;
    int chatBox_;
    int icon_[2];
    int count;
    int cuntspeed_;
};



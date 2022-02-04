#pragma once
#include <string>
#include "BaseScene.h"
class EndScene :
	public BaseScene
{
public:
    EndScene(std::string endtype);
    ~EndScene();
private:
    uniquBaseScn Update(uniquBaseScn own) override;
    void DrawOwnScn() override;
    bool Init(void) override;
    SceneID GetSceneID(void) override { return SceneID::EndScene; };
    std::string endType_;
};


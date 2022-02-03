#pragma once
#include <memory>
#include "common/Vector2.h"
class BaseScene;

using uniquBaseScn = std::unique_ptr<BaseScene>;

enum class SceneID
{
	Transition,
	Title,
	Game,
	Max
};

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual uniquBaseScn Update( uniquBaseScn own)=0;
	virtual void Draw();
	virtual void DrawOwnScn()=0 ;
	virtual bool Init(void) =0;
	virtual SceneID GetSceneID(void) = 0;
protected:
	int sceneScrID_;
	Vector2 screenSize_;


};


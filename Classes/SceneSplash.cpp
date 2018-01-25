#include "SceneSplash.h"
#include "SceneMainMenu.h"

Scene* SceneSplash::createScene()
{
    auto scene = Scene::create();
    auto layer = SceneSplash::create();

    scene->addChild(layer);
    return scene;
}

bool SceneSplash::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	//��ʱ������ͣ��2����Զ���ת��������
    this->scheduleOnce(schedule_selector(SceneSplash::goToMainMenuScene), DISPLAY_TIME_SPLASH_SCENE);

	this->setBackground("splash.jpg");

    return true;
}

void SceneSplash::goToMainMenuScene(float dt)
{
    auto scene = SceneMainMenu::createScene();
    
    Director::getInstance( )->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}




#include "SampleEngine.h"

void SampleEngine::setup(void)
{
    // call super
    EngineBoy::setup();

    // set y yValue
    this->getContext().setYValue(12);

    // show menu
    this->changeToScene(SampleGameScenes::Menu);
}

////////////////////////////
// Engineboy implementation

void SampleEngine::willShowScene(GameScene<SampleGameContext, SampleGameScenes> *nextScene)
{
  // Get rid of 'unused parameter' warnings
  (void)nextScene;
}

void SampleEngine::didDismissScene(GameScene<SampleGameContext, SampleGameScenes> *previousScene)
{
  // Clean up
  if(previousScene != nullptr)
       delete previousScene;
}

GameScene<SampleGameContext, SampleGameScenes> * SampleEngine::gameSceneForSceneID(SampleGameScenes sceneID)
{
    switch(sceneID)
    {
        case SampleGameScenes::Menu: return new MenuScene;
        case SampleGameScenes::GameA: return new GameSceneA;
        case SampleGameScenes::GameB: return new GameSceneB;
        default: return nullptr;
    }
}

void SampleEngine::_render(void){
  arduboy.setCursor(41,0);
  arduboy.print(F("EngineBoy"));

  arduboy.fillRect(0, this->getContext().yValue()-2, 128, 1);
}

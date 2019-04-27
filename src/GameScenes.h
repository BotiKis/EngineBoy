#pragma once

#include "EngineBoy.h"
#include "SampleGameContext.h"

enum class SampleGameScenes{
  Menu,
  GameA,
  GameB
};

//////////////////////
//////////////////////

class MenuScene : public GameScene<SampleGameContext, SampleGameScenes>
{
private:
    uint8_t menuIDX;

public:
    MenuScene();
    void update(EngineBoy<SampleGameContext, SampleGameScenes> & engine) override;
    void render(EngineBoy<SampleGameContext, SampleGameScenes> & engine) override;
};


//////////////////////
//////////////////////

class GameSceneA : public GameScene<SampleGameContext, SampleGameScenes>
{

public:
    void update(EngineBoy<SampleGameContext, SampleGameScenes> & engine) override;
    void render(EngineBoy<SampleGameContext, SampleGameScenes> & engine) override;
};


//////////////////////
//////////////////////

class GameSceneB : public GameScene<SampleGameContext, SampleGameScenes>
{

public:
    void update(EngineBoy<SampleGameContext, SampleGameScenes> & engine) override;
    void render(EngineBoy<SampleGameContext, SampleGameScenes> & engine) override;
};

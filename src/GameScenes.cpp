#include "GameScenes.h"

////////////////////////////////////////////
// MenuScene

MenuScene::MenuScene()
{
    menuIDX = 0;
}

void MenuScene::update(EngineBoy<SampleGameContext, SampleGameScenes> & engine)
{
    if(engine.arduboy.justPressed(B_BUTTON))
        engine.changeToScene((menuIDX == 0) ? SampleGameScenes::GameA : SampleGameScenes::GameB);

    if(engine.arduboy.justPressed(UP_BUTTON))
        menuIDX--;

    if(engine.arduboy.justPressed(DOWN_BUTTON))
        menuIDX++;

    menuIDX = menuIDX%2;
}

void MenuScene::render(EngineBoy<SampleGameContext, SampleGameScenes> & engine)
{
    uint8_t yPos = engine.getContext().yValue();

    engine.arduboy.setCursor(0, yPos);
    engine.arduboy.print(F("MENU"));

    engine.arduboy.setCursor(8, yPos + 10);
    engine.arduboy.print(F("Start Game A"));

    engine.arduboy.setCursor(8, yPos + 18);
    engine.arduboy.print(F("Start Game B"));

    engine.arduboy.setCursor(1, yPos + 10+menuIDX*8);
    engine.arduboy.print(F(">"));
}


////////////////////////////////////////////
// GameSceneA

void GameSceneA::update(EngineBoy<SampleGameContext, SampleGameScenes> & engine)
{
    if(engine.arduboy.justPressed(A_BUTTON)) engine.changeToScene(SampleGameScenes::Menu);
}

void GameSceneA::render(EngineBoy<SampleGameContext, SampleGameScenes> & engine)
{
    uint8_t yPos = engine.getContext().yValue();

    engine.arduboy.setCursor(0, yPos);
    engine.arduboy.print(F("GAME A"));

    engine.arduboy.setCursor(0, yPos + 10);
    engine.arduboy.print(F("Press A to return\nto the Menu"));
}

////////////////////////////////////////////
// GameSceneB

void GameSceneB::update(EngineBoy<SampleGameContext, SampleGameScenes> & engine)
{
    if(engine.arduboy.justPressed(A_BUTTON)) engine.changeToScene(SampleGameScenes::Menu);
}

void GameSceneB::render(EngineBoy<SampleGameContext, SampleGameScenes> & engine)
{
    uint8_t yPos = engine.getContext().yValue();

    engine.arduboy.setCursor(0, yPos);
    engine.arduboy.print(F("GAME B"));

    engine.arduboy.setCursor(0, yPos + 10);
    engine.arduboy.print(F("Press A to return\nto the Menu"));
}

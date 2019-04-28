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
		auto & tinyfont = engine.getContext().tinyfont();

		tinyfont.setCursor(0, yPos);
		tinyfont.print(F("MENU"));

		tinyfont.setCursor(8, yPos + 10);
		tinyfont.print(F("Start Game A"));

		tinyfont.setCursor(8, yPos + 18);
		tinyfont.print(F("Start Game B"));

		tinyfont.setCursor(1, yPos + 10+menuIDX*8);
		tinyfont.print(F(">"));
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
		auto & tinyfont = engine.getContext().tinyfont();

		tinyfont.setCursor(0, yPos);
		tinyfont.print(F("GAME A"));

		tinyfont.setCursor(0, yPos + 10);
		tinyfont.print(F("Press A to return\nto the Menu"));
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
		auto & tinyfont = engine.getContext().tinyfont();

		tinyfont.setCursor(0, yPos);
		tinyfont.print(F("GAME B"));

		tinyfont.setCursor(0, yPos + 10);
		tinyfont.print(F("Press A to return\nto the Menu"));
}

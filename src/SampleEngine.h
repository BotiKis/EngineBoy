#pragma once

#include "EngineBoy.h"
#include "GameScenes.h"
#include "SampleGameContext.h"

class SampleEngine: public EngineBoy <SampleGameContext, SampleGameScenes>
{
private:
	SampleGameContext _context;

public:
	void setup(void) final;

	// Getter & Setter for context
	SampleGameContext & getContext(void) final
	{
			return this->_context;
	}

	const SampleGameContext & getContext(void) const final
	{
		return this->_context;
	}

private:
	void willShowScene(GameScene<SampleGameContext, SampleGameScenes> *nextScene) final;
	void didDismissScene(GameScene<SampleGameContext, SampleGameScenes> *previousScene) final;
	GameScene<SampleGameContext, SampleGameScenes> * gameSceneForSceneID(SampleGameScenes sceneID);

	void _render(void) final;
};

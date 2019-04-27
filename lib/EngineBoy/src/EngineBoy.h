#pragma once

// license

#include <Arduboy2.h>

template<typename GameContextType, typename GameSceneType>
class EngineBoy;

template<typename GameContextType, typename GameSceneType>
class GameScene;

//////////////////////////////
// EngineBoy Engine

template<typename GameContextType, typename GameSceneType>
class EngineBoy
{
public:
	using GameContext = GameContextType;
	using GameSceneID = GameSceneType;

public:
	Arduboy2 arduboy;

private:
  // Used to calculate deltatime
  uint32_t _lastUpdateTimestamp = 0;
	uint32_t _deltaTime = 0;

protected:
  GameScene<GameContext, GameSceneID> *_currentScene;

public:
	// getter for deltatime
	uint32_t deltaTime() {return _deltaTime;} const

	virtual GameContext & getContext(void) = 0;
	virtual const GameContext & getContext(void) const = 0;

	virtual void setup(void)
    {
        // Init arduboy related stuff
        arduboy.begin();
        arduboy.initRandomSeed();
        arduboy.setFrameRate(60);

        // init internal stuff
        _currentScene = nullptr;
        _lastUpdateTimestamp = millis();
    }

	virtual void update(void){
		// calculate delta time
		uint32_t currentTime = millis();
		_deltaTime = currentTime - _lastUpdateTimestamp;
		_lastUpdateTimestamp = currentTime;

		// Update arduboy
		arduboy.pollButtons();

		// Tell current scene to update
		if(_currentScene != nullptr)
			_currentScene->update(*this);

		// call internal updaate
		_update();
	}

	virtual void display(void)
  {
      // Render current scene
      arduboy.clear();
      if(_currentScene)
          _currentScene->render(*this);

			// call internal render
			_render();

			arduboy.display();
  }

	void changeToScene(GameSceneID sceneID)
	{
	  // call callback of old scene
	  if(_currentScene != nullptr)
	      _currentScene->willDisappear(*this);
	  this->didDismissScene(_currentScene);

		// get new scene
	  _currentScene = this->gameSceneForSceneID(sceneID);

	  // call callback of new scene
		this->willShowScene(_currentScene);
		if(_currentScene != nullptr)
				_currentScene->didAppear(*this);
	}

protected:

  virtual GameScene<GameContext, GameSceneID>* gameSceneForSceneID(GameSceneID sceneID) = 0;

	virtual void willShowScene(GameScene<GameContext, GameSceneID> *nextScene)
	{
		// Get rid of 'unused parameter' warnings
		(void)nextScene;
	}

  virtual void didDismissScene(GameScene<GameContext, GameSceneID> *previousScene)
	{
		// Get rid of 'unused parameter' warnings
		(void)previousScene;
	}

	// Methods which gets called after the corresponding methods of the current scene
	// Consistent things like UI could be put here.
	virtual void _update(void){};
	virtual void _render(void){};
};


//////////////////////////////
// EngineBoy GameScene

template<typename GameContextType, typename GameSceneType>
class GameScene
{
public:
	using GameSceneID = GameSceneType;
	using GameContext = GameContextType;

protected:

	// In the implementation set this to the correct ID
	GameSceneID _gameSceneID;

private:

	GameSceneID getGameSceneID(void) const
	{
		return _gameSceneID;
	}

public:

  // Methods need to be implemented by subclass
	virtual void update(EngineBoy<GameContext, GameSceneID> & engine) = 0;
	virtual void render(EngineBoy<GameContext, GameSceneID> & engine) = 0;

  // Other methods
	virtual ~GameScene(void) {};

	virtual void didAppear(EngineBoy<GameContext, GameSceneID> & engine)
	{
		// Get rid of 'unused parameter' warnings
		(void)engine;
	}

	virtual void willDisappear(EngineBoy<GameContext, GameSceneID> & engine)
	{
		// Get rid of 'unused parameter' warnings
		(void)engine;
	}
};
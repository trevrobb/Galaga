#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include "AudioManager.h"
#include "Timer.h"
#include "StartScreen.h"
#include "BackGroundStars.h"
class GameManager {

private:
	static GameManager* sInstance;

	const int FRAME_RATE = 120;

	bool mQuit;
	
	Graphics* mGraphics;


	Timer* mTimer;
	SDL_Event mEvents;

	AssetManager* mAssetManager;
	InputManager* mInputManager;
	AudioManager* mAudioManager;

	Texture* mTex;

	BackGroundStars* mStars;
	StartScreen* mStartScreen;

public:

	static GameManager* Instance();
	static void Release();

	void Run();

	void ScaleEffect();

private:
	GameManager();
	~GameManager();


	void EarlyUpdate();
	void Update();
	void lateUpdate();

	void Render();
};




#endif

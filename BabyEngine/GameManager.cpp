#include "GameManager.h"
#include "MathHelper.h"
#include<time.h>	


GameManager* GameManager::sInstance = NULL;

GameManager* GameManager::Instance() {
	if (sInstance == NULL)
		sInstance = new GameManager();

	return sInstance;
}

void GameManager::Release() {
	delete sInstance;
	sInstance = NULL;

}

GameManager::GameManager() {

	srand(time(0));
	mQuit = false;

	mGraphics = Graphics::Instance();

	if (!Graphics::Initialized())
		mQuit = true;

	mAssetManager = AssetManager::Instance();

	mInputManager = InputManager::Instance();

	mAudioManager = AudioManager::Instance();


	mTimer = Timer::Instance();

	mStars = BackGroundStars::Instance();
	mStartScreen = new StartScreen();
	
}

GameManager::~GameManager() {


	AssetManager::Release();
	mAssetManager = NULL;

	Graphics::Release();
	mGraphics = NULL;

	InputManager::Release();
	mInputManager = NULL;

	Timer::Release();
	mTimer = NULL;

	delete mTex; 
	mTex = NULL;

	AudioManager::Release();
	mAudioManager = NULL;

	BackGroundStars::Release();
	mStars = NULL;

	delete mStartScreen;
	mStartScreen = NULL;

}

void GameManager::EarlyUpdate() {
	

	mInputManager->Update();
	mTimer->Reset();

}

void GameManager::Update() {
	

	mStars->Update();
	mStartScreen->Update();

	



}

void GameManager::lateUpdate() {

	mInputManager->UpdatePrevInput();
	

}

void GameManager::Render() {

	mGraphics->ClearBackBuffer();


	mStars->Render();
	
	mStartScreen->Render();
	

	mGraphics->Render();

}
void GameManager::Run() {
	while (!mQuit) {
		mTimer->Update();
		while (SDL_PollEvent(&mEvents) != 0) {
			if (mEvents.type == SDL_QUIT) {
				mQuit = true;
			}
			
		}

		if (mTimer->DeltaTime() >= (1.0f / FRAME_RATE)) {

			EarlyUpdate();
			Update();
			lateUpdate();
			Render();
		}
		
	}
}


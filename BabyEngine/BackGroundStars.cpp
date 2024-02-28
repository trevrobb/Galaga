#include "BackGroundStars.h"

BackGroundStars* BackGroundStars::sInstance = NULL;

BackGroundStars* BackGroundStars::Instance() {
	if (sInstance == NULL)
		sInstance = new BackGroundStars();

	return sInstance;
}

void BackGroundStars::Release() {
	delete sInstance;
	sInstance = NULL;
}


BackGroundStars::BackGroundStars() {
	for (int i = 0; i < LAYER_COUNT; i++) {
		mLayers[i] = new StarLayer(i);
	}

}

void BackGroundStars::Scroll(bool b) {
	Star::Scroll(b);
}


BackGroundStars::~BackGroundStars() {
	for (int i = 0; i < LAYER_COUNT; i++) {
		delete mLayers[i];
		mLayers[i] = NULL;
	}
}

void BackGroundStars::Update() {
	for (int i = 0; i < LAYER_COUNT; i++)
		mLayers[i]->Update();
}

void BackGroundStars::Render() {
	for (int i = 0; i < LAYER_COUNT; i++)
		mLayers[i]->Render();
}
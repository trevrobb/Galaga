#ifndef _BACKGROUNDSTARS_H
#define _BACKGROUNDSTARS_H
#include "StarLayer.h"


class BackGroundStars {
private:

	static BackGroundStars* sInstance;

	static const int LAYER_COUNT = 3;

	StarLayer* mLayers[LAYER_COUNT];

public:
	static BackGroundStars* Instance();
	static void Release();
	void Scroll(bool b);
	void Update();
	void Render();

private:
	BackGroundStars();
	~BackGroundStars();
};









#endif // !_BACKGROUNDSTARS_H


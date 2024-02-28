#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "BackGroundStars.h"


class StartScreen : public GameEntity {

private:

	Timer* mTimer;
	InputManager* mInput;
	//top bar entities
	GameEntity* mTopBar;
	Texture* mPlayer1;
	Texture* mHiScore;
	Texture* mPlayer2;

	//playMode entities
	GameEntity* mPlayModes;
	Texture* mOnePlayerMode;
	Texture* mTwoPlayerMode;
	Texture* mCursor;
	Vector2 mCursorStartPos;
	Vector2 mCursorOffset;
	int mSelectedMode;

	//Bottom Bar Entities
	GameEntity* mBotbar;
	Texture* mNamco;
	Texture* mDates;
	Texture* mRights;

	//logo
	Texture* mLogo;

	//screen animation vars
	Vector2 mAnimationStartPos;
	Vector2 mAnimationEndPos;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;

	BackGroundStars* mStars;


public:
	StartScreen();
	~StartScreen();

	void ChangeSelectedMode(int change);

	void Update();
	void Render();




};




#endif

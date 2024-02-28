#include "StartScreen.h"

StartScreen::StartScreen() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	//Top Bar
	mTopBar = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, 80.0f));
	mPlayer1 = new Texture("1UP", "galg.ttf", 16, { 200, 0, 0 });
	mHiScore = new Texture("HI-SCORE", "galg.ttf", 16, { 200, 0, 0 });
	mPlayer2 = new Texture("2UP", "galg.ttf", 16, { 200, 0, 0 });



	mPlayer1->Parent(mTopBar);
	mHiScore->Parent(mTopBar);
	mPlayer2->Parent(mTopBar);


	mPlayer1->Pos(Vector2(-Graphics::Instance()->SCREEN_WIDTH * .35f, 0.0f));
	mHiScore->Pos(VEC2_ZERO);
	mPlayer2->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * .2f, 0.0f));

	mTopBar->Parent(this);

	//logo
	mLogo = new Texture("gal_img.png", 0, 0, 1020, 510);
	
	mLogo->Scale(Vector2(0.5f, 0.5f));
	mLogo->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.3f));
	
	mLogo->Parent(this);

	//PlayModes (1 and 2 Player)
	mPlayModes = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * .55f));
	mOnePlayerMode = new Texture("1 Player", "galg.ttf", 32, { 230, 230, 230 });
	mTwoPlayerMode = new Texture("2 Player", "galg.ttf", 32, { 230, 230, 230 });
	mCursor = new Texture("Cursor.png");


	mOnePlayerMode->Parent(mPlayModes);
	mTwoPlayerMode->Parent(mPlayModes);
	mCursor->Parent(mPlayModes);

	mOnePlayerMode->Pos(Vector2(0.0, -35.0f));
	mTwoPlayerMode->Pos(Vector2(0.0, 35.0f));
	mCursor->Pos(Vector2(-140.0f, -35.0f));

	mPlayModes->Parent(this);

	mCursorStartPos = mCursor->Pos(local);
	mCursorOffset = Vector2(0.0f, 70.0f);
	mSelectedMode = 0;

	//Bottom Bar Entities
	mBotbar = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * .7f));
	mNamco = new Texture("namco", "namco__.ttf", 36, { 200, 0, 0 });
	mDates = new Texture("1981 1985 NAMCO LTD.", "galg.ttf", 32, { 230, 230, 230 });
	mRights = new Texture("ALL RIGHTS RESERVED", "galg.ttf", 32, { 230, 230, 230 });

	mNamco->Parent(mBotbar);
	mDates->Parent(mBotbar);
	mRights->Parent(mBotbar);

	mNamco->Pos(VEC2_ZERO);
	mDates->Pos(Vector2(0.0f, 90.0f));
	mRights->Pos(Vector2(0.0, 170.0f));

	mBotbar->Parent(this);


	//Screen anim vars
	mAnimationStartPos = Vector2(0.0, Graphics::Instance()->SCREEN_HEIGHT);
	mAnimationEndPos = VEC2_ZERO;
	mAnimationTotalTime = 5.0f;
	mAnimationTimer = 0.0f;
	mAnimationDone = false;

	Pos(mAnimationStartPos);

}


StartScreen::~StartScreen() {
	//freeing Top bar
	delete mTopBar;
	mTopBar = NULL;

	delete mPlayer1;
	mPlayer1 = NULL;

	delete mHiScore;
	mHiScore = NULL;

	delete mPlayer2;
	mPlayer2 = NULL;

	//freeing playmode
	delete mPlayModes;
	mPlayModes = NULL;

	delete mOnePlayerMode;
	mOnePlayerMode = NULL;

	delete mTwoPlayerMode;
	mTwoPlayerMode = NULL;

	delete mCursor;
	mCursor = NULL;

	//freeing bottom bar
	delete mBotbar;
	mBotbar = NULL;

	delete mNamco;
	mNamco = NULL;

	delete mDates;
	mDates = NULL;

	delete mRights;
	mRights = NULL;

	//freeing logo
	delete mLogo;
	mLogo = NULL;


}

void StartScreen::ChangeSelectedMode(int change) {
	mSelectedMode += change;

	if (mSelectedMode < 0)
		mSelectedMode = 1;
	else if (mSelectedMode > 1)
		mSelectedMode = 0;

	mCursor->Pos(mCursorStartPos + mCursorOffset * mSelectedMode);
}

void StartScreen::Update() {

	if (!mAnimationDone) {
		mAnimationTimer += mTimer->DeltaTime();
		Pos(Lerp(mAnimationStartPos, mAnimationEndPos, mAnimationTimer / mAnimationTotalTime));
		mStars->Scroll(true);
		if (mAnimationTimer >= mAnimationTotalTime) {
			mAnimationDone = true;
			mStars->Scroll(false);
		}

		if (mInput->KeyPressed(SDL_SCANCODE_UP) || mInput->KeyPressed(SDL_SCANCODE_DOWN) || mInput->KeyPressed(SDL_SCANCODE_S) || mInput->KeyPressed(SDL_SCANCODE_W)) {
			mAnimationDone = true;
			mStars->Scroll(false);
			Pos(mAnimationEndPos);
		}
	}
	else {
		if (mInput->KeyPressed(SDL_SCANCODE_DOWN) || mInput->KeyPressed(SDL_SCANCODE_S)) {
			ChangeSelectedMode(1);
		}
		else if (mInput->KeyPressed(SDL_SCANCODE_UP) || mInput->KeyPressed(SDL_SCANCODE_W)) {
			ChangeSelectedMode(-1);
		}
	}
	mStars = BackGroundStars::Instance();
	


}

void StartScreen::Render() {
	mPlayer1->Render();
	mHiScore->Render();
	mPlayer2->Render();

	mOnePlayerMode->Render();
	mTwoPlayerMode->Render();
	mCursor->Render();

	mNamco->Render();
	mDates->Render();
	mRights->Render();

	mLogo->Render();
}


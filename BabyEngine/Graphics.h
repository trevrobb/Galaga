#ifndef _GRAPHICS_H
#define _GRAPHICS_H
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

class Graphics {

public: 
	static const int SCREEN_WIDTH = 1024;	
	static const int SCREEN_HEIGHT = 896;
	const char* WINDOW_TITLE = "Arcade";

private:
	static Graphics* sInstance; 
	static bool sInitialized;

	SDL_Window* mWindow;
	SDL_Surface* mBackBuffer;



	SDL_Renderer* mRenderer;

public:
	static Graphics* Instance();
	static void Release();
	static bool Initialized();
	

	SDL_Texture* LoadTexture(std::string path);

	SDL_Texture* CreateTextTecture(TTF_Font* font, std::string text, SDL_Color color);

	
	void ClearBackBuffer();
	void DrawTexture(SDL_Texture* tex, SDL_Rect* clip = NULL,  SDL_Rect* rend = NULL, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);


	void Render();
	

private:

	Graphics();
	~Graphics();

	bool Init();


};


#endif
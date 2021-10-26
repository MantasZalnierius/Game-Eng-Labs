#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <SDL_image.h>
#include <SDL.h>
#include <vector>
#include "Timer.h"
#include "DrawAPI.h"

class AnimatedSprite {
public:
	AnimatedSprite();
	AnimatedSprite(SDL_Texture*);
	AnimatedSprite(SDL_Texture*, const SDL_Rect&);
	~AnimatedSprite();

	const Timer& getClock();
	const float getTime();
	const std::vector<SDL_Rect>& getFrames();
	void clearFrames();
	const SDL_Rect& getFrame(int);
	void addFrame(const SDL_Rect&);
	const int getCurrentFrame();
	void setLooped(bool);
	const bool getLooped();
	void setPlayed(bool);
	const bool getPlayed();
	void setTime(float t_timer);
	void setTextureRect(SDL_Rect t_rect);
	void render(int x, int y, SDL_Renderer* t_renderer);
	void update();
	SDL_Texture* getTexture() {return m_texture;}
	
private:
	Timer m_clock;
	float m_timer;
	SDL_Texture* m_texture;
	std::vector<SDL_Rect> m_frames;
	unsigned int m_current_frame;
	bool m_loop;
	unsigned int m_play_count;
	unsigned int m_max_plays;
	bool m_played;
	SDL_Rect m_rectOfImage;
	DrawAPI* sdlDrawApi;
};
#endif
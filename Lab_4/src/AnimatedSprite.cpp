#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite() : 
	m_current_frame(0),
	m_timer(0.5f),
	m_loop(true),
	m_play_count(0),
	m_max_plays(0),
	m_played(false)
{
	sdlDrawApi = new SdlDrawAPI();
}

AnimatedSprite::AnimatedSprite(SDL_Texture* t_texture) : AnimatedSprite(){
    m_texture = t_texture;
}

AnimatedSprite::AnimatedSprite(SDL_Texture* t_texture, const SDL_Rect& t_rect) : 
	AnimatedSprite(t_texture)
{
	m_frames.push_back(t_rect);
}

AnimatedSprite::~AnimatedSprite() {
}

const Timer& AnimatedSprite::getClock() {
	return m_clock;
}

const float AnimatedSprite::getTime() {
	return m_timer;
}

void AnimatedSprite::setTime(float t_timer)
{
	m_timer = t_timer;
}

const std::vector<SDL_Rect>& AnimatedSprite::getFrames() {
	return m_frames;
}

void AnimatedSprite::clearFrames() {
	m_current_frame = 0;
	m_played = false;
	if (!m_frames.empty())
	{
		m_frames.clear();
	}
}

const SDL_Rect& AnimatedSprite::getFrame(int n) {
	return m_frames[n];
}

void AnimatedSprite::addFrame(const SDL_Rect& t_frame) {
	m_frames.push_back(t_frame);
}

const int AnimatedSprite::getCurrentFrame() {
	return m_current_frame;
}

void AnimatedSprite::setLooped(bool loop) {
	this->m_loop = loop;
}

const bool AnimatedSprite::getLooped() {
	return this->m_loop;
}

void AnimatedSprite::setPlayed(bool played) {
	this->m_played = played;
}

const bool AnimatedSprite::getPlayed() {
	return this->m_played;
}

void AnimatedSprite::render(int t_x, int t_y, SDL_Renderer* t_renderer)
{
    SDL_Rect rect = {t_x, t_y, m_rectOfImage.w, m_rectOfImage.h};
	sdlDrawApi->drawSDLTexture(m_texture, rect, t_renderer, m_rectOfImage);
}

void AnimatedSprite::setTextureRect(SDL_Rect t_rectOfImage)
{
    m_rectOfImage = t_rectOfImage;
}

void AnimatedSprite::update(){
	// If not looped only play once
	if (m_played == true && !m_loop)
	{
		m_current_frame = m_frames.size() - 1;
	}
	else {
		if (m_clock.getTimerAsSeconds() > m_timer) {
			if (m_frames.size() > m_current_frame + 1)
			{
				m_current_frame++;
			}
			else {
				m_current_frame = 0;
				m_played = true;
			}
			m_clock.restart();
		}
	}
	
}
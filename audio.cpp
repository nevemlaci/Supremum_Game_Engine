#include "audio.h"
#include <iostream>

AudioManager::AudioManager()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

void AudioManager::setMusic(const char* path)
{
	this->bgmusic = Mix_LoadMUS(path);
	if (!this->bgmusic) {
		std::cout << "Failed to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
	
	}
}

void AudioManager::startMusic()
{
	Mix_PlayMusic(this->bgmusic, 0);
}

void AudioManager::stopMusic()
{
	Mix_HaltMusic();
}

void AudioManager::loadSFX(const char* path, std::string id)
{
	this->sfx[id] = Mix_LoadWAV(path);
}

void AudioManager::playSFX(std::string id, int loops, int channel)
{
	Mix_PlayChannel(channel, this->sfx[id], loops);
}
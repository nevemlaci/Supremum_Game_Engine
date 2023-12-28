#pragma once

#include <SDL_mixer.h>
#include <map>
#include <string>

class AudioManager {
public:
	AudioManager();

	void startMusic();
	void stopMusic();
	void setMusic(const char* path);
	void loadSFX(const char* path, std::string id);
	void playSFX(std::string id, int loops=1, int channel=-1);
private:
	Mix_Music* bgmusic;
	std::map<std::string, Mix_Chunk*> sfx;
};
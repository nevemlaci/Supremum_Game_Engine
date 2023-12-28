#pragma once

#include <SDL_mixer.h>
#include <map>
#include <string>

class AudioManager {
public:
	/// @brief AudioManager constructor, initializes SDL_mixer and opens the audio device
	AudioManager();
	/// @brief set the music
	/// @param path path to the music file(wav)
	void setMusic(const char* path);
	/// @brief start playing the music set by setMusic()
	void startMusic();
	/// @brief stop playing the music
	void stopMusic();
	/// @brief loads a sound
	/// @param path path to the sound file(wav)
	/// @param id id of the sound. 
	void loadSFX(const char* path, std::string id);
	/// @brief plays a sound
	/// @param id the id of the sound to be played
	/// @param loops how many times should the sound be looped(1 by default)
	/// @param channel channel to play the sound on(-1 by default)
	void playSFX(std::string id, int loops=1, int channel=-1);
private:
	/// @brief music
	Mix_Music* bgmusic;
	/// @brief map of sounds
	/// @todo memory leak if sound isnt freed when new sound of same id is loaded
	std::map<std::string, Mix_Chunk*> sfx;
};
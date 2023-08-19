#include "headers/music.h"


void Music::PlayMusic(int num) {

	if (backgroundmusic != nullptr) {
		Mix_PlayMusic(backgroundmusic, num);
	}

}

void Music::PauseBackgroundMusic() {

	Mix_PauseMusic();

}

void Music::SetBackgroundVolume(int volume) {

	Mix_VolumeMusic(volume);

}
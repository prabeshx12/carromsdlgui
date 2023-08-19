#pragma once
#include <SDL.h>
#include<SDL_mixer.h>
#include <iostream>

class Music {
	private:
		Mix_Music* backgroundmusic;

	public:
		Music(const char* musicfilepath) {
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
				std::cout << "Audio Library not working!!" << Mix_GetError() << std::endl;
			}
			backgroundmusic = Mix_LoadMUS(musicfilepath);
		}

		~Music() {
			Mix_FreeMusic(backgroundmusic);
		}

		void PlayMusic(int num);

		void PauseBackgroundMusic();

		void SetBackgroundVolume(int volume);

};

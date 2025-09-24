/* 
    Copyright (C) 2025  Juan Perdomo (Jakepys)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include "colors.h"
#include "laudio.h"

// Initializes the audio system with the given parameters.
// freq: Sample rate (e.g., 44100)
// format: Audio format (e.g., MIX_DEFAULT_FORMAT)
// channels: Number of channels (e.g., 2 for stereo)
// chunksize: Size of audio chunks
int init_audio(int freq, int format, int channels, int chunksize) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0){
        fprintf(stderr, RED "SDL Init Err: %s\n" RESET, SDL_GetError());
        return 0;
    }

    if (Mix_OpenAudio(freq, format, channels, chunksize) < 0) {
        fprintf(stderr, RED "Mix Open Audio Err: %s\n" RESET, Mix_GetError());
        return 0;
    }

    // Reserve any channels
    Mix_AllocateChannels(16);

    return 1;
}

// Loads and plays an audio file (e.g., MP3).
// Returns 0 on error, -1 on success.
int play_audio(const char *fileaudio) {
    Mix_Music *music = Mix_LoadMUS(fileaudio);

    if (!music) {
        fprintf(stderr, RED "Error to load %s: %s\n", fileaudio, Mix_GetError());
        return 0;
    }

    if (Mix_PlayMusic(music, 1) == -1) {
        fprintf(stderr, RED "Error to play: %s\n" RESET, Mix_GetError());
        return 0;
    }

    return -1;
}

// Pauses the currently playing music.

void pause_audio() {
    if (Mix_PlayingMusic()) {
        Mix_PauseMusic();
    }
}
// Resumes paused music.


void resume_audio() {
    if (Mix_PlayingMusic()) {
        Mix_ResumeMusic();
    }
// Stops the music playback.
}


void stop_audio() {
// Sets the music volume (0-128).
    Mix_HaltMusic();
}


// Closes the audio system and frees resources.
void set_audio_volume(int volume) {
    Mix_VolumeMusic(volume);
}

void close_audio() {
    Mix_CloseAudio();
    SDL_Quit();
}
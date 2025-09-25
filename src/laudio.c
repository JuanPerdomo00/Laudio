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
#include "laudio.h"

// Initial state, to avoid recreating or calling functions more than once.
static int initial_state_audio = 0;

// Initializes the audio system with the given parameters.
// freq: Sample rate (e.g., 44100)
// format: Audio format (e.g., MIX_DEFAULT_FORMAT)
// channels: Number of channels (e.g., 2 for stereo)
// chunksize: Size of audio chunks
int init_audio(int freq, int format, int channels, int chunksize) {
    if(initial_state_audio) {
        return 1;
    }

    if (SDL_Init(SDL_INIT_AUDIO) < 0){
        return 0;
    }

    if (Mix_OpenAudio(freq, format, channels, chunksize) < 0) {
        return 0;
    }

    // Reserve any channels
    Mix_AllocateChannels(16);
    initial_state_audio = 1;
    return 1;
}

// Loads and plays an audio file (e.g., MP3).
int play_audio(const char *fileaudio) {
    Mix_Music *music = Mix_LoadMUS(fileaudio);

    if (!music) {
        return 0;
    }

    if (Mix_PlayMusic(music, 1) == -1) {
        Mix_FreeMusic(music);
        return 0;
    }

    return 1;
}

// Pauses the currently playing music.
void pause_audio() {
    if (Mix_PlayingMusic() || Mix_PausedMusic()) {
        Mix_PauseMusic();
    }
}
// Resumes paused music.
void resume_audio() {
    if (Mix_PausedMusic()) {
        Mix_ResumeMusic();
    }
}


// Stop music.
void stop_audio() {
    Mix_HaltMusic();
}

// Closes the audio system and frees resources.
void set_audio_volume(int volume) {
    Mix_VolumeMusic(volume);
}

void close_audio() {
    if(initial_state_audio) {
        Mix_CloseAudio();
        SDL_Quit();
        initial_state_audio = 0;
    }
}

// State initialize audio
int audio_is_initialized() {
    return  initial_state_audio;
}
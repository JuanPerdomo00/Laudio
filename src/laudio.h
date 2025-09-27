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

#ifndef AUDIO_H
#define AUDIO_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

// Initializes the audio system
int init_audio(int freq, int format, int channels, int chunksize);

// Loads and plays an audio file
int play_audio(const char *fileaudio);

// Pauses the currently playing music
void pause_audio();

// Resumes paused music
void resume_audio();

// Stops the music playback
void stop_audio();

// Sets the music volume (0-128)
void set_audio_volume(int volume);

// Closes the audio system and frees resources
void close_audio();

// State audio
int audio_is_initialized();

// is playing audio
int is_playing_audio();
#endif 
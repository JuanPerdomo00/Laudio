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

#include <lua.h>
#include <lauxlib.h>
#include "laudio.h"

// Lua function: audio.init(freq, format, channels, chunksize)
// Initializes the audio system from Lua.
static int l_init_audio(lua_State *L) {
    int freq = luaL_optinteger(L, 1, 44100);
    int format = luaL_optinteger(L, 2, MIX_DEFAULT_FORMAT);
    int channel = luaL_optinteger(L, 3, 2);
    int chunksize = luaL_optinteger(L, 4, 2048);

    if(!init_audio(freq, format, channel, chunksize)) {
        lua_pushnil(L);
        lua_pushstring(L, Mix_GetError());
        return 2;
    }

    lua_pushboolean(L, 1);
    return 1;
}

// Lua function: audio.close()
// Closes the audio system from Lua.
static int l_close_audio(lua_State *L) {
    close_audio();
    return 0;
}


// Lua function: audio.play("file.mp3")
// Plays an audio file from Lua.
static int l_play_audio(lua_State *L) {
    const char *fileaudio  = luaL_checkstring(L, 1);
    if (!audio_is_initialized()) {
        lua_pushnil(L);
        lua_pushstring(L, "Audio not initialized");
        return 2;
    }

    if (play_audio(fileaudio)) {
        lua_pushboolean(L, 1);
        return 1;
    }

    lua_pushnil(L);
    lua_pushstring(L, Mix_GetError());
    return 2;
}


// Lua function: audio.pause()
// Pauses the audio playback from Lua.
static int l_pause_audio(lua_State *L) {
    pause_audio();
    return 0;
}


// Lua function: audio.resume()
// Resumes the audio playback from Lua.
static int l_resume_audio(lua_State *L) {
    resume_audio();
    return 0;
}



// Lua function: audio.stop()
// Stops the audio playback from Lua.
static int l_stop_audio(lua_State *L) {
    stop_audio();
    return 0;
}


// Lua function: audio.set_audio_volume(volume)
// Sets the audio volume from Lua.
static int l_set_audio_volume(lua_State *L) {
    int volume = luaL_checkinteger(L, 1);
    set_audio_volume(volume);
    return 0;
}



// Lua register func
int luaopen_laudio(lua_State *L) {
    luaL_Reg funcs[] = {
        {"init", l_init_audio},
        {"close", l_close_audio},
        {"play", l_play_audio},
        {"pause", l_pause_audio},
        {"resume", l_resume_audio},
        {"stop", l_stop_audio},
        {"set_audio_volume", l_set_audio_volume},
        {NULL, NULL}
    };

    luaL_newlib(L, funcs);
    return 1;
}
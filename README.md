# LAudio - Simple Audio Playback Library for Lua

LAudio is a minimal audio playback library using Lua C API bindings with SDL2_mixer.
It provides a small set of functions for basic audio usage: play, pause, stop, and volume control.

# Compiling and installing Lua audio
```sh
make
# Check where Lua expects C modules
lua -e "print(package.cpath)"
# Copy the compiled library to the correct path
sudo cp laudio.so /usr/local/lib/lua/5.4/

# or use install.lua
# If the Lua installation path is different, please check
# it. If the folder is different from 5.4, modify the
# script or do it manually. (It's faster if you do it  #manually. XD)
lua install.lua
```

# explanation and use of the API in Lua
```lua
-- package name is 'audio'
local audio = require("audio")

-- Initialize the module
-- By default, it uses a standard frequency, format, and chunk size.
-- For more details see SDL_mixer docs:
-- https://wiki.libsdl.org/SDL2_mixer/Mix_OpenAudio
audio.init()

-- Play an audio file
audio.play("test.wav")

-- Pause / resume playback
audio.pause()

-- Stop playback
audio.stop()

-- Set volume (integer value, e.g. 0–128 depending on SDL_mixer)
audio.setVolume(64)

-- Close and clean up
audio.close()

-- is playing audio
audio.is_playing()
```

# Supported Formats
Supported formats depend on how SDL_mixer was built on your system.
Most builds include:

- WAV
- MP3
- OGG Vorbis

# Full Example
in file `test.lua`
The example song was taken from the Free Software Foundation website.
[FSF](https://www.gnu.org/music/free-software-song.en.html)
--[[ 
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
]]--

local audio = require("laudio")

local ok, err = audio.init()
if not ok then
    print("Error initializing audio", err)
    return 
end

print("Audio initialized")
audio.play("FreeSWSong.ogg")

print("Playing...")
os.execute("sleep 10")

print("Pause...")
audio.pause()
os.execute("sleep 3")

print("Resume...")
audio.resume()

print("Volume control...")
for i = 0, 100, 10 do
    print("Volume: ".. i)
    audio.set_audio_volume(i)
    os.execute("sleep 1")
end

os.execute("sleep 10")
print("Stop...")
audio.stop()
audio.close()

print("Audio closed")

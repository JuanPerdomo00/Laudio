function banner()
    print([[
    Laudio library installer.
    by: Jakepys.
    ]])
end

function cmd(...)
    io.popen(... .. " 2>&1")
end

function main()
    banner()
    cmd("make")
    cmd("sudo mv laudio.so /usr/local/lib/lua/5.4/")
end

main()

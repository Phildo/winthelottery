build: bin/SDLActivity-debug.apk
	

bin/SDLActivity-debug.apk:
	ndk-build; ant debug

install: bin/SDLActivity-debug.apk
	adb uninstall com.phildogames.winthelottery; adb -d install bin/SDLActivity-debug.apk

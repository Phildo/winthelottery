build: bin/SDLActivity-debug.apk
	ndk-build; ant -S debug

install: build
	adb uninstall com.phildogames.winthelottery; adb -d install bin/SDLActivity-debug.apk

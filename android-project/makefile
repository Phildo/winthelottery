build: bin/SDLActivity-debug.apk
	ndk-build; ant -S debug

install: build
	adb uninstall com.phildogames.winthelottery; adb -d install bin/SDLActivity-debug.apk

debug: install
	adb shell am start -n com.phildogames.winthelottery/com.phildogames.winthelottery.WinTheLotteryActivity ; adb logcat -c ; adb logcat | sed -n /WTL/p


DEVICE=-e #-e = emulator, -d = device (usb)

build: bin/SDLActivity-debug.apk
	ndk-build ; ant -S debug

install: build
	adb $(DEVICE) install -r bin/SDLActivity-debug.apk

run: install
	adb shell am start -n com.phildogames.winthelottery/com.phildogames.winthelottery.WinTheLotteryActivity

debug: run
	adb logcat -c && adb logcat | sed -n /WTL/p


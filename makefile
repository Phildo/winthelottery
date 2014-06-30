go: android

android:
	cd android-project; amake install;

adebug: android
	adb shell am start -n com.phildogames.winthelottery/com.phildogames.winthelottery.WinTheLotteryActivity ; adb logcat -c ; adb logcat | sed -n /WTL/p


SRCDIR = src
BINDIR = bin
CC = g++
DEBUG = -g
DEBUGGER = gdb
CFLAGS = -Wall $(DEBUG)
LFLAGS = -Wall

go: android

android: adebug
	

abuild:
	cd android-project; amake build;

ainstall:
	cd android-project; amake install;

adebug: ainstall
	adb shell am start -n com.phildogames.winthelottery/com.phildogames.winthelottery.WinTheLotteryActivity ; adb logcat -c ; adb logcat | sed -n /WTL/p

#can easily switch out depending on what version I'm working on
debug: adebug
	

test:
	$(CC) $(CFLAGS) src/test_main.cpp src/model.cpp -o $(BINDIR)/test.out; $(BINDIR)/test.out

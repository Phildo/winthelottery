#
# This makefile mainly forwards make commands to correct project
#


#
# defaults (switch out for sugar w/r/t currently working-on platform)
#
build: abuild
	

install: ainstall
	

debug: adebug
	


#
# android
#
abuild:
	cd android-project; amake build;

ainstall:
	cd android-project; amake install;

adebug:
	cd android-project; amake debug;

#
# ios
#
ibuild:
	#cd ios-project; amake build;

iinstall:
	#cd ios-project; amake install;

idebug:
	#cd ios-project; amake debug;

#
# pc
#
pbuild:
	#cd pc-project; amake build;

pinstall:
	#cd pc-project; amake install;

pdebug:
	#cd pc-project; amake debug;

#
# testing
#
tbuild:
	cd tests; amake build;

tinstall:
	cd tests; amake install;

tdebug:
	cd tests; amake debug;


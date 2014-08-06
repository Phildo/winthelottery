#
# This makefile mainly forwards make commands to correct project
#
SRC_DIR=src
ANDROID_DIR=android-project
IOS_DIR=ios-project
PC_DIR=pc-project
TEST_DIR=tests

ANDROID_DEF=WTL_ANDROID
IOS_DEF=WTL_IOS
PC_DEF=WTL_PC

#
# defaults (switch out for sugar w/r/t currently working-on platform)
#
build: abuild
	

install: ainstall
	

debug: adebug
	


#
# android
#
adefine:
	sed -i.bak -E -e 's/$(IOS_DEF)|$(PC_DEF)/$(ANDROID_DEF)/g' $(SRC_DIR)/defines.h && rm $(SRC_DIR)/defines.h.bak

abuild: adefine
	cd $(ANDROID_DIR); amake build;

ainstall: adefine
	cd $(ANDROID_DIR); amake install;

adebug: adefine
	cd $(ANDROID_DIR); amake debug;

#
# ios
#
idefine:
	sed -i.bak -E -e 's/$(ANDROID_DEF)|$(PC_DEF)/$(IOS_DEF)/g' $(SRC_DIR)/defines.h && rm $(SRC_DIR)/defines.h.bak

ibuild: idefine
	#cd $(IOS_DIR); amake build;

iinstall: idefine
	#cd $(IOS_DIR); amake install;

idebug: idefine
	#cd $(IOS_DIR); amake debug;

#
# pc
#
pdefine:
	sed -i.bak -E -e 's/$(IOS_DEF)|$(ANDROID_DEF)/$(PC_DEF)/g' $(SRC_DIR)/defines.h && rm $(SRC_DIR)/defines.h.bak

pbuild: pdefine
	#cd $(PC_DIR); amake build;

pinstall: pdefine
	#cd $(PC_DIR); amake install;

pdebug: pdefine
	#cd $(PC_DIR); amake debug;

#
# testing
#
tbuild: pdefine
	cd $(TEST_DIR); amake build;

tinstall: pdefine
	cd $(TEST_DIR); amake install;

tdebug: pdefine
	cd $(TEST_DIR); amake debug;


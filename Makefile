all:
	cc -o send -g3 RCSwitch.cpp send.cpp -DRCSwitchDisableReceiving=1 -DRPI=1 -lwiringPi
	cc -o on RCSwitch.cpp on.cpp -DRCSwitchDisableReceiving=1 -DRPI=1 -lwiringPi
	strip on

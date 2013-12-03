#
# Just a helper for Makefiles addicts.
# The smews build system uses scons
#
IPADDR=192.168.5.68
TARGET=mbed_ethernet
APPS=:myapp1/all_in_one
PROGRAM_CMD=cp ./bin/mbed_ethernet/smews.bin /media/vanneste/MBED

all:
	scons ipaddr=$(IPADDR) target=$(TARGET) apps=$(APPS) && $(PROGRAM_CMD) && sync
clean:
	scons -c

#!/bin/bash -ex

make clean

# With SDCARD_DISABLED
BOARD_ID=magspoof MCU=SAMD11C14A SDCARD=SDCARD_DISABLED make all mostly_clean


mv -v *.bin ./binaries/

echo Done building bootloaders!


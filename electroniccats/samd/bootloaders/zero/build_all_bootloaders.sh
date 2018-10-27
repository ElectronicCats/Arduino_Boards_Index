#!/bin/bash -ex

BOARD_ID=sparkfun_9dof NAME=SparkFun_9DoF_Razor make clean all

BOARD_ID=arduino_zero NAME=samd21_sam_ba make clean all

BOARD_ID=genuino_zero NAME=samd21_sam_ba_genuino make clean all

BOARD_ID=arduino_mkr1000 NAME=samd21_sam_ba_arduino_mkr1000 make clean all
mv -v samd21_sam_ba_arduino_mkr1000.* ../mkr1000/

BOARD_ID=genuino_mkr1000 NAME=samd21_sam_ba_genuino_mkr1000 make clean all
mv -v samd21_sam_ba_genuino_mkr1000.* ../mkr1000/

echo Done building bootloaders!


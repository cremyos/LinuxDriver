# ------------------------------------------------------------------------------
# Makefile for the LDD-LinuxDeviceDrivers.
# Author: Lniper
# Date: 2017-02-18
# Aim: Init the module and exiting the module.
# ------------------------------------------------------------------------------


#Driver Description
DRIVER_VERSION := "0.0.1"
DRIVER_AUTHOR := "Lniper"
DRIVER_DESC := "Para Device module for LDD_LinuxDeviceDriver"
DRIVER_LICENSE := "GPL"

MODULE_NAME := smodule

KERNELDIR ?= /lib/modules/$(shell uname -r)/build

PWD := $(shell pwd)

obj-m := smodule.o


modules:
	make -C $(KERNELDIR) M=$(PWD) modules


clean:
	make -C $(KERNELDIR) M=$(PWD) clean
	rm -f modules.order Module.symvers Module.markers

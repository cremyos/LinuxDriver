# ------------------------------------------------------------------------------
# Makefile for the LDD-LinuxDeviceDrivers.
# Author: Lniper
# Date: 2017-02-18
# Aim: Init the module and exiting the module.
# ------------------------------------------------------------------------------

obj-m	:= Myworld.o
KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD	:= $(shell pwd)

modules:
	make -C $(KERNELDIR) M=$(PWD) modules_install

clean:
	rm -rf *.o *~ .depend *.mod.o *.mod.c *.ko *.symvers *.order

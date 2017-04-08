# ------------------------------------------------------------------------------
# Makefile for the LDD-LinuxDeviceDrivers.
# Author: Lniper
# Date: 2017-02-18
# Aim: Init the module and exiting the module.
# ------------------------------------------------------------------------------


#obj-m	:= Myworld.o
#KERNELDIR := /lib/modules/$(shell uname -r)/build
#PWD	:= $(shell pwd)

#modules:
#	make -C $(KERNELDIR) M=$(PWD) modules_install

#clean:
#	rm -rf .*.cmd *.o *.mod.c *.ko .tmp_versions



ifneq ($(KERNELRELEASE),)
obj-m := Myworld.o

else
PWD  := $(shell pwd)
KVER := $(shell uname -r)
KDIR := /lib/modules/$(KVER)/build
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -rf .*.cmd *.o *.mod.c *.ko .tmp_versions *.symvers *.order
endif

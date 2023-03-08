obj-m += seconds.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
wsl:
	make -C /root/WSL2-Linux-Kernel M=$(PWD) modules
wsl-clean:
	make -C /root/WSL2-Linux-Kernel M=$(PWD) clean
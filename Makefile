obj-m := bugg-ad400x.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

install:
	sudo cp bugg-ad400x.ko /lib/modules/$(shell uname -r)
	sudo depmod -a

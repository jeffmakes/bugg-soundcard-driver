obj-m := bugg-ad400x.o

all:
	for dir in /lib/modules/*; do \
		make -C $$dir/build M=$(PWD) modules; \
	done

clean:
	for dir in /lib/modules/*; do \
		make -C $$dir/build M=$(PWD) clean; \
	done

install:
	for dir in /lib/modules/*; do \
		sudo cp bugg-ad400x.ko $$dir; \
		echo $$dir; \
		sudo depmod -a `basename $$dir`; \
	done

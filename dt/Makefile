all: bugg-soundcard.dtbo

# Compile the device tree source into a device tree blob
bugg-soundcard.dtbo: bugg-soundcard.dts
	dtc -@ -I dts -O dtb -o $@ $<

# Install the compiled device tree overlay
install: bugg-soundcard.dtbo
	cp $< /boot/overlays/

# Clean up build artifacts
clean:
	rm -f bugg-soundcard.dtbo

.PHONY: all install clean

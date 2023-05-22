Need to enable each custom overlay in /boot/config.txt (see last line)

Compile the overlay dts into a dto like this:
 dtc -@ -I dts -O dtb -o bugg-pdm-soundcard.dtbo bugg-pdm-soundcard-overlay.dts


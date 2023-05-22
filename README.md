Need to enable each custom overlay in /boot/config.txt (see last line)

Compile the overlay dts into a dto like this:
 dtc -@ -I dts -O dtb -o bugg-pdm-soundcard.dtbo bugg-pdm-soundcard-overlay.dts

 TODO: rename the "ad400x" kernel module to, e.g., "bugg-soundcard" or "bugg-soundcard-external" or "bugg-microphone-external".
 It doesn't really make sense to mention the AD400x, since the kernel module isn't actually compatible with that chip, it's compatible with our whole soundcard circuit of which that chip is just a part. 

 Also see if we can incorporate the internal and external microphones into the same sound card DTO and kernel module. That would be elegant, and would probably simplify maintenance. 


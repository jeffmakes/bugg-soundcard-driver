// SPDX-License-Identifier: GPL-2.0-only
/*
 * Attempt to use the PCM peripheral to drive a Analog Devices AD400x ADC 
 * by configuring it to behave like a SPI bus master.
 * 
 * For the Bugg project: https://bugg.xyz
 *
 * - Adapted from the ics43432.c codec driver.
 * - Non configurable.
 * - I2S interface, 64 BCLs per frame, 32 bits per channel, 24 bit data
 *
 * Copyright (c) 2015 Axis Communications AB
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/soc.h>
#include <sound/initval.h>
#include <sound/tlv.h>

#define AD400X_RATE_MIN 7190 /* Hz, from data sheet */
#define AD400X_RATE_MAX 52800  /* Hz, from data sheet */

#define AD400X_FORMATS (SNDRV_PCM_FMTBIT_S24_LE | SNDRV_PCM_FMTBIT_S32)

static struct snd_soc_dai_driver ad400x_dai = {
	.name = "ad400x-hifi",
	.capture = {
		.stream_name = "Capture",
		.channels_min = 1,
		.channels_max = 2,
		.rate_min = AD400X_RATE_MIN,
		.rate_max = AD400X_RATE_MAX,
		.rates = SNDRV_PCM_RATE_CONTINUOUS,
		.formats = AD400X_FORMATS,
	},
};

static const struct snd_soc_component_driver ad400x_component_driver = {
	.idle_bias_on		= 1,
	.use_pmdown_time	= 1,
	.endianness		= 1,
	.non_legacy_dai_naming	= 1,
};

static int ad400x_probe(struct platform_device *pdev)
{
	return devm_snd_soc_register_component(&pdev->dev,
			&ad400x_component_driver,
			&ad400x_dai, 1);
}

#ifdef CONFIG_OF
static const struct of_device_id ad400x_ids[] = {
	{ .compatible = "invensense,ad400x", },
	{ }
};
MODULE_DEVICE_TABLE(of, ad400x_ids);
#endif

static struct platform_driver ad400x_driver = {
	.driver = {
		.name = "ad400x",
		.of_match_table = of_match_ptr(ad400x_ids),
	},
	.probe = ad400x_probe,
};

module_platform_driver(ad400x_driver);

MODULE_DESCRIPTION("ASoC AD400X driver");
MODULE_AUTHOR("Jeff Gough <j@monad.is>");
MODULE_LICENSE("GPL v2");

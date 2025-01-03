/* gpixel.c - 'great' pixel manipulation */
/* Copyright (c) 2024 Ian P. Jarvis */
/* Licensed under LGPL 2.1 */

#include "gpixel.h"

void gpixel_setrgb(struct gpixel_rgb* gpx_rgb, unsigned char red, unsigned char green, unsigned char blue, unsigned char max_value) {
	gpx_rgb->red = red;
	gpx_rgb->green = green;
	gpx_rgb->blue = blue;
	gpx_rgb->max_value = max_value;
}

unsigned char gpixel_getrgb_red(struct gpixel_rgb* gpx_rgb) {
	return gpx_rgb->red;
}

unsigned char gpixel_getrgb_green(struct gpixel_rgb* gpx_rgb) {
	return gpx_rgb->green;
}

unsigned char gpixel_getrgb_blue(struct gpixel_rgb* gpx_rgb) {
	return gpx_rgb->blue;
}

unsigned char gpixel_getrgb_max_value(struct gpixel_rgb* gpx_rgb) {
	return gpx_rgb->max_value;
}

void gpixel_setcmy(struct gpixel_cmy* gpx_cmy, unsigned char cyan, unsigned char magenta, unsigned char yellow, unsigned char max_value) {
	gpx_cmy->cyan = cyan;
	gpx_cmy->magenta = magenta;
	gpx_cmy->yellow = yellow;
	gpx_cmy->max_value = max_value;
}

unsigned char gpixel_getcmy_cyan(struct gpixel_cmy* gpx_cmy) {
	return gpx_cmy->cyan;
}

unsigned char gpixel_getcmy_magneta(struct gpixel_cmy* gpx_cmy) {
	return gpx_cmy->magenta;
}

unsigned char gpixel_getcmy_yellow(struct gpixel_cmy* gpx_cmy) {
	return gpx_cmy->yellow;
}

unsigned char gpixel_getcmy_max_value(struct gpixel_cmy* gpx_cmy) {
	return gpx_cmy->max_value;
}

void gpixel_setcmyk(struct gpixel_cmyk* gpx_cmyk, unsigned char cyan, unsigned char magenta, unsigned char yellow, unsigned char black, unsigned char max_value) {
	gpx_cmyk->cyan = cyan;
	gpx_cmyk->magenta = magenta;
	gpx_cmyk->yellow = yellow;
	gpx_cmyk->black = black;
	gpx_cmyk->max_value = max_value;
}

unsigned char gpixel_getcmyk_cyan(struct gpixel_cmyk* gpx_cmyk) {
	return gpixel_cmy->cyan;
}

unsigned char gpixel_getcmyk_magenta(struct gpixel_cmyk* gpx_cmyk) {
	return gpixel_cmy->magenta;
}

unsigned char gpixel_getcmyk_yellow(struct gpixel_cmyk* gpx_cmyk) {
	return gpixel_cmy->yellow;
}

unsigned char gpixel_getcmyk_black(struct gpixel_cmyk* gpx_cmyk) {
	return gpixel_cmy->black;
}

unsigned char gpixel_getcmyk_max_value(struct gpixel_cmyk* gpx_cmyk) {
	return gpixel_cmy->max_value;
}

void gpixel_scale_rgb(struct gpixel_rgb* gpx_rgb, unsigned char new_max_value) {
	unsigned char old_max_value = gpx_rgb->max_value;
	unsigned short hold_value = gpx_rgb->red;
	hold_value *= new_max_value;
	hold_value /= old_max_value;
	gpx_rgb->red = hold_value;
	hold_value = gpx_rgb->green;
	hold_value *= new_max_value;
	hold_value /= old_max_value;
	gpx_rgb->green = hold_value;
	hold_value = gpx_rgb->blue;
	hold_value *= new_max_value;
	hold_value /= old_max_value;
	gpx_rgb->blue = hold_value;
	gpx_rgb->max_value = new_max_value;
}

void gpixel_scale_cmy(struct gpixel_cmy* gpx_cmy, unsigned char new_max_value) {
	unsigned char old_max_value = gpx_cmy->max_value;
	unsigned short hold_value = gpx_cmy->cyan;
	hold_value *= new_max_value;
	hold_value /= old_max_value;
	gpx_cmy->cyan = hold_value;
	hold_value = gpx_cmy->magenta;
	hold_value *= new_max_value;
	hold_value /= old_max_value;
	gpx_cmy->magenta = hold_value;
	hold_value = gpx_cmy->yellow;
	hold_value *= new_max_value;
	hold_value /= old_max_value;
	gpx_cmy->yellow = hold_value;
	gpx_cmy->max_value = new_max_value;
}

void gpixel_scale_cmyk(struct gpixel_cmyk* gpx_cmyk, unsigned char new_max_value) {
	unsigned char old_max_value = gpx_cmyk->max_value;
	unsigned short hold_value = gpx_cmyk->cyan;
	hold_value *= new_max_value;
	hold_value /= old_max_value;
	gpx_cmyk->cyan = hold_value;
	hold_value = gpx_cmyk->magenta;
	hold_value *= new_max_value;
	hold_value /= old_max_value;
	gpx_cmyk->magenta = hold_value;
	hold_value = gpx_cmyk->yellow;
	hold_value *= new_max_value;
	hold_value /= old_max_value;
	gpx_cmyk->yellow = hold_value;
	hold_value = gpx_cmyk->black;
	hold_value *= new_max_value;
	hold_value /= old_max_value;
	gpx_cmyk->black = hold_value;
	gpx_cmyk->max_value = new_max_value;
}

void gpixel_transform_to_rgb(struct gpixel_rgb* gpx_rgb, struct gpixel_cmy* gpx_cmy) {
	unsigned char max_value = gpx_cmy->max_value;
	gpx_rgb->red = max_value - gpx_cmy->cyan;
	gpx_rgb->green = max_value - gpx_cmy->magenta;
	gpx_rgb->blue = max_value - gpx_cmy->yellow;
	gpx_rgb->max_value = max_value;
}

void gpixel_transform_to_rgb(struct gpixel_rgb* gpx_rgb, struct gpixel_cmyk* gpx_cmyk) {
	unsigned char max_value = gpx_cmk->max_value;
	unsigned char max_rgb = max_value - gpx_cmyk->black;
	gpx_rgb->red = max_rgb - ((max_rgb * gpx_cmyk->cyan) / max_value);
	gpx_rgb->green = max_rgb - ((max_rgb * gpx_cmyk->magenta) / max_value);
	gpx_rgb->blue = max_rgb - ((max_rgb * gpx_cmyk->yellow) / max_value);
	gpx_rgb->max_value = max_value;
}

void gpixel_transform_to_cmy(struct gpixel_cmy* gpx_cmy, struct gpixel_rgb* gpx_rgb) {
	unsigned char max_value = gpx_rgb->max_value;
	gpx_cmy->cyan = max_value - gpx_rgb->red;
	gpx_cmy->magenta = max_value - gpx_rgb->green;
	gpx_cmy->yellow = max_value - gpx_rgb->blue;
	gpx_cmy->max_value = max_value;
}

void gpixel_transform_to_cmy(struct gpixel_cmy* gpx_cmy, struct gpixel_cmyk* gpx_cmyk) {
	unsigned char max_value = gpx_cmyk->max_value;
	gpx_cmy->cyan = gpx_cmyk->cyan - max_value;
	gpx_cmy->magenta = gpx_cmyk->magenta - max_value;
	gpx_cmy->yellow = gpx_cmyk->yellow - max_value;
	gpx_cmy->max_value = max_value;
}

void gpixel_transform_to_cmyk(struct gpixel_cmyk* gpx_cmyk, struct gpixel_rgb* gpx_rgb) {
	unsigned char max_rgb = gpx_rgb->red;
	if(max_rgb < gpx_rgb->green)
		max_rgb = gpx_rgb->green;
	if(max_rgb < gpx_rgb->blue)
		max_rgb = gpx_rgb->blue;

	gpx_cmyk->black = gpx_rgb->max_value - max_rgb;
	if(max_rgb == 0) {
		gpx_cmyk->cyan = 0;
		gpx_cmyk->magenta = 0;
		gpx_cmyk->yellow = 0;
	}
	else {
		gpx_cmyk->cyan = (max_rgb - gpx_rgb->red) / max_rgb;
		gpx_cmyk->magenta = (max_rgb - gpx_rgb->green) / max_rgb;
		gpx_cmyk->yellow = (max_rgb - gpx_rgb->blue) / max_rgb;
	}
	gpx_cmyk->max_value = gpx_rgb->max_value;
}

void gpixel_transform_to_cmyk(struct gpixel_cmyk* gpx_cmyk, struct gpixel_cmy* gpx_cmy) {
	unsigned char min_cmy = gpx_cmy->cyan;
	if(min_cmy > gpx_cmy->magenta)
		min_cmy = gpx_cmy->magenta;
	if(min_cmy > gpx_cmy->yellow)
		min_cmy = gpx_cmy->yellow;

	gpx_cmyk->black = min_cmy;
	unsigned char gpx_cmyk_black = min_cmy;
	unsigned char max_value_minus_black = gpx_cmy->max_value - gpx_cmyk_black;
	if(max_value_minus_black == 0) {
		gpx_cmyk->cyan = 0;
		gpx_cmyk->magenta = 0;
		gpx_cmyk->yellow = 0;
	}
	else {
		gpx_cmyk->cyan = (gpx_cmy->cyan - gpx_cmyk_black) / max_value_minus_black;
		gpx_cmyk->magenta = (gpx_rgb->magenta - gpx_cmyk_black) / max_value_minus_black;
		gpx_cmyk->yellow = (gpx_rgb->yellow - gpx_cmyk_black) / max_value_minus_black;
	}
	gpx_cmyk->max_value = gpx_cmy->max_value;
}

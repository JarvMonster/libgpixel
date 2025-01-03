/* gpixel.h - 'great' pixel manipulation */
/* Copyright (c) 2024 Ian P. Jarvis */
/* Licensed under LGPL 2.1 */

#ifndef GPIXEL_H
#define GPIXEL_H /* GPIXEL_H */

struct gpixel_rgb {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char max_value;
};

struct gpixel_cmy {
	unsigned char cyan;
	unsigned char magenta;
	unsigned char yellow;
	unsigned char max_value;
};

struct gpixel_cmyk {
	unsigned char cyan;
	unsigned char magenta;
	unsigned char yellow;
	unsigned char black;
	unsigned char max_value;
};

void gpixel_setrgb(struct gpixel_rgb*, unsigned char, unsigned char, unsigned char, unsigned char);

unsigned char gpixel_getrgb_red(struct gpixel_rgb*);

unsigned char gpixel_getrgb_green(struct gpixel_rgb*);

unsigned char gpixel_getrgb_blue(struct gpixel_rgb*);

unsigned char gpixel_getrgb_max_value(struct gpixel_rgb*);

void gpixel_setcmy(struct gpixel_cmy*, unsigned char, unsigned char, unsigned char, unsigned char);

unsigned char gpixel_getcmy_cyan(struct gpixel_cmy*);

unsigned char gpixel_getcmy_magneta(struct gpixel_cmy*);

unsigned char gpixel_getcmy_yellow(struct gpixel_cmy*);

unsigned char gpixel_getcmy_max_value(struct gpixel_cmy*);

void gpixel_setcmyk(struct gpixel_cmyk*, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);

unsigned char gpixel_getcmyk_cyan(struct gpixel_cmyk*);

unsigned char gpixel_getcmyk_magenta(struct gpixel_cmyk*);

unsigned char gpixel_getcmyk_yellow(struct gpixel_cmyk*);

unsigned char gpixel_getcmyk_black(struct gpixel_cmyk*);

unsigned char gpixel_getcmyk_max_value(struct gpixel_cmyk*);

void gpixel_scale_rgb(struct gpixel_rgb*, unsigned char);

void gpixel_scale_cmy(struct gpixel_cmy*, unsigned char);

void gpixel_scale_cmyk(struct gpixel_cmyk*, unsigned char);

void gpixel_transform_to_rgb(struct gpixel_rgb*, struct gpixel_cmy*);

void gpixel_transform_to_rgb(struct gpixel_rgb*, struct gpixel_cmyk*);

void gpixel_transform_to_cmy(struct gpixel_cmy*, struct gpixel_rgb*);

void gpixel_transform_to_cmy(struct gpixel_cmy*, struct gpixel_cmyk*);

void gpixel_transform_to_cmyk(struct gpixel_cmyk*, struct gpixel_rgb*);

void gpixel_transform_to_cmyk(struct gpixel_cmyk*, struct gpixel_cmy*);

#endif /* GPIXEL_H */

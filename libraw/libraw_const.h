/* -*- C++ -*-
 * File: libraw_const.h
 * Copyright 2008-2018 LibRaw LLC (info@libraw.org)
 * Created: Sat Mar  8 , 2008
 * LibRaw error codes
LibRaw is free software; you can redistribute it and/or modify
it under the terms of the one of two licenses as you choose:

1. GNU LESSER GENERAL PUBLIC LICENSE version 2.1
   (See file LICENSE.LGPL provided in LibRaw distribution archive for details).

2. COMMON DEVELOPMENT AND DISTRIBUTION LICENSE (CDDL) Version 1.0
   (See file LICENSE.CDDL provided in LibRaw distribution archive for details).

 */

#ifndef _LIBRAW_ERRORS_H
#define _LIBRAW_ERRORS_H

#define LIBRAW_DEFAULT_ADJUST_MAXIMUM_THRESHOLD 0.75
#define LIBRAW_DEFAULT_AUTO_BRIGHTNESS_THRESHOLD 0.01
/* limit allocation size, default is 2Gb */
#define LIBRAW_MAX_ALLOC_MB_DEFAULT 2048L

/* Check if enough file space exists before tag read */
#ifndef LIBRAW_NO_IOSPACE_CHECK
#define LIBRAW_IOSPACE_CHECK
#endif
/* LibRaw uses own memory pool management, with LIBRAW_MSIZE (512)
entries. It is enough for parsing/decoding non-damaged files, but
may overflow on specially crafted files (eg. with many string values
like XMP blocks.
LIBRAW_MEMPOOL_CHECK define will result in error on pool overflow */
#ifndef LIBRAW_NO_MEMPOOL_CHECK
#define LIBRAW_MEMPOOL_CHECK
#endif

#define LIBRAW_IFD_MAXCOUNT 10

enum LibRaw_openbayer_patterns
{
  LIBRAW_OPENBAYER_RGGB = 0x94,
  LIBRAW_OPENBAYER_BGGR = 0x16,
  LIBRAW_OPENBAYER_GRBG = 0x61,
  LIBRAW_OPENBAYER_GBRG = 0x49
};

enum LibRaw_dngfields_marks
{
  LIBRAW_DNGFM_FORWARDMATRIX = 1,
  LIBRAW_DNGFM_ILLUMINANT = 1<<1,
  LIBRAW_DNGFM_COLORMATRIX = 1<<2,
  LIBRAW_DNGFM_CALIBRATION = 1<<3,
  LIBRAW_DNGFM_ANALOGBALANCE = 1<<4,
  LIBRAW_DNGFM_BLACK = 1<<5,
  LIBRAW_DNGFM_WHITE = 1<<6,
  LIBRAW_DNGFM_OPCODE2 = 1<<7,
  LIBRAW_DNGFM_LINTABLE = 1<<8,
  LIBRAW_DNGFM_CROPORIGIN = 1<<9,
  LIBRAW_DNGFM_CROPSIZE = 1<<10,
  LIBRAW_DNGFM_PREVIEWCS = 1<<11,
  LIBRAW_DNGFM_ASSHOTNEUTRAL = 1<<12,
  LIBRAW_DNGFM_BASELINEEXPOSURE = 1<<13,
  LIBRAW_DNGFM_LINEARRESPONSELIMIT = 1<<14
};

enum LibRaw_As_Shot_WB_Applied_codes
{
  LIBRAW_ASWB_APPLIED = 1,
  LIBRAW_ASWB_CANON = 2,
  LIBRAW_ASWB_NIKON = 4,
  LIBRAW_ASWB_NIKON_SRAW = 8,
  LIBRAW_ASWB_PENTAX = 16
};

enum LibRaw_whitebalance_code
{
  /*
      EXIF light sources
      12 = FL-D; Daylight fluorescent (D 5700K – 7100K) (F1,F5)
      13 = FL-N; Day white fluorescent (N 4600K – 5400K) (F7,F8)
      14 = FL-W; Cool white fluorescent (W 3900K – 4500K) (F2,F6, office, store, warehouse)
      15 = FL-WW; White fluorescent (WW 3200K – 3700K) (F3, residential)
      16 = FL-L; Soft/Warm white fluorescent (L 2600K - 3250K) (F4, kitchen, bath)
  */
  LIBRAW_WBI_Unknown = 0,
  LIBRAW_WBI_Daylight = 1,
  LIBRAW_WBI_Fluorescent = 2,
  LIBRAW_WBI_Tungsten = 3,
  LIBRAW_WBI_Flash = 4,
  LIBRAW_WBI_FineWeather = 9,
  LIBRAW_WBI_Cloudy = 10,
  LIBRAW_WBI_Shade = 11,
  LIBRAW_WBI_FL_D = 12,
  LIBRAW_WBI_FL_N = 13,
  LIBRAW_WBI_FL_W = 14,
  LIBRAW_WBI_FL_WW = 15,
  LIBRAW_WBI_FL_L = 16,
  LIBRAW_WBI_Ill_A = 17,
  LIBRAW_WBI_Ill_B = 18,
  LIBRAW_WBI_Ill_C = 19,
  LIBRAW_WBI_D55 = 20,
  LIBRAW_WBI_D65 = 21,
  LIBRAW_WBI_D75 = 22,
  LIBRAW_WBI_D50 = 23,
  LIBRAW_WBI_StudioTungsten = 24,
  LIBRAW_WBI_Sunset = 64,
  LIBRAW_WBI_HT_Mercury = 67,
  LIBRAW_WBI_Auto = 82,
  LIBRAW_WBI_Custom = 83,
  LIBRAW_WBI_Auto1 = 85,
  LIBRAW_WBI_Auto2 = 86,
  LIBRAW_WBI_Auto3 = 87,
  LIBRAW_WBI_Auto4 = 88,
  LIBRAW_WBI_Custom1 = 90,
  LIBRAW_WBI_Custom2 = 91,
  LIBRAW_WBI_Custom3 = 93,
  LIBRAW_WBI_Custom4 = 93,
  LIBRAW_WBI_Custom5 = 94,
  LIBRAW_WBI_Custom6 = 95,
  LIBRAW_WBI_Measured = 100,
  LIBRAW_WBI_Underwater = 120,
  LIBRAW_WBI_Other = 255
};

enum LibRaw_MultiExposure_related
{
  LIBRAW_ME_NONE = 0,
  LIBRAW_ME_SIMPLE = 1,
  LIBRAW_ME_OVERLAY = 2,
  LIBRAW_ME_HDR = 3
};

enum LibRaw_dng_processing
{
  LIBRAW_DNG_NONE = 0,
  LIBRAW_DNG_FLOAT = 1,
  LIBRAW_DNG_LINEAR = 2,
  LIBRAW_DNG_DEFLATE = 4,
  LIBRAW_DNG_XTRANS = 8,
  LIBRAW_DNG_OTHER = 16,
  LIBRAW_DNG_8BIT = 32,
  /*LIBRAW_DNG_LARGERANGE=64,*/ /* more than 16 bit integer */
  LIBRAW_DNG_ALL = LIBRAW_DNG_FLOAT | LIBRAW_DNG_LINEAR | LIBRAW_DNG_XTRANS | LIBRAW_DNG_8BIT |
                   LIBRAW_DNG_OTHER /* |LIBRAW_DNG_LARGERANGE */,
  LIBRAW_DNG_DEFAULT = LIBRAW_DNG_FLOAT | LIBRAW_DNG_LINEAR | LIBRAW_DNG_DEFLATE | LIBRAW_DNG_8BIT
};

enum LibRaw_runtime_capabilities
{
  LIBRAW_CAPS_RAWSPEED = 1,
  LIBRAW_CAPS_DNGSDK = 2
};

enum LibRaw_camera_mounts
{
  LIBRAW_MOUNT_Unknown = 0,
  LIBRAW_MOUNT_Minolta_A = 1,
  LIBRAW_MOUNT_Sony_E = 2,
  LIBRAW_MOUNT_Canon_EF = 3,
  LIBRAW_MOUNT_Canon_EF_S = 4,
  LIBRAW_MOUNT_Canon_EF_M = 5,
  LIBRAW_MOUNT_Nikon_F = 6,
  LIBRAW_MOUNT_Nikon_CX = 7, /* used in Nikon 1 series */
  LIBRAW_MOUNT_FT = 8,       /* original 4/3 */
  LIBRAW_MOUNT_mFT = 9,      /* micro 4/3 */
  LIBRAW_MOUNT_Pentax_K = 10,
  LIBRAW_MOUNT_Pentax_Q = 11,
  LIBRAW_MOUNT_Pentax_645 = 12,
  LIBRAW_MOUNT_Fuji_X = 13,
  LIBRAW_MOUNT_Leica_M = 14,
  LIBRAW_MOUNT_Leica_R = 15,
  LIBRAW_MOUNT_Leica_S = 16,
  LIBRAW_MOUNT_Samsung_NX = 17,
  LIBRAW_MOUNT_RicohModule = 18,
  LIBRAW_MOUNT_Samsung_NX_M = 19,
  LIBRAW_MOUNT_Leica_L = 20, /* camera mount, takes SL and TL lenses */
  LIBRAW_MOUNT_Contax_N = 21,
  LIBRAW_MOUNT_Sigma_X3F = 22,
  LIBRAW_MOUNT_Leica_TL = 23,
  LIBRAW_MOUNT_Leica_SL = 24,
  LIBRAW_MOUNT_Nikon_Z = 25,
  LIBRAW_MOUNT_FixedLens = 99
};

enum LibRaw_camera_formats
{
  LIBRAW_FORMAT_APSC = 1,
  LIBRAW_FORMAT_FF = 2,
  LIBRAW_FORMAT_MF = 3,
  LIBRAW_FORMAT_APSH = 4,
  LIBRAW_FORMAT_1INCH = 5,
  LIBRAW_FORMAT_1div2p3INCH = 6,
  LIBRAW_FORMAT_FT = 8,
  LIBRAW_FORMAT_Leica_DMR = 15
};

enum LibRaw_lens_focal_types
{
  LIBRAW_FT_UNDEFINED = 0,
  LIBRAW_FT_FIXED = 1,
  LIBRAW_FT_ZOOM = 2
};

enum LibRaw_sony_cameratypes
{
  LIBRAW_SONY_DSC = 1,
  LIBRAW_SONY_DSLR = 2,
  LIBRAW_SONY_NEX = 3,
  LIBRAW_SONY_SLT = 4,
  LIBRAW_SONY_ILCE = 5,
  LIBRAW_SONY_ILCA = 6
};

enum LibRaw_processing_options
{
  LIBRAW_PROCESSING_SONYARW2_NONE = 0,
  LIBRAW_PROCESSING_SONYARW2_BASEONLY = 1,
  LIBRAW_PROCESSING_SONYARW2_DELTAONLY = 1 << 1,
  LIBRAW_PROCESSING_SONYARW2_DELTAZEROBASE = 1 << 2,
  LIBRAW_PROCESSING_SONYARW2_DELTATOVALUE = 1 << 3,
  LIBRAW_PROCESSING_SONYARW2_ALLFLAGS = LIBRAW_PROCESSING_SONYARW2_BASEONLY + LIBRAW_PROCESSING_SONYARW2_DELTAONLY +
                                        LIBRAW_PROCESSING_SONYARW2_DELTAZEROBASE +
                                        LIBRAW_PROCESSING_SONYARW2_DELTATOVALUE,
  LIBRAW_PROCESSING_DP2Q_INTERPOLATERG = 1 << 4,
  LIBRAW_PROCESSING_DP2Q_INTERPOLATEAF = 1 << 5,
  LIBRAW_PROCESSING_PENTAX_PS_ALLFRAMES = 1 << 6,
  LIBRAW_PROCESSING_CONVERTFLOAT_TO_INT = 1 << 7,
  LIBRAW_PROCESSING_SRAW_NO_RGB = 1 << 8,
  LIBRAW_PROCESSING_SRAW_NO_INTERPOLATE = 1 << 9,
  LIBRAW_PROCESSING_NO_ROTATE_FOR_KODAK_THUMBNAILS = 1 << 11,
  LIBRAW_PROCESSING_USE_DNG_DEFAULT_CROP = 1 << 12,
  LIBRAW_PROCESSING_USE_PPM16_THUMBS = 1 << 13,
  LIBRAW_PROCESSING_SKIP_MAKERNOTES = 1 << 14,
  LIBRAW_PROCESSING_CHECK_DNG_ILLUMINANT = 1 << 15,
  LIBRAW_PROCESSING_DNGSDK_ZEROCOPY = 1 << 16
};

enum LibRaw_decoder_flags
{
  LIBRAW_DECODER_HASCURVE = 1 << 4,
  LIBRAW_DECODER_SONYARW2 = 1 << 5,
  LIBRAW_DECODER_TRYRAWSPEED = 1 << 6,
  LIBRAW_DECODER_OWNALLOC = 1 << 7,
  LIBRAW_DECODER_FIXEDMAXC = 1 << 8,
  LIBRAW_DECODER_ADOBECOPYPIXEL = 1 << 9,
  LIBRAW_DECODER_LEGACY_WITH_MARGINS = 1 << 10,
  LIBRAW_DECODER_3CHANNEL = 1 << 11,
  LIBRAW_DECODER_SINAR4SHOT = 1 << 11,
  LIBRAW_DECODER_NOTSET = 1 << 15
};

#define LIBRAW_XTRANS 9

enum LibRaw_constructor_flags
{
  LIBRAW_OPTIONS_NONE = 0,
  LIBRAW_OPIONS_NO_MEMERR_CALLBACK = 1,
  LIBRAW_OPIONS_NO_DATAERR_CALLBACK = 1 << 1
};

enum LibRaw_warnings
{
  LIBRAW_WARN_NONE = 0,
  LIBRAW_WARN_BAD_CAMERA_WB = 1 << 2,
  LIBRAW_WARN_NO_METADATA = 1 << 3,
  LIBRAW_WARN_NO_JPEGLIB = 1 << 4,
  LIBRAW_WARN_NO_EMBEDDED_PROFILE = 1 << 5,
  LIBRAW_WARN_NO_INPUT_PROFILE = 1 << 6,
  LIBRAW_WARN_BAD_OUTPUT_PROFILE = 1 << 7,
  LIBRAW_WARN_NO_BADPIXELMAP = 1 << 8,
  LIBRAW_WARN_BAD_DARKFRAME_FILE = 1 << 9,
  LIBRAW_WARN_BAD_DARKFRAME_DIM = 1 << 10,
  LIBRAW_WARN_NO_JASPER = 1 << 11,
  LIBRAW_WARN_RAWSPEED_PROBLEM = 1 << 12,
  LIBRAW_WARN_RAWSPEED_UNSUPPORTED = 1 << 13,
  LIBRAW_WARN_RAWSPEED_PROCESSED = 1 << 14,
  LIBRAW_WARN_FALLBACK_TO_AHD = 1 << 15,
  LIBRAW_WARN_PARSEFUJI_PROCESSED = 1 << 16
};

enum LibRaw_exceptions
{
  LIBRAW_EXCEPTION_NONE = 0,
  LIBRAW_EXCEPTION_ALLOC = 1,
  LIBRAW_EXCEPTION_DECODE_RAW = 2,
  LIBRAW_EXCEPTION_DECODE_JPEG = 3,
  LIBRAW_EXCEPTION_IO_EOF = 4,
  LIBRAW_EXCEPTION_IO_CORRUPT = 5,
  LIBRAW_EXCEPTION_CANCELLED_BY_CALLBACK = 6,
  LIBRAW_EXCEPTION_BAD_CROP = 7,
  LIBRAW_EXCEPTION_IO_BADFILE = 8,
  LIBRAW_EXCEPTION_DECODE_JPEG2000 = 9,
  LIBRAW_EXCEPTION_TOOBIG = 10,
  LIBRAW_EXCEPTION_MEMPOOL = 11
};

enum LibRaw_progress
{
  LIBRAW_PROGRESS_START = 0,
  LIBRAW_PROGRESS_OPEN = 1,
  LIBRAW_PROGRESS_IDENTIFY = 1 << 1,
  LIBRAW_PROGRESS_SIZE_ADJUST = 1 << 2,
  LIBRAW_PROGRESS_LOAD_RAW = 1 << 3,
  LIBRAW_PROGRESS_RAW2_IMAGE = 1 << 4,
  LIBRAW_PROGRESS_REMOVE_ZEROES = 1 << 5,
  LIBRAW_PROGRESS_BAD_PIXELS = 1 << 6,
  LIBRAW_PROGRESS_DARK_FRAME = 1 << 7,
  LIBRAW_PROGRESS_FOVEON_INTERPOLATE = 1 << 8,
  LIBRAW_PROGRESS_SCALE_COLORS = 1 << 9,
  LIBRAW_PROGRESS_PRE_INTERPOLATE = 1 << 10,
  LIBRAW_PROGRESS_INTERPOLATE = 1 << 11,
  LIBRAW_PROGRESS_MIX_GREEN = 1 << 12,
  LIBRAW_PROGRESS_MEDIAN_FILTER = 1 << 13,
  LIBRAW_PROGRESS_HIGHLIGHTS = 1 << 14,
  LIBRAW_PROGRESS_FUJI_ROTATE = 1 << 15,
  LIBRAW_PROGRESS_FLIP = 1 << 16,
  LIBRAW_PROGRESS_APPLY_PROFILE = 1 << 17,
  LIBRAW_PROGRESS_CONVERT_RGB = 1 << 18,
  LIBRAW_PROGRESS_STRETCH = 1 << 19,
  /* reserved */
  LIBRAW_PROGRESS_STAGE20 = 1 << 20,
  LIBRAW_PROGRESS_STAGE21 = 1 << 21,
  LIBRAW_PROGRESS_STAGE22 = 1 << 22,
  LIBRAW_PROGRESS_STAGE23 = 1 << 23,
  LIBRAW_PROGRESS_STAGE24 = 1 << 24,
  LIBRAW_PROGRESS_STAGE25 = 1 << 25,
  LIBRAW_PROGRESS_STAGE26 = 1 << 26,
  LIBRAW_PROGRESS_STAGE27 = 1 << 27,

  LIBRAW_PROGRESS_THUMB_LOAD = 1 << 28,
  LIBRAW_PROGRESS_TRESERVED1 = 1 << 29,
  LIBRAW_PROGRESS_TRESERVED2 = 1 << 30,
  LIBRAW_PROGRESS_TRESERVED3 = 1 << 31
};
#define LIBRAW_PROGRESS_THUMB_MASK 0x0fffffff

enum LibRaw_errors
{
  LIBRAW_SUCCESS = 0,
  LIBRAW_UNSPECIFIED_ERROR = -1,
  LIBRAW_FILE_UNSUPPORTED = -2,
  LIBRAW_REQUEST_FOR_NONEXISTENT_IMAGE = -3,
  LIBRAW_OUT_OF_ORDER_CALL = -4,
  LIBRAW_NO_THUMBNAIL = -5,
  LIBRAW_UNSUPPORTED_THUMBNAIL = -6,
  LIBRAW_INPUT_CLOSED = -7,
  LIBRAW_NOT_IMPLEMENTED = -8,
  LIBRAW_UNSUFFICIENT_MEMORY = -100007,
  LIBRAW_DATA_ERROR = -100008,
  LIBRAW_IO_ERROR = -100009,
  LIBRAW_CANCELLED_BY_CALLBACK = -100010,
  LIBRAW_BAD_CROP = -100011,
  LIBRAW_TOO_BIG = -100012,
  LIBRAW_MEMPOOL_OVERFLOW = -100013
};

#define LIBRAW_FATAL_ERROR(ec) ((ec) < -100000)

enum LibRaw_thumbnail_formats
{
  LIBRAW_THUMBNAIL_UNKNOWN = 0,
  LIBRAW_THUMBNAIL_JPEG = 1,
  LIBRAW_THUMBNAIL_BITMAP = 2,
  LIBRAW_THUMBNAIL_BITMAP16 = 3,
  LIBRAW_THUMBNAIL_LAYER = 4,
  LIBRAW_THUMBNAIL_ROLLEI = 5
};

enum LibRaw_image_formats
{
  LIBRAW_IMAGE_JPEG = 1,
  LIBRAW_IMAGE_BITMAP = 2
};

#endif

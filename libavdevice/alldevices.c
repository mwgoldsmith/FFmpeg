/*
 * Register all the grabbing devices.
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "config.h"
#include "avdevice.h"

#define REGISTER_OUTDEV(X, x)                                           \
    {                                                                   \
        extern AVOutputFormat ff_##x##_muxer;                           \
        if (CONFIG_##X##_OUTDEV)                                        \
            av_register_output_format(&ff_##x##_muxer);                 \
    }

#define REGISTER_INDEV(X, x)                                            \
    {                                                                   \
        extern AVInputFormat ff_##x##_demuxer;                          \
        if (CONFIG_##X##_INDEV)                                         \
            av_register_input_format(&ff_##x##_demuxer);                \
    }

#define REGISTER_INOUTDEV(X, x) REGISTER_OUTDEV(X, x); REGISTER_INDEV(X, x)

void avdevice_register_all(void)
{
    static int initialized;

    if (initialized)
        return;
    initialized = 1;

    /* devices */
#if CONFIG_ALSA_INDEV
    REGISTER_INDEV(ALSA, alsa)
#endif
#if CONFIG_ALSA_OUTDEV
      REGISTER_OUTDEV(ALSA, alsa)
#endif
#if CONFIG_AVFOUNDATION_INDEV
      REGISTER_INDEV(AVFOUNDATION, avfoundation)
#endif
#if CONFIG_BKTR_INDEV
      REGISTER_INDEV(BKTR, bktr)
#endif
#if CONFIG_CACA_OUTDEV
      REGISTER_OUTDEV(CACA, caca)
#endif
#if CONFIG_DECKLINK_INDEV
      REGISTER_INDEV(DECKLINK, decklink)
#endif
#if CONFIG_DECKLINK_OUTDEV
      REGISTER_OUTDEV(DECKLINK, decklink)
#endif
#if CONFIG_DSHOW_INDEV
      REGISTER_INDEV(DSHOW, dshow)
#endif
#if CONFIG_DV1394_INDEV
      REGISTER_INDEV(DV1394, dv1394)
#endif
#if CONFIG_FBDEV_INDEV
      REGISTER_INDEV(FBDEV, fbdev)
#endif
#if CONFIG_FBDEV_OUTDEV
      REGISTER_OUTDEV(FBDEV, fbdev)
#endif
#if CONFIG_GDIGRAB_INDEV
      REGISTER_INDEV(GDIGRAB, gdigrab)
#endif
#if CONFIG_IEC61883_INDEV
      REGISTER_INDEV(IEC61883, iec61883)
#endif
#if CONFIG_JACK_INDEV
      REGISTER_INDEV(JACK, jack)
#endif
#if CONFIG_LAVFI_INDEV
      REGISTER_INDEV(LAVFI, lavfi)
#endif
#if CONFIG_OPENAL_INDEV
      REGISTER_INDEV(OPENAL, openal)
#endif
#if CONFIG_OPENGL_OUTDEV
      REGISTER_OUTDEV(OPENGL, opengl)
#endif
#if CONFIG_OSS_INDEV
      REGISTER_INDEV(OSS, oss)
#endif
#if CONFIG_OSS_OUTDEV
      REGISTER_OUTDEV(OSS, oss)
#endif
#if CONFIG_PULSE_INDEV
      REGISTER_INDEV(PULSE, pulse)
#endif
#if CONFIG_PULSE_OUTDEV
      REGISTER_OUTDEV(PULSE, pulse)
#endif
#if CONFIG_QTKIT_INDEV
      REGISTER_INDEV(QTKIT, qtkit)
#endif
#if CONFIG_SDL_OUTDEV
      REGISTER_OUTDEV(SDL, sdl)
#endif
#if CONFIG_SNDIO_INDEV
      REGISTER_INDEV(SNDIO, sndio)
#endif
#if CONFIG_SNDIO_OUTDEV
      REGISTER_OUTDEV(SNDIO, sndio)
#endif
#if CONFIG_V4L2_INDEV
      REGISTER_INDEV(V4L2, v4l2)
#endif
#if CONFIG_V4L2_OUTDEV
      REGISTER_OUTDEV(V4L2, v4l2)
#endif
      //    REGISTER_INDEV   (V4L,              v4l
#if CONFIG_VFWCAP_INDEV
      REGISTER_INDEV(VFWCAP, vfwcap)
#endif
#if CONFIG_X11GRAB_INDEV
      REGISTER_INDEV(X11GRAB, x11grab)
#endif
#if CONFIG_X11GRAB_XCB_INDEV
      REGISTER_INDEV(X11GRAB_XCB, x11grab_xcb)
#endif
#if CONFIG_XV_OUTDEV
      REGISTER_OUTDEV(XV, xv)
#endif

      /* external libraries */
#if CONFIG_LIBCDIO_INDEV
      REGISTER_INDEV(LIBCDIO, libcdio)
#endif
#if CONFIG_LIBDC1394_INDEV
      REGISTER_INDEV(LIBDC1394, libdc1394)
#endif

}

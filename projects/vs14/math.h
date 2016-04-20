/*
 * Correctly include the correct math.h header based on which native
 * Windows compiler is in use.
 * Copyright (c) 2015 Matthew Oliver
 *
 * This file is part of Shift Media Project.
 *
 * Shift Media Project is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Shift Media Project is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with the code; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef _SMP_MATH_H
#define _SMP_MATH_H

#ifdef __INTEL_COMPILER
    // Use the Intel Math library. This provides Intel processor optimized functions.
    //  This also avoids an error with the msvc math.h definition of NAN found in msvc12.
#   include <mathimf.h>
    // The Intel header automatically includes defines used with complex.h
    //  that interfere with normal code and need to be removed.
#   undef I
#   undef complex
#elif defined(_MSC_VER)
#   include <crtversion.h>
#   ifndef _USE_MATH_DEFINES
#       define _USE_MATH_DEFINES
#   endif
#   if _VC_CRT_MAJOR_VERSION >= 14
#       include <../ucrt/math.h>
#   else
#       include <../include/math.h>
#   endif
#else
#   include_next <math.h>
#endif

#endif /* _SMP_MATH_H */

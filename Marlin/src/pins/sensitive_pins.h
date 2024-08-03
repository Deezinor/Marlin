/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

<<<<<<< HEAD
#include <stdint.h>
=======
//
// Prepare a list of protected pins for M42/M43
//

#if PIN_EXISTS(X_MIN)
  #define _X_MIN X_MIN_PIN,
#else
  #define _X_MIN
#endif
#if PIN_EXISTS(X_MAX)
  #define _X_MAX X_MAX_PIN,
#else
  #define _X_MAX
#endif
#if PIN_EXISTS(X_CS) && AXIS_HAS_SPI(X)
  #define _X_CS X_CS_PIN,
#else
  #define _X_CS
#endif
#if PIN_EXISTS(X_MS1)
  #define _X_MS1 X_MS1_PIN,
#else
  #define _X_MS1
#endif
#if PIN_EXISTS(X_MS2)
  #define _X_MS2 X_MS2_PIN,
#else
  #define _X_MS2
#endif
#if PIN_EXISTS(X_MS3)
  #define _X_MS3 X_MS3_PIN,
#else
  #define _X_MS3
#endif
#if PIN_EXISTS(X_ENABLE)
  #define _X_ENABLE_PIN X_ENABLE_PIN,
#else
  #define _X_ENABLE_PIN
#endif

#define _X_PINS X_STEP_PIN, X_DIR_PIN, _X_ENABLE_PIN _X_MIN _X_MAX _X_MS1 _X_MS2 _X_MS3 _X_CS

#if HAS_Y_AXIS

  #if PIN_EXISTS(Y_MIN)
    #define _Y_MIN Y_MIN_PIN,
  #else
    #define _Y_MIN
  #endif
  #if PIN_EXISTS(Y_MAX)
    #define _Y_MAX Y_MAX_PIN,
  #else
    #define _Y_MAX
  #endif
  #if PIN_EXISTS(Y_CS) && AXIS_HAS_SPI(Y)
    #define _Y_CS Y_CS_PIN,
  #else
    #define _Y_CS
  #endif
  #if PIN_EXISTS(Y_MS1)
    #define _Y_MS1 Y_MS1_PIN,
  #else
    #define _Y_MS1
  #endif
  #if PIN_EXISTS(Y_MS2)
    #define _Y_MS2 Y_MS2_PIN,
  #else
    #define _Y_MS2
  #endif
  #if PIN_EXISTS(Y_MS3)
    #define _Y_MS3 Y_MS3_PIN,
  #else
    #define _Y_MS3
  #endif
  #if PIN_EXISTS(Y_ENABLE)
    #define _Y_ENABLE_PIN Y_ENABLE_PIN,
  #else
    #define _Y_ENABLE_PIN
  #endif

  #define _Y_PINS Y_STEP_PIN, Y_DIR_PIN, _Y_ENABLE_PIN _Y_MIN _Y_MAX _Y_MS1 _Y_MS2 _Y_MS3 _Y_CS

#else

  #define _Y_PINS

#endif

#if HAS_Z_AXIS

  #if PIN_EXISTS(Z_MIN)
    #define _Z_MIN Z_MIN_PIN,
  #else
    #define _Z_MIN
  #endif
  #if PIN_EXISTS(Z_MAX)
    #define _Z_MAX Z_MAX_PIN,
  #else
    #define _Z_MAX
  #endif
  #if PIN_EXISTS(Z_CS) && AXIS_HAS_SPI(Z)
    #define _Z_CS Z_CS_PIN,
  #else
    #define _Z_CS
  #endif
  #if PIN_EXISTS(Z_MS1)
    #define _Z_MS1 Z_MS1_PIN,
  #else
    #define _Z_MS1
  #endif
  #if PIN_EXISTS(Z_MS2)
    #define _Z_MS2 Z_MS2_PIN,
  #else
    #define _Z_MS2
  #endif
  #if PIN_EXISTS(Z_MS3)
    #define _Z_MS3 Z_MS3_PIN,
  #else
    #define _Z_MS3
  #endif
  #if PIN_EXISTS(Z_ENABLE)
    #define _Z_ENABLE_PIN Z_ENABLE_PIN,
  #else
    #define _Z_ENABLE_PIN
  #endif

  #define _Z_PINS Z_STEP_PIN, Z_DIR_PIN, _Z_ENABLE_PIN _Z_MIN _Z_MAX _Z_MS1 _Z_MS2 _Z_MS3 _Z_CS

#else

  #define _Z_PINS

#endif

#if HAS_I_AXIS

  #if PIN_EXISTS(I_MIN)
    #define _I_MIN I_MIN_PIN,
  #else
    #define _I_MIN
  #endif
  #if PIN_EXISTS(I_MAX)
    #define _I_MAX I_MAX_PIN,
  #else
    #define _I_MAX
  #endif
  #if PIN_EXISTS(I_CS) && AXIS_HAS_SPI(I)
    #define _I_CS I_CS_PIN,
  #else
    #define _I_CS
  #endif
  #if PIN_EXISTS(I_MS1)
    #define _I_MS1 I_MS1_PIN,
  #else
    #define _I_MS1
  #endif
  #if PIN_EXISTS(I_MS2)
    #define _I_MS2 I_MS2_PIN,
  #else
    #define _I_MS2
  #endif
  #if PIN_EXISTS(I_MS3)
    #define _I_MS3 I_MS3_PIN,
  #else
    #define _I_MS3
  #endif
  #if PIN_EXISTS(I_ENABLE)
    #define _I_ENABLE_PIN I_ENABLE_PIN,
  #else
    #define _I_ENABLE_PIN
  #endif

  #define _I_PINS I_STEP_PIN, I_DIR_PIN, _I_ENABLE_PIN _I_MIN _I_MAX _I_MS1 _I_MS2 _I_MS3 _I_CS

#else

  #define _I_PINS

#endif

#if HAS_J_AXIS

  #if PIN_EXISTS(J_MIN)
    #define _J_MIN J_MIN_PIN,
  #else
    #define _J_MIN
  #endif
  #if PIN_EXISTS(J_MAX)
    #define _J_MAX J_MAX_PIN,
  #else
    #define _J_MAX
  #endif
  #if PIN_EXISTS(J_CS) && AXIS_HAS_SPI(J)
    #define _J_CS J_CS_PIN,
  #else
    #define _J_CS
  #endif
  #if PIN_EXISTS(J_MS1)
    #define _J_MS1 J_MS1_PIN,
  #else
    #define _J_MS1
  #endif
  #if PIN_EXISTS(J_MS2)
    #define _J_MS2 J_MS2_PIN,
  #else
    #define _J_MS2
  #endif
  #if PIN_EXISTS(J_MS3)
    #define _J_MS3 J_MS3_PIN,
  #else
    #define _J_MS3
  #endif
  #if PIN_EXISTS(J_ENABLE)
    #define _J_ENABLE_PIN J_ENABLE_PIN,
  #else
    #define _J_ENABLE_PIN
  #endif

  #define _J_PINS J_STEP_PIN, J_DIR_PIN, _J_ENABLE_PIN _J_MIN _J_MAX _J_MS1 _J_MS2 _J_MS3 _J_CS

#else

  #define _J_PINS

#endif

#if HAS_K_AXIS

  #if PIN_EXISTS(K_MIN)
    #define _K_MIN K_MIN_PIN,
  #else
    #define _K_MIN
  #endif
  #if PIN_EXISTS(K_MAX)
    #define _K_MAX K_MAX_PIN,
  #else
    #define _K_MAX
  #endif
  #if PIN_EXISTS(K_CS) && AXIS_HAS_SPI(K)
    #define _K_CS K_CS_PIN,
  #else
    #define _K_CS
  #endif
  #if PIN_EXISTS(K_MS1)
    #define _K_MS1 K_MS1_PIN,
  #else
    #define _K_MS1
  #endif
  #if PIN_EXISTS(K_MS2)
    #define _K_MS2 K_MS2_PIN,
  #else
    #define _K_MS2
  #endif
  #if PIN_EXISTS(K_MS3)
    #define _K_MS3 K_MS3_PIN,
  #else
    #define _K_MS3
  #endif
  #if PIN_EXISTS(K_ENABLE)
    #define _K_ENABLE_PIN K_ENABLE_PIN,
  #else
    #define _K_ENABLE_PIN
  #endif

  #define _K_PINS K_STEP_PIN, K_DIR_PIN, _K_ENABLE_PIN _K_MIN _K_MAX _K_MS1 _K_MS2 _K_MS3 _K_CS

#else

  #define _K_PINS

#endif
>>>>>>> upstream/bugfix-2.0.x

//
// Define unsorted and arrays of pins which may have duplicstes,
// but don't allocate any runtime memory for these arrays.
// We'll use constexpr functions to get the Nth distinct value,
// and return -1 if we go past the end of the array.
//
constexpr pin_t sensitive_dio[] PROGMEM = {

<<<<<<< HEAD
  #if HAS_X_AXIS
    #if PIN_EXISTS(X_MIN)
      X_MIN_PIN,
    #endif
    #if PIN_EXISTS(X_MAX)
      X_MAX_PIN,
    #endif
    #if PIN_EXISTS(X_CS) && AXIS_HAS_SPI(X)
      X_CS_PIN,
    #endif
    #if PIN_EXISTS(X_MS1)
      X_MS1_PIN,
    #endif
    #if PIN_EXISTS(X_MS2)
      X_MS2_PIN,
    #endif
    #if PIN_EXISTS(X_MS3)
      X_MS3_PIN,
    #endif
    #if PIN_EXISTS(X_ENABLE)
      X_ENABLE_PIN,
=======
// Mixing stepper, Switching stepper, or regular stepper
#define E_NEEDED(N) (ENABLED(MIXING_EXTRUDER) && MIXING_STEPPERS > N) \
                 || (ENABLED(SWITCHING_EXTRUDER) && E_STEPPERS > N) \
                 || (NONE(SWITCHING_EXTRUDER, MIXING_EXTRUDER) && EXTRUDERS > N)

#define _E0_CS
#define _E0_MS1
#define _E0_MS2
#define _E0_MS3

#if E_NEEDED(0)
  #if PIN_EXISTS(E0_CS) && AXIS_HAS_SPI(E0)
    #undef _E0_CS
    #define _E0_CS E0_CS_PIN,
  #endif
  #if PIN_EXISTS(E0_MS1)
    #undef _E0_MS1
    #define _E0_MS1 E0_MS1_PIN,
  #endif
  #if PIN_EXISTS(E0_MS2)
    #undef _E0_MS2
    #define _E0_MS2 E0_MS2_PIN,
  #endif
  #if PIN_EXISTS(E0_MS3)
    #undef _E0_MS3
    #define _E0_MS3 E0_MS3_PIN,
  #endif
#endif

#define _E1_CS
#define _E1_MS1
#define _E1_MS2
#define _E1_MS3

#if E_NEEDED(1)
  #if PIN_EXISTS(E1_CS) && AXIS_HAS_SPI(E1)
    #undef _E1_CS
    #define _E1_CS E1_CS_PIN,
  #endif
  #if PIN_EXISTS(E1_MS1)
    #undef _E1_MS1
    #define _E1_MS1 E1_MS1_PIN,
  #endif
  #if PIN_EXISTS(E1_MS2)
    #undef _E1_MS2
    #define _E1_MS2 E1_MS2_PIN,
  #endif
  #if PIN_EXISTS(E1_MS3)
    #undef _E1_MS3
    #define _E1_MS3 E1_MS3_PIN,
  #endif
#endif

#define _E2_CS
#define _E2_MS1
#define _E2_MS2
#define _E2_MS3

#if E_NEEDED(2)
  #if PIN_EXISTS(E2_CS) && AXIS_HAS_SPI(E2)
    #undef _E2_CS
    #define _E2_CS E2_CS_PIN,
  #endif
  #if PIN_EXISTS(E2_MS1)
    #undef _E2_MS1
    #define _E2_MS1 E2_MS1_PIN,
  #endif
  #if PIN_EXISTS(E2_MS2)
    #undef _E2_MS2
    #define _E2_MS2 E2_MS2_PIN,
  #endif
  #if PIN_EXISTS(E2_MS3)
    #undef _E2_MS3
    #define _E2_MS3 E2_MS3_PIN,
  #endif
#endif

#define _E3_CS
#define _E3_MS1
#define _E3_MS2
#define _E3_MS3

#if E_NEEDED(3)
  #if PIN_EXISTS(E3_CS) && AXIS_HAS_SPI(E3)
    #undef _E3_CS
    #define _E3_CS E3_CS_PIN,
  #endif
  #if PIN_EXISTS(E3_MS1)
    #undef _E3_MS1
    #define _E3_MS1 E3_MS1_PIN,
  #endif
  #if PIN_EXISTS(E3_MS2)
    #undef _E3_MS2
    #define _E3_MS2 E3_MS2_PIN,
  #endif
  #if PIN_EXISTS(E3_MS3)
    #undef _E3_MS3
    #define _E3_MS3 E3_MS3_PIN,
  #endif
#endif

#define _E4_CS
#define _E4_MS1
#define _E4_MS2
#define _E4_MS3

#if E_NEEDED(4)
  #if PIN_EXISTS(E4_CS) && AXIS_HAS_SPI(E4)
    #undef _E4_CS
    #define _E4_CS E4_CS_PIN,
  #endif
  #if PIN_EXISTS(E4_MS1)
    #undef _E4_MS1
    #define _E4_MS1 E4_MS1_PIN,
  #endif
  #if PIN_EXISTS(E4_MS2)
    #undef _E4_MS2
    #define _E4_MS2 E4_MS2_PIN,
  #endif
  #if PIN_EXISTS(E4_MS3)
    #undef _E4_MS3
    #define _E4_MS3 E4_MS3_PIN,
  #endif
#endif

#define _E5_CS
#define _E5_MS1
#define _E5_MS2
#define _E5_MS3

#if E_NEEDED(5)
  #if PIN_EXISTS(E5_CS) && AXIS_HAS_SPI(E5)
    #undef _E5_CS
    #define _E5_CS E5_CS_PIN,
  #endif
  #if PIN_EXISTS(E5_MS1)
    #undef _E5_MS1
    #define _E5_MS1 E5_MS1_PIN,
  #endif
  #if PIN_EXISTS(E5_MS2)
    #undef _E5_MS2
    #define _E5_MS2 E5_MS2_PIN,
  #endif
  #if PIN_EXISTS(E5_MS3)
    #undef _E5_MS3
    #define _E5_MS3 E5_MS3_PIN,
  #endif
#endif

#define _E6_CS
#define _E6_MS1
#define _E6_MS2
#define _E6_MS3

#if E_NEEDED(6)
  #if PIN_EXISTS(E6_CS) && AXIS_HAS_SPI(E6)
    #undef _E6_CS
    #define _E6_CS E6_CS_PIN,
  #endif
  #if PIN_EXISTS(E6_MS2)
    #undef _E6_MS2
    #define _E6_MS2 E6_MS2_PIN,
  #endif
  #if PIN_EXISTS(E6_MS3)
    #undef _E6_MS3
    #define _E6_MS3 E6_MS3_PIN,
  #endif
  #if PIN_EXISTS(E6_MS4)
    #undef _E6_MS4
    #define _E6_MS4 E6_MS4_PIN,
  #endif
#endif

#define _E7_CS
#define _E7_MS1
#define _E7_MS2
#define _E7_MS3

#if E_NEEDED(7)
  #if PIN_EXISTS(E7_CS) && AXIS_HAS_SPI(E7)
    #undef _E7_CS
    #define _E7_CS E7_CS_PIN,
  #endif
  #if PIN_EXISTS(E7_MS3)
    #undef _E7_MS3
    #define _E7_MS3 E7_MS3_PIN,
  #endif
  #if PIN_EXISTS(E7_MS4)
    #undef _E7_MS4
    #define _E7_MS4 E7_MS4_PIN,
  #endif
  #if PIN_EXISTS(E7_MS5)
    #undef _E7_MS5
    #define _E7_MS5 E7_MS5_PIN,
  #endif
#endif

//
// E Steppers
//

#define _E0_PINS
#define _E1_PINS
#define _E2_PINS
#define _E3_PINS
#define _E4_PINS
#define _E5_PINS
#define _E6_PINS
#define _E7_PINS

#if HAS_EXTRUDERS
  #undef _E0_PINS
  #define _E0_PINS E0_STEP_PIN, E0_DIR_PIN, E0_ENABLE_PIN, _E0_CS _E0_MS1 _E0_MS2 _E0_MS3
#endif

#if ENABLED(SWITCHING_EXTRUDER)
                      // Tools 0 and 1 use E0
  #if EXTRUDERS > 2   // Tools 2 and 3 use E1
    #undef _E1_PINS
    #define _E1_PINS E1_STEP_PIN, E1_DIR_PIN, E1_ENABLE_PIN, _E1_CS _E1_MS1 _E1_MS2 _E1_MS3
    #if EXTRUDERS > 4 // Tools 4 and 5 use E2
      #undef _E2_PINS
      #define _E2_PINS E2_STEP_PIN, E2_DIR_PIN, E2_ENABLE_PIN, _E2_CS _E2_MS1 _E2_MS2 _E2_MS3
>>>>>>> upstream/bugfix-2.0.x
    #endif
  #endif

  #if HAS_Y_AXIS
    #if PIN_EXISTS(Y_MIN)
      Y_MIN_PIN,
    #endif
    #if PIN_EXISTS(Y_MAX)
      Y_MAX_PIN,
    #endif
    #if PIN_EXISTS(Y_CS) && AXIS_HAS_SPI(Y)
      Y_CS_PIN,
    #endif
    #if PIN_EXISTS(Y_MS1)
      Y_MS1_PIN,
    #endif
    #if PIN_EXISTS(Y_MS2)
      Y_MS2_PIN,
    #endif
    #if PIN_EXISTS(Y_MS3)
      Y_MS3_PIN,
    #endif
    #if PIN_EXISTS(Y_ENABLE)
      Y_ENABLE_PIN,
    #endif
  #endif

  #if HAS_Z_AXIS
    #if PIN_EXISTS(Z_MIN)
      Z_MIN_PIN,
    #endif
    #if PIN_EXISTS(Z_MAX)
      Z_MAX_PIN,
    #endif
    #if PIN_EXISTS(Z_CS) && AXIS_HAS_SPI(Z)
      Z_CS_PIN,
    #endif
    #if PIN_EXISTS(Z_MS1)
      Z_MS1_PIN,
    #endif
    #if PIN_EXISTS(Z_MS2)
      Z_MS2_PIN,
    #endif
    #if PIN_EXISTS(Z_MS3)
      Z_MS3_PIN,
    #endif
    #if PIN_EXISTS(Z_ENABLE)
      Z_ENABLE_PIN,
    #endif
  #endif

  #if HAS_I_AXIS
    #if PIN_EXISTS(I_MIN)
      I_MIN_PIN,
    #endif
    #if PIN_EXISTS(I_MAX)
      I_MAX_PIN,
    #endif
    #if PIN_EXISTS(I_CS) && AXIS_HAS_SPI(I)
      I_CS_PIN,
    #endif
    #if PIN_EXISTS(I_MS1)
      I_MS1_PIN,
    #endif
    #if PIN_EXISTS(I_MS2)
      I_MS2_PIN,
    #endif
    #if PIN_EXISTS(I_MS3)
      I_MS3_PIN,
    #endif
    #if PIN_EXISTS(I_ENABLE)
      I_ENABLE_PIN,
    #endif
  #endif

  #if HAS_J_AXIS
    #if PIN_EXISTS(J_MIN)
      J_MIN_PIN,
    #endif
    #if PIN_EXISTS(J_MAX)
      J_MAX_PIN,
    #endif
    #if PIN_EXISTS(J_CS) && AXIS_HAS_SPI(J)
      J_CS_PIN,
    #endif
    #if PIN_EXISTS(J_MS1)
      J_MS1_PIN,
    #endif
    #if PIN_EXISTS(J_MS2)
      J_MS2_PIN,
    #endif
    #if PIN_EXISTS(J_MS3)
      J_MS3_PIN,
    #endif
    #if PIN_EXISTS(J_ENABLE)
      J_ENABLE_PIN,
    #endif
  #endif

  #if HAS_K_AXIS
    #if PIN_EXISTS(K_MIN)
      K_MIN_PIN,
    #endif
    #if PIN_EXISTS(K_MAX)
      K_MAX_PIN,
    #endif
    #if PIN_EXISTS(K_CS) && AXIS_HAS_SPI(K)
      K_CS_PIN,
    #endif
    #if PIN_EXISTS(K_MS1)
      K_MS1_PIN,
    #endif
    #if PIN_EXISTS(K_MS2)
      K_MS2_PIN,
    #endif
    #if PIN_EXISTS(K_MS3)
      K_MS3_PIN,
    #endif
    #if PIN_EXISTS(K_ENABLE)
      K_ENABLE_PIN,
    #endif
  #endif

  #if HAS_U_AXIS
    #if PIN_EXISTS(U_MIN)
      U_MIN_PIN,
    #endif
    #if PIN_EXISTS(U_MAX)
      U_MAX_PIN,
    #endif
    #if PIN_EXISTS(U_CS) && AXIS_HAS_SPI(U)
      U_CS_PIN,
    #endif
    #if PIN_EXISTS(U_MS1)
      U_MS1_PIN,
    #endif
    #if PIN_EXISTS(U_MS2)
      U_MS2_PIN,
    #endif
    #if PIN_EXISTS(U_MS3)
      U_MS3_PIN,
    #endif
  #endif

<<<<<<< HEAD
  #if HAS_V_AXIS
    #if PIN_EXISTS(V_MIN)
      V_MIN_PIN,
    #endif
    #if PIN_EXISTS(V_MAX)
      V_MAX_PIN,
    #endif
    #if PIN_EXISTS(V_CS) && AXIS_HAS_SPI(V)
      V_CS_PIN,
    #endif
    #if PIN_EXISTS(V_MS1)
      V_MS1_PIN,
    #endif
    #if PIN_EXISTS(V_MS2)
      V_MS2_PIN,
    #endif
    #if PIN_EXISTS(V_MS3)
      V_MS3_PIN,
    #endif
  #endif

  #if HAS_W_AXIS
    #if PIN_EXISTS(W_MIN)
      W_MIN_PIN,
    #endif
    #if PIN_EXISTS(W_MAX)
      W_MAX_PIN,
    #endif
    #if PIN_EXISTS(W_CS) && AXIS_HAS_SPI(W)
      W_CS_PIN,
    #endif
    #if PIN_EXISTS(W_MS1)
      W_MS1_PIN,
    #endif
    #if PIN_EXISTS(W_MS2)
      W_MS2_PIN,
    #endif
    #if PIN_EXISTS(W_MS3)
      W_MS3_PIN,
    #endif
  #endif

  //
  // Extruder Chip Select, Digital Micro-steps
  //

  // Mixing stepper, Switching stepper, or regular stepper
  #define E_NEEDED(N) (ENABLED(MIXING_EXTRUDER) && MIXING_STEPPERS > N) \
                   || (HAS_SWITCHING_EXTRUDER && E_STEPPERS > N) \
                   || (NONE(SWITCHING_EXTRUDER, MIXING_EXTRUDER) && EXTRUDERS > N)

  #if E_NEEDED(0)
    E0_STEP_PIN, E0_DIR_PIN, E0_ENABLE_PIN,
    #if PIN_EXISTS(E0_CS) && AXIS_HAS_SPI(E0)
      E0_CS_PIN,
    #endif
    #if PIN_EXISTS(E0_MS1)
      E0_MS1_PIN,
    #endif
    #if PIN_EXISTS(E0_MS2)
      E0_MS2_PIN,
    #endif
    #if PIN_EXISTS(E0_MS3)
      E0_MS3_PIN,
    #endif
  #endif

  #if E_NEEDED(1)
    E1_STEP_PIN, E1_DIR_PIN, E1_ENABLE_PIN,
    #if PIN_EXISTS(E1_CS) && AXIS_HAS_SPI(E1)
      E1_CS_PIN,
    #endif
    #if PIN_EXISTS(E1_MS1)
      E1_MS1_PIN,
    #endif
    #if PIN_EXISTS(E1_MS2)
      E1_MS2_PIN,
    #endif
    #if PIN_EXISTS(E1_MS3)
      E1_MS3_PIN,
    #endif
  #endif

  #if E_NEEDED(2)
    E2_STEP_PIN, E2_DIR_PIN, E2_ENABLE_PIN,
    #if PIN_EXISTS(E2_CS) && AXIS_HAS_SPI(E2)
      E2_CS_PIN,
    #endif
    #if PIN_EXISTS(E2_MS1)
      E2_MS1_PIN,
    #endif
    #if PIN_EXISTS(E2_MS2)
      E2_MS2_PIN,
    #endif
    #if PIN_EXISTS(E2_MS3)
      E2_MS3_PIN,
    #endif
  #endif

  #if E_NEEDED(3)
    E3_STEP_PIN, E3_DIR_PIN, E3_ENABLE_PIN,
    #if PIN_EXISTS(E3_CS) && AXIS_HAS_SPI(E3)
      E3_CS_PIN,
    #endif
    #if PIN_EXISTS(E3_MS1)
      E3_MS1_PIN,
    #endif
    #if PIN_EXISTS(E3_MS2)
      E3_MS2_PIN,
    #endif
    #if PIN_EXISTS(E3_MS3)
      E3_MS3_PIN,
    #endif
  #endif

  #if E_NEEDED(4)
    E4_STEP_PIN, E4_DIR_PIN, E4_ENABLE_PIN,
    #if PIN_EXISTS(E4_CS) && AXIS_HAS_SPI(E4)
      E4_CS_PIN,
    #endif
    #if PIN_EXISTS(E4_MS1)
      E4_MS1_PIN,
    #endif
    #if PIN_EXISTS(E4_MS2)
      E4_MS2_PIN,
    #endif
    #if PIN_EXISTS(E4_MS3)
      E4_MS3_PIN,
    #endif
  #endif

  #if E_NEEDED(5)
    E5_STEP_PIN, E5_DIR_PIN, E5_ENABLE_PIN,
    #if PIN_EXISTS(E5_CS) && AXIS_HAS_SPI(E5)
      E5_CS_PIN,
    #endif
    #if PIN_EXISTS(E5_MS1)
      E5_MS1_PIN,
    #endif
    #if PIN_EXISTS(E5_MS2)
      E5_MS2_PIN,
    #endif
    #if PIN_EXISTS(E5_MS3)
      E5_MS3_PIN,
    #endif
  #endif

  #if E_NEEDED(6)
    E6_STEP_PIN, E6_DIR_PIN, E6_ENABLE_PIN,
    #if PIN_EXISTS(E6_CS) && AXIS_HAS_SPI(E6)
      E6_CS_PIN,
    #endif
    #if PIN_EXISTS(E6_MS2)
      E6_MS2_PIN,
    #endif
    #if PIN_EXISTS(E6_MS3)
      E6_MS3_PIN,
    #endif
    #if PIN_EXISTS(E6_MS4)
      E6_MS4_PIN,
    #endif
  #endif

  #if E_NEEDED(7)
    E7_STEP_PIN, E7_DIR_PIN, E7_ENABLE_PIN,
    #if PIN_EXISTS(E7_CS) && AXIS_HAS_SPI(E7)
      E7_CS_PIN,
    #endif
    #if PIN_EXISTS(E7_MS3)
      E7_MS3_PIN,
    #endif
    #if PIN_EXISTS(E7_MS4)
      E7_MS4_PIN,
    #endif
    #if PIN_EXISTS(E7_MS5)
      E7_MS5_PIN,
    #endif
  #endif

  //
  // Hotend Heaters and Fans
  //

  #if HAS_HOTEND
    HEATER_0_PIN,
    #if PIN_EXISTS(E0_AUTO_FAN)
      E0_AUTO_FAN_PIN,
    #endif
  #endif
  #if HAS_MULTI_HOTEND
    HEATER_1_PIN,
    #if PIN_EXISTS(E1_AUTO_FAN)
      E1_AUTO_FAN_PIN,
    #endif
  #endif
  #if HOTENDS > 2
    HEATER_2_PIN,
    #if PIN_EXISTS(E2_AUTO_FAN)
      E2_AUTO_FAN_PIN,
    #endif
  #endif
  #if HOTENDS > 3
    HEATER_3_PIN,
    #if PIN_EXISTS(E3_AUTO_FAN)
      E3_AUTO_FAN_PIN,
    #endif
  #endif
  #if HOTENDS > 4
    HEATER_4_PIN,
    #if PIN_EXISTS(E4_AUTO_FAN)
      E4_AUTO_FAN_PIN,
    #endif
  #endif
  #if HOTENDS > 5
    HEATER_5_PIN,
    #if PIN_EXISTS(E5_AUTO_FAN)
      E5_AUTO_FAN_PIN,
    #endif
  #endif
  #if HOTENDS > 6
    HEATER_6_PIN,
    #if PIN_EXISTS(E6_AUTO_FAN)
      E6_AUTO_FAN_PIN,
    #endif
  #endif
  #if HOTENDS > 7
    HEATER_7_PIN,
    #if PIN_EXISTS(E7_AUTO_FAN)
      E7_AUTO_FAN_PIN,
    #endif
  #endif
=======
#define DIO_PIN(P) TERN(TARGET_LPC1768, P, analogInputToDigitalPin(P))

#if HAS_HOTEND
  #undef _H0_PINS
  #define _H0_PINS HEATER_0_PIN, E0_AUTO_FAN_PIN, DIO_PIN(TEMP_0_PIN),
  #if HAS_MULTI_HOTEND
    #undef _H1_PINS
    #define _H1_PINS HEATER_1_PIN, E1_AUTO_FAN_PIN, DIO_PIN(TEMP_1_PIN),
    #if HOTENDS > 2
      #undef _H2_PINS
      #define _H2_PINS HEATER_2_PIN, E2_AUTO_FAN_PIN, DIO_PIN(TEMP_2_PIN),
      #if HOTENDS > 3
        #undef _H3_PINS
        #define _H3_PINS HEATER_3_PIN, E3_AUTO_FAN_PIN, DIO_PIN(TEMP_3_PIN),
        #if HOTENDS > 4
          #undef _H4_PINS
          #define _H4_PINS HEATER_4_PIN, E4_AUTO_FAN_PIN, DIO_PIN(TEMP_4_PIN),
          #if HOTENDS > 5
            #undef _H5_PINS
            #define _H5_PINS HEATER_5_PIN, E5_AUTO_FAN_PIN, DIO_PIN(TEMP_5_PIN),
            #if HOTENDS > 6
              #undef _H6_PINS
              #define _H6_PINS HEATER_6_PIN, E6_AUTO_FAN_PIN, DIO_PIN(TEMP_6_PIN),
              #if HOTENDS > 7
                #undef _H7_PINS
                #define _H7_PINS HEATER_7_PIN, E7_AUTO_FAN_PIN, DIO_PIN(TEMP_7_PIN),
              #endif // HOTENDS > 7
            #endif // HOTENDS > 6
          #endif // HOTENDS > 5
        #endif // HOTENDS > 4
      #endif // HOTENDS > 3
    #endif // HOTENDS > 2
  #endif // HAS_MULTI_HOTEND
#endif // HOTENDS
>>>>>>> upstream/bugfix-2.0.x

  //
  // Dual X, Dual Y, Multi-Z
  // Chip Select and Digital Micro-stepping
  //

<<<<<<< HEAD
  #if HAS_X2_STEPPER
    #if PIN_EXISTS(X2_CS) && AXIS_HAS_SPI(X2)
      X2_CS_PIN,
    #endif
    #if PIN_EXISTS(X2_MS1)
      X2_MS1_PIN,
    #endif
    #if PIN_EXISTS(X2_MS2)
      X2_MS2_PIN,
    #endif
    #if PIN_EXISTS(X2_MS3)
      X2_MS3_PIN,
    #endif
=======
#if HAS_X2_STEPPER
  #if PIN_EXISTS(X2_CS) && AXIS_HAS_SPI(X2)
    #define _X2_CS X2_CS_PIN,
  #else
    #define _X2_CS
>>>>>>> upstream/bugfix-2.0.x
  #endif

<<<<<<< HEAD
  #if HAS_Y2_STEPPER
    #if PIN_EXISTS(Y2_CS) && AXIS_HAS_SPI(Y2)
      Y2_CS_PIN,
    #endif
    #if PIN_EXISTS(Y2_MS1)
      Y2_MS1_PIN,
    #endif
    #if PIN_EXISTS(Y2_MS2)
      Y2_MS2_PIN,
    #endif
    #if PIN_EXISTS(Y2_MS3)
      Y2_MS3_PIN,
    #endif
=======
#if HAS_DUAL_Y_STEPPERS
  #if PIN_EXISTS(Y2_CS) && AXIS_HAS_SPI(Y2)
    #define _Y2_CS Y2_CS_PIN,
  #else
    #define _Y2_CS
>>>>>>> upstream/bugfix-2.0.x
  #endif

<<<<<<< HEAD
  #if NUM_Z_STEPPERS >= 2
    #if PIN_EXISTS(Z2_CS) && AXIS_HAS_SPI(Z2)
      Z2_CS_PIN,
    #endif
    #if PIN_EXISTS(Z2_MS1)
      Z2_MS1_PIN,
    #endif
    #if PIN_EXISTS(Z2_MS2)
      Z2_MS2_PIN,
    #endif
    #if PIN_EXISTS(Z2_MS3)
      Z2_MS3_PIN,
    #endif
=======
#if NUM_Z_STEPPERS >= 2
  #if PIN_EXISTS(Z2_CS) && AXIS_HAS_SPI(Z2)
    #define _Z2_CS Z2_CS_PIN,
  #else
    #define _Z2_CS
>>>>>>> upstream/bugfix-2.0.x
  #endif

  #if NUM_Z_STEPPERS >= 3
    #if PIN_EXISTS(Z3_CS) && AXIS_HAS_SPI(Z3)
      Z3_CS_PIN,
    #endif
    #if PIN_EXISTS(Z3_MS1)
      Z3_MS1_PIN,
    #endif
    #if PIN_EXISTS(Z3_MS2)
      Z3_MS2_PIN,
    #endif
    #if PIN_EXISTS(Z3_MS3)
      Z3_MS3_PIN,
    #endif
  #endif

  #if NUM_Z_STEPPERS >= 4
    #if PIN_EXISTS(Z4_CS) && AXIS_HAS_SPI(Z4)
      Z4_CS_PIN,
    #endif
    #if PIN_EXISTS(Z4_MS1)
      Z4_MS1_PIN,
    #endif
    #if PIN_EXISTS(Z4_MS2)
      Z4_MS2_PIN,
    #endif
    #if PIN_EXISTS(Z4_MS3)
      Z4_MS3_PIN,
    #endif
  #endif

  #if PIN_EXISTS(PS_ON)
    PS_ON_PIN,
  #endif

<<<<<<< HEAD
  #if HAS_BED_PROBE && PIN_EXISTS(Z_MIN_PROBE)
    Z_MIN_PROBE_PIN,
=======
#if NUM_Z_STEPPERS >= 3
  #if PIN_EXISTS(Z3_CS) && AXIS_HAS_SPI(Z3)
    #define _Z3_CS Z3_CS_PIN,
  #else
    #define _Z3_CS
>>>>>>> upstream/bugfix-2.0.x
  #endif

  #if PIN_EXISTS(FAN0)
    FAN0_PIN,
  #endif
  #if PIN_EXISTS(FAN1)
    FAN1_PIN,
  #endif
  #if PIN_EXISTS(FAN2)
    FAN2_PIN,
  #endif
<<<<<<< HEAD
  #if PIN_EXISTS(FAN3)
    FAN3_PIN,
=======
  #define _Z3_PINS Z3_STEP_PIN, Z3_DIR_PIN, Z3_ENABLE_PIN, _Z3_CS _Z3_MS1 _Z3_MS2 _Z3_MS3
#else
  #define _Z3_PINS
#endif

#if NUM_Z_STEPPERS >= 4
  #if PIN_EXISTS(Z4_CS) && AXIS_HAS_SPI(Z4)
    #define _Z4_CS Z4_CS_PIN,
  #else
    #define _Z4_CS
>>>>>>> upstream/bugfix-2.0.x
  #endif
  #if PIN_EXISTS(FAN4)
    FAN4_PIN,
  #endif
  #if PIN_EXISTS(FAN5)
    FAN5_PIN,
  #endif
  #if PIN_EXISTS(FAN6)
    FAN6_PIN,
  #endif
  #if PIN_EXISTS(FAN7)
    FAN7_PIN,
  #endif
  #if PIN_EXISTS(CONTROLLER_FAN)
    CONTROLLER_FAN_PIN,
  #endif

  #if TEMP_SENSOR_BED && PINS_EXIST(TEMP_BED, HEATER_BED)
    HEATER_BED_PIN,
  #endif

  #if TEMP_SENSOR_CHAMBER && PIN_EXISTS(TEMP_CHAMBER)
    #if PIN_EXISTS(HEATER_CHAMBER)
      HEATER_CHAMBER_PIN,
    #endif
    #if PIN_EXISTS(CHAMBER_AUTO_FAN)
      CHAMBER_AUTO_FAN_PIN,
    #endif
  #endif

  #if TEMP_SENSOR_COOLER && PIN_EXISTS(TEMP_COOLER)
    #if PIN_EXISTS(COOLER_AUTO_FAN)
      COOLER_AUTO_FAN_PIN,
    #endif
    #if PIN_EXISTS(COOLER)
      COOLER_PIN,
    #endif
  #endif

  #ifdef HAL_SENSITIVE_PINS
    HAL_SENSITIVE_PINS
  #endif
};

<<<<<<< HEAD
constexpr pin_t sensitive_aio[] PROGMEM = {
  #if HAS_HOTEND
    TEMP_0_PIN,
  #endif
  #if HAS_MULTI_HOTEND
    TEMP_1_PIN,
  #endif
  #if HOTENDS > 2
    TEMP_2_PIN,
  #endif
  #if HOTENDS > 3
    TEMP_3_PIN,
  #endif
  #if HOTENDS > 4
    TEMP_4_PIN,
  #endif
  #if HOTENDS > 5
    TEMP_5_PIN,
  #endif
  #if HOTENDS > 6
    TEMP_6_PIN,
  #endif
  #if HOTENDS > 7
    TEMP_7_PIN,
  #endif
  #if TEMP_SENSOR_BED && PINS_EXIST(TEMP_BED, HEATER_BED)
    TEMP_BED_PIN,
  #endif
  #if TEMP_SENSOR_CHAMBER && PIN_EXISTS(TEMP_CHAMBER)
    TEMP_CHAMBER_PIN,
  #endif
  #if TEMP_SENSOR_COOLER && PIN_EXISTS(TEMP_COOLER)
    TEMP_COOLER_PIN,
  #endif
};
=======
#if TEMP_SENSOR_BED && PINS_EXIST(TEMP_BED, HEATER_BED)
  #define _BED_PINS HEATER_BED_PIN, DIO_PIN(TEMP_BED_PIN),
#else
  #define _BED_PINS
#endif

#if TEMP_SENSOR_CHAMBER && PIN_EXISTS(TEMP_CHAMBER)
  #define _CHAMBER_TEMP DIO_PIN(TEMP_CHAMBER_PIN),
#else
  #define _CHAMBER_TEMP
#endif
#if TEMP_SENSOR_CHAMBER && PINS_EXIST(TEMP_CHAMBER, HEATER_CHAMBER)
  #define _CHAMBER_HEATER HEATER_CHAMBER_PIN,
#else
  #define _CHAMBER_HEATER
#endif
#if TEMP_SENSOR_CHAMBER && PINS_EXIST(TEMP_CHAMBER, CHAMBER_AUTO_FAN)
  #define _CHAMBER_FAN CHAMBER_AUTO_FAN_PIN,
#else
  #define _CHAMBER_FAN
#endif

#if TEMP_SENSOR_COOLER && PIN_EXISTS(TEMP_COOLER)
  #define _COOLER_TEMP DIO_PIN(TEMP_COOLER_PIN),
#else
  #define _COOLER_TEMP
#endif
#if TEMP_SENSOR_COOLER && PIN_EXISTS(COOLER)
  #define _COOLER COOLER_PIN,
#else
  #define _COOLER
#endif
#if TEMP_SENSOR_COOLER && PINS_EXIST(TEMP_COOLER, COOLER_AUTO_FAN)
  #define _COOLER_FAN COOLER_AUTO_FAN_PIN,
#else
  #define _COOLER_FAN
#endif

#ifndef HAL_SENSITIVE_PINS
  #define HAL_SENSITIVE_PINS
#endif

#ifdef RUNTIME_ONLY_ANALOG_TO_DIGITAL
  #define _SP_END
#else
  #define _SP_END -2

  // Move a regular pin in front to the end
  template<pin_t F, pin_t ...D>
  struct OnlyPins : OnlyPins<D..., F> { };

  // Remove a -1 from the front
  template<pin_t ...D>
  struct OnlyPins<-1, D...> : OnlyPins<D...> { };

  // Remove -2 from the front, emit the rest, cease propagation
  template<pin_t ...D>
  struct OnlyPins<_SP_END, D...> { static constexpr size_t size = sizeof...(D); static constexpr pin_t table[sizeof...(D)] PROGMEM = { D... }; };
#endif

#define SENSITIVE_PINS \
  _X_PINS _Y_PINS _Z_PINS _I_PINS _J_PINS _K_PINS \
  _X2_PINS _Y2_PINS _Z2_PINS _Z3_PINS _Z4_PINS _Z_PROBE \
  _E0_PINS _E1_PINS _E2_PINS _E3_PINS _E4_PINS _E5_PINS _E6_PINS _E7_PINS \
  _H0_PINS _H1_PINS _H2_PINS _H3_PINS _H4_PINS _H5_PINS _H6_PINS _H7_PINS \
  _PS_ON _FAN0 _FAN1 _FAN2 _FAN3 _FAN4 _FAN5 _FAN6 _FAN7 _FANC \
  _BED_PINS _CHAMBER_TEMP _CHAMBER_HEATER _CHAMBER_FAN \
  _COOLER_TEMP _COOLER _COOLER_FAN HAL_SENSITIVE_PINS \
  _SP_END
>>>>>>> upstream/bugfix-2.0.x

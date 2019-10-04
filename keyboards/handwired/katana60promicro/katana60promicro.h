/* Copyright 2017 Baris Tosun
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef KATANA60_H
#define KATANA60_H

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
#define LAYOUT( \
      k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c, k4d, k4e, \
      k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, \
      k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, \
      k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e, \
      k00, k01, k02, k03, k04, k05, k06,           k09, k0a, k0b, k0c, k0d \
) \
{ \
    { k0d, k0b, k09, k05, k04, k02, k00 }, \
    { k0c, k0a, k06, k17, k03, k01, k40 }, \
    { k1e, k1c, k1a, k18, k15, k13, k11 }, \
    { k1d, k1b, k19, k16, k14, k12, k10 }, \
    { k2d, k2b, k29, k27, k25, k23, k21 }, \
    { k2c, k2a, k28, k26, k24, k22, k20 }, \
    { k3d, k3b, k39, k37, k35, k33, k31 }, \
    { k3c, k3a, k38, k36, k34, k32, k30 }, \
    { k4e, k4c, k4a, k48, k46, k44, k42 }, \
    { k4d, k4b, k49, k47, k45, k43, k41 }, \
}

#endif

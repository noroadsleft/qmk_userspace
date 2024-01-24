/* Copyright 2019-2022 James Young (@noroadsleft)
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

#include "noroadsleft.h"

// Layer shorthand
enum layers {
    // BASE LAYERS
    _DV,
    _QW,
    _CM,
    // FUNCTION LAYERS
    _FL,
    _FR,
    // OTHER LAYERS
    _SY
};

#define FN_CAPS LT(_FL, KC_CAPS)
#define FL_BSPC LT(_FL, KC_BSPC)
#define FR_SPC  LT(_FR, KC_SPC)
#define CTL_GRV MT(MOD_LCTL, KC_GRV) // Left Control when held, Grave accent when tapped

/* LAYOUT_ortho_5x14_2x2u_c
 * ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │00   │01 │02 │03 │04 │05 │06 │07 │08 │09 │0A │0B │0C │0D   │
 * ├─────┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼─────┤
 * │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1A │1B │1C │1D   │
 * ├─────┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼─────┤
 * │20   │21 │22 │23 │24 │25 │26 │27 │28 │29 │2A │2B │2C │2D   │
 * ├─────┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼─────┤
 * │30   │31 │32 │33 │34 │35 │36 │37 │38 │39 │3A │3B │3C │3D   │
 * ├─────┼───┼───┼───┼───┼───┴───┼───┴───┼───┼───┼───┼───┼─────┤
 * │40   │41 │42 │43 │44 │  45   │  47   │49 │4A │4B │4C │4D   │
 * └─────┴───┴───┴───┴───┴───────┴───────┴───┴───┴───┴───┴─────┘
 */
#define LAYOUT_ortho_5x14_2x2u_c( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, \
    k40, k41, k42, k43, k44,   k45,      k47,    k49, k4A, k4B, k4C, k4D  \
) { \
    { k00, k01, k02, k03, k04, k05, k06,   k07, k08,   k09, k0A, k0B, k0C, k0D }, \
    { k10, k11, k12, k13, k14, k15, k16,   k17, k18,   k19, k1A, k1B, k1C, k1D }, \
    { k20, k21, k22, k23, k24, k25, k26,   k27, k28,   k29, k2A, k2B, k2C, k2D }, \
    { k30, k31, k32, k33, k34, k35, k36,   k37, k38,   k39, k3A, k3B, k3C, k3D }, \
    { k40, k41, k42, k43, k44, k45, KC_NO, k47, KC_NO, k49, k4A, k4B, k4C, k4D }  \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DV] = LAYOUT_ortho_5x14_2x2u_c(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC, KC_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_SLSH, KC_EQL,  KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_MINS,
        FN_CAPS, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_HOME, KC_PGUP, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_END,  KC_PGDN, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
        CTL_GRV, KC_NUBS, KC_LGUI, MO(_FL), KC_LALT,          FL_BSPC, FR_SPC,           KC_RALT, MO(_FL), KC_RGUI, KC_BSLS, KC_RCTL
    ),

    [_QW] = LAYOUT_ortho_5x14_2x2u_c(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
        FN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        CTL_GRV, KC_NUBS, KC_LGUI, MO(_FL), KC_LALT,          FL_BSPC, FR_SPC,           KC_RALT, MO(_FL), KC_RGUI, KC_BSLS, KC_RCTL
    ),

    [_CM] = LAYOUT_ortho_5x14_2x2u_c(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_LBRC, KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
        FN_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_HOME, KC_PGUP, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        CTL_GRV, KC_NUBS, KC_LGUI, MO(_FL), KC_LALT,          FL_BSPC, FR_SPC,           KC_RALT, MO(_FL), KC_RGUI, KC_BSLS, KC_RCTL
    ),

    [_FL] = LAYOUT_ortho_5x14_2x2u_c(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_CALC, KC_APP,  _______, _______, _______, KC_PSCR, KC_SCRL, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
        _______, M_SALL,  _______, _______, _______, _______, _______, _______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
        _______, M_UNDO,  M_CUT,   M_COPY,  M_PASTE, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
        _______, _______, _______, _______, _______,          _______, KC_DEL,           _______, _______, _______, KC_PAUS, _______
    ),

    [_FR] = LAYOUT_ortho_5x14_2x2u_c(
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   _______, _______,
        _______, _______, _______, _______, KC_E,    KC_F,    _______, _______, KC_PAST, KC_P4,   KC_P5,   KC_P6,   _______, _______,
        _______, _______, _______, _______, KC_C,    KC_D,    _______, _______, KC_PMNS, KC_P1,   KC_P2,   KC_P3,   _______, KC_PENT,
        _______, _______, _______, _______, KC_A,    KC_B,    _______, _______, KC_PPLS, KC_P0,   _______, KC_PDOT, _______, _______,
        _______, _______, _______, _______, _______,          TG(_SY), _______,          _______, _______, _______, _______, _______
    ),

    [_SY] = LAYOUT_ortho_5x14_2x2u_c(
        TG(_SY), TO(_DV), TO(_QW), TO(_CM), _______, _______, _______, _______, _______, QK_BOOT, _______, DB_TOGG, _______, VRSN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______
    ),

};

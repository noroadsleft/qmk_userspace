/* Copyright 2021-2025 James Young (@noroadsleft)
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

enum layer_names {
    // BASE LAYERS
    _DV,
    _QW,
    _NP,
    // FUNCTION LAYER
    _FN,
    _MA,
    // OTHER LAYERS
    _SY,
};

// KEYCODE DEFINITIONS
#define FN_CAPS LT(_FN, KC_CAPS)  // Function Layer when held, Caps Lock when tapped
#define CTL_GRV MT(MOD_LCTL, KC_GRV)  // Left Control when held, Grave accent when tapped

#define LAYOUT_60_iso_tsangan_split_rshift( \
    K00, K03, K02, K01, K04, K05, K06, K07, K08, K09, K0C, K0B, K0A, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C,      \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K1D, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, \
    K40, K41, K42,                K43,                     K4B, K4C, K4D  \
) { \
    { K00, K01, K02, K03, K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B, K0C, K0D   }, \
    { K10, K11, K12, K13, K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B, K1C, K1D   }, \
    { K20, K21, K22, K23, K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B, K2C, KC_NO }, \
    { K30, K31, K32, K33, K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B, K3C, K3D   }, \
    { K40, K41, K42, K43, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K4B, K4C, K4D   }  \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DV] = LAYOUT_60_iso_tsangan_split_rshift(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,
        FN_CAPS, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, MO(_MA),
        CTL_GRV, KC_LGUI, KC_LALT,                            KC_SPC,                                      KC_RALT, MO(_FN), KC_RCTL
    ),

    [_QW] = LAYOUT_60_iso_tsangan_split_rshift(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        FN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_MA),
        CTL_GRV, KC_LGUI, KC_LALT,                            KC_SPC,                                      KC_RALT, MO(_FN), KC_RCTL
    ),

    [_NP] = LAYOUT_60_iso_tsangan_split_rshift(
        _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______,
        _______, _______, _______, _______, KC_E,    KC_F,    _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_PSLS, KC_PEQL,
        _______, _______, _______, _______, KC_C,    KC_D,    _______, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, KC_PMNS, _______, KC_PENT,
        _______, _______, _______, _______, _______, KC_A,    KC_B,    _______, KC_P0,   _______, KC_PDOT, _______, _______, MO(_MA),
        _______, _______, _______,                            TG(_NP),                                     _______, _______, _______
    ),

    [_FN] = LAYOUT_60_iso_tsangan_split_rshift(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_CALC, KC_APP,  _______, _______, _______, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_PSCR, KC_SCRL,
        _______, M_SALL,  _______, _______, _______, _______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, KC_PAUS, KC_PENT,
        _______, _______, M_UNDO,  M_CUT,   M_COPY,  M_PASTE, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, TG(_SY), _______, MO(_MA),
        _______, _______, _______,                            TG(_NP),                                     _______, _______, _______
    ),

    [_MA] = LAYOUT_60_iso_tsangan_split_rshift(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DM_REC1, DM_REC2, _______,
        _______, _______, _______, G_PUSH,  _______, _______, _______, _______, _______, _______, _______, DM_PLY1, DM_PLY2,
        _______, _______, _______, G_FTCH,  _______, _______, _______, _______, _______, _______, _______, _______, DM_RSTP, _______,
        _______, _______, _______, _______, _______, _______, G_BRCH,  _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                                     _______, _______, _______
    ),

    [_SY] = LAYOUT_60_iso_tsangan_split_rshift(
        TG(_SY), TO(_DV), TO(_QW), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, QK_RBT,  DB_TOGG, XXXXXXX, VRSN,    XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                                     XXXXXXX, _______, XXXXXXX
    ),

};

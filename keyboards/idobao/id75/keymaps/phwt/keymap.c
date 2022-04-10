/* Copyright 2022 phwt
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
#include QMK_KEYBOARD_H
#include "features/caps_word.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    C_CONST = SAFE_RANGE,
    C_VAR,
    C_DOTNET,

    V_DOWN,
    V_UP,
    V_MID,

    // Layers
    LOWER,
    RAISE,
    TOGGLE
};

enum layers {
    _CMK, // Colemak DH Matrix
    _QTY, // QWERTY
    _FN,  // Functions base
    _LWR,
    _RSE,
    _MSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // clang-format off
    [_CMK] = LAYOUT_ortho_5x15(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PSLS, KC_PAST, KC_PMNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_P7,   KC_P8,   KC_P9,   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
        KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_P4,   KC_P5,   KC_P6,   KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_P1,   KC_P2,   KC_P3,   KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LALT, KC_LGUI, LOWER,  KC_SPC,   MO(_FN), KC_PPLS, KC_P0,   KC_PDOT, MO(_FN), KC_SPC,  RAISE,   _______, _______, KC_RALT
    ),
    [_QTY] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_QUOT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_FN] = LAYOUT_ortho_5x15(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_BRID, KC_MPLY, KC_BRIU, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_LWR] = LAYOUT_ortho_5x15(
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END,  _______, _______, _______
    ),
    [_RSE] = LAYOUT_ortho_5x15(
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, V_UP,    KC_UP,   V_DOWN,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, V_MID,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_HOME, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_MSE] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_WH_U, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};
// clang-format on

const uint16_t PROGMEM _reset[]   = {LOWER, RAISE, KC_ESC, COMBO_END};
const uint16_t PROGMEM _const[]   = {KC_C, KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM _var[]     = {KC_V, KC_R, COMBO_END};
const uint16_t PROGMEM _dotnet[]  = {KC_D, KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM _ltoggle[] = {LOWER, RAISE, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(_reset, RESET),     //
    COMBO(_const, C_CONST),   //
    COMBO(_var, C_VAR),       //
    COMBO(_dotnet, C_DOTNET), //
    COMBO(_ltoggle, TOGGLE)   //
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) return false;

    switch (keycode) {
        case C_CONST:
            if (record->event.pressed) SEND_STRING("const");
            return false;
        case C_VAR:
            if (record->event.pressed) SEND_STRING("var");
            return false;
        case C_DOTNET:
            if (record->event.pressed) SEND_STRING("dotnet");
            return false;
        case V_UP:
            if (record->event.pressed) {
                for (size_t i = 0; i < 10; i++) {
                    SEND_STRING(SS_LCTL("y"));
                }
            }
            return false;
        case V_DOWN:
            if (record->event.pressed) {
                for (size_t i = 0; i < 10; i++) {
                    SEND_STRING(SS_LCTL("e"));
                }
            }
            return false;
        case V_MID:
            if (record->event.pressed) {
                SEND_STRING("50%%zz");
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LWR);
            } else {
                layer_off(_LWR);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RSE);
            } else {
                layer_off(_RSE);
            }
            return false;
        case TOGGLE:
            if (record->event.pressed) layer_invert(_QTY);
            return false;
        default:
            return true; // Process all other keycodes normally
    }
};

const key_override_t ctrl_esc_term = ko_make_basic(MOD_MASK_CTRL, KC_ESC, C(KC_GRV));

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &ctrl_esc_term,
    NULL // Null terminate the array of overrides!
};

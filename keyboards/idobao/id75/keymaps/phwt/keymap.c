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

    // Macros for Visual Studio Code
    M_TERM, // Toggle terminal (Ctrl + `)
    M_VIM,  // Toggle Vim (Cmd + I + M)
    M_LNUP, // Move line up
    M_LNDN  // Move line down
};

enum layers {
    _CMK, // Colemak DH Matrix
    _QTY, // QWERTY
    _FN,  // Functions
    _MSE  // Mouse
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // clang-format off
    [_CMK] = LAYOUT_ortho_5x15(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,  KC_BSLS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    _______, _______,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC,
        KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    _______, _______,  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_SPC,  KC_SPC,  MO(_FN), MO(_MSE),MO(_FN), KC_SPC,  KC_SPC,  TG(_QTY),KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_QTY] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_FN] = LAYOUT_ortho_5x15(
        RESET,   KC_F1,   KC_F2,      KC_F3,   KC_F4,      KC_F5,   KC_MYCM, KC_MPLY, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, _______, G(KC_LBRC), M_LNUP,  G(KC_RBRC), _______, KC_BRID, KC_BRIU, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_LEFT,    M_LNDN,  KC_RGHT,    _______, M_TERM,  M_VIM,   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,    _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,    _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_MSE] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, KC_WH_D, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};
// clang-format on

const uint16_t PROGMEM _rbspc[]  = {KC_MINS, KC_EQL, COMBO_END};
const uint16_t PROGMEM _rdel[]   = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM _went[]   = {KC_QUOT, KC_ENT, COMBO_END};
const uint16_t PROGMEM _wsft[]   = {KC_UP, KC_RSFT, COMBO_END};
const uint16_t PROGMEM _const[]  = {KC_C, KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM _var[]    = {KC_V, KC_R, COMBO_END};
const uint16_t PROGMEM _dotnet[] = {KC_D, KC_N, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(_rbspc, KC_BSPC),  //
    COMBO(_rdel, KC_DEL),    //
    COMBO(_went, KC_ENT),    //
    COMBO(_wsft, KC_RSFT),   //
    COMBO(_const, C_CONST),  //
    COMBO(_var, C_VAR),      //
    COMBO(_dotnet, C_DOTNET) //
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
        case M_TERM:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_GRV);
                clear_keyboard();
            }
            return false;
        case M_VIM:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_I);
                register_code(KC_M);
                clear_keyboard();
            }
            return false;
        case M_LNUP:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code_delay(KC_UP, 10);
                clear_keyboard();
            }
            return false;
        case M_LNDN:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code_delay(KC_DOWN, 10);
                clear_keyboard();
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
};

/* Copyright 2015-2023 Jack Humbert
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

enum layers { _BASE, _LOWER, _RAISE, _NUM };
enum keycodes { M_BHREG = SAFE_RANGE };

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define NUM    MO(_NUM)
#define TH_ENT LT(_RAISE, KC_ENT)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, M_BHREG, KC_LALT, KC_LGUI, KC_SPC,  LOWER,   LOWER,   TH_ENT,  KC_RGUI, NUM,     KC_HOME, KC_END
    ),
    [_LOWER] = LAYOUT_planck_grid(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        _______, _______, _______, _______, KC_PLUS, _______, _______, KC_UNDS, _______, _______, KC_LBRC, KC_RBRC,
        _______, KC_PIPE, KC_BSLS, _______, KC_MINS, _______, _______, KC_EQL,  _______, _______, KC_MINS, KC_EQL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT_planck_grid(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, KC_WH_D, _______, _______, KC_LEFT, KC_UP,   KC_RGHT, _______, _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_WH_U, _______, _______, _______, KC_DOWN, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_NUM] = LAYOUT_planck_grid(
        _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_P4,   KC_P5,   KC_P6,   _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_P0,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};
/* clang-format on */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_BHREG:
            if (record->event.pressed) {
                send_string("\"_");
            }
            return false;
    }
    return true;
}

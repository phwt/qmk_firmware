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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    V_DOWN = SAFE_RANGE,
    V_UP,
    V_MID,

    M_MUTE,

    // Layers
    LOWER,
    RAISE,
    TOGGLE,
    TOGGLE_ARROW,
    TOGGLE_SYMBOL
};

enum layers {
    _QWERTY,  // QWERTY
    _COLEMAK, // Colemak-DH Matrix
    _SYMBOL,
    _FN,
    _LOWER,
    _RAISE
};

#define TH_BSPC LT(0, KC_BSPC) // Hold for Alt + Backspace

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // clang-format off
    [_QWERTY] = LAYOUT_ortho_5x15(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TH_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_P7,   KC_P8,   KC_P9,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
        TH_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_P4,   KC_P5,   KC_P6,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P1,   KC_P2,   KC_P3,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
        KC_LCTL, MO(_FN), KC_LALT, KC_LGUI, KC_SPC,  KC_SPC,  KC_SPC,  KC_P0,   TOGGLE, LOWER,   RAISE,   KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_COLEMAK] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    _______, _______, _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
        _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    _______, _______, _______, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______, _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_SYMBOL] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL
    ),
    [_FN] = LAYOUT_ortho_5x15(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_BRID, KC_MPLY, KC_BRIU, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, M_MUTE,  _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  _______, _______, _______, _______
    ),
    [_LOWER] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, V_UP,    KC_UP,   V_DOWN,  _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
        KC_WH_D, KC_LEFT, KC_DOWN, KC_RGHT, KC_WH_U, V_MID,   _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT_ortho_5x15(
        KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_DEL,
        KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_CIRC, _______, _______, KC_MINS, KC_UNDS, _______, _______, _______, KC_EQL,  KC_PLUS, _______, _______, KC_DLR,  KC_PIPE,
        _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};
// clang-format on

const uint16_t PROGMEM _reset[]        = {LOWER, RAISE, KC_ESC, COMBO_END};
const uint16_t PROGMEM _arrowtoggle[]  = {KC_LBRC, KC_RBRC, KC_MINS, KC_EQL, COMBO_END};
const uint16_t PROGMEM _symboltoggle[] = {KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(_reset, RESET),               //
    COMBO(_arrowtoggle, TOGGLE_ARROW),  //
    COMBO(_symboltoggle, TOGGLE_SYMBOL) //
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case V_UP:
            if (record->event.pressed) {
                for (size_t i = 0; i < 10; i++) {
                    SEND_STRING(SS_LCTL("o")); // y
                }
            }
            return false;
        case V_DOWN:
            if (record->event.pressed) {
                for (size_t i = 0; i < 10; i++) {
                    SEND_STRING(SS_LCTL("k")); // e
                }
            }
            return false;
        case V_MID:
            if (record->event.pressed) {
                SEND_STRING("50%%zz");
            }
            return false;
        case M_MUTE:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_F1);
                clear_keyboard();
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_FN);
                layer_on(_LOWER);
            } else {
                layer_off(_FN);
                layer_off(_LOWER);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_FN);
                layer_on(_RAISE);
            } else {
                layer_off(_FN);
                layer_off(_RAISE);
            }
            return false;
        case TOGGLE:
            if (record->event.pressed) layer_invert(_COLEMAK);
            return false;
        case TOGGLE_ARROW:
            if (record->event.pressed) layer_off(_SYMBOL);
            return false;
        case TOGGLE_SYMBOL:
            if (record->event.pressed) layer_on(_SYMBOL);
            return false;
        case TH_BSPC:
            if (record->event.pressed && !record->tap.count) {
                tap_code16(A(KC_BSPC));
                return false;
            }
            return true;
        default:
            return true; // Process all other keycodes normally
    }
};

const key_override_t ctrl_esc_term         = ko_make_basic(MOD_MASK_CTRL, KC_ESC, C(KC_GRV));
const key_override_t gui_esc_cycle         = ko_make_basic(MOD_MASK_GUI, KC_ESC, G(KC_GRV));
const key_override_t shift_backspace_sleep = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_SLEP);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &ctrl_esc_term, &gui_esc_cycle, &shift_backspace_sleep,
    NULL // Null terminate the array of overrides!
};

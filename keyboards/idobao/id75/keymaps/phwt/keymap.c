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
    C_CONST = SAFE_RANGE,
    C_VAR,
    C_DOTNET,

    V_DOWN,
    V_UP,
    V_MID,

    M_MUTE,
    M_GRH,  // grs HEAD^
    M_GSAC, // gst > ga > gst > gc

    // Layers
    LOWER,
    RAISE,
    TOGGLE
};

enum { TD_RSFT_CAPS = 0 };

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS) //
};

#define KC_SAPS TD(TD_RSFT_CAPS)

enum layers {
    _CMK, // Colemak-DH Matrix
    _QTY, // Non-split QWERTY
    _FN,
    _LWR,
    _RSE,
    _MSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // clang-format off
    [_CMK] = LAYOUT_ortho_5x15(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PEQL, KC_PAST, KC_PMNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_P7,   KC_P8,   KC_P9,   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
        KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_P4,   KC_P5,   KC_P6,   KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_P1,   KC_P2,   KC_P3,   KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_UP,   KC_SAPS,
        KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  KC_SPC,  KC_P0,   KC_PPLS, MO(_FN), RAISE,   KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_QTY] = LAYOUT_ortho_5x15(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, XXXXXXX, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, XXXXXXX, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_FN] = LAYOUT_ortho_5x15(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_BRID, KC_MPLY, KC_BRIU, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, M_MUTE,  _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, M_GRH,   _______, M_GSAC,  _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_LWR] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, V_UP,    KC_UP,   V_DOWN,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, V_MID,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END,  _______, _______, _______, _______
    ),
    [_RSE] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LABK, KC_GRV,  KC_EXLM, KC_DQUO, KC_LCBR, _______, _______, _______, KC_RCBR, KC_QUOT, KC_ASTR, KC_TILD, KC_RABK, _______,
        _______, KC_COLN, KC_CIRC, KC_PLUS, KC_COMM, KC_LPRN, _______, _______, _______, KC_RPRN, KC_DOT,  KC_MINS, KC_DLR,  KC_SCLN, _______,
        _______, KC_SLSH, KC_QUES, KC_PGUP, KC_UNDS, KC_LBRC, _______, _______, _______, KC_RBRC, KC_EQL,  KC_PGDN, KC_PIPE, KC_BSLS, _______,
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
const uint16_t PROGMEM _ltoggle[] = {LOWER, RAISE, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(_reset, RESET),   //
    COMBO(_ltoggle, TOGGLE) //
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
        case M_MUTE:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_F1);
                clear_keyboard();
            }
            return false;
        case M_GRH:
            if (record->event.pressed) {
                SEND_STRING("grh HEAD^");
            }
            return false;
        case M_GSAC:
            if (record->event.pressed) {
                SEND_STRING("gst && ga . && gst" SS_TAP(X_ENTER) "gc -m \":\"" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_FN);
                layer_on(_LWR);
            } else {
                layer_off(_FN);
                layer_off(_LWR);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_FN);
                layer_on(_RSE);
            } else {
                layer_off(_FN);
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

const key_override_t ctrl_esc_term         = ko_make_basic(MOD_MASK_CTRL, KC_ESC, C(KC_GRV));
const key_override_t gui_esc_cycle         = ko_make_basic(MOD_MASK_GUI, KC_ESC, G(KC_GRV));
const key_override_t shift_backspace_sleep = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_SLEP);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &ctrl_esc_term, &gui_esc_cycle, &shift_backspace_sleep,
    NULL // Null terminate the array of overrides!
};

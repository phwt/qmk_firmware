/* Copyright 2018 MechMerlin
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
enum custom_keycodes { M_CONST = SAFE_RANGE, M_VAR, M_DOTNET };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // clang-format off
    [0] = LAYOUT_ortho_5x15(
        KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCOLON, KC_LBRC, KC_RBRC, KC_DEL, KC_BSLS,
        KC_BSPC, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_ENT, KC_TRANSPARENT, KC_HOME,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_TRANSPARENT, KC_UP, KC_END,
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_SPC, MO(2), MO(1), MO(2), KC_SPC, KC_SPC, TG(3), KC_LEFT, KC_DOWN, KC_RGHT
    )
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_CONST:
            if (record->event.pressed) {
                SEND_STRING("const");
            } else {
            }
            return false;
        case M_VAR:
            if (record->event.pressed) {
                SEND_STRING("var");
            } else {
            }
            return false;
        case M_DOTNET:
            if (record->event.pressed) {
                SEND_STRING("dotnet");
            } else {
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

enum combos {
    C_N_T_M_CONST,
    V_R_M_VAR,
    D_N_T_M_DOTNET,
};

const uint16_t PROGMEM c_n_t_m_const[]  = {KC_C, KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM v_r_m_var[]      = {KC_V, KC_R, COMBO_END};
const uint16_t PROGMEM d_n_t_m_dotnet[] = {KC_D, KC_N, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [C_N_T_M_CONST]  = COMBO(c_n_t_m_const, M_CONST),
    [V_R_M_VAR]      = COMBO(v_r_m_var, M_VAR),
    [D_N_T_M_DOTNET] = COMBO(d_n_t_m_dotnet, M_DOTNET),
};
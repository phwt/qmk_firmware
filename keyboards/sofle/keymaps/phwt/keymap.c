#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _COLEMAK,
    _WINDOWS,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE, //
    COLEMAK,
    TOGOS
};

#define LOWER OSL(_LOWER)
#define RAISE OSL(_RAISE)
#define ADJUST MO(_ADJUST)

#define TH_BSPC LT(0, KC_BSPC) // Hold for Alt + Backspace
#define TH_LEFT LT(0, KC_LEFT) // Hold for Home
#define TH_RGHT LT(0, KC_RGHT) // Hold for End
#define TH_UP LT(0, KC_UP)     // Hold for Page Up
#define TH_DOWN LT(0, KC_DOWN) // Hold for Page Down
#define TH_LOCK LT(0, KC_ESC)  // Hold to lock

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_QWERTY] = LAYOUT(
        TH_LOCK, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TH_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
        TH_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY,    XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  LOWER,        RAISE, KC_ENT,  KC_RGUI, KC_LBRC, KC_RBRC
    ),
    [_COLEMAK] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
        _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,    _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                          _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),
    [_WINDOWS] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                          _______, KC_LGUI, KC_LALT, _______, _______,    _______, _______, _______, _______, _______
    ),
    [_LOWER] = LAYOUT(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,                      _______, _______, _______, _______, _______, _______,
        KC_CAPS, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
        KC_GRV,  _______, _______, _______, _______, _______,                      _______, _______, _______, KC_MINS, KC_EQL,  KC_DEL,
        KC_TILD, _______, _______, _______, _______, _______,                      _______, _______, KC_UP,   KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_CIRC, _______, _______, C(KC_F), C(KC_J),                      _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,  KC_QUOT,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, ADJUST,     _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
        RESET,   _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, TOGOS,   QWERTY,  COLEMAK, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, XXXXXXX,    XXXXXXX, _______, _______, _______, _______
    )
    // clang-format on
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWERTY"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Colemak"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case TOGOS:
            if (record->event.pressed) layer_invert(_WINDOWS);
            return false;
        case TH_BSPC:
            if (record->event.pressed && !record->tap.count) {
                tap_code16(A(KC_BSPC));
                return false;
            }
            return true;
        case TH_LEFT:
            if (record->event.pressed && !record->tap.count) {
                tap_code(KC_HOME);
                return false;
            }
            return true;
        case TH_RGHT:
            if (record->event.pressed && !record->tap.count) {
                tap_code(KC_END);
                return false;
            }
            return true;
        case TH_UP:
            if (record->event.pressed && !record->tap.count) {
                tap_code(KC_PGUP);
                return false;
            }
            return true;
        case TH_DOWN:
            if (record->event.pressed && !record->tap.count) {
                tap_code(KC_PGDN);
                return false;
            }
            return true;
        case TH_LOCK:
            if (record->event.pressed && !record->tap.count) {
                if (IS_LAYER_ON(_WINDOWS)) {
                    tap_code(KC_SLEP);
                } else {
                    register_code(KC_LGUI);
                    register_code(KC_LCTRL);
                    register_code(KC_Q);
                    clear_keyboard();
                }
                return false;
            }
            return true;
    }
    return true;
}

const key_override_t ctrl_esc_term         = ko_make_basic(MOD_MASK_CTRL, KC_ESC, C(KC_GRV));
const key_override_t gui_esc_cycle         = ko_make_basic(MOD_MASK_GUI, KC_ESC, G(KC_GRV));
const key_override_t shift_backspace_sleep = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_SLEP);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &ctrl_esc_term, &gui_esc_cycle, &shift_backspace_sleep,
    NULL // Null terminate the array of overrides!
};

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

#endif

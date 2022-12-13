#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _COLEMAK,
    _WINDOWS,

    _SYM,
    _NUM,
    _ADJUST,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE, //
    COLEMAK,
    TOGOS,

    M_BHREG,
    M_ARRFN,
    M_TOGIM,
};

#define OS_SYM OSL(_SYM)
#define OS_NUM OSL(_NUM)
#define TO_DEF TO(_QWERTY)
#define ADJUST MO(_ADJUST)

#define TH_BSPC LT(0, KC_BSPC) // Hold for Alt + Backspace
#define TH_LEFT LT(0, KC_LEFT) // Hold for Home
#define TH_RGHT LT(0, KC_RGHT) // Hold for End
#define TH_ESC LT(0, KC_ESC)   // Hold for Alt
#define TH_LOCK LT(0, KC_GRV)  // Hold to lock
#define TH_ENT LT(0, KC_ENT)   // Hold for Spotlight

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_QWERTY] = LAYOUT(
        TH_LOCK, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TH_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
        TH_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY,    XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_LALT,     OS_SYM, TH_ENT,  KC_RGUI, XXXXXXX, XXXXXXX
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
                          _______, _______, KC_LCTL, _______, KC_LGUI,    _______, _______, _______, _______, _______
    ),
    [_SYM] = LAYOUT(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        KC_LALT, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_PLUS,                      KC_UNDS, KC_LEFT, KC_UP,   KC_RGHT, KC_LBRC, KC_RBRC,
        _______, _______, _______, KC_LPRN, KC_RPRN, KC_MINS, _______,    _______, KC_EQL,  _______, KC_DOWN, _______, KC_MINS, KC_EQL,
                          _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),
    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST,                      _______, _______, KC_UP,   _______, M_ARRFN, _______,
        _______, KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_PSLS,                      _______, KC_LEFT, KC_DOWN, KC_RGHT, M_TOGIM, M_BHREG,
        _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PEQL, _______,    _______, _______, _______, _______, _______, _______, _______,
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
    static const char PROGMEM logo[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0,  0, 0, 0, 0, 240, 240, 240, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0,  0,   0,   0,   0,  0, 0,  0,   0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 224, 224, 224, 0,   0,   0,   0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  254, 254, 254, 124, 14, 14, 6, 14, 30, 254, 252, 248, 0, 0, 0, 0, 255, 255, 255, 14, 14, 6, 14, 30, 254, 252, 248, 0, 0, 62, 254, 254, 224, 0, 0, 224, 224, 224, 128, 0, 192, 252, 254, 126, 2, 0, 14, 14, 14, 255, 255, 255, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 124, 240, 224, 224, 224, 248, 127, 63, 31, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 3, 63, 255, 252, 255, 31, 3, 15, 255, 248, 255, 127, 7, 0, 0, 0, 0, 0, 0, 31,  127, 127, 240, 224, 224, 224, 224, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31,  31,  0,   0,   0,  0,  0, 0,  0,  0,   0,   0,   0, 0, 0, 0, 0,   0,   0,   0,  0,  0, 0,  0,  0,   0,   0,   0, 0, 0,  0,   0,   0,   0, 0, 0,   0,   0,   0,   0, 0,   0,   0,   0,   0, 0, 0,  0,  0,  0,   0,   0,   0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    oled_write_raw_P(logo, sizeof(logo));
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    if (IS_LAYER_ON(_WINDOWS)) {
        oled_write_ln_P(PSTR("M > W"), false);
    } else {
        oled_write_ln_P(PSTR("M < W"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Q < C"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("Q > C"), false);
            break;
        default:
            oled_write_P(PSTR("UNDEF"), false);
    }
    oled_write_P(PSTR("\n\n"), false);

    // Print current layer
    int highest_layer = get_highest_layer(layer_state);
    (highest_layer == _COLEMAK || highest_layer == _QWERTY) ? oled_write_P(PSTR(">"), false) : oled_write_P(PSTR(" "), false);
    oled_write_ln_P(PSTR("BSE"), false);

    (highest_layer == _SYM) ? oled_write_P(PSTR(">"), false) : oled_write_P(PSTR(" "), false);
    oled_write_ln_P(PSTR("SYM"), false);

    (highest_layer == _NUM) ? oled_write_P(PSTR(">"), false) : oled_write_P(PSTR(" "), false);
    oled_write_ln_P(PSTR("NUM"), false);

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

int knob_pressed           = 0;
int knob_action_brightness = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MPLY:
            if (record->event.pressed) {
                knob_pressed = 1;
                return false;
            } else {
                knob_pressed = 0;
                if (knob_action_brightness) {
                    knob_action_brightness = 0;
                } else {
                    tap_code(KC_MPLY);
                }
                return true;
            }
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
        case TH_ESC:
            if (record->event.pressed && !record->tap.count) {
                register_code(KC_LALT);
                return false;
            }
            clear_keyboard();
            return true;
        case TH_LOCK:
            if (record->event.pressed && !record->tap.count) {
                if (IS_LAYER_ON(_WINDOWS)) {
                    tap_code(KC_SLEP);
                } else {
                    tap_code16(G(C(KC_Q)));
                }
                return false;
            }
            return true;
        case TH_ENT:
            if (record->event.pressed && !record->tap.count) {
                register_code(KC_LGUI);
                tap_code(KC_SPC);
                clear_keyboard();
                return false;
            }
            clear_keyboard();
            return true;
        case M_BHREG:
            if (record->event.pressed) {
                send_string("\"_");
            }
            return false;
        case M_ARRFN:
            if (record->event.pressed) {
                send_string("=> {}");
                tap_code(KC_LEFT);
            }
            return false;
        case M_TOGIM:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_L);
                tap_code(KC_H);
                clear_keyboard();
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (knob_pressed) {
            knob_action_brightness = 1;
            (clockwise) ? tap_code(KC_BRIU) : tap_code(KC_BRID);
        } else {
            (clockwise) ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
        }
    }
    return true;
}

#endif

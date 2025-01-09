#include QMK_KEYBOARD_H

enum custom_keycodes {
    CK_GESC = SAFE_RANGE // send grave key if pressed with any modifier held down, send escape otherwise
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi(
        CK_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRV,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_MUTE,
        KC_LCTL,        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_VOLU,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_VOLD,
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_65_ansi(
        QK_GESC,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_HOME,
        _______,        RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR, KC_SCRL, KC_PAUS, QK_BOOT, KC_PGUP,
        KC_LCTL,        RGB_SPI, RGB_SPD, _______, KC_FIND, _______, _______, _______, _______, _______, _______, _______,          EE_CLR,  KC_PGDN,
        KC_LSFT,                 _______, KC_CUT,  KC_COPY, KC_PSTE, _______, NK_TOGG, _______, _______, _______, _______, _______, KC_VOLU, KC_END,
        _______,        _______, _______,                            _______,                   _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    )
};
// clang-format on

const uint8_t ANY_MOD_MASK = MOD_MASK_CSAG;

bool any_mod_held_down(void) {
    return (get_mods() & ANY_MOD_MASK) | (get_oneshot_mods() & ANY_MOD_MASK);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_GESC:
            if (record->event.pressed) {
                if (any_mod_held_down()) {
                    SEND_STRING(SS_TAP(X_GRAVE));
                } else {
                    SEND_STRING(SS_TAP(X_ESCAPE));
                }
            }
            break;
    }
    return true;
}

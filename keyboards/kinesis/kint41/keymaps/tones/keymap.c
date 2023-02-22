#include QMK_KEYBOARD_H

enum layers { L_, L_SC2, L_FN };
enum custom_keycodes {
    DITTO = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_HOME, KC_1, KC_2, KC_3, KC_4, KC_5,
        KC_PGUP, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,
         KC_EQL, KC_A, KC_O, KC_E, KC_U, KC_I,
        KC_GRV, KC_SCLN, KC_Q, KC_J, KC_K, KC_X,
                 KC_LEFT, KC_SLSH, KC_LBRC, KC_LPRN,
        KC_UNDS, OSL(L_FN),
        KC_LGUI,
        KC_LCTL, KC_LSFT, KC_LALT,

          RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_END,
           KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_PGDN,
           KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_MINS,
           KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,  KC_TAB,
        KC_RPRN, KC_RBRC, KC_BSLS, KC_RGHT,
          KC_UP, KC_DOWN,
        KC_BSPC,
        KC_ESC, KC_SPC, KC_ENT
    ),
    [L_SC2] = LAYOUT(
         KC_ESC, _______, _______, _______,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
        _______, _______, _______, _______, _______,  KC_ESC,
        _______, _______,    KC_C,    KC_D, _______, _______,
           KC_L, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_9,
          KC_5,   KC_6,
        KC_LSFT,
          DITTO, KC_LCTL, KC_LALT,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        OSL(L_FN), _______,
        KC_LGUI,
        _______, _______, _______
    ),
    [L_FN] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
        XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MSTP, XXXXXXX,
        XXXXXXX, TG(L_SC2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______,
        _______,
        _______, _______, _______,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
          KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
        XXXXXXX, KC_PSCR, XXXXXXX, KC_PAUS, XXXXXXX,  KC_F12,
        XXXXXXX,  KC_INS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,  KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
          RESET, XXXXXXX,
        XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

uint16_t key = KC_NO;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case DITTO:
            register_code16(key);
            return false;
        case KC_3:
            key = KC_F3;
            break;
        case KC_2:
            key = KC_F2;
            break;
        case KC_1:
            key = KC_F1;
            break;
        case KC_LSFT:
        case KC_RSFT:
        case KC_LALT:
        case KC_RALT:
        case KC_LGUI:
        case KC_RGUI:
        case KC_LCTL:
        case KC_RCTL:
            break;
        default:
            key = keycode;
            break;
        }
    } else {
        if (keycode == DITTO) {
            unregister_code16(key);
            return false;
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    writePin(LED0, !layer_state_cmp(state, L_SC2));
    writePin(LED1, !layer_state_cmp(state, L_FN));
    return state;
}

void keyboard_post_init_user(void) {
    setPinOutput(LED0);
    setPinOutput(LED1);
    setPinOutput(LED2);
    setPinOutput(LED3);

    writePinHigh(LED2);
    writePinHigh(LED3);
}

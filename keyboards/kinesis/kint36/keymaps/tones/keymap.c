#include QMK_KEYBOARD_H

enum layers { L_, L_SC2, L_FPS, L_SV, L_FN };
enum custom_keycodes {
    DITTO = SAFE_RANGE,
    ENTER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_] = LAYOUT(
         KC_ESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,
         KC_INS,  KC_1,     KC_2,     KC_3,     KC_4,   KC_5,
        KC_HOME,  KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,   KC_Y,
         KC_TAB,  KC_A,     KC_O,     KC_E,     KC_U,   KC_I,
         KC_EQL,  KC_SCLN,  KC_Q,     KC_J,     KC_K,   KC_X,
                  KC_UP,    KC_LEFT,  KC_DOWN,  KC_RGHT,
        KC_PGDN,  KC_PGUP,
        KC_LCTL,
        KC_MINS,  KC_LSFT,  KC_LALT,

        KC_F9,     KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_F,      KC_G,    KC_C,    KC_R,    KC_L,    KC_END,
        KC_D,      KC_H,    KC_T,    KC_N,    KC_S,    KC_ESC,
        KC_B,      KC_M,    KC_W,    KC_V,    KC_Z,    KC_GRV,
                   KC_LBRC, KC_RBRC, KC_BSLS, KC_SLSH,
        OSL(L_FN), KC_UNDS,
        KC_BSPC,
        KC_LGUI,   KC_SPC,  ENTER
    ),
    [L_SC2] = LAYOUT(
         KC_F11, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,  KC_ESC,
        _______, _______,    KC_C,    KC_D, _______, _______,
        _______, _______, _______, _______, _______, _______,
           KC_L, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,
        _______, _______,
        KC_LSFT,
          DITTO, KC_LCTL, KC_LALT,

        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______
    ),
    [L_FPS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
         KC_ESC,    KC_0,    KC_9,    KC_8,    KC_7,    KC_6,
         KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_LCTL,  KC_TAB,    KC_A,    KC_W,    KC_D,    KC_R,
        KC_LSFT,    KC_Z,    KC_Q,    KC_S,    KC_E,    KC_F,
                    KC_X,    KC_Y,    KC_G,    KC_T,
                    KC_C,    KC_V,
                             KC_B,
        KC_LALT,  KC_SPC,    KC_M,

        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______
    ),
    [L_SV] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, KC_RSFT, _______, _______, _______, _______,
                 _______, _______, _______, _______,
                 _______, _______,
                             KC_R,
        _______,  KC_DEL, _______,

        _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______
    ),
    [L_FN] = LAYOUT(
        XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,   KC_MPRV,   KC_MNXT,  KC_MSTP, XXXXXXX,
        XXXXXXX, TG(L_SC2), TG(L_FPS), TG(L_SV), XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,   KC_MUTE,   KC_VOLD,  KC_VOLU, XXXXXXX,
                 XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,
        _______, _______,
        _______,
        _______, _______, _______,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,
        XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),
    /*
    [L_SC] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
          KC_F3,   KC_F2,   KC_F3,   KC_F4,    KC_M,  KC_ESC,
          KC_F4,    KC_2,    KC_4, _______, _______, _______,
           KC_1,    KC_3,    KC_6, _______, _______, _______,
           KC_5,    KC_7,    KC_8, _______, _______, _______,
                    KC_9,    KC_0, _______,    KC_H,
        KC_MINS, _______,
        KC_LSFT,
          DITTO, KC_LCTL, KC_LALT,

        _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        KC_LGUI, _______,
        _______,
        _______, _______,  KC_ENT
    ),
    [L_BLANK] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______,

        _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______
    ),
    */
};

uint16_t key = KC_NO;
bool back_to_fps = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case DITTO:
            register_code16(key);
            return false;
        case ENTER:
            if (IS_LAYER_ON(L_FPS)) {
                back_to_fps = true;
                layer_off(L_FPS);
            } else if (back_to_fps) {
                layer_on(L_FPS);
                back_to_fps = false;
            }
            register_code16(KC_ENT);
            return false;
        case KC_F4:
            key = KC_F3;
            break;
        case KC_F3:
            key = KC_F2;
            break;
        case KC_F2:
            key = KC_F1;
            break;
        case KC_F5:
            key = KC_F6;
            break;
        case KC_F6:
            key = KC_F7;
            break;
        case KC_F7:
            key = KC_F8;
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
        switch (keycode) {
        case DITTO:
            unregister_code16(key);
            return false;
        case ENTER:
            unregister_code16(KC_ENT);
            return false;
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    writePin(LED0, !layer_state_cmp(state, L_SC2));
    writePin(LED1, !layer_state_cmp(state, L_FPS));
    writePin(LED2, !layer_state_cmp(state, L_SV));
    writePin(LED3, !layer_state_cmp(state, L_FN));
    return state;
}

void keyboard_post_init_user(void) {
}

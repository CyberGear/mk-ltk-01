/* Copyright 2021 REPLACE_WITH_YOUR_NAME
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

enum custom_keycodes {
    MFA = SAFE_RANGE,
    MFA_2,
    UTIL,
    UTIL_2,
    FLASH_2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
                                              KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,   KC_F6,   KC_F7,   KC_F8,      KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_PSCR,   UTIL,    MFA,
        KC_PMNS, KC_PAST, KC_PSLS, KC_NLCK,   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,            KC_INS,  KC_PGUP,
        KC_PPLS, KC_P7,    KC_P8,    KC_P9,   KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,        KC_DEL,  KC_PGDN,
                 KC_P4,    KC_P5,    KC_P6,   KC_LCTL,        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,               KC_HOME, KC_END,
        KC_PENT, KC_P1,    KC_P2,    KC_P3,   KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,
                 KC_PDOT,  KC_P0,             KC_LCTL,   KC_LGUI,   KC_LALT,                        KC_SPC,                             KC_RALT,   MO(1) ,     KC_RCTL,       KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
                                              RESET,     _______, _______, _______, _______,   _______, _______, _______, _______,    _______, _______, _______, _______,   _______,   UTIL_2,  MFA_2,
        _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______,
        _______, _______, _______, _______,   _______,     _______, _______, _______, FLASH_2, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______,
                 _______, _______, _______,   _______,        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______,
        _______, _______, _______, _______,   _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                    KC_AUDIO_VOL_UP,
                 _______, _______,            _______,   _______,   _______,                       _______,                             _______,   _______,   _______,        _______, KC_AUDIO_VOL_DOWN, _______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MFA:
            if (!record->event.pressed) {
                SEND_STRING_DELAY(SS_LALT("c"), 0);
                SEND_STRING_DELAY(SS_LCTL("v"), 200);
                SEND_STRING_DELAY(SS_TAP(X_ENTER), 50);
            }
            break;
        case MFA_2:
            if (!record->event.pressed) {
                SEND_STRING_DELAY(SS_LALT("c"), 0);
                SEND_STRING_DELAY(SS_LCTL(SS_LSFT("v")), 150);
                SEND_STRING_DELAY(SS_TAP(X_ENTER), 50);
            }
            break;
        case UTIL:
            if (!record->event.pressed) {
                SEND_STRING(SS_LGUI("e"));
            }
            break;
        case UTIL_2:
            if (!record->event.pressed) {
                SEND_STRING(SS_LGUI("t"));
            }
            break;
        case FLASH_2:
            if (!record->event.pressed) {
                SEND_STRING_DELAY(SS_LGUI("t"), 0);
                _delay_ms(500);
                SEND_STRING_DELAY("qmk flash -kb handwired/mkltk01 && exit", 0);
                SEND_STRING_DELAY(SS_TAP(X_ENTER), 50);
            }
            break;
    }
    return true;
};

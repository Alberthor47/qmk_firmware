/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// #include "keymap_spanish_latin_america.h"
#include QMK_KEYBOARD_H

// Custom keycodes definitions
// enum custom_keycodes {
//     ANGLE_BRACKET_LEFT = SAFE_RANGE,
//     ANGLE_BRACKET_RIGHT,
// };

// Tap dance definitions
enum {
    TD_CAPLOCK,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,  KC_COMM,  KC_DOT,  KC_SCLN,   KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,   KC_L,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                          KC_D,    KC_H,    KC_T,    KC_N,   KC_S,   KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  TD(TD_CAPLOCK),KC_LBRC,  KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,   KC_Z,  KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,  MO(1),  KC_LGUI,     KC_SPC,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_GRV, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX,                      A(KC_Q), KC_QUOT, KC_BSLS, KC_ASTR, KC_LPRN,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, A(KC_SCLN), KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, _______, KC_LGUI,     KC_SPC,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,   MO(3), KC_LGUI,     KC_SPC, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, _______, KC_LGUI,     KC_SPC, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case ANGLE_BRACKET_LEFT:
//             if (record->event.pressed) {
//                 SEND_STRING("<");
//             }
//             break;
//         case ANGLE_BRACKET_RIGHT:
//             if (record->event.pressed) {
//                 SEND_STRING(">");
//             }
//             break;
//     }
//     return true;
// };

bool rgb_matrix_indicators_user(void) {
    // CapsLock light
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(26, 255, 255, 255);
    }

    // White Back Light
    // L
    rgb_matrix_set_color(0, 255, 255, 255);
    rgb_matrix_set_color(1, 255, 255, 255);
    rgb_matrix_set_color(2, 255, 255, 255);
    rgb_matrix_set_color(3, 255, 255, 255);
    rgb_matrix_set_color(4, 255, 255, 255);
    rgb_matrix_set_color(5, 255, 255, 255);
    // R
    rgb_matrix_set_color(27, 255, 255, 255);
    rgb_matrix_set_color(28, 255, 255, 255);
    rgb_matrix_set_color(29, 255, 255, 255);
    rgb_matrix_set_color(30, 255, 255, 255);
    rgb_matrix_set_color(31, 255, 255, 255);
    rgb_matrix_set_color(32, 255, 255, 255);
    return false;
}


#ifdef OLED_ENABLE
    oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

    void render_space(void) {
        oled_write_P(PSTR("     "), false);
    }

    void render_mod_status_gui_alt(uint8_t modifiers) {
        static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
        static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
        static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
        static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

        static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
        static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
        static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
        static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

        // fillers between the modifier icons bleed into the icon frames
        static const char PROGMEM off_off_1[] = {0xc5, 0};
        static const char PROGMEM off_off_2[] = {0xc6, 0};
        static const char PROGMEM on_off_1[] = {0xc7, 0};
        static const char PROGMEM on_off_2[] = {0xc8, 0};
        static const char PROGMEM off_on_1[] = {0xc9, 0};
        static const char PROGMEM off_on_2[] = {0xca, 0};
        static const char PROGMEM on_on_1[] = {0xcb, 0};
        static const char PROGMEM on_on_2[] = {0xcc, 0};

        if(modifiers & MOD_MASK_GUI) {
            oled_write_P(gui_on_1, false);
        } else {
            oled_write_P(gui_off_1, false);
        }

        if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
            oled_write_P(on_on_1, false);
        } else if(modifiers & MOD_MASK_GUI) {
            oled_write_P(on_off_1, false);
        } else if(modifiers & MOD_MASK_ALT) {
            oled_write_P(off_on_1, false);
        } else {
            oled_write_P(off_off_1, false);
        }

        if(modifiers & MOD_MASK_ALT) {
            oled_write_P(alt_on_1, false);
        } else {
            oled_write_P(alt_off_1, false);
        }

        if(modifiers & MOD_MASK_GUI) {
            oled_write_P(gui_on_2, false);
        } else {
            oled_write_P(gui_off_2, false);
        }

        if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
            oled_write_P(on_on_2, false);
        } else if(modifiers & MOD_MASK_GUI) {
            oled_write_P(on_off_2, false);
        } else if(modifiers & MOD_MASK_ALT) {
            oled_write_P(off_on_2, false);
        } else {
            oled_write_P(off_off_2, false);
        }

        if(modifiers & MOD_MASK_ALT) {
            oled_write_P(alt_on_2, false);
        } else {
            oled_write_P(alt_off_2, false);
        }
    }

    void render_mod_status_ctrl_shift(uint8_t modifiers) {
        static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
        static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
        static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
        static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

        static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
        static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
        static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
        static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

        // fillers between the modifier icons bleed into the icon frames
        static const char PROGMEM off_off_1[] = {0xc5, 0};
        static const char PROGMEM off_off_2[] = {0xc6, 0};
        static const char PROGMEM on_off_1[] = {0xc7, 0};
        static const char PROGMEM on_off_2[] = {0xc8, 0};
        static const char PROGMEM off_on_1[] = {0xc9, 0};
        static const char PROGMEM off_on_2[] = {0xca, 0};
        static const char PROGMEM on_on_1[] = {0xcb, 0};
        static const char PROGMEM on_on_2[] = {0xcc, 0};

        if(modifiers & MOD_MASK_CTRL) {
            oled_write_P(ctrl_on_1, false);
        } else {
            oled_write_P(ctrl_off_1, false);
        }

        if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
            oled_write_P(on_on_1, false);
        } else if(modifiers & MOD_MASK_CTRL) {
            oled_write_P(on_off_1, false);
        } else if(modifiers & MOD_MASK_SHIFT) {
            oled_write_P(off_on_1, false);
        } else {
            oled_write_P(off_off_1, false);
        }

        if(modifiers & MOD_MASK_SHIFT) {
            oled_write_P(shift_on_1, false);
        } else {
            oled_write_P(shift_off_1, false);
        }

        if(modifiers & MOD_MASK_CTRL) {
            oled_write_P(ctrl_on_2, false);
        } else {
            oled_write_P(ctrl_off_2, false);
        }

        if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
            oled_write_P(on_on_2, false);
        } else if(modifiers & MOD_MASK_CTRL) {
            oled_write_P(on_off_2, false);
        } else if(modifiers & MOD_MASK_SHIFT) {
            oled_write_P(off_on_2, false);
        } else {
            oled_write_P(off_off_2, false);
        }

        if(modifiers & MOD_MASK_SHIFT) {
            oled_write_P(shift_on_2, false);
        } else {
            oled_write_P(shift_off_2, false);
        }
    }

    void render_logo(void) {
        static const char PROGMEM corne_logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84,
            0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
            0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
        oled_write_P(PSTR("     "), false);
        oled_write_P(corne_logo, false);
        oled_write_P(PSTR("     "), false);
        oled_write_P(PSTR("BE GO"), false);
    }

    void render_layer_state(void) {
        static const char PROGMEM default_layer[] = {
            0x20, 0x94, 0x95, 0x96, 0x20,
            0x20, 0xb4, 0xb5, 0xb6, 0x20,
            0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
        static const char PROGMEM raise_layer[] = {
            0x20, 0x97, 0x98, 0x99, 0x20,
            0x20, 0xb7, 0xb8, 0xb9, 0x20,
            0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
        static const char PROGMEM lower_layer[] = {
            0x20, 0x9a, 0x9b, 0x9c, 0x20,
            0x20, 0xba, 0xbb, 0xbc, 0x20,
            0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
        static const char PROGMEM adjust_layer[] = {
            0x20, 0x9d, 0x9e, 0x9f, 0x20,
            0x20, 0xbd, 0xbe, 0xbf, 0x20,
            0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
        if(layer_state_is(3)) {
            oled_write_P(adjust_layer, false);
        } else if(layer_state_is(2)) {
            oled_write_P(lower_layer, false);
        } else if(layer_state_is(1)) {
            oled_write_P(raise_layer, false);
        } else {
            oled_write_P(default_layer, false);
        }
    }

    bool oled_task_user(void) {
        render_logo();
        render_space();
        render_layer_state();
        render_space();
        render_mod_status_gui_alt(get_mods());
        render_mod_status_ctrl_shift(get_mods());
        return false;
    }

#endif

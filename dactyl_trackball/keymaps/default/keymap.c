// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    MOD_LEFT,
    MOD_RIGHT,
    MOUSE,
    CALC,
    CODE,
    NORM
};

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

// Home row mods 
#define MD_A LT(MOD_LEFT, KC_A)  // 'A' when tapped, "mod" layer when held
#define MD_Æ LT(MOD_RIGHT, KC_SCLN)  // 'Æ' when tapped, "mod" layer when held

// Left
#define MD_S LALT_T(KC_S)  // 'S' when tapped, "alt" when held
#define MD_D LSFT_T(KC_D)  // 'D' when tapped, "shit" when held
#define MD_F LCTL_T(KC_F)  // 'F' when held, "control" when held

// Right
#define MD_J RCTL_T(KC_J)  // 'J' when tapped, "alt" when held
#define MD_K RSFT_T(KC_K)  // 'K' when tapped, "shit" when held
#define MD_L RALT_T(KC_L)  // 'L' when held, "control" when held


// KC_TRNS - for transparent key
#define _______ KC_TRNS
// KC_NO - for no key
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // [BASE] = LAYOUT(
    //     KC_ESC,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                                         KC_6, KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,
    //     KC_TAB,  KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,                                         KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC,
    //     KC_CAPS, KC_A,    KC_S,   KC_D,    KC_F,    KC_G,                                         KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    //     KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,                                         KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    //              KC_EQL, KC_NUBSS, TO(CALC), TO(PROG),                                                     TO(GAME), TO(BASE), KC_NUHS, KC_RBRC,
    //                                                       KC_RCTL, KC_LALT,    KC_RALT, KC_RCTL,
    //                                              KC_BSPC, KC_DEL,  KC_HOME,    KC_PGUP, KC_ENT, KC_SPC,
    //                                                                KC_END,     KC_PGDN  
    // ),
    //
    // +--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
    // |  ESC   |   1    |   2    |   3    |   4    |   5    |                          |   6    |   7    |   8    |   9    |   0    |  MINS  |
    // +--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
    // |  TAB   |   Q    |   W    |   E    |   R    |   T    |                          |   Y    |   U    |   I    |   O    |   P    |  LBRC  |
    // +--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
    // |  CAPS  |   A    |   S    |   D    |   F    |   G    |                          |   H    |   J    |   K    |   L    |  SCLN  |  QUOT  |
    // +--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
    // |  LSFT  |   Z    |   X    |   C    |   V    |   B    |                          |   N    |   M    |  COMM  |  DOT   |  SLSH  |  RSFT  |
    // +--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
    //          |  EQL   | NUBSS  |TO(CALC)|TO(PROG)|                                            |TO(NORM)|TO(CODE)|  NUHS  |  RBRC  |
    //          +--------+--------+--------+--------+                                            +--------+--------+--------+--------+
    //
    //                                              +--------+--------+        +--------+--------+
    //                                              |  LCTL  |  LALT  |        |  RALT  |  RCTL  |
    //                                     +--------+--------+--------+        +--------+--------+--------+
    //                                     |        |        |  HOME  |        |  PGUP  |        |        |
    //                                     |  BSPC  |  DEL   +--------+        +--------+  ENT   |  SPC   |
    //                                     |        |        |  END   |        |  PGDN  |        |        |
    //                                     +--------+--------+--------+        +--------+--------+--------+
    //

    [BASE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,       KC_8,       KC_9,       KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,       KC_I,       KC_O,       KC_P,    KC_LBRC,
        KC_CAPS, MD_A,    MD_S,   MD_D,    MD_F,    KC_G,                                         KC_H,    MD_J,       MD_K,       MD_L,       MD_Æ,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,                                         KC_N,    KC_M,       KC_COMM,    KC_DOT,     KC_SLSH, KC_RSFT,
                 KC_EQL, KC_NUBS, TO(CALC), TO(MOUSE),                                                     TT(NORM),   TO(CODE),   KC_NUHS,    KC_RBRC,
        KC_END,  KC_DEL, KC_BSPC, KC_HOME, KC_LALT, KC_LCTL,                                      KC_RCTL, KC_RALT,    KC_PGUP,    KC_SPC,     KC_ENT,  KC_PGDN
    ),

    [MOD_LEFT] = LAYOUT(
        KC_NO,      KC_F1,   KC_F2,     KC_F3,      KC_F4,   KC_F5,                                         KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10, KC_F11,
        KC_NO,      KC_NO,   KC_NO,     KC_NO,      KC_NO,   KC_NO,                                         KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_F12,
        KC_NO,      KC_NO,   _______,   _______,    _______, KC_NO,                                         KC_LEFT, KC_UP,   KC_DOWN,  KC_RGHT, KC_NO,  KC_NO,
        KC_NO,      KC_NO,   KC_NO,     KC_NO,      KC_NO,   KC_NO,                                         KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_NO,
                    KC_NO,   KC_NO,     KC_NO,      KC_NO,                                                           KC_NO,   KC_NO,    KC_NO,   KC_NO,
        MS_BTN4,    MS_BTN2, MS_BTN1,   MS_BTN5, LM(BASE, MOD_LGUI), DRAG_SCROLL,                           KC_NO,   KC_NO,   KC_NO,    KC_TAB,  KC_NO,  KC_NO
    ),

    [MOD_RIGHT] = LAYOUT(
        KC_NO,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                         KC_F6,   KC_F7,      KC_F8,      KC_F9,      KC_F10, KC_F11,
        KC_NO,      KC_VOLU, KC_NO,   KC_NO,   KC_BRIU, KC_NO,                                         KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,  KC_F12,
        KC_NO,      KC_VOLD, KC_MPLY, KC_MNXT, KC_BRID, KC_NO,                                         KC_NO,   _______,    _______,    _______,    KC_NO,  KC_NO,
        KC_NO,      KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,                                         KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,  KC_NO,
                    KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                           KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,   KC_NO,   KC_NO,   LM(BASE, MOD_LGUI), KC_NO,                              KC_NO,   KC_NO,      KC_NO,      KC_TAB,     KC_NO,  KC_NO
    ),

    [MOUSE] = LAYOUT(
        KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,                                         KC_NO,         KC_NO,   KC_NO,    KC_NO,   KC_NO, KC_NO,
        KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,                                         KC_NO,         KC_NO,   KC_NO,    KC_NO,   KC_NO, KC_NO,
        KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,                                         KC_NO,         KC_NO,   KC_NO,    KC_NO,   KC_NO, KC_NO,
        KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,                                         KC_NO,         KC_NO,   KC_NO,    KC_NO,   KC_NO, KC_NO,
                    KC_NO,   KC_NO,   KC_NO,   TO(BASE),                                                                    KC_NO,   KC_NO,    KC_NO,   KC_NO,
        MS_BTN4,    MS_BTN2, MS_BTN1, MS_BTN5, KC_NO,         DRAG_SCROLL,                                   MS_BTN1,   DRAG_SCROLL,   MS_BTN5,    MS_BTN2, MS_BTN1, MS_BTN4
    ),

    [CALC] = LAYOUT(
        QK_BOOT,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                         KC_PSLS, KC_P7,    KC_P8,    KC_P9,      KC_PMNS,    KC_NO,
        KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                         KC_PAST, KC_P4,    KC_P5,    KC_P6,      KC_PPLS,    KC_NO,
        KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                         KC_NO,   KC_P1,    KC_P2,    KC_P3,      KC_PENT,    KC_NO,
        KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                         KC_NO,   KC_NO,    KC_P0,    KC_PCMM,    KC_NO,      KC_NO,
                    KC_NO,   KC_NO,   TO(BASE),KC_NO,                                                           KC_NO,    KC_NO,    KC_NO,      KC_NO,
        KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                         KC_NO,   KC_NO,    KC_NO,    KC_NO,      KC_NO,      KC_NO
    ),

    [CODE] = LAYOUT(
        KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                         KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,   QK_BOOT,
        KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                         KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,   KC_NO,
        KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                         KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,   KC_NO,
        KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                         KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,   KC_NO,
                    KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                           KC_NO,      TO(BASE),    KC_NO,   KC_NO,
        KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                         KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,   KC_NO
    ),

    [NORM] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,     KC_7,    KC_8,      KC_9,       KC_0,       KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,     KC_U,    KC_I,      KC_O,       KC_P,       KC_LBRC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                         KC_H,     KC_J,    KC_K,      KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                         KC_N,     KC_M,    KC_COMM,   KC_DOT,     KC_SLSH,    KC_RSFT,
                 KC_EQL,  KC_NUBS, MS_BTN6, MS_BTN7,                                                         TO(BASE),MO(MOD_LEFT),     KC_NUHS,    KC_RBRC,
        KC_END,  KC_DEL,  KC_BSPC, KC_HOME, KC_LALT, KC_RCTL,                                      KC_RCTL,  KC_RALT, KC_PGUP, KC_SPC,    KC_ENT,     KC_PGDN
    )
};


// Trackball
#define SCROLL_DIVISOR_H 32.0
#define SCROLL_DIVISOR_V 32.0
static float scroll_accumulated_h = 0;
static float scroll_accumulated_v = 0;

// Keyboard
#define DRAG_SCROLL_DELAY 200  // Time in ms to determine tap vs ho
uint8_t mod_state;
bool set_scrolling = false;
static uint16_t drag_scroll_timer = 0;


report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v -= (float)mouse_report.y / SCROLL_DIVISOR_V;

        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Keep the remainder for next time
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the x/y movement since we're scrolling
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();

    switch (keycode) {
        case KC_ESC:
        {
            static bool KC_GRV_registered;
            static bool S_KC_GRV_registered;

            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {   // For ½
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_GRV);
                    KC_GRV_registered = true;
                    set_mods(mod_state);
                    return false;
                } 
                else if (mod_state & MOD_MASK_CTRL) {   // For §
                    del_mods(MOD_MASK_CTRL);
                    register_code(KC_LSFT);
                    register_code(KC_GRV);
                    S_KC_GRV_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (KC_GRV_registered) {
                    unregister_code(KC_GRV);
                    KC_GRV_registered = false;
                    return false;
                } 
                else if (S_KC_GRV_registered) {
                    unregister_code(KC_GRV);      // Unregister in reverse order
                    unregister_code(KC_LSFT);
                    S_KC_GRV_registered = false;
                    return false;
                }
            }
            return true;
        }
        case DRAG_SCROLL:
        {
            if (record->event.pressed) {
                drag_scroll_timer = timer_read();
                set_scrolling = true;  // Enable scroll immediately on press
            } else {
                set_scrolling = false;  // Disable scroll on release
                if (timer_elapsed(drag_scroll_timer) < DRAG_SCROLL_DELAY) {
                    // If released quickly, send MB3
                    tap_code(KC_BTN3);
                }
            }
            return false;
        }

    }

    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) != MOD_LEFT || MOUSE) {
        set_scrolling = false;
        scroll_accumulated_h = 0;
        scroll_accumulated_v = 0;
    }
    return state;
};
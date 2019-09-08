#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

/*
 * To make:
 * make rgbkb/zen/rev1:ingrid
 */

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _FN,
    _ADJ
};

// Keycode defines for layers
#define QWERTY   DF(_QWERTY)
#define FN       MO(_FN)
#define ADJ      MO(_ADJ)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.             .-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |  `   |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | ADJ  |  FN  | Space| Enter||Bksp |Space |  FN  | Left | Down |  Up  |Right |
 * `------------------------------------------------''-----------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                        KC_6,     KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_GRAVE,KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,                        KC_Y,     KC_U,   KC_I,    KC_O,    KC_P,    KC_DEL, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                        KC_H,     KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,                        KC_N,     KC_M,   KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_ENT)  , \
  KC_LCTL, KC_LGUI, KC_LALT, ADJ,     FN,     KC_SPC, KC_ENT,   KC_BSPC,  LT(_FN, KC_SPC),   FN,      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT \
),

/* _FN
 * ,-----------------------------------------.             .-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      | PgUp |  {   |  }   |      |             |      | Home |  Up  |  End |      |  \   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      | PgDn |  (   |  )   |  +   |             |  -   | Left | Down |Right |      |  |   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |  [   |  ]   |  =   |             |  _   | PgDn |  <   |  >   | PgUp |      |
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      ||     |      |      |      |      |      |      |
 * `------------------------------------------------''-----------------------------------------------'
 */
[_FN] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  , \
  _______, _______, KC_PGUP, KC_LCBR, KC_RCBR, _______,                   _______, KC_HOME, KC_UP,   KC_END,  _______, KC_BSLS , \
  _______, _______, KC_PGDN, KC_LPRN, KC_RPRN, KC_PLUS,                   KC_MINS, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PIPE , \
  _______, _______, _______, KC_LBRC, KC_RBRC, KC_EQL,                    KC_UNDS, KC_PGDN, KC_LABK, KC_RABK, KC_PGUP, _______ , \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* _ADJ
 * ,-----------------------------------------.             .-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |RGB Tg|RGBAni|Hue Up|Sat Up|Val Up|             |      |      | Vol+ |      |PrtScr|Reset |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |RGBCol|Hue Dn|Sat Dn|Val Dn|             |      |      | Vol- |      |      | INS  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      | Play |      |      |      |
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      ||     |      |      |      |      |      |      |
 * `------------------------------------------------''-----------------------------------------------'
 */
[_ADJ] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7  , KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  , \
  _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,                   _______, _______, KC_VOLU, _______, KC_PSCR, RESET   , \
  _______, _______, RGB_M_P, RGB_HUD, RGB_SAD, RGB_VAD,                   _______, _______, KC_VOLD, _______, _______, KC_INS , \
  _______, _______, _______, _______, _______, _______,                   _______, _______, KC_MPLY, _______, _______, _______ , \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)

};

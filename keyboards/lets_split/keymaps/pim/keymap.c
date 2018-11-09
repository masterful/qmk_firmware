#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layout:
 *                                                       row-col
 * ,-----------------------------------------.                             ,-----------------------------------------.
 * | 0--0 | 0--1 | 0--2 | 0--3 | 0--4 | 0--5 |                             | 0--8 | 0--9 | 0--a | 0--b | 0--c | 0--d |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | 1--0 | 1--1 | 1--2 | 1--3 | 1--4 | 1--5 |                             | 1--8 | 1--9 | 1--a | 1--b | 1--c | 1--d |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | 2--0 | 2--1 | 2--2 | 2--3 | 2--4 | 2--5 |                             | 2--8 | 2--9 | 2--a | 2--b | 2--c | 2--d |
 * |------+------+------+------+------+------+-------------. ,-------------+------+------+------+------+------+------|
 * | 3--0 | 3--1 | 3--2 | 3--3 | 3--4 | 3--5 | 4--5 | 0--6 | | 0--7 | 4--8 | 3--8 | 3--9 | 3--a | 3--b | 3--c | 3--d |
 * |------+------+------+------+------+------+------+------| |------+------+------+------+------+------+------+------|
 * | 4--0 | 4--1 | 4--2 | 4--3 | 4--4 |      |      | 1--6 | | 1--7 |      |      | 4--9 | 4--a | 4--b | 4--c | 4--d |
 * `----------------------------------| 4--6 | 3--6 |------| |------| 3--7 | 4--7 |----------------------------------'
 *                                    |      |      | 2--6 | | 2--7 |      |      |
 *                                    `--------------------' `--------------------'
 */


/* Qwerty
 * ,-----------------------------------------.                             ,-----------------------------------------.
 * |  `   |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  0   |  \   |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   |                             |  Y   |  U   |  I   |  O   |  P   | Bksp |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | Esc  |  A   |  S   |  D   |  F   |  G   |                             |  H   |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------+-------------. ,-------------+------+------+------+------+------+------|
 * | Shft |  Z   |  X   |  C   |  V   |  B   |  [   | Left | |  Up  |  ]   |  N   |  M   |  ,   |  .   |  /   | Shft |
 * |------+------+------+------+------+------+------+------| |------+------+------+------+------+------+------+------|
 * | Ctrl | Adj  | Lowr | Rais | Alt  |      |      | Rght | | Down |      |      | GUI  | Rais | Lowr | Ctrl | Adj  |
 * `----------------------------------| GUI  | Entr |------| |------| Entr | Spce |----------------------------------'
 *                                    |      |      |  -   | |  =   |      |      |
 *                                    `--------------------' `--------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT, KC_UP,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_RGHT, KC_DOWN, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS, KC_EQL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_LCTL, ADJUST,  LOWER,   RAISE,   KC_LALT, KC_LBRC, KC_LGUI, KC_SPC,  KC_RBRC, KC_RGUI, RAISE,   LOWER,   KC_RCTL, ADJUST \
),

/* Lower
 * ,-----------------------------------------.                             ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                             |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                             | N-LK |  7   |  8   |  9   | Bksp | Del  |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |                             |      |  4   |  5   |  6   |  \   | Isrt |
 * |------+------+------+------+------+------+-------------. ,-------------+------+------+------+------+------+------|
 * | Shft |      |      |      |      |      |      |      | | PgUp |      |      |  1   |  2   |  3   |      | Shft |
 * |------+------+------+------+------+------+------+------| |------+------+------+------+------+------+------+------|
 * | Ctrl | Adj  | Lowr | Rais | Alt  |      |      |      | | PgDn |      |      |  0   |      |  .   |      | Adj  |
 * `----------------------------------| GUI  | Spce |------| |------| Entr | Spce |----------------------------------'
 *                                    |      |      |      | |      |      |      |
 *                                    `--------------------' `--------------------'
 */
[_LOWER] = KEYMAP( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_PGUP, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_NLCK, KC_KP_7, KC_KP_8, KC_KP_9, KC_BSPC, KC_DEL, \
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_BSLS, KC_INS, \
  KC_LSFT, _______, _______, _______, _______, _______, KC_SPC,  KC_ENT,  _______, KC_KP_1, KC_KP_2, KC_KP_3, _______, KC_RSFT, \
  KC_LCTL, ADJUST,  LOWER,   RAISE,   KC_LALT, _______, KC_LGUI, KC_SPC,  _______, KC_KP_0, _______, KC_PDOT, _______, ADJUST \
),

/* Raise
 * ,-----------------------------------------.                             ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                             |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * |      |      |      |      |  \   |   6  |                             |      | PgDn | PgUp |      |      | Bksp |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |                             | Left | Down | Up   | Rght |      |      |
 * |------+------+------+------+------+------+-------------. ,-------------+------+------+------+------+------+------|
 * | Shft |      |      |      |      |      |      |      | | PgUp |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------| |------+------+------+------+------+------+------+------|
 * | Ctrl | Adj  | Lowr | Rais | Alt  |      |      |      | | PgDn |      |      |      |      |      |      | Adj  |
 * `----------------------------------| GUI  | Spce |------| |------| Home | End  |----------------------------------'
 *                                    |      |      |      | |      |      |      |
 *                                    `--------------------' `--------------------'
 */
[_RAISE] = KEYMAP( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_PGUP, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, _______, _______, _______, KC_BSLS, KC_6,    _______, KC_PGDN, _______, KC_PGDN, KC_PGUP, _______, _______, KC_BSPC, \
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  KC_LSFT, _______, _______, _______, _______, _______, KC_SPC,  KC_HOME, _______, _______, _______, _______, _______, _______, \
  KC_LCTL, ADJUST,  LOWER,   RAISE,   KC_LALT, _______, KC_LGUI, KC_END,  _______, _______, _______, _______, _______, ADJUST \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.                             ,-----------------------------------------.
 * | Rset |      | Mute | Vol- | Vol+ |      |                             |      |      |      |      |      | Rset |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                             |      |      | M-up |      |      | Bksp |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * |      |      | |<<  | play |  >>| |      |                             |      | M-lf | M-dn | M-rg | M-a1 |      |
 * |------+------+------+------+------+------+-------------. ,-------------+------+------+------+------+------+------|
 * | Shft |      |      |      |      |      |      |      | | M-b3 | M-b4 | M-b5 | M-su | M-sd | M-sr | M-a0 |      |
 * |------+------+------+------+------+------+------+------| |------+------+------+------+------+------+------+------|
 * | Ctrl | Adj  | Lowr | Rais | Alt  |      |      |      | | M-wu |      |      |      |      |      |      | Adj  |
 * `----------------------------------| GUI  | Spce |------| |------| M-b1 | M-b2 |----------------------------------'
 *                                    |      |      |      | | M-wd |      |      |
 *                                    `--------------------' `--------------------'
 */
[_ADJUST] =  KEYMAP( \
  RESET,   _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_BTN3, _______, _______, _______, _______, _______, RESET, \
  _______, _______, _______, _______, _______, _______, _______, KC_WH_U, _______, _______, KC_MS_U, _______, _______, KC_BSPC, \
  _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_WH_D, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL1, _______, \
  KC_LSFT, _______, _______, _______, _______, _______, KC_SPC,  KC_BTN1, KC_BTN5, KC_SPDN, KC_SPUP, KC_SPRT, KC_ACL0, _______, \
  KC_LCTL, ADJUST,  LOWER,   RAISE,   KC_LALT, _______, KC_LGUI, KC_BTN2, KC_BTN4, _______, _______, _______, _______, ADJUST \
)

};


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

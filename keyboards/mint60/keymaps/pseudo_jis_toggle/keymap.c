/* Copyright 2018 Eucalyn
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
#include "print.h"
#include "keymap_japanese.h"

#define OVR_ON KEY_OVERRIDE_ON
#define OVR_OFF KEY_OVERRIDE_OFF
#define OVR_TOG KEY_OVERRIDE_TOGGLE

// 1. shift + 通常キー → 通常キー
const key_override_t at_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_2, JP_AT);
const key_override_t circ_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_6, JP_CIRC);
const key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, JP_COLN);

// 2. shift + 通常キー → shift + 通常キー
const key_override_t ampr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_7, JP_AMPR);
const key_override_t astr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_8, JP_ASTR);
const key_override_t lprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_9, JP_LPRN);
const key_override_t rprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, JP_RPRN);
const key_override_t unds_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, JP_UNDS);
const key_override_t plus_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, JP_PLUS);
const key_override_t lcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, JP_LCBR);
const key_override_t rcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, JP_RCBR);
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, JP_PIPE);
const key_override_t dquo_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, JP_DQUO);
const key_override_t tild_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, JP_TILD);

// 3. 通常キー → 通常キー
const key_override_t lbrc_key_override = ko_make_with_layers_and_negmods(0, KC_LBRC, JP_LBRC, ~0, (uint8_t)MOD_MASK_SHIFT);
const key_override_t rbrc_key_override = ko_make_with_layers_and_negmods(0, KC_RBRC, JP_RBRC, ~0, (uint8_t)MOD_MASK_SHIFT);
const key_override_t bsls_key_override = ko_make_with_layers_and_negmods(0, KC_BSLS, JP_BSLS, ~0, (uint8_t)MOD_MASK_SHIFT);

// 4, 通常キー → shift + 通常キー
const key_override_t eql_key_override = ko_make_with_layers_and_negmods(0, KC_EQL, JP_EQL, ~0, (uint8_t)MOD_MASK_SHIFT);
const key_override_t quot_key_override = ko_make_with_layers_and_negmods(0, KC_QUOT, JP_QUOT, ~0, (uint8_t)MOD_MASK_SHIFT);
const key_override_t grv_key_override = ko_make_with_layers_and_negmods(0, KC_GRV, JP_GRV, ~0, (uint8_t)MOD_MASK_SA);

// 5. alt + 通常キー → 通常キー
const key_override_t zkhk_key_override = ko_make_basic(MOD_MASK_ALT, KC_GRV, JP_ZKHK);

const key_override_t **key_overrides = (const key_override_t *[]){
    &at_key_override,
    &circ_key_override,
    &coln_key_override,
    &astr_key_override,
    &lprn_key_override,
    &rprn_key_override,
    &unds_key_override,
    &plus_key_override,
    &lcbr_key_override,
    &rcbr_key_override,
    &pipe_key_override,
    &dquo_key_override,
    &tild_key_override,
    &lbrc_key_override,
    &rbrc_key_override,
    &bsls_key_override,
    &eql_key_override,
    &quot_key_override,
    &grv_key_override,
    &zkhk_key_override,
    NULL};

enum custom_keycodes
{
  RGBRST = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,    KC_BSPC,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC,   KC_BSLS,
        KC_CAPS,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_ENT,
        KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,    KC_UP,      MO(1),
        KC_LCTL,   MO(1),     KC_LGUI,   KC_LALT,   KC_SPC,     KC_SPC,    KC_APP,    KC_RCTL,               KC_LEFT,    KC_DOWN,    KC_RGHT
    ),
    [1] = LAYOUT(
        KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,    KC_F12,    KC_DEL,
        RGB_TOG,   KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, RGB_MOD, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,     XXXXXXX,   XXXXXXX,
        XXXXXXX,   KC_LEFT, KC_DOWN, KC_RIGHT,KC_END,  RGB_RMOD,XXXXXXX, KC_VOLD, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,   XXXXXXX,
        _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGBRST,  XXXXXXX, KC_MUTE, KC_END,  KC_PGDN, KC_DOWN, _______,   KC_PGUP,   _______,
        XXXXXXX,   _______,   _______,   _______,   OVR_ON,     OVR_OFF,   XXXXXXX,   XXXXXXX,               KC_HOME,   KC_PGDN,   KC_END
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: %u, col: %u, row: %u, pressed: %b\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif

  switch (keycode)
  {
  case RGBRST:
#ifdef RGBLIGHT_ENABLE
    if (record->event.pressed)
    {
      eeconfig_update_rgblight_default();
      rgblight_enable();
    }
#endif
    break;
  }
  return true;
}

void keyboard_post_init_user(void)
{
  // 希望する動作に合わせて値をカスタマイズします
  debug_enable = true;
  // debug_matrix=true;
  // debug_keyboard=true;
  // debug_mouse=true;

  key_override_off();
}

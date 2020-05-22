/* Copyright 2015-2017 Jack Humbert
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

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _NEO,
  _PROGRAMMING,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION,
  _NUMGUI,
};

enum planck_keycodes {
  LOWER = SAFE_RANGE,
  SHLOWER,
  RAISE,
  SWBASE, // switch base layer (normal/neo)
  FUNCTION,
  BACKLIT,
  NUM_GUI, // Numbers + LGUI
};

#define FUNESC LT(_FUNCTION, KC_ESC)
#define SFTQUOT MT(MOD_RSFT, KC_QUOT)
#define MO_PROG MO(_PROGRAMMING)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Esc/Fn|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |>Progr| GUI  | ALT  |Lower |    Space    |Raise | AltGr|SwBase|>Progr| Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {FUNESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFTQUOT},
  {KC_LCTL, MO_PROG, KC_LGUI, KC_LALT, LOWER,   SHLOWER, KC_SPC,  RAISE,   KC_RALT, SWBASE,  MO_PROG, KC_RCTL}
},

/* Neo. Requires the Neo layout in software and just changes some modifiers around.
 * TODO: @ in top-left
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Esc/Fn|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |>Progr| GUI  | ALT  |Lower |    Space    |Raise | AltGr|SwBase|>Progr| Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_NEO] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_CLCK, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______}
},

/* Neo-like programming layer for US-QUERTY keyboard layout
 * Differences: @ in top-left
 * ,-----------------------------------------------------------------------------------.
 * |      |   @  |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   #  |   $  |   |  |   ~  |   `  |   +  |   %  |   "  |   '  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PROGRAMMING] = {
  {_______, KC_AT,   KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC, KC_EXLM, KC_LT,   KC_GT,   KC_EQL,  KC_AMPR, _______},
  {_______, KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, KC_ASTR, KC_QUES, KC_LPRN, KC_RPRN, KC_MINS, KC_COLN, _______},
  {_______, KC_HASH, KC_DLR,  KC_PIPE, KC_TILD, KC_GRV,  KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_SCLN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |  F9  |  F10 |  F11 |  F12 |      |   /  |   7  |   8  |   9  | + =  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F5  |  F6  |  F7  |  F8  |      |   *  |   4  |   5  |   6  | _ -  | | \  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |   0  |   1  |   2  |   3  | " '  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_EQL,  KC_BSPC},
  {KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_MINS, KC_BSLS},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_QUOT, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______} 
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   [  |   ]  |      |      | Print| ScrLk| Pause|      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   #  |   $  |   (  |   )  |   &  |      | Ins  | Home | PgUp |      |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   %  |   ^  |   {  |   }  |   |  |      | Del  | End  | PgDn |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_BSPC},
  {KC_DEL,  KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_AMPR, _______, KC_INS,  KC_HOME, KC_PGUP, _______, KC_BSLS},
  {_______, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_PIPE, _______, KC_DEL,  KC_END,  KC_PGDN, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______} 
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      | NKRO |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
#define NKRO_TG MAGIC_TOGGLE_NKRO
[_ADJUST] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, NKRO_TG, _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Function (Pok3r-like)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      | Prev | Play | Next |      |      |Pg Up |  Up  |Pg Dn |Prt Sc| Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Vol- | Mute | Vol+ |      | Home | Left | Down |Right | End  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Ins  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Esc  |             | Esc  | Home |Pg Up |Pg Dn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = {
  {KC_ESC , _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, KC_PSCR, KC_DEL},
  {_______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END , _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_INS,  _______, _______, _______, _______},
  {_______, _______, _______, _______, KC_ESC , _______, _______, KC_ESC , KC_HOME, KC_PGUP, KC_PGDN, KC_END}
},

/* Numbers with GUI - for switching workspaces in i3
 * ,-----------------------------------------------------------------------------------.
 * |      |   7  |   8  |   9  |   0  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMGUI] = {
  {_______, KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______} 
},

};

static float qwerty_song[][2] = SONG(QWERTY_SOUND);
static float neo_song[][2] = SONG(ZELDA_PUZZLE);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case SHLOWER:
      if (record->event.pressed) {
        register_code(KC_LSFT);
      } else {
        unregister_code(KC_LSFT);
      }
      return process_record_user(LOWER, record);
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case SWBASE:
      if (record->event.pressed) {
        // default_layer_state is initially zero, but will have the _QWERTY bit
        // set after switching once.
        if (!default_layer_state || default_layer_state & (1 << _QWERTY)) {
          default_layer_set(1 << _NEO);
          PLAY_SONG(neo_song);
        } else {
          default_layer_set(1 << _QWERTY);
          PLAY_SONG(qwerty_song);
        }
      }
      return false;
    case FUNCTION:
      if (record->event.pressed) {
        layer_on(_FUNCTION);
      } else {
        layer_off(_FUNCTION);
      }
      return false;
    case NUM_GUI:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        layer_on(_NUMGUI);
      } else {
        unregister_code(KC_LGUI);
        layer_off(_NUMGUI);
      }
      return false;
  }
  return true;
}

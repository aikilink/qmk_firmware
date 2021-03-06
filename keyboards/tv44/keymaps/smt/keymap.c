#include "tv44.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

// Keycodes
enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom macros
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift
#define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
#define ALT_GRV     ALT_T(KC_GRV)               // Tap for Backtick, hold for Alt (Ctrl+Alt+Shift)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
 * |Hyper/Tab|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Bksp   |
 * |---------`------`------`------`------`------`------`------`------`------`------`---------|
 * | Ctrl/Esc |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '    |
 * |----------`------`------`------`------`------`------`------`------`------`------`--------|
 * |   Shift   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sft/Ent|
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
 * |  Alt/` |   GUI   |  Lower |    Space     |    Space     |  Raise  | GUI  | Alt  | Ctrl  |
 *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------'
 */
[_QWERTY] = KEYMAP_TV45(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
    HPR_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC      ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    CTL_ESC ,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,    KC_QUOT     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    KC_LSFT  ,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,    SFT_ENT    ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    ALT_GRV ,   KC_LGUI     ,   LOWER ,     KC_SPC     ,     KC_SPC      ,  RAISE  ,  KC_RGUI, KC_RALT,     KC_RCTL   ),
/*`---------+---------------+---------+-------^^^------+-------^^^-------+----------+--------+--------+--------------'*/

/* Colemak
 * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
 * |Hyper/Tab|   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |  Bksp   |
 * |---------`------`------`------`------`------`------`------`------`------`------`---------|
 * | Ctrl/Esc |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |   '    |
 * |----------`------`------`------`------`------`------`------`------`------`------`--------|
 * |   Shift   |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Sft/Ent|
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
 * |  Alt/` |   GUI   |  Lower |    Space     |    Space     |  Raise  | GUI  | Alt  | Ctrl  |
 *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------'
 */
[_COLEMAK] = KEYMAP_TV45(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
    HPR_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,    KC_BSPC      ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    CTL_ESC ,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    KC_LSFT  ,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,    SFT_ENT    ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    ALT_GRV ,   KC_LGUI     ,   LOWER ,     KC_SPC     ,     KC_SPC      ,  RAISE  ,  KC_RGUI, KC_RALT,     KC_RCTL   ),
/*`---------+---------------+---------+-------^^^------+-------^^^-------+----------+--------+--------+--------------'*/

/* Dvorak
 * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
 * |Hyper/Tab|   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  Bksp   |
 * |---------`------`------`------`------`------`------`------`------`------`------`---------|
 * | Ctrl/Esc |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |   -    |
 * |----------`------`------`------`------`------`------`------`------`------`------`--------|
 * | Shift     |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Sft/Ent|
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
 * |  Alt/` |   GUI   |  Lower |    Space     |    Space     |  Raise  | GUI  | Alt  | Ctrl  |
 *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------'
 */
[_DVORAK] = KEYMAP_TV45(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
    HPR_TAB,KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC      ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    CTL_ESC ,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    KC_LSFT  , KC_SCLN,   KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    SFT_ENT    ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    ALT_GRV ,   KC_LGUI     ,   LOWER ,     KC_SPC     ,     KC_SPC      ,  RAISE  ,  KC_RGUI, KC_RALT,     KC_RCTL   ),
/*`---------+---------------+---------+-------^^^------+-------^^^-------+----------+--------+--------+--------------'*/

/* Lower
 * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
 * |   0     |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   Del   |
 * |---------`------`------`------`------`------`------`------`------`------`------`---------|
 * |   $      |   4  |   5  |   6  |   .  |   +  |   *  |   4  |   5  |   6  |   .  | PageUp |
 * |----------`------`------`------`------`------`------`------`------`------`------`--------|
 * |   =       |   7  |   8  |   9  |   0  |   -  |   /  |   1  |   2  |   3  |  Up  |PageDn |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
 * |  Brite |         |        |    Home      |     End      |         | Left | Down | Right |
 *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------'
 */
[_LOWER] = KEYMAP_TV45(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
ALL_T(KC_0),   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL       ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
CTL_T(KC_DLR),  KC_4,    KC_5,    KC_6,  KC_DOT, KC_PLUS, KC_ASTR,    KC_4,    KC_5,    KC_6,  KC_DOT,    KC_PGUP     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
SFT_T(KC_EQL),   KC_7,    KC_8,    KC_9,    KC_0, KC_MINS, KC_SLSH,    KC_1,    KC_2,    KC_3,   KC_UP, SFT_T(KC_PGDN),
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
ALT_T(BACKLIT),   _______   , _______ ,     KC_HOME    ,      KC_END     , _______ ,  KC_LEFT, KC_DOWN,     KC_RGHT   ),
/*`---------+---------------+---------+-------^^^------+-------^^^-------+----------+--------+--------+--------------'*/

/* Raise
 * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
 * |   ~     |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   Del   |
 * |---------`------`------`------`------`------`------`------`------`------`------`---------|
 * |   F1     |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   ?  |   +  |   {  |   }  |        |
 * |----------`------`------`------`------`------`------`------`------`------`------`--------|
 * |   F7      |  F8  |  F9  |  F10 |  F11 |  F12 |   -  |   /  |   =  |   [  |   ]  |       |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
 * |  Brite |         |        |     Play     |     Next     |         | Mute | Vol- | Vol+  |
 *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------'
 */
[_RAISE] = KEYMAP_TV45(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
ALL_T(KC_TILD),KC_EXLM,KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    KC_DEL       ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
CTL_T(KC_F1),  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_UNDS, KC_QUES, KC_PLUS, KC_LCBR, KC_RCBR,    KC_PIPE     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
 SFT_T(KC_F7),  KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_MINS, KC_SLSH,  KC_EQL, KC_LBRC, KC_RBRC, SFT_T(KC_BSLS),
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
ALT_T(BACKLIT),   _______   , _______ ,     KC_MPLY    ,     KC_MNXT     , _______ ,  KC_MUTE, KC_VOLD,     KC_VOLU   ),
/*`---------+---------------+---------+-------^^^------+-------^^^-------+----------+--------+--------+--------------'*/

/* Adjust (Lower + Raise)
 * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
 * |         | Reset|      |      |      |      |      |      |      |      |      |  Reset  |
 * |---------`------`------`------`------`------`------`------`------`------`------`---------|
 * |          |      |      |      |      |AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |        |
 * |----------`------`------`------`------`------`------`------`------`------`------`--------|
 * |           |      |      |      |      |     |       |      |      |      |      |       |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
 * |        |         |        |              |              |         |      |      |       |
 *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------'
 */
[_ADJUST] = KEYMAP_TV45(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
    _______, RESET , _______, _______, _______, _______, _______, _______, _______, _______, _______,      RESET      ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    _______ ,_______, _______, _______, _______, AG_NORM, AG_SWAP,  QWERTY, COLEMAK,  DVORAK, _______,    _______     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______  ,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______    ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    _______ ,   _______     , _______ ,     _______    ,     _______     , _______ ,  _______, _______,     _______   ),
/*`---------+---------------+---------+-------^^^------+-------^^^-------+----------+--------+--------+--------------'*/
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
    case COLEMAK:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_DVORAK);
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
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "rgblight.h"

#define BASE 0 // default layer
#define FL1 1 // symbols
#define FL2 2 // media keys
#define FL3 3 // numbers
#define FL4 4 // misc
#define FL5 5 //numpad

#define BWORD LALT(KC_BSPC) 
#define T_PRE LCTL(KC_B)
#define KC_SEARCH LCTL(KC_R)
#define KC_CLOSE LCTL(KC_C)
#define KC_CLEAR LCTL(KC_L)
#define KC_COPY LGUI(KC_C)
#define KC_PASTE LGUI(KC_V)
#define KC_CTRLU LCTL(KC_U)
#define KC_CTRLP LCTL(KC_P)
#define KC_MAC_L LCTL(KC_LEFT)
#define KC_MAC_R LCTL(KC_RIGHT)

//define your vim leader (escaping included) here
#define VIM_LEADER "\\"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  WHPTXT,
  VIM_NERDCOMMENTER,
  PAREN,
  VIM_DIFF_UP,
  VIM_DIFF_DOWN,
  VIM_CLOSE_ALL,
  VIM_SAVE_ALL,
  VIM_SAVE,
  TMUX_SEARCH,
  TMUX_1,
  TMUX_2,
  TMUX_3,
  TMUX_4,
  TMUX_5,
  TMUX_CREAT,
  TMUX_DEST,
  TMUX_VERT_SPLIT,
  TMUX_SWAP,
  TMUX_HORZ_SPLIT,
  TMUX_SWAP_LAYOUT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Base Layer
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,
        LT(FL4,KC_TAB) ,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC,
        MO(FL1),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_BSLS,
        KC_LCTL,TG(FL3),KC_LGUI,MO(FL5),KC_LALT,
                                        KC_INS, KC_PSCR,
                                                        KC_DEL,
                                        KC_SPC, KC_BSPC, KC_TAB,
        // right hand
             KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_SLASH,
             KC_RBRC,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,
                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
             KC_BSLS,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_UP,  KC_RSHIFT,
                             KC_RALT,MO(FL2),KC_LEFT,KC_DOWN,MT(MOD_RCTL,KC_RIGHT),
             KC_RCTL,        KC_ESC,
             KC_PGUP,
             KC_TAB,KC_ENT, KC_SPC
    ),

// VIM LAYER
[FL1] = LAYOUT_ergodox(
       // left hand
       KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       VRSN,   KC_TRNS,BWORD,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,
       VIM_SAVE_ALL,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
          EPRM,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  VIM_CLOSE_ALL,
       KC_TRNS, KC_TRNS, VIM_DIFF_DOWN,VIM_DIFF_UP, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_TRNS,
                KC_LEFT, KC_DOWN,KC_UP,   KC_RIGHT, KC_SLASH, KC_BSLASH,
       KC_PIPE, KC_CIRCUMFLEX, KC_DOLLAR,KC_TRNS, KC_TRNS, KC_PGUP, VIM_NERDCOMMENTER,
                         KC_TRNS,KC_TRNS, KC_HOME, KC_PGDN, KC_END,
       KC_TRNS,   KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_ENT, KC_TRNS

),

// MEDIA, MOUSE, and TMUX layer
[FL2] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TMUX_VERT_SPLIT, KC_TRNS,
       TMUX_SEARCH, TMUX_1, TMUX_2, TMUX_3, TMUX_4, TMUX_5, KC_TRNS,
       KC_CAPS, WHPTXT, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
       TMUX_SWAP, KC_TRNS, TMUX_DEST, TMUX_CREAT, KC_TRNS, KC_TRNS, KC_TRNS,
       EPRM,    KC_APP,  TMUX_SWAP_LAYOUT, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_TRNS, TMUX_HORZ_SPLIT,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MSTP, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       RESET,   KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

// Num pad and RGB layer
[FL3] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       RGB_M_T,  RGB_M_B, VIM_DIFF_UP, VIM_DIFF_DOWN, KC_BRMD, KC_BRMU, KC_TRNS,
       RGB_TOG,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,
                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       RGB_SAI,  RGB_SAD,
       RGB_HUI,
       RGB_HUD, RGB_MOD, RGB_RMOD
),
//VIM-Like extension 
[FL4] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_COPY,    KC_CTRLU,    KC_ESC,    KC_TAB,    KC_PASTE,    KC_TAB,
                 KC_MAC_L,    KC_PGDN,    KC_PGUP,    KC_MAC_R,    VIM_SAVE, KC_TRNS,
       KC_TRNS,  KC_CTRLP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
// NUMPAD
[FL5] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS,    KC_7,       KC_8,    KC_9,    KC_TRNS,    KC_TRNS,
                 KC_TRNS,    KC_4,       KC_5,    KC_6, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS,
                          KC_DOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_ENT, KC_0
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(FL1)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
    case WHPTXT:
      if(record->event.pressed) {
           SEND_STRING(SS_LGUI("a")); 
	   SEND_STRING("\b");
      }
      return false;
      break;
      /*macro to make nerdcommenter more intellij like*/
     case VIM_NERDCOMMENTER:
      if(record->event.pressed) {
           SEND_STRING(VIM_LEADER); 
           SEND_STRING("c"); 
	   SEND_STRING(" ");
      }
      return false;
      break;
     case PAREN:
      if(record->event.pressed) {
           SEND_STRING("()"); 
      }
      return false;
      break;
     case VIM_DIFF_UP:
      if(record->event.pressed) {
           SEND_STRING("[c"); 
      }
      return false;
      break;
     case VIM_DIFF_DOWN:
      if(record->event.pressed) {
           SEND_STRING("]c"); 
      }
      return false;
      break;
     case VIM_CLOSE_ALL:
      if(record->event.pressed) {
           SEND_STRING(":qa!" SS_TAP(X_ENTER)); 
      }
      return false;
      break;
     case VIM_SAVE_ALL:
      if(record->event.pressed) {
           SEND_STRING(":xa!" SS_TAP(X_ENTER)); 
      }
      return false;
      break;
     case VIM_SAVE:
      if(record->event.pressed) {
           SEND_STRING(":w" SS_TAP(X_ENTER)); 
      }
      return false;
      break;

     case TMUX_SEARCH:
      if(record->event.pressed) {
           SEND_STRING(SS_LCTRL("b") SS_TAP(X_ENTER)); 
      }
      return false;
      break;

     case TMUX_1:
      if(record->event.pressed) {
           SEND_STRING(SS_LCTRL("b") "1"); 
      }
      return false;
      break;

     case TMUX_2:
      if(record->event.pressed) {
           SEND_STRING(SS_LCTRL("b") "2"); 
      }
      return false;
      break;

     case TMUX_3:
      if(record->event.pressed) {
           SEND_STRING(SS_LCTRL("b") "3"); 
      }
      return false;
      break;

     case TMUX_4:
      if(record->event.pressed) {
           SEND_STRING(SS_LCTRL("b") "4"); 
      }
      return false;
      break;

     case TMUX_5:
      if(record->event.pressed) {
           SEND_STRING(SS_LCTRL("b") "5"); 
      }
      return false;
      break;

     case TMUX_CREAT:
      if(record->event.pressed) {
           SEND_STRING(SS_LCTRL("b") "c"); 
      }
      return false;
      break;

     case TMUX_DEST:
      if(record->event.pressed) {
           SEND_STRING(SS_LCTRL("b") "x"); 
	   SEND_STRING("y");
      }
      return false;
      break;
     case TMUX_VERT_SPLIT:
      if(record->event.pressed) {
           SEND_STRING(SS_LCTRL("b") "%"); 
      }
      return false;
      break;
     case TMUX_SWAP:
      if(record->event.pressed) {
           SEND_STRING(SS_LCTRL("b") "o"); 
      }
      return false;
      break;
     case TMUX_HORZ_SPLIT:
      if(record->event.pressed) {
           SEND_STRING(SS_LCTRL("b") "\""); 
      }
      return false;
      break;
     case TMUX_SWAP_LAYOUT:
      if(record->event.pressed) {
           SEND_STRING(SS_LCTRL("b") " "); 
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 0:
	    rgblight_setrgb(0xFF, 0x00,0xFF);
            break;
        case 1:
            ergodox_right_led_1_on();
	    rgblight_setrgb(0xFF, 0x00,0x00);
            break;
        case 2:
            ergodox_right_led_2_on();
	    rgblight_setrgb(0x00, 0xFF,0x00);
            break;
	case 3:
	    ergodox_right_led_3_on();
	    rgblight_setrgb(0x00, 0x00,0xFF);
	    break;
	case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
	    rgblight_setrgb(0xFF, 0xFF,0x00);
	    break;
	case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
	    ergodox_right_led_3_on();
	    rgblight_setrgb(0xFF, 0xFF,0xFF);
	    break;
	    
        default:
            // none
            break;
    }

};

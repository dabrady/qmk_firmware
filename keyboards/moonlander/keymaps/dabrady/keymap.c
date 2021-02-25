#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_REDO LSFT(KC_MAC_UNDO)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)

#define SS_SPOTLIGHT SS_LGUI(SS_TAP(X_SPACE)) // MacOS Spotlight shortcut is CMD+SPACE

enum custom_keycodes {
  _SLACK_ = ML_SAFE_RANGE,
  _CHROME_,
  _ITERM2_,
  _EMACS_,
};

enum layers {
  BASE = 0,
  NUMBERS,
  NAVIGATION,
  SPECIALS,
  PLEBIANS,
};

// NOTE(dabrady) 'DC' stands for 'dance code'. My own prefix, not a standard.
enum tap_dance_codes {
  DC_TEXT_MANIP,
  DC_WHOOPS,
};
// NOTE(dabrady) 'TD' stands for 'tap dance'; a QMK standard prefix.
#define TD_TEXT_MANIP TD(DC_TEXT_MANIP)
#define TD_WHOOPS TD(DC_WHOOPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    KC_PERC,   KC_AMPR,   KC_LBRACKET, KC_LCBR, KC_LPRN,   KC_EQUAL, _SLACK_,            TD_WHOOPS,    KC_GRAVE,     KC_RPRN,              KC_RCBR,    KC_RBRACKET, KC_EXLM, KC_HASH,
    KC_QUOTE,  KC_SCOLON, KC_COMMA,    KC_DOT,  KC_P,      KC_Y,     _CHROME_,           _______,        KC_F,         KC_G,                 KC_C,       KC_R,        KC_L,    KC_QUES,
    KC_ESCAPE, KC_A,      KC_O,        KC_E,    KC_U,      KC_I,     _ITERM2_,           _EMACS_,     KC_D,         KC_H,                 KC_T,       KC_N,        KC_S,    KC_MINUS,
    KC_LSHIFT, _______,   KC_Q,        KC_J,    KC_K,      KC_X,                                         KC_B,         KC_M,                 KC_W,       KC_V,        KC_Z,    KC_RSHIFT,
    KC_LCTRL,  KC_LALT,   _______,     _______, KC_BSPACE,           TD_TEXT_MANIP,        RGUI(KC_SPACE),               LT(NUMBERS,KC_SLASH), KC_BSLASH,  _______,     _______, LT(SPECIALS,KC_NO),
                                                        KC_ENTER, KC_LGUI, KC_AT,        KC_DLR, LT(NAVIGATION,KC_TAB), KC_SPACE
  ),
  [NUMBERS] = LAYOUT_moonlander(
    _______,   _______,   _______,     _______, _______,   _______,  _______,            _______,        _______,      _______,       _______,    _______,     _______, _______,
    _______,   _______,   _______,     _______, _______,   KC_ASTR,  _______,            _______,        KC_PLUS,      _______,       _______,    _______,     _______, _______,
    _______,   KC_7,      KC_5,        KC_3,    KC_1,      KC_9,     _______,            _______,        KC_0,         KC_2,          KC_4,       KC_6,        KC_8,    _______,
    _______,   _______,   _______,     _______, _______,   KC_CIRC,                                      KC_PIPE,      _______,       _______,    _______,     _______, _______,
    _______,   _______,   _______,     _______, _______,             _______,            _______,                      _______,       _______,    _______,     _______, _______,
                                                   _______, _______, _______,            _______, _______, _______
  ),
  [NAVIGATION] = LAYOUT_moonlander(
    _______,   _______,    _______,       _______,    _______,     _______,    _______,     _______,     _______,      _______,       _______,    _______,     _______, _______,
    _______,   _______,    KC_MS_WH_DOWN, KC_MS_UP,   KC_MS_WH_UP, _______,    _______,     _______,     _______,      KC_PGDOWN,     KC_UP,      KC_PGUP,     _______, _______,
    _______,   KC_MS_BTN2, KC_MS_LEFT,    KC_MS_DOWN, KC_MS_RIGHT, _______,    _______,     _______,     _______,      KC_LEFT,       KC_DOWN,    KC_RIGHT,    _______, _______,
    _______,   _______,    _______,       _______,    _______,     KC_MS_BTN3,                           _______,      _______,       _______,    _______,     _______, _______,
    _______,   _______,    _______,       _______,    _______,                 _______,     _______,                   _______,       _______,    _______,     _______, _______,
                                                          KC_MS_BTN1, _______, _______,     _______, _______, _______
  ),
  [SPECIALS] = LAYOUT_moonlander(
    RESET,       KC_F1,   KC_F2,       KC_F3,   KC_F4,     KC_F5,    KC_F11,             TOGGLE_LAYER_COLOR, KC_F6,    KC_F7,         KC_F8,      KC_F9,       KC_F10,       KC_F11,
    WEBUSB_PAIR, _______, _______,     _______, _______,   _______,  _______,            RGB_TOG,            _______,  _______,       _______,    _______,     _______,      KC_F12,
    _______,     _______, _______,     _______, _______,   _______,  _______,            _______,            _______,  _______,       _______,    _______,     _______,      _______,
    _______,     _______, _______,     _______, _______,   _______,                                          _______,  _______,       _______,    _______,     _______,      _______,
    _______,     _______, _______,     _______, _______,       KC_AUDIO_MUTE,            _______,                      _______,       _______,    _______,     TO(PLEBIANS), _______,
                                         _______, _______, KC_AUDIO_VOL_DOWN,            KC_AUDIO_VOL_UP, _______, _______
  ),
  [PLEBIANS] = LAYOUT_moonlander(
    KC_GRAVE,  KC_1,      KC_2,        KC_3,     KC_4,     KC_5,     _______,            _______,        KC_6,         KC_7,          KC_8,       KC_8,        KC_9,         KC_0,
    KC_TAB,    KC_Q,      KC_W,        KC_E,     KC_R,     KC_T,     _______,            _______,        KC_Y,         KC_U,          KC_I,       KC_O,        KC_P,         KC_BSPACE,
    KC_LCTRL,  KC_A,      KC_S,        KC_D,     KC_F,     KC_G,     _______,            TO(BASE),       KC_H,         KC_J,          KC_K,       KC_L,        KC_SCOLON,    KC_ENTER,
    _______,   KC_Z,      KC_X,        KC_C,     KC_V,     KC_B,                                         KC_N,         KC_M,          KC_COMMA,   KC_DOT,      KC_SLASH,     _______,
    _______,   _______,   KC_LALT,     KC_LCTRL, KC_LGUI,            KC_ESCAPE,          _______,                     _______,        _______,    _______,     _______,      _______,
                                                   KC_SPACE,  _______, _______,          _______, _______, KC_SPACE
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

// TODO(dabrady) Reformat for readability like the above.
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
  [BASE] = { {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {146,224,255}, {146,224,255}, {146,224,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,0,255}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {14,255,255}, {146,224,255}, {146,224,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,0,255} },

  [NUMBERS] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {91,245,251}, {141,255,233}, {91,245,251}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {91,245,251}, {141,255,233}, {91,245,251}, {0,0,0}, {0,0,0}, {0,0,0}, {0,204,255}, {0,0,0}, {0,0,0}, {0,0,0} },

  [NAVIGATION] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,204,255}, {0,0,0}, {0,0,0} },

  [SPECIALS] = { {0,205,155}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {33,255,255}, {33,255,255}, {33,255,255}, {0,204,255}, {33,255,255}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {14,255,255}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {33,255,255}, {0,0,0}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255} },

  [PLEBIANS] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,205,155}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
      rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
      RGB rgb = hsv_to_rgb( hsv );
      float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
      rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }

  uint8_t layer = biton32(layer_state);
  switch (layer) {
  case BASE ... PLEBIANS:
    set_layer_color(layer);
    break;
  default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Handle macros and other specials
  switch (keycode) {
  // NOTE(dabrady) These are my first attempt at application-switchers: they rely on Spotlight searches.
  // TODO(dabrady) Consider leveraging Hammerspoon or some other host-machine software to handle this instead, and just
  // send a special command from here.
  case _SLACK_:
    if (record->event.pressed) {
      SEND_STRING(SS_SPOTLIGHT SS_DELAY(100) SS_TAP(X_S) SS_DELAY(100) SS_TAP(X_L)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
  case _CHROME_:
    if (record->event.pressed) {
      SEND_STRING(SS_SPOTLIGHT SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_H) SS_DELAY(100) SS_TAP(X_R)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
  case _ITERM2_:
    if (record->event.pressed) {
      SEND_STRING(SS_SPOTLIGHT SS_DELAY(100) SS_TAP(X_I) SS_DELAY(100) SS_TAP(X_T)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
  case _EMACS_:
    if (record->event.pressed) {
      SEND_STRING(SS_SPOTLIGHT SS_DELAY(100) SS_TAP(X_E) SS_DELAY(100) SS_TAP(X_M)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
  }
  return true;
}

typedef struct {
  uint8_t step;
} tap;

enum dance_steps {
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  DOUBLE_SINGLE_TAP,
  MORE_TAPS
};

// NOTE(dabrady) Global state map of tap dance keys. (Gross, but functional.)
static tap dance_states[] = {
  [DC_TEXT_MANIP] = {
    .step = 0
  },
  [DC_WHOOPS] = {
    .step = 0
  }
};

void on_text_manip(qk_tap_dance_state_t *state, void *user_data);
uint8_t text_manip_dance_step(qk_tap_dance_state_t *state);
void text_manip_finished(qk_tap_dance_state_t *state, void *user_data);
void text_manip_reset(qk_tap_dance_state_t *state, void *user_data);

// NOTE(dabrady) This function is called on every tap of DC_TEXT_MANIP, and is
// responsible for handling every tap that isn't part of a known dance.
//
// More specifically, it does this:
// - Nothing for the first two taps in the sequence (which are possible dances
//   themselves and are interpreted by text_manip_dance_step and handled by
//   text_manip_finished)
// - Sends three taps of KC_MAC_COPY on the third tap (this is officially just a
//   button mash, not a dance)
// - Sends one tap of KC_MAC_COPY on every subsequent tap of DC_TEXT_MANIP
void on_text_manip(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    // Make up for the last 3 missed taps
    tap_code16(KC_MAC_COPY);
    tap_code16(KC_MAC_COPY);
    tap_code16(KC_MAC_COPY);
  } else if(state->count > 3) {
    // Keep the taps coming
    tap_code16(KC_MAC_COPY);
  } else { /* Defer processing of the first two taps, might be a dance */ }
}
// NOTE(dabrady) This function matches a sequence of taps to a recognized dance.
uint8_t text_manip_dance_step(qk_tap_dance_state_t *state) {
  // A single-tap dance
  if (state->count == 1) {
    // If it was pressed-and-interrupted or pressed-and-released, it's a tap.
    // Otherwise, it was pressed but never released, and thus is a hold.
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  return MORE_TAPS;
}
// NOTE(dabrady) This function is called after a dance has finished (dances
// are defined as a sequence of taps occurring within a configured time period).
void text_manip_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_states[DC_TEXT_MANIP].step = text_manip_dance_step(state);
  switch (dance_states[DC_TEXT_MANIP].step) {
  case SINGLE_TAP: register_code16(KC_MAC_COPY); break;
  case SINGLE_HOLD: register_code16(KC_MAC_PASTE); break;
  case DOUBLE_TAP: register_code16(KC_MAC_CUT); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_MAC_COPY); register_code16(KC_MAC_COPY);
  case DOUBLE_HOLD:
  case MORE_TAPS:
  default:
    break;
  }
}
// NOTE(dabrady) This function is called to finalize a dance.
void text_manip_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_states[DC_TEXT_MANIP].step) {
  case SINGLE_TAP: unregister_code16(KC_MAC_COPY); break;
  case SINGLE_HOLD: unregister_code16(KC_MAC_PASTE); break;
  case DOUBLE_TAP: unregister_code16(KC_MAC_CUT); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_MAC_COPY); break;
  case DOUBLE_HOLD:
  case MORE_TAPS:
  default:
    break;
  }
  dance_states[DC_TEXT_MANIP].step = 0;
}

void on_whoops(qk_tap_dance_state_t *state, void *user_data);
uint8_t whoops_dance_step(qk_tap_dance_state_t *state);
void whoops_finished(qk_tap_dance_state_t *state, void *user_data);
void whoops_reset(qk_tap_dance_state_t *state, void *user_data);

// NOTE(dabrady) This function is called on every tap of DC_WHOOPS, and is
// responsible for handling every tap that isn't part of a known dance.
//
// More specifically, it does this:
// - Nothing for the first two taps in the dance (which are possible complete
//   dances themselves and are interpreted by whoops_dance_step and handled by
//   whoops_finished)
// - Sends three taps of KC_MAC_UNDO on the third tap (this is officially just a
//   button mash, not a dance)
// - Sends one tap of KC_MAC_UNDO on every subsequent tap of DC_WHOOPS
void on_whoops(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    // Make up for the last 3 missed taps
    tap_code16(KC_MAC_UNDO);
    tap_code16(KC_MAC_UNDO);
    tap_code16(KC_MAC_UNDO);
  } else if(state->count > 3) {
    // Keep the taps coming
    tap_code16(KC_MAC_UNDO);
  } else { /* Defer processing of the first two taps, might be a dance */ }
}
// NOTE(dabrady) This function matches a sequence of taps to a recognized dance.
uint8_t whoops_dance_step(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  return MORE_TAPS;
}
// NOTE(dabrady) This function is called after a dance has finished (dances
// are defined as a sequence of taps occurring within a configured time period).
void whoops_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_states[DC_WHOOPS].step = whoops_dance_step(state);
  switch (dance_states[DC_WHOOPS].step) {
  case SINGLE_TAP: register_code16(KC_MAC_UNDO); break;
  case DOUBLE_TAP: register_code16(KC_MAC_UNDO); register_code16(KC_MAC_UNDO); break;
  case DOUBLE_HOLD: register_code16(KC_MAC_REDO); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_MAC_UNDO); register_code16(KC_MAC_UNDO);
  case SINGLE_HOLD:
  case MORE_TAPS:
  default:
    break;
  }
}
// NOTE(dabrady) This function is called to finalize a dance.
void whoops_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_states[DC_WHOOPS].step) {
  case SINGLE_TAP: unregister_code16(KC_MAC_UNDO); break;
  case DOUBLE_TAP: unregister_code16(KC_MAC_UNDO); break;
  case DOUBLE_HOLD: unregister_code16(KC_MAC_REDO); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_MAC_UNDO); break;
  case SINGLE_HOLD:
  case MORE_TAPS:
  default:
    break;
  }
  dance_states[DC_WHOOPS].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [DC_TEXT_MANIP] = ACTION_TAP_DANCE_FN_ADVANCED(on_text_manip, text_manip_finished, text_manip_reset),
  [DC_WHOOPS] = ACTION_TAP_DANCE_FN_ADVANCED(on_whoops, whoops_finished, whoops_reset),
};

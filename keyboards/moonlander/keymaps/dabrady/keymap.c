#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
};


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_PERC,   KC_AMPR,   KC_LBRACKET, KC_LCBR, KC_LPRN,   KC_EQUAL, ST_MACRO_0,         TD(DANCE_1),    KC_GRAVE,     KC_RPRN,        KC_RCBR,    KC_RBRACKET, KC_EXLM, KC_HASH,
    KC_QUOTE,  KC_SCOLON, KC_COMMA,    KC_DOT,  KC_P,      KC_Y,     ST_MACRO_1,         _______,        KC_F,         KC_G,           KC_C,       KC_R,        KC_L,    KC_QUES,
    KC_ESCAPE, KC_A,      KC_O,        KC_E,    KC_U,      KC_I,     ST_MACRO_2,         ST_MACRO_3,     KC_D,         KC_H,           KC_T,       KC_N,        KC_S,    KC_MINUS,
    KC_LSHIFT, _______,   KC_Q,        KC_J,    KC_K,      KC_X,                                         KC_B,         KC_M,           KC_W,       KC_V,        KC_Z,    KC_RSHIFT,
    KC_LCTRL,  KC_LALT,   _______,     _______, KC_BSPACE,           TD(DANCE_0),        RGUI(KC_SPACE),               LT(1,KC_SLASH), KC_BSLASH,  _______,     _______, LT(3,KC_NO),
                                                        KC_ENTER, KC_LGUI, KC_AT,        KC_DLR, LT(2,KC_TAB), KC_SPACE
  ),
  [1] = LAYOUT_moonlander(
    _______,   _______,   _______,     _______, _______,   _______,  _______,            _______,        _______,      _______,        _______,    _______,     _______, _______,
    _______,   _______,   _______,     _______, _______,   KC_ASTR,  _______,            _______,        KC_PLUS,      _______,        _______,    _______,     _______, _______,
    _______,   KC_7,      KC_5,        KC_3,    KC_1,      KC_9,     _______,            _______,        KC_0,         KC_2,           KC_4,       KC_6,        KC_8,    _______,
    _______,   _______,   _______,     _______, _______,   KC_CIRC,                                      KC_PIPE,      _______,        _______,    _______,     _______, _______,
    _______,   _______,   _______,     _______, _______,             _______,            _______,                      _______,        _______,    _______,     _______, _______,
                                                   _______, _______, _______,            _______, _______, _______
  ),
  [2] = LAYOUT_moonlander(
    _______,   _______,    _______,       _______,    _______,     _______,    _______,     _______,     _______,      _______,        _______,    _______,     _______, _______,
    _______,   _______,    KC_MS_WH_DOWN, KC_MS_UP,   KC_MS_WH_UP, _______,    _______,     _______,     _______,      KC_PGDOWN,      KC_UP,      KC_PGUP,     _______, _______,
    _______,   KC_MS_BTN2, KC_MS_LEFT,    KC_MS_DOWN, KC_MS_RIGHT, _______,    _______,     _______,     _______,      KC_LEFT,        KC_DOWN,    KC_RIGHT,    _______, _______,
    _______,   _______,    _______,       _______,    _______,     KC_MS_BTN3,                           _______,      _______,        _______,    _______,     _______, _______,
    _______,   _______,    _______,       _______,    _______,                 _______,     _______,                   _______,        _______,    _______,     _______, _______,
                                                          KC_MS_BTN1, _______, _______,     _______, _______, _______
  ),
  [3] = LAYOUT_moonlander(
    RESET,       KC_F1,   KC_F2,       KC_F3,   KC_F4,     KC_F5,    KC_F11,             TOGGLE_LAYER_COLOR, KC_F6,    KC_F7,          KC_F8,      KC_F9,       KC_F10,  KC_F11,
    WEBUSB_PAIR, _______, _______,     _______, _______,   _______,  _______,            RGB_TOG,            _______,  _______,        _______,    _______,     _______, KC_F12,
    _______,     _______, _______,     _______, _______,   _______,  _______,            _______,            _______,  _______,        _______,    _______,     _______, _______,
    _______,     _______, _______,     _______, _______,   _______,                                          _______,  _______,        _______,    _______,     _______, _______,
    _______,     _______, _______,     _______, _______,       KC_AUDIO_MUTE,            _______,                      _______,        _______,    _______,     TO(4),   _______,
                                         _______, _______, KC_AUDIO_VOL_DOWN,            KC_AUDIO_VOL_UP, _______, _______
  ),
  [4] = LAYOUT_moonlander(
    KC_GRAVE,  KC_1,      KC_2,        KC_3,     KC_4,     KC_5,     _______,            _______,       KC_6,         KC_7,           KC_8,       KC_8,       KC_9,      KC_0,
    KC_TAB,    KC_Q,      KC_W,        KC_E,     KC_R,     KC_T,     _______,            _______,       KC_Y,         KC_U,           KC_I,       KC_O,       KC_P,      KC_BSPACE,
    KC_LCTRL,  KC_A,      KC_S,        KC_D,     KC_F,     KC_G,     _______,            TO(0),         KC_H,         KC_J,           KC_K,       KC_L,       KC_SCOLON, KC_ENTER,
    _______,   KC_Z,      KC_X,        KC_C,     KC_V,     KC_B,                                        KC_N,         KC_M,           KC_COMMA,   KC_DOT,     KC_SLASH,  _______,
    _______,   _______,   KC_LALT,     KC_LCTRL, KC_LGUI,            KC_ESCAPE,          _______,                     _______,        _______,    _______,    _______,   _______,
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
    [0] = { {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {146,224,255}, {146,224,255}, {146,224,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,0,255}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {0,204,255}, {179,164,153}, {179,164,153}, {179,164,153}, {179,164,153}, {14,255,255}, {146,224,255}, {146,224,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,0,255} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {91,245,251}, {141,255,233}, {91,245,251}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {91,245,251}, {141,255,233}, {91,245,251}, {0,0,0}, {0,0,0}, {0,0,0}, {0,204,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,204,255}, {0,0,0}, {0,0,0} },

    [3] = { {0,205,155}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {33,255,255}, {33,255,255}, {33,255,255}, {0,204,255}, {33,255,255}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {14,255,255}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {33,255,255}, {0,0,0}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255} },

    [4] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,205,155}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

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
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)) SS_DELAY(100) SS_TAP(X_S) SS_DELAY(100) SS_TAP(X_L)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_H) SS_DELAY(100) SS_TAP(X_R)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)) SS_DELAY(100) SS_TAP(X_I) SS_DELAY(100) SS_TAP(X_T)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)) SS_DELAY(100) SS_TAP(X_E) SS_DELAY(100) SS_TAP(X_M)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_0_dance_step(qk_tap_dance_state_t *state);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_C));
        tap_code16(LGUI(KC_C));
        tap_code16(LGUI(KC_C));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_C));
    }
}

uint8_t dance_0_dance_step(qk_tap_dance_state_t *state) {
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
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_0_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(LGUI(KC_C)); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_V)); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_X)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_C)); register_code16(LGUI(KC_C));
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_C)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_V)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_X)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_C)); break;
    }
    dance_state.step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_1_dance_step(qk_tap_dance_state_t *state);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_Z));
        tap_code16(RGUI(KC_Z));
        tap_code16(RGUI(KC_Z));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_Z));
    }
}

uint8_t dance_1_dance_step(qk_tap_dance_state_t *state) {
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
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_1_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(RGUI(KC_Z)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_Z)); register_code16(RGUI(KC_Z)); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_Z))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_Z)); register_code16(RGUI(KC_Z));
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_Z)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_Z)); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_Z))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_Z)); break;
    }
    dance_state.step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};

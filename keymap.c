#include QMK_KEYBOARD_H
#include "config.h"
#include "rgb_matrix_map.h"

enum LAYERS {
	BASE_LAYER = 0,
	MAC_LAYER,
	FUNCTION_LAYER,
	NUMPAD_LAYER
};

int LAYER_COLORS_HSV[][3] = { {HSV_GOLD}, {HSV_AZURE}, {HSV_TEAL}, {HSV_RED} };

#define ARRAYSIZE(x)  (sizeof(x) / sizeof((x)[0]))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[BASE_LAYER] = LAYOUT_65_ansi_blocker(
			KC_GESC,                    KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_DEL,
		    KC_TAB,                     KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, KC_PGUP,
			LT(NUMPAD_LAYER, KC_CAPS),  KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
		    KC_LSFT,                    KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     KC_END,
		    KC_LCTL,                    KC_LGUI,  KC_LALT,                KC_SPC,                        MO(FUNCTION_LAYER),  KC_RCTL,  KC_LEFT, KC_DOWN,   KC_RIGHT),

		[MAC_LAYER] = LAYOUT_65_ansi_blocker(
			_______,  _______,  _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
			_______,  _______,  _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
			_______,  _______,  _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______,          _______,  _______,
			_______,  _______,  _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______,          _______,  _______,
			_______,  KC_LALT,  KC_LEFT_GUI,                     _______,                                 _______, _______, _______, _______,  _______),

		[FUNCTION_LAYER] = LAYOUT_65_ansi_blocker(
			KC_GRAVE, KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  _______,  _______,
		    _______,  RGB_TOG,  RGB_MOD, RGB_HUI,RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR,  KC_SLCK, KC_PAUS, QK_BOOT,  _______,
			_______,  RGB_SPI,  RGB_SPD, _______,_______, _______, _______, _______, _______, _______, _______,  _______,          EEP_RST,  _______,
		    _______,  _______,  _______, _______,_______, _______, _______, _______, _______, _______, _______,  _______,          KC_VOLU,  KC_MUTE,
		    _______,  _______,  TG(MAC_LAYER),                  _______,                               _______,  _______, KC_MPRV, KC_VOLD,  KC_MNXT),

		[NUMPAD_LAYER] = LAYOUT_65_ansi_blocker(
			_______,  _______,  _______, _______,  _______,  _______, _______, _______, KC_PSLS, KC_PAST, KC_PMNS, _______, _______, _______,  _______,
			_______,  _______,  _______, _______,  _______,  _______, _______, KC_7,    KC_8,    KC_9,    KC_PPLS, _______, _______, _______,  _______,
			_______,  _______,  _______, _______,  _______,  _______, _______, KC_4,    KC_5,    KC_6,    KC_PPLS, _______,          _______,  _______,
			_______,  _______,  _______, _______,  _______,  _______, _______, KC_1,    KC_2,    KC_3,    KC_PENT, _______,          _______,  _______,
			_______,  _______,  _______,                     KC_0,                                        _______, _______, _______, _______,  _______
		),

		[4] = LAYOUT_65_ansi_blocker(
			_______,  _______,  _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
			_______,  _______,  _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
			_______,  _______,  _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______,          _______,  _______,
			_______,  _______,  _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______,          _______,  _______,
			_______,  _______,  _______,                     _______,                                     _______, _______, _______, _______,  _______
		),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    int current_layer = biton32(state);

	rgblight_sethsv_noeeprom(LAYER_COLORS_HSV[current_layer][0], LAYER_COLORS_HSV[current_layer][1], LAYER_COLORS_HSV[current_layer][2]);

    return state;
}

// handles lighting up specific keys
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
	int current_layer = biton32(layer_state);

	HSV current_hsv;
	current_hsv.h = LAYER_COLORS_HSV[current_layer][0];
	current_hsv.s = LAYER_COLORS_HSV[current_layer][1];
	current_hsv.v = LAYER_COLORS_HSV[current_layer][2];
	RGB current_rgb = hsv_to_rgb(current_hsv);

	rgb_matrix_set_color(LED_ESC, current_rgb.r, current_rgb.g, current_rgb.b);

	int is_caps_lock_enabled = IS_HOST_LED_ON(USB_LED_CAPS_LOCK);
    if (is_caps_lock_enabled) {
		rgb_matrix_set_color(LED_CAPS, current_rgb.r, current_rgb.g, current_rgb.b);
    }

	if (current_layer == NUMPAD_LAYER) {
		for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_NUMPAD); i++) {
			rgb_matrix_set_color(LED_LIST_NUMPAD[i], current_rgb.r, current_rgb.g, current_rgb.b);
		}
	}
}

void keyboard_post_init_user(void) {
	rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
	rgblight_sethsv_noeeprom(HSV_GOLD);
};
#include "constants.h"
#include <stdint.h>
#include <avr/pgmspace.h>

#include "HIDTables.h"

#if THEKBD_RELEASE==1

extern const uint8_t layoutTable[keysTotalNumber]={
    // row 0 right
    0, 0, HID_KEYBOARD_RIGHT_ARROW, HID_KEYBOARD_DOWN_ARROW, HID_KEYBOARD_LEFT_ARROW, 0,
    HID_KEYBOARD_PRINTSCREEN,
    // row 0 left
    HID_KEYBOARD_PAUSE, HID_KEYBOARD_DELETE, HID_KEYBOARD_END, HID_KEYBOARD_PAGE_DOWN,
    HID_KEYBOARD_HOME, 0, 0,

    // row 1 right
    HID_KEYBOARD_RIGHT_ALT, 0,   0, HID_KEYBOARD_UP_ARROW, 0, HID_KEYBOARD_ENTER, HID_KEYBOARD_DELETE_FORWARD,
    // row 1 left
    HID_KEYBOARD_LEFT_GUI,  HID_KEYBOARD_SPACEBAR, 0, HID_KEYBOARD_PAGE_UP,  0, 0, HID_KEYBOARD_LEFT_ALT,

    // row 2 right
    HID_KEYBOARD_RIGHT_CONTROL, HID_KEYBOARD_SLASH_AND_QUESTION_MARK, HID_KEYBOARD_PERIOD_AND_GREATER_THAN,
    HID_KEYBOARD_COMMA_AND_LESS_THAN, HID_KEYBOARD_M_AND_M, HID_KEYBOARD_N_AND_N, 0,
    // row 2 left
    0, HID_KEYBOARD_B_AND_B, HID_KEYBOARD_V_AND_V, HID_KEYBOARD_C_AND_C, HID_KEYBOARD_X_AND_X,
    HID_KEYBOARD_Z_AND_Z, HID_KEYBOARD_LEFT_CONTROL,

    // row 3 right
    HID_KEYBOARD_RIGHT_SHIFT, HID_KEYBOARD_SEMICOLON_AND_COLON, HID_KEYBOARD_L_AND_L, HID_KEYBOARD_K_AND_K,
    HID_KEYBOARD_J_AND_J, HID_KEYBOARD_H_AND_H, HID_KEYBOARD_QUOTE_AND_DOUBLEQUOTE,
    // row 3 left
    HID_KEYBOARD_RIGHT_BRACKET_AND_RIGHT_CURLY_BRACE, HID_KEYBOARD_G_AND_G, HID_KEYBOARD_F_AND_F,
    HID_KEYBOARD_D_AND_D, HID_KEYBOARD_S_AND_S, HID_KEYBOARD_A_AND_A, HID_KEYBOARD_LEFT_SHIFT,

    // row 4 right
    HID_KEYBOARD_RIGHT_BRACKET_AND_RIGHT_CURLY_BRACE, HID_KEYBOARD_P_AND_P, HID_KEYBOARD_O_AND_O, HID_KEYBOARD_I_AND_I,
    HID_KEYBOARD_U_AND_U, HID_KEYBOARD_Y_AND_Y, HID_KEYBOARD_BACKSLASH_AND_PIPE,
    // row 4 left
    HID_KEYBOARD_LEFT_BRACKET_AND_LEFT_CURLY_BRACE, HID_KEYBOARD_T_AND_T, HID_KEYBOARD_R_AND_R,
    HID_KEYBOARD_E_AND_E, HID_KEYBOARD_W_AND_W, HID_KEYBOARD_Q_AND_Q, HID_KEYBOARD_TAB,

    // row 5 right
    HID_KEYBOARD_LEFT_BRACKET_AND_LEFT_CURLY_BRACE, HID_KEYBOARD_EQUALS_AND_PLUS, HID_KEYBOARD_MINUS_AND_UNDERSCORE,
    HID_KEYBOARD_0_AND_RIGHT_PAREN, HID_KEYBOARD_9_AND_LEFT_PAREN, HID_KEYBOARD_8_AND_ASTERISK,
    HID_KEYBOARD_7_AND_AMPERSAND,
    // row 5  left
    HID_KEYBOARD_6_AND_CARAT, HID_KEYBOARD_5_AND_PERCENT, HID_KEYBOARD_4_AND_DOLLAR, HID_KEYBOARD_3_AND_POUND,
    HID_KEYBOARD_2_AND_AT, HID_KEYBOARD_1_AND_EXCLAMATION_POINT, HID_KEYBOARD_GRAVE_ACCENT_AND_TILDE,

    // row 6 right
    HID_KEYBOARD_INSERT, HID_KEYBOARD_F12, HID_KEYBOARD_F11, HID_KEYBOARD_F10, HID_KEYBOARD_F9,
    HID_KEYBOARD_F8, HID_KEYBOARD_F7,
    // row 6 left
    HID_KEYBOARD_F6, HID_KEYBOARD_F5,  HID_KEYBOARD_F4,  HID_KEYBOARD_F3,  HID_KEYBOARD_F2,
    HID_KEYBOARD_F1, HID_KEYBOARD_ESCAPE
};

#elif THEKBD_RELEASE==2
/*
extern const uint8_t layoutTable[keysTotalNumber] PROGMEM = {
    // row 0 left
    HID_KEYBOARD_GRAVE_ACCENT_AND_TILDE, HID_KEYBOARD_F1, HID_KEYBOARD_F2, HID_KEYBOARD_F3,
    HID_KEYBOARD_F4, HID_KEYBOARD_F5, HID_KEYBOARD_F6,
    // row 0 right
    HID_KEYBOARD_F7, HID_KEYBOARD_F8, HID_KEYBOARD_F9, HID_KEYBOARD_F10, HID_KEYBOARD_F11,
    HID_KEYBOARD_F12, HID_KEYBOARD_LEFT_BRACKET_AND_LEFT_CURLY_BRACE,

    // row 1 left
    HID_KEYBOARD_TAB, HID_KEYBOARD_Q_AND_Q, HID_KEYBOARD_W_AND_W, HID_KEYBOARD_E_AND_E,
    HID_KEYBOARD_R_AND_R, HID_KEYBOARD_T_AND_T, 0,
    // row 1 right
    HID_KEYBOARD_BACKSLASH_AND_PIPE, HID_KEYBOARD_Y_AND_Y, HID_KEYBOARD_U_AND_U,
    HID_KEYBOARD_I_AND_I, HID_KEYBOARD_O_AND_O, HID_KEYBOARD_P_AND_P,
    HID_KEYBOARD_RIGHT_BRACKET_AND_RIGHT_CURLY_BRACE,

    // row 2 left
    HID_KEYBOARD_LEFT_SHIFT, HID_KEYBOARD_A_AND_A, HID_KEYBOARD_S_AND_S, HID_KEYBOARD_D_AND_D,
    HID_KEYBOARD_F_AND_F, HID_KEYBOARD_G_AND_G, HID_KEYBOARD_MINUS_AND_UNDERSCORE,
    // row 2 right
    HID_KEYBOARD_QUOTE_AND_DOUBLEQUOTE, HID_KEYBOARD_H_AND_H, HID_KEYBOARD_J_AND_J,
    HID_KEYBOARD_K_AND_K, HID_KEYBOARD_L_AND_L, HID_KEYBOARD_SEMICOLON_AND_COLON,
    HID_KEYBOARD_RIGHT_SHIFT,

    // row 3 left
    0, HID_KEYBOARD_Z_AND_Z, HID_KEYBOARD_X_AND_X, HID_KEYBOARD_C_AND_C, HID_KEYBOARD_V_AND_V,
    HID_KEYBOARD_B_AND_B, 0,
    // row 3 right
    0, HID_KEYBOARD_N_AND_N, HID_KEYBOARD_M_AND_M, HID_KEYBOARD_COMMA_AND_LESS_THAN,
    HID_KEYBOARD_PERIOD_AND_GREATER_THAN, HID_KEYBOARD_SLASH_AND_QUESTION_MARK, 0,

    // row 4 left
    HID_KEYBOARD_PAGE_UP, HID_KEYBOARD_END, HID_KEYBOARD_SPACEBAR, 0, HID_KEYBOARD_DELETE,
    HID_KEYBOARD_LEFT_CONTROL, 0,
    // row 4 right
    0, HID_KEYBOARD_RIGHT_CONTROL, HID_KEYBOARD_DELETE_FORWARD, 0, HID_KEYBOARD_ENTER,
    HID_KEYBOARD_LEFT_ARROW, HID_KEYBOARD_UP_ARROW,

    // row 5 left
    HID_KEYBOARD_HOME, HID_KEYBOARD_PAGE_DOWN, 0, HID_KEYBOARD_ESCAPE, HID_KEYBOARD_LEFT_GUI,
    HID_KEYBOARD_LEFT_ALT, 0,
    // row 5 right
    0, HID_KEYBOARD_RIGHT_ALT, HID_KEYBOARD_RIGHT_GUI, HID_KEYBOARD_INSERT, 0,
    HID_KEYBOARD_DOWN_ARROW, HID_KEYBOARD_RIGHT_ARROW,
};
*/

extern const uint8_t layoutTable[numLayers*keysTotalNumber] PROGMEM = {
    // LAYER 0
    // LAYER 0
    // LAYER 0

    // row 0 left
    HID_KEYBOARD_GRAVE_ACCENT_AND_TILDE, HID_KEYBOARD_F1, HID_KEYBOARD_F2, HID_KEYBOARD_F3,
    HID_KEYBOARD_F4, HID_KEYBOARD_F5, HID_KEYBOARD_F6,
    // row 0 right
    HID_KEYBOARD_F7, HID_KEYBOARD_F8, HID_KEYBOARD_F9, HID_KEYBOARD_F10, HID_KEYBOARD_F11,
    HID_KEYBOARD_F12, HID_KEYBOARD_LEFT_BRACKET_AND_LEFT_CURLY_BRACE,

    // row 1 left
    HID_KEYBOARD_TAB, HID_KEYBOARD_Q_AND_Q, HID_KEYBOARD_W_AND_W, HID_KEYBOARD_E_AND_E,
    HID_KEYBOARD_R_AND_R, HID_KEYBOARD_T_AND_T, 0,
    // row 1 right
    HID_KEYBOARD_BACKSLASH_AND_PIPE, HID_KEYBOARD_Y_AND_Y, HID_KEYBOARD_U_AND_U,
    HID_KEYBOARD_I_AND_I, HID_KEYBOARD_O_AND_O, HID_KEYBOARD_P_AND_P,
    HID_KEYBOARD_RIGHT_BRACKET_AND_RIGHT_CURLY_BRACE,

    // row 2 left
    HID_KEYBOARD_LEFT_SHIFT, HID_KEYBOARD_A_AND_A, HID_KEYBOARD_S_AND_S, HID_KEYBOARD_D_AND_D,
    HID_KEYBOARD_F_AND_F, HID_KEYBOARD_G_AND_G, HID_KEYBOARD_MINUS_AND_UNDERSCORE,
    // row 2 right
    HID_KEYBOARD_QUOTE_AND_DOUBLEQUOTE, HID_KEYBOARD_H_AND_H, HID_KEYBOARD_J_AND_J,
    HID_KEYBOARD_K_AND_K, HID_KEYBOARD_L_AND_L, HID_KEYBOARD_SEMICOLON_AND_COLON,
    HID_KEYBOARD_RIGHT_SHIFT,

    // row 3 left
    KEY_LAYER_SWITCH_LEFT, HID_KEYBOARD_Z_AND_Z, HID_KEYBOARD_X_AND_X, HID_KEYBOARD_C_AND_C,
    HID_KEYBOARD_V_AND_V, HID_KEYBOARD_B_AND_B, 0,
    // row 3 right
    0, HID_KEYBOARD_N_AND_N, HID_KEYBOARD_M_AND_M, HID_KEYBOARD_COMMA_AND_LESS_THAN,
    HID_KEYBOARD_PERIOD_AND_GREATER_THAN, HID_KEYBOARD_SLASH_AND_QUESTION_MARK,
    KEY_LAYER_SWITCH_RIGHT,

    // row 4 left
    HID_KEYBOARD_PAGE_UP, HID_KEYBOARD_END, HID_KEYBOARD_SPACEBAR, KEY_LAYER_SELECT_LEFT,
    HID_KEYBOARD_DELETE, HID_KEYBOARD_LEFT_CONTROL, 0,
    // row 4 right
    0, HID_KEYBOARD_RIGHT_CONTROL, HID_KEYBOARD_DELETE_FORWARD, KEY_LAYER_SELECT_RIGHT,
    HID_KEYBOARD_ENTER, HID_KEYBOARD_LEFT_ARROW, HID_KEYBOARD_UP_ARROW,

    // row 5 left
    HID_KEYBOARD_HOME, HID_KEYBOARD_PAGE_DOWN, 0, HID_KEYBOARD_ESCAPE, HID_KEYBOARD_LEFT_GUI,
    HID_KEYBOARD_LEFT_ALT, 0,
    // row 5 right
    0, HID_KEYBOARD_RIGHT_ALT, HID_KEYBOARD_RIGHT_GUI, HID_KEYBOARD_INSERT, 0,
    HID_KEYBOARD_DOWN_ARROW, HID_KEYBOARD_RIGHT_ARROW,

    // LAYER 1
    // LAYER 1
    // LAYER 1

    // row 0 left
    HID_KEYBOARD_GRAVE_ACCENT_AND_TILDE, HID_KEYBOARD_F1, HID_KEYBOARD_F2, HID_KEYBOARD_F3,
    HID_KEYBOARD_F4, HID_KEYBOARD_F5, HID_KEYBOARD_F6,
    // row 0 right
    HID_KEYBOARD_F7, HID_KEYBOARD_F8, HID_KEYBOARD_F9, HID_KEYBOARD_F10, HID_KEYBOARD_F11,
    HID_KEYBOARD_F12, HID_KEYBOARD_LEFT_BRACKET_AND_LEFT_CURLY_BRACE,

    // row 1 left
    HID_KEYBOARD_TAB, HID_KEYBOARD_6_AND_CARAT, HID_KEYBOARD_7_AND_AMPERSAND,
    HID_KEYBOARD_8_AND_ASTERISK, HID_KEYBOARD_9_AND_LEFT_PAREN, HID_KEYBOARD_0_AND_RIGHT_PAREN, 0,
    // row 1 right
    HID_KEYBOARD_BACKSLASH_AND_PIPE, HID_KEYBOARD_6_AND_CARAT, HID_KEYBOARD_7_AND_AMPERSAND,
    HID_KEYBOARD_8_AND_ASTERISK, HID_KEYBOARD_9_AND_LEFT_PAREN, HID_KEYBOARD_0_AND_RIGHT_PAREN,
    HID_KEYBOARD_RIGHT_BRACKET_AND_RIGHT_CURLY_BRACE,

    // row 2 left
    HID_KEYBOARD_LEFT_SHIFT, HID_KEYBOARD_1_AND_EXCLAMATION_POINT, HID_KEYBOARD_2_AND_AT,
    HID_KEYBOARD_3_AND_POUND, HID_KEYBOARD_4_AND_DOLLAR, HID_KEYBOARD_5_AND_PERCENT, 0,
    // row 2 right
    HID_KEYBOARD_QUOTE_AND_DOUBLEQUOTE, HID_KEYBOARD_1_AND_EXCLAMATION_POINT, HID_KEYBOARD_2_AND_AT,
    HID_KEYBOARD_3_AND_POUND, HID_KEYBOARD_4_AND_DOLLAR, HID_KEYBOARD_5_AND_PERCENT,
    HID_KEYBOARD_RIGHT_SHIFT,

    // row 3 left
    KEY_LAYER_SWITCH_LEFT, 0, 0, HID_KEYBOARD_MINUS_AND_UNDERSCORE, HID_KEYBOARD_EQUALS_AND_PLUS,
    0, 0,
    // row 3 right
    0, HID_KEYBOARD_MINUS_AND_UNDERSCORE, HID_KEYBOARD_EQUALS_AND_PLUS,
    HID_KEYBOARD_COMMA_AND_LESS_THAN, HID_KEYBOARD_PERIOD_AND_GREATER_THAN,
    HID_KEYBOARD_SLASH_AND_QUESTION_MARK, KEY_LAYER_SWITCH_RIGHT,

    // row 4 left
    HID_KEYBOARD_PAGE_UP, HID_KEYBOARD_END, HID_KEYBOARD_SPACEBAR, KEY_LAYER_SELECT_LEFT,
    HID_KEYBOARD_DELETE, HID_KEYBOARD_LEFT_CONTROL, 0,
    // row 4 right
    0, HID_KEYBOARD_RIGHT_CONTROL, HID_KEYBOARD_DELETE_FORWARD, KEY_LAYER_SELECT_RIGHT,
    HID_KEYBOARD_ENTER, HID_KEYBOARD_LEFT_ARROW, HID_KEYBOARD_UP_ARROW,

    // row 5 left
    HID_KEYBOARD_HOME, HID_KEYBOARD_PAGE_DOWN, 0, HID_KEYBOARD_ESCAPE, HID_KEYBOARD_LEFT_GUI,
    HID_KEYBOARD_LEFT_ALT, 0,
    // row 5 right
    0, HID_KEYBOARD_RIGHT_ALT, HID_KEYBOARD_RIGHT_GUI, HID_KEYBOARD_INSERT, 0,
    HID_KEYBOARD_DOWN_ARROW, HID_KEYBOARD_RIGHT_ARROW
};
#else
    #error "Unsupported release!"
#endif // THEKBD_RELEASE

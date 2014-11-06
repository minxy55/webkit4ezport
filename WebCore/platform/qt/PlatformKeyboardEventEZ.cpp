/*
 * Copyright (C) 2006 Nikolas Zimmermann <zimmermann@kde.org>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "PlatformKeyboardEvent.h"

#include "NotImplemented.h"
#include "WindowsKeyboardCodes.h"

#include "EZEvent.h"
#include <ctype.h>

using namespace std;
using namespace EZ;

namespace WebCore {

String keyIdentifierForQtKeyCode(int keyCode)
{
    switch (keyCode) {
    case EZ::Key_Menu:
    case EZ::Key_Alt:
        return "Alt";
    case EZ::Key_Clear:
        return "Clear";
    case EZ::Key_Down:
        return "Down";
    case EZ::Key_End:
        return "End";
    case EZ::Key_Return:
    case EZ::Key_Enter:
        return "Enter";
    case EZ::Key_Execute:
        return "Execute";
    case EZ::Key_F1:
        return "F1";
    case EZ::Key_F2:
        return "F2";
    case EZ::Key_F3:
        return "F3";
    case EZ::Key_F4:
        return "F4";
    case EZ::Key_F5:
        return "F5";
    case EZ::Key_F6:
        return "F6";
    case EZ::Key_F7:
        return "F7";
    case EZ::Key_F8:
        return "F8";
    case EZ::Key_F9:
        return "F9";
    case EZ::Key_F10:
        return "F10";
    case EZ::Key_F11:
        return "F11";
    case EZ::Key_F12:
        return "F12";
    case EZ::Key_F13:
        return "F13";
    case EZ::Key_F14:
        return "F14";
    case EZ::Key_F15:
        return "F15";
    case EZ::Key_F16:
        return "F16";
    case EZ::Key_F17:
        return "F17";
    case EZ::Key_F18:
        return "F18";
    case EZ::Key_F19:
        return "F19";
    case EZ::Key_F20:
        return "F20";
    case EZ::Key_F21:
        return "F21";
    case EZ::Key_F22:
        return "F22";
    case EZ::Key_F23:
        return "F23";
    case EZ::Key_F24:
        return "F24";
    case EZ::Key_Help:
        return "Help";
    case EZ::Key_Home:
        return "Home";
    case EZ::Key_Insert:
        return "Insert";
    case EZ::Key_Left:
        return "Left";
    case EZ::Key_PageDown:
        return "PageDown";
    case EZ::Key_PageUp:
        return "PageUp";
    case EZ::Key_Pause:
        return "Pause";
    case EZ::Key_Print:
        return "PrintScreen";
    case EZ::Key_Right:
        return "Right";
    case EZ::Key_Select:
        return "Select";
    case EZ::Key_Up:
        return "Up";
        // Standard says that DEL becomes U+007F.
    case EZ::Key_Delete:
        return "U+007F";
    case EZ::Key_Backspace:
        return "U+0008";
    case EZ::Key_Tab:
        return "U+0009";
    case EZ::Key_Backtab:
        return "U+0009";
    default:
        return String::format("U+%04X", toupper(keyCode));
    }
}

int windowsKeyCodeForKeyEvent(unsigned int keycode, bool isKeypad)
{
    // Determine wheter the event comes from the keypad
    if (isKeypad) {
        switch (keycode) {
        case EZ::Key_0:
            return VK_NUMPAD0; // (60) Numeric keypad 0 key
        case EZ::Key_1:
            return VK_NUMPAD1; // (61) Numeric keypad 1 key
        case EZ::Key_2:
            return  VK_NUMPAD2; // (62) Numeric keypad 2 key
        case EZ::Key_3:
            return VK_NUMPAD3; // (63) Numeric keypad 3 key
        case EZ::Key_4:
            return VK_NUMPAD4; // (64) Numeric keypad 4 key
        case EZ::Key_5:
            return VK_NUMPAD5; // (65) Numeric keypad 5 key
        case EZ::Key_6:
            return VK_NUMPAD6; // (66) Numeric keypad 6 key
        case EZ::Key_7:
            return VK_NUMPAD7; // (67) Numeric keypad 7 key
        case EZ::Key_8:
            return VK_NUMPAD8; // (68) Numeric keypad 8 key
        case EZ::Key_9:
            return VK_NUMPAD9; // (69) Numeric keypad 9 key
        case EZ::Key_Asterisk:
            return VK_MULTIPLY; // (6A) Multiply key
        case EZ::Key_Plus:
            return VK_ADD; // (6B) Add key
        case EZ::Key_Minus:
            return VK_SUBTRACT; // (6D) Subtract key
        case EZ::Key_Period:
            return VK_DECIMAL; // (6E) Decimal key
        case EZ::Key_Slash:
            return VK_DIVIDE; // (6F) Divide key
        case EZ::Key_PageUp:
            return VK_PRIOR; // (21) PAGE UP key
        case EZ::Key_PageDown:
            return VK_NEXT; // (22) PAGE DOWN key
        case EZ::Key_End:
            return VK_END; // (23) END key
        case EZ::Key_Home:
            return VK_HOME; // (24) HOME key
        case EZ::Key_Left:
            return VK_LEFT; // (25) LEFT ARROW key
        case EZ::Key_Up:
            return VK_UP; // (26) UP ARROW key
        case EZ::Key_Right:
            return VK_RIGHT; // (27) RIGHT ARROW key
        case EZ::Key_Down:
            return VK_DOWN; // (28) DOWN ARROW key
        case EZ::Key_Enter:
        case EZ::Key_Return:
            return VK_RETURN; // (0D) Return key
        case EZ::Key_Insert:
            return VK_INSERT; // (2D) INS key
        case EZ::Key_Delete:
            return VK_DELETE; // (2E) DEL key
        default:
            return 0;
        }

    } else

    switch (keycode) {
    case EZ::Key_Backspace:
        return VK_BACK; // (08) BACKSPACE key
    case EZ::Key_Backtab:
    case EZ::Key_Tab:
        return VK_TAB; // (09) TAB key
    case EZ::Key_Clear:
        return VK_CLEAR; // (0C) CLEAR key
    case EZ::Key_Enter:
    case EZ::Key_Return:
        return VK_RETURN; // (0D) Return key
    case EZ::Key_Shift:
        return VK_SHIFT; // (10) SHIFT key
    case EZ::Key_Control:
        return VK_CONTROL; // (11) CTRL key
    case EZ::Key_Menu:
    case EZ::Key_Alt:
        return VK_MENU; // (12) ALT key

    case EZ::Key_F1:
        return VK_F1;
    case EZ::Key_F2:
        return VK_F2;
    case EZ::Key_F3:
        return VK_F3;
    case EZ::Key_F4:
        return VK_F4;
    case EZ::Key_F5:
        return VK_F5;
    case EZ::Key_F6:
        return VK_F6;
    case EZ::Key_F7:
        return VK_F7;
    case EZ::Key_F8:
        return VK_F8;
    case EZ::Key_F9:
        return VK_F9;
    case EZ::Key_F10:
        return VK_F10;
    case EZ::Key_F11:
        return VK_F11;
    case EZ::Key_F12:
        return VK_F12;
    case EZ::Key_F13:
        return VK_F13;
    case EZ::Key_F14:
        return VK_F14;
    case EZ::Key_F15:
        return VK_F15;
    case EZ::Key_F16:
        return VK_F16;
    case EZ::Key_F17:
        return VK_F17;
    case EZ::Key_F18:
        return VK_F18;
    case EZ::Key_F19:
        return VK_F19;
    case EZ::Key_F20:
        return VK_F20;
    case EZ::Key_F21:
        return VK_F21;
    case EZ::Key_F22:
        return VK_F22;
    case EZ::Key_F23:
        return VK_F23;
    case EZ::Key_F24:
        return VK_F24;

    case EZ::Key_Pause:
        return VK_PAUSE; // (13) PAUSE key
    case EZ::Key_CapsLock:
        return VK_CAPITAL; // (14) CAPS LOCK key
    case EZ::Key_Kana_Lock:
    case EZ::Key_Kana_Shift:
        return VK_KANA; // (15) Input Method Editor (IME) Kana mode
    case EZ::Key_Hangul:
        return VK_HANGUL; // VK_HANGUL (15) IME Hangul mode
        // VK_JUNJA (17) IME Junja mode
        // VK_FINAL (18) IME final mode
    case EZ::Key_Hangul_Hanja:
        return VK_HANJA; // (19) IME Hanja mode
    case EZ::Key_Kanji:
        return VK_KANJI; // (19) IME Kanji mode
    case EZ::Key_Escape:
        return VK_ESCAPE; // (1B) ESC key
        // VK_CONVERT (1C) IME convert
        // VK_NONCONVERT (1D) IME nonconvert
        // VK_ACCEPT (1E) IME accept
        // VK_MODECHANGE (1F) IME mode change request
    case EZ::Key_Space:
        return VK_SPACE; // (20) SPACEBAR
    case EZ::Key_PageUp:
        return VK_PRIOR; // (21) PAGE UP key
    case EZ::Key_PageDown:
        return VK_NEXT; // (22) PAGE DOWN key
    case EZ::Key_End:
        return VK_END; // (23) END key
    case EZ::Key_Home:
        return VK_HOME; // (24) HOME key
    case EZ::Key_Left:
        return VK_LEFT; // (25) LEFT ARROW key
    case EZ::Key_Up:
        return VK_UP; // (26) UP ARROW key
    case EZ::Key_Right:
        return VK_RIGHT; // (27) RIGHT ARROW key
    case EZ::Key_Down:
        return VK_DOWN; // (28) DOWN ARROW key
    case EZ::Key_Select:
        return VK_SELECT; // (29) SELECT key
    case EZ::Key_Print:
        return VK_SNAPSHOT; // (2A) PRINT key
    case EZ::Key_Execute:
        return VK_EXECUTE; // (2B) EXECUTE key
    case EZ::Key_Insert:
        return VK_INSERT; // (2D) INS key
    case EZ::Key_Delete:
        return VK_DELETE; // (2E) DEL key
    case EZ::Key_Help:
        return VK_HELP; // (2F) HELP key
    case EZ::Key_0:
    case EZ::Key_ParenLeft:
        return VK_0; // (30) 0) key
    case EZ::Key_1:
        return VK_1; // (31) 1 ! key
    case EZ::Key_2:
    case EZ::Key_At:
        return VK_2; // (32) 2 & key
    case EZ::Key_3:
    case EZ::Key_NumberSign:
        return VK_3; // case '3': case '#';
    case EZ::Key_4:
    case EZ::Key_Dollar: // (34) 4 key '$';
        return VK_4;
    case EZ::Key_5:
    case EZ::Key_Percent:
        return VK_5; // (35) 5 key  '%'
    case EZ::Key_6:
    case EZ::Key_AsciiCircum:
        return VK_6; // (36) 6 key  '^'
    case EZ::Key_7:
    case EZ::Key_Ampersand:
        return VK_7; // (37) 7 key  case '&'
    case EZ::Key_8:
    case EZ::Key_Asterisk:
        return VK_8; // (38) 8 key  '*'
    case EZ::Key_9:
    case EZ::Key_ParenRight:
        return VK_9; // (39) 9 key '('
    case EZ::Key_A:
        return VK_A; // (41) A key case 'a': case 'A': return 0x41;
    case EZ::Key_B:
        return VK_B; // (42) B key case 'b': case 'B': return 0x42;
    case EZ::Key_C:
        return VK_C; // (43) C key case 'c': case 'C': return 0x43;
    case EZ::Key_D:
        return VK_D; // (44) D key case 'd': case 'D': return 0x44;
    case EZ::Key_E:
        return VK_E; // (45) E key case 'e': case 'E': return 0x45;
    case EZ::Key_F:
        return VK_F; // (46) F key case 'f': case 'F': return 0x46;
    case EZ::Key_G:
        return VK_G; // (47) G key case 'g': case 'G': return 0x47;
    case EZ::Key_H:
        return VK_H; // (48) H key case 'h': case 'H': return 0x48;
    case EZ::Key_I:
        return VK_I; // (49) I key case 'i': case 'I': return 0x49;
    case EZ::Key_J:
        return VK_J; // (4A) J key case 'j': case 'J': return 0x4A;
    case EZ::Key_K:
        return VK_K; // (4B) K key case 'k': case 'K': return 0x4B;
    case EZ::Key_L:
        return VK_L; // (4C) L key case 'l': case 'L': return 0x4C;
    case EZ::Key_M:
        return VK_M; // (4D) M key case 'm': case 'M': return 0x4D;
    case EZ::Key_N:
        return VK_N; // (4E) N key case 'n': case 'N': return 0x4E;
    case EZ::Key_O:
        return VK_O; // (4F) O key case 'o': case 'O': return 0x4F;
    case EZ::Key_P:
        return VK_P; // (50) P key case 'p': case 'P': return 0x50;
    case EZ::Key_Q:
        return VK_Q; // (51) Q key case 'q': case 'Q': return 0x51;
    case EZ::Key_R:
        return VK_R; // (52) R key case 'r': case 'R': return 0x52;
    case EZ::Key_S:
        return VK_S; // (53) S key case 's': case 'S': return 0x53;
    case EZ::Key_T:
        return VK_T; // (54) T key case 't': case 'T': return 0x54;
    case EZ::Key_U:
        return VK_U; // (55) U key case 'u': case 'U': return 0x55;
    case EZ::Key_V:
        return VK_V; // (56) V key case 'v': case 'V': return 0x56;
    case EZ::Key_W:
        return VK_W; // (57) W key case 'w': case 'W': return 0x57;
    case EZ::Key_X:
        return VK_X; // (58) X key case 'x': case 'X': return 0x58;
    case EZ::Key_Y:
        return VK_Y; // (59) Y key case 'y': case 'Y': return 0x59;
    case EZ::Key_Z:
        return VK_Z; // (5A) Z key case 'z': case 'Z': return 0x5A;
    case EZ::Key_Meta:
        return VK_LWIN; // (5B) Left Windows key (Microsoft Natural keyboard)
        // case EZ::Key_Meta_R: FIXME: What to do here?
        //    return VK_RWIN; // (5C) Right Windows key (Natural keyboard)
        // VK_APPS (5D) Applications key (Natural keyboard)
        // VK_SLEEP (5F) Computer Sleep key
        // VK_SEPARATOR (6C) Separator key
        // VK_SUBTRACT (6D) Subtract key
        // VK_DECIMAL (6E) Decimal key
        // VK_DIVIDE (6F) Divide key
        // handled by key code above

    case EZ::Key_NumLock:
        return VK_NUMLOCK; // (90) NUM LOCK key

    case EZ::Key_ScrollLock:
        return VK_SCROLL; // (91) SCROLL LOCK key

        // VK_LSHIFT (A0) Left SHIFT key
        // VK_RSHIFT (A1) Right SHIFT key
        // VK_LCONTROL (A2) Left CONTROL key
        // VK_RCONTROL (A3) Right CONTROL key
        // VK_LMENU (A4) Left MENU key
        // VK_RMENU (A5) Right MENU key
        // VK_BROWSER_BACK (A6) Windows 2000/XP: Browser Back key
        // VK_BROWSER_FORWARD (A7) Windows 2000/XP: Browser Forward key
        // VK_BROWSER_REFRESH (A8) Windows 2000/XP: Browser Refresh key
        // VK_BROWSER_STOP (A9) Windows 2000/XP: Browser Stop key
        // VK_BROWSER_SEARCH (AA) Windows 2000/XP: Browser Search key
        // VK_BROWSER_FAVORITES (AB) Windows 2000/XP: Browser Favorites key
        // VK_BROWSER_HOME (AC) Windows 2000/XP: Browser Start and Home key
        // VK_VOLUME_MUTE (AD) Windows 2000/XP: Volume Mute key
        // VK_VOLUME_DOWN (AE) Windows 2000/XP: Volume Down key
        // VK_VOLUME_UP (AF) Windows 2000/XP: Volume Up key
        // VK_MEDIA_NEXT_TRACK (B0) Windows 2000/XP: Next Track key
        // VK_MEDIA_PREV_TRACK (B1) Windows 2000/XP: Previous Track key
        // VK_MEDIA_STOP (B2) Windows 2000/XP: Stop Media key
        // VK_MEDIA_PLAY_PAUSE (B3) Windows 2000/XP: Play/Pause Media key
        // VK_LAUNCH_MAIL (B4) Windows 2000/XP: Start Mail key
        // VK_LAUNCH_MEDIA_SELECT (B5) Windows 2000/XP: Select Media key
        // VK_LAUNCH_APP1 (B6) Windows 2000/XP: Start Application 1 key
        // VK_LAUNCH_APP2 (B7) Windows 2000/XP: Start Application 2 key

        // VK_OEM_1 (BA) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the ';:' key
    case EZ::Key_Semicolon:
    case EZ::Key_Colon:
        return VK_OEM_1; // case ';': case ':': return 0xBA;
        // VK_OEM_PLUS (BB) Windows 2000/XP: For any country/region, the '+' key
    case EZ::Key_Plus:
    case EZ::Key_Equal:
        return VK_OEM_PLUS; // case '=': case '+': return 0xBB;
        // VK_OEM_COMMA (BC) Windows 2000/XP: For any country/region, the ',' key
    case EZ::Key_Comma:
    case EZ::Key_Less:
        return VK_OEM_COMMA; // case ',': case '<': return 0xBC;
        // VK_OEM_MINUS (BD) Windows 2000/XP: For any country/region, the '-' key
    case EZ::Key_Minus:
    case EZ::Key_Underscore:
        return VK_OEM_MINUS; // case '-': case '_': return 0xBD;
        // VK_OEM_PERIOD (BE) Windows 2000/XP: For any country/region, the '.' key
    case EZ::Key_Period:
    case EZ::Key_Greater:
        return VK_OEM_PERIOD; // case '.': case '>': return 0xBE;
        // VK_OEM_2 (BF) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '/?' key
    case EZ::Key_Slash:
    case EZ::Key_Question:
        return VK_OEM_2; // case '/': case '?': return 0xBF;
        // VK_OEM_3 (C0) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '`~' key
    case EZ::Key_AsciiTilde:
    case EZ::Key_QuoteLeft:
        return VK_OEM_3; // case '`': case '~': return 0xC0;
        // VK_OEM_4 (DB) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '[{' key
    case EZ::Key_BracketLeft:
    case EZ::Key_BraceLeft:
        return VK_OEM_4; // case '[': case '{': return 0xDB;
        // VK_OEM_5 (DC) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '\|' key
    case EZ::Key_Backslash:
    case EZ::Key_Bar:
        return VK_OEM_5; // case '\\': case '|': return 0xDC;
        // VK_OEM_6 (DD) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the ']}' key
    case EZ::Key_BracketRight:
    case EZ::Key_BraceRight:
        return VK_OEM_6; // case ']': case '}': return 0xDD;
        // VK_OEM_7 (DE) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the 'single-quote/double-quote' key
    case EZ::Key_QuoteDbl:
        return VK_OEM_7; // case '\'': case '"': return 0xDE;
        // VK_OEM_8 (DF) Used for miscellaneous characters; it can vary by keyboard.
        // VK_OEM_102 (E2) Windows 2000/XP: Either the angle bracket key or the backslash key on the RT 102-key keyboard
        // VK_PROCESSKEY (E5) Windows 95/98/Me, Windows NT 4.0, Windows 2000/XP: IME PROCESS key
        // VK_PACKET (E7) Windows 2000/XP: Used to pass Unicode characters as if they were keystrokes. The VK_PACKET key is the low word of a 32-bit Virtual Key value used for non-keyboard input methods. For more information, see Remark in KEYBDINPUT,SendInput, WM_KEYDOWN, and WM_KEYUP
        // VK_ATTN (F6) Attn key
        // VK_CRSEL (F7) CrSel key
        // VK_EXSEL (F8) ExSel key
        // VK_EREOF (F9) Erase EOF key
        // VK_PLAY (FA) Play key
        // VK_ZOOM (FB) Zoom key
        // VK_NONAME (FC) Reserved for future use
        // VK_PA1 (FD) PA1 key
        // VK_OEM_CLEAR (FE) Clear key
    default:
        return 0;
    }
}

static bool isVirtualKeyCodeRepresentingCharacter(int code)
{
    switch (code) {
    case VK_SPACE:
    case VK_0:
    case VK_1:
    case VK_2:
    case VK_3:
    case VK_4:
    case VK_5:
    case VK_6:
    case VK_7:
    case VK_8:
    case VK_9:
    case VK_A:
    case VK_B:
    case VK_C:
    case VK_D:
    case VK_E:
    case VK_F:
    case VK_G:
    case VK_H:
    case VK_I:
    case VK_J:
    case VK_K:
    case VK_L:
    case VK_M:
    case VK_N:
    case VK_O:
    case VK_P:
    case VK_Q:
    case VK_R:
    case VK_S:
    case VK_T:
    case VK_U:
    case VK_V:
    case VK_W:
    case VK_X:
    case VK_Y:
    case VK_Z:
    case VK_NUMPAD0:
    case VK_NUMPAD1:
    case VK_NUMPAD2:
    case VK_NUMPAD3:
    case VK_NUMPAD4:
    case VK_NUMPAD5:
    case VK_NUMPAD6:
    case VK_NUMPAD7:
    case VK_NUMPAD8:
    case VK_NUMPAD9:
    case VK_MULTIPLY:
    case VK_ADD:
    case VK_SEPARATOR:
    case VK_SUBTRACT:
    case VK_DECIMAL:
    case VK_DIVIDE:
    case VK_OEM_1:
    case VK_OEM_PLUS:
    case VK_OEM_COMMA:
    case VK_OEM_MINUS:
    case VK_OEM_PERIOD:
    case VK_OEM_2:
    case VK_OEM_3:
    case VK_OEM_4:
    case VK_OEM_5:
    case VK_OEM_6:
    case VK_OEM_7:
        return true;
    default:
        return false;
    }
}

static String keyTextForKeyEvent(EZKeyEvent* event)
{
    switch (event->key()) {
    case EZ::Key_Tab:
    case EZ::Key_Backtab:
        if (event->text().isNull())
            return "\t";
        break;
    case EZ::Key_Enter:
        if (event->text().isNull())
            return "\r";
    }
    return event->text();
}

PlatformKeyboardEvent::PlatformKeyboardEvent(EZKeyEvent* event)
{
    const int state = event->modifiers();
    m_type = (event->type() == EZKeyEvent::KeyRelease) ? KeyUp : KeyDown;
    m_text = keyTextForKeyEvent(event);
    m_unmodifiedText = m_text; // FIXME: not correct
    m_keyIdentifier = keyIdentifierForQtKeyCode(event->key());
    m_autoRepeat = event->isAutoRepeat();
    m_ctrlKey = (state & EZ::ControlModifier);
    m_altKey = (state & EZ::AltModifier);
    m_metaKey = (state & EZ::MetaModifier);
    m_isKeypad = (state & EZ::KeypadModifier);
    m_windowsVirtualKeyCode = windowsKeyCodeForKeyEvent(event->key(), m_isKeypad);
    m_nativeVirtualKeyCode = event->nativeVirtualKey();
    m_shiftKey = (state & EZ::ShiftModifier) || event->key() == EZ::Key_Backtab; // Simulate Shift+Tab with Key_Backtab
    m_ezEvent = event;
}

void PlatformKeyboardEvent::disambiguateKeyDownEvent(Type type, bool)
{
    // Can only change type from KeyDown to RawKeyDown or Char, as we lack information for other conversions.
    ASSERT(m_type == KeyDown);
    m_type = type;

    if (type == RawKeyDown) {
        m_text = String();
        m_unmodifiedText = String();
    } else {
        /*
            When we receive shortcut events like Ctrl+V then the text in the QKeyEvent is
            empty. If we're asked to disambiguate the event into a Char keyboard event,
            we try to detect this situation and still set the text, to ensure that the
            general event handling sends a key press event after this disambiguation.
        */
        if (m_text.isEmpty() && m_windowsVirtualKeyCode && isVirtualKeyCodeRepresentingCharacter(m_windowsVirtualKeyCode))
            m_text.append(UChar(m_windowsVirtualKeyCode));

        m_keyIdentifier = String();
        m_windowsVirtualKeyCode = 0;
    }
}

bool PlatformKeyboardEvent::currentCapsLockState()
{
    notImplemented();
    return false;
}

void PlatformKeyboardEvent::getCurrentModifierState(bool& shiftKey, bool& ctrlKey, bool& altKey, bool& metaKey)
{
    notImplemented();
    shiftKey = false;
    ctrlKey = false;
    altKey = false;
    metaKey = false;
}

uint32_t PlatformKeyboardEvent::nativeModifiers() const
{
    ASSERT(m_ezEvent);
    return m_ezEvent->nativeModifiers();
}

uint32_t PlatformKeyboardEvent::nativeScanCode() const
{
    ASSERT(m_ezEvent);
    return m_ezEvent->nativeScanCode();
}

}

// vim: ts=4 sw=4 et

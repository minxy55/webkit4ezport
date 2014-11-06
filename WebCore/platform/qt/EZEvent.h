
#ifndef EZ_KEY_EVENT_H_
#define EZ_KEY_EVENT_H_

#include "EZTypeDef.h"
#include "EZPoint.h"

namespace EZ
{
	enum MouseButton {
		NoneButton = 0,
		LeftButton = 1 << 0,
		MidButton = 1 << 2,
		RightButton = 1 << 3,
	};
	
	const EZ_INT32U NoModifier = 0;
	const EZ_INT32U ControlModifier = 1 << 0;
	const EZ_INT32U AltModifier = 1 << 1;
	const EZ_INT32U MetaModifier = 1 << 2;
	const EZ_INT32U KeypadModifier = 1 << 3;
	const EZ_INT32U ShiftModifier = 1 << 4;

	enum KeyVal {
		Key_None = 0x00,
		Key_Menu = 0x80,
	    Key_Alt,
	    Key_Clear,
	    Key_Return,
	    Key_Enter,
	    Key_F1,
	    Key_F2,
	    Key_F3,
	    Key_F4,
	    Key_F5,
	    Key_F6,
	    Key_F7,
	    Key_F8,
	    Key_F9,
	    Key_F10,
	    Key_F11,
	    Key_F12,
	    Key_F13,
	    Key_F14,
	    Key_F15,
	    Key_F16,
	    Key_F17,
	    Key_F18,
	    Key_F19,
	    Key_F20,
	    Key_F21,
	    Key_F22,
	    Key_F23,
	    Key_F24,
	    Key_Help,
		// Standard says that DEL becomes U+007F.
	    Key_Backspace,
	    Key_Tab,
	    Key_Backtab,

		Key_Shift,
		Key_Control,
		Key_Pause,
	    Key_CapsLock,
	    Key_Kana_Lock,
	    Key_Kana_Shift,
	    Key_Hangul,
	    Key_Hangul_Hanja,
	    Key_Kanji,
	    Key_Escape,
	    Key_Space,
	    Key_PageUp,
	    Key_PageDown,
	    Key_End,
	    Key_Home,
	    Key_Left,
	    Key_Up,
	    Key_Right,
	    Key_Down,
	    Key_Select,
	    Key_Print,
	    Key_Execute,
	    Key_Insert,
	    Key_Delete,
	    Key_Asterisk,
		Key_Plus,
		Key_Minus,
		Key_Period,
		Key_Slash,
		Key_ParenLeft,
	    Key_ParenRight,
	    Key_NumberSign,
	    Key_Dollar,
	    Key_Percent,
	    Key_AsciiCircum,
	    Key_Ampersand,
	    
	    Key_0,
	    Key_1,
	    Key_2,
	    Key_At,
	    Key_3,
	    Key_4,
	    Key_5,
	    Key_6,
	    Key_7,
	    Key_8,
	    Key_9,
	    Key_A,
	    Key_B,
	    Key_C,
	    Key_D,
	    Key_E,
	    Key_F,
	    Key_G,
	    Key_H,
	    Key_I,
	    Key_J,
	    Key_K,
	    Key_L,
	    Key_M,
	    Key_N,
	    Key_O,
	    Key_P,
	    Key_Q,
	    Key_R,
	    Key_S,
	    Key_T,
	    Key_U,
	    Key_V,
	    Key_W,
	    Key_X,
	    Key_Y,
	    Key_Z,
	    Key_Meta,

	    Key_NumLock,

	    Key_ScrollLock,
	    Key_Semicolon,
	    Key_Colon,
	    Key_Equal,
	    Key_Comma,
	    Key_Less,
	    Key_Underscore,
	    Key_Greater,
	    Key_Question,
	    Key_AsciiTilde,
	    Key_QuoteLeft,
	    Key_BracketLeft,
	    Key_BraceLeft,
	    Key_Backslash,
	    Key_Bar,
	    Key_BracketRight,
	    Key_BraceRight,
	    Key_QuoteDbl,

		Key_Back,
		Key_Forward,
		Key_Stop,
		Key_Refresh,
	};
		
class EZEvent {
public:
	enum EventType {
		GraphicsSceneMouseDoubleClick,
		GraphicsSceneMousePress,
		GraphicsSceneMouseRelease,
		GraphicsSceneMouseMove,
	};

	EventType type() { return m_type; }

protected:
	EventType m_type;

};


class EZKeySequence {
public:
	enum StandardKey {
		UnknownKey,
		Cut,
        Copy,
        Paste,
        Undo,
        Redo,
        MoveToNextChar,
        MoveToPreviousChar,
        MoveToNextWord,
        MoveToPreviousWord,
        MoveToNextLine,
        MoveToPreviousLine,
        MoveToStartOfLine,
        MoveToEndOfLine,
        MoveToStartOfBlock,
        MoveToEndOfBlock,
        MoveToStartOfDocument,
        MoveToEndOfDocument,
        MoveToPreviousPage,
        MoveToNextPage,
        SelectNextChar,
        SelectPreviousChar,
        SelectNextWord,
        SelectPreviousWord,
        SelectNextLine,
        SelectPreviousLine,
        SelectStartOfLine,
        SelectEndOfLine,
        SelectStartOfBlock,
        SelectEndOfBlock,
        SelectStartOfDocument,
        SelectEndOfDocument,
        DeleteStartOfWord,
        DeleteEndOfWord,
        InsertParagraphSeparator,
        InsertLineSeparator,
        SelectAll,
	};
};


class EZKeyEvent : public EZEvent {
public:
	enum KeyState {
		KeyPress = 0x70,
		KeyRelease = 0x71,
	};

public:
	EZKeyEvent() { m_type = (EventType)0; }
	EZKeyEvent(KeyState keyState, KeyVal keyVal, EZ_INT32U m) { m_type = (EventType)0; }
	
	KeyVal key() { return Key_None; }
	bool isAutoRepeat() { return false; }
	void setAccepted(bool) { }
	String text() { return ""; }

	static EZ_INT32U KeyboardModifiers(EZ_INT32U m) { return 0; }

	EZ_INT32U modifiers() { return 0; }
	EZ_INT32U nativeModifiers() { return 0; }
    EZ_INT32U nativeScanCode() { return 0; }
	EZ_INT32U nativeVirtualKey() { return 0; }

	EZKeySequence::StandardKey keySequence() { return EZKeySequence::UnknownKey; };
};


class EZInputEvent : public EZEvent {
public:
	
};

class EZMouseEvent : public EZInputEvent {
public:
	MouseButton buttons() { return NoneButton; }
};

class EZGraphicsSceneMouseEvent : public EZMouseEvent {
public:
};


class EZContextMenuEvent : EZInputEvent {
public:
	EZPoint pos() { return EZPoint(0, 0); }
	EZPoint globalPos() { return EZPoint(0, 0); }
};
		
};

#endif



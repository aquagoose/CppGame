//
// Created by ollie on 12/09/22.
//

#ifndef GAME_INPUT_H
#define GAME_INPUT_H

#include <unordered_set>
#include <GLFW/glfw3.h>

namespace Engine {

    enum Keys {
        Unknown = -1,

        Space = 32,
        Apostrophe = 39,

        Comma = 44,
        Minus,
        Period,
        Dot = Period,
        Slash,

        Num0,
        Num1,
        Num2,
        Num3,
        Num4,
        Num5,
        Num6,
        Num7,
        Num8,
        Num9,

        Semicolon = 59,
        Equals = 61,

        A = 65,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,

        LeftBracket = 91,
        Backslash,
        RightBracket,

        GraveAccent = 96,
        Backtick = GraveAccent,
        World1 = 161,
        World2 = 162,

        Escape = 256,
        Enter,
        Tab,
        Backspace,
        Insert,
        Delete,
        Right,
        Left,
        Down,
        Up,
        PageUp,
        PageDown,
        Home,
        End,

        CapsLock = 280,
        ScrollLock,
        NumLock,
        PrintScreen,
        Pause,

        F1 = 290,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,
        F13,
        F14,
        F15,
        F16,
        F17,
        F18,
        F19,
        F20,
        F21,
        F22,
        F23,
        F24,
        F25,

        Keypad0 = 320,
        Keypad1,
        Keypad2,
        Keypad3,
        Keypad4,
        Keypad5,
        Keypad6,
        Keypad7,
        Keypad8,
        Keypad9,
        KeypadDecimal,
        KeypadDivide,
        KeypadMultiply,
        KeypadSubtract,
        KeypadAdd,
        KeypadEnter,
        KeypadEqual,

        LeftShift = 340,
        LeftControl,
        LeftAlt,
        LeftSuper,
        RightShift,
        RightControl,
        RightAlt,
        RightSuper,

        Menu
    };

    class Input {
    private:
        Input() {}

        std::unordered_set<Keys> _keysDown;
        std::unordered_set<Keys> _newKeys;

        static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    public:
        static void _Initialize(GLFWwindow* window);
        static void _Update(GLFWwindow* window);

        static bool KeyDown(Keys key);

        static bool KeyPressed(Keys key);
    };

} // Engine

#endif //GAME_INPUT_H

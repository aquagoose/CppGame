//
// Created by ollie on 11/09/2022.
//

#ifndef GAME_TIME_H
#define GAME_TIME_H

namespace Engine {

    class Time {
    private:
        Time() = default;
        static float _lastTime;
        static float _deltaTime;
        static float _totalTime;

    public:
        static void _Initialize();
        static void _Update();

        static float DeltaTime();
        static float TotalTime();
    };

} // Engine

#endif //GAME_TIME_H

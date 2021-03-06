#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "entities/Cannon.h"
#include "entities/Ball.h"

class Game {
  private:
    bool _isRunning;
    SDL_Window* _window;
    float _deltaTime;
    int _ticksLastFrame;
    void _updateDeltaTime();
    void _waitForTargetFramerate();
    Cannon* _cannon;
    Ball* _ball;

  public:
    Game();
    ~Game();
    static SDL_Renderer* Renderer;
    bool IsRunning() const;
    void Initialize(const int width, const int height);
    void Update();
    void Render();
    void ProcessInput();
    void Quit();
};

#endif

#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "EntityManager.h"

class EntityManager;

class Game {
  private:
    bool _isRunning;
    SDL_Window* _window;
    EntityManager* _entityManager;
    float _deltaTime;
    int _ticksLastFrame;
    void _updateDeltaTime();
    void _waitForTargetFramerate();

  public:
    Game();
    static SDL_Renderer* Renderer;
    bool IsRunning() const;
    void Initialize(const int width, const int height);
    void Update();
    void Render();
    void ProcessInput();
    void Destroy();
};

#endif

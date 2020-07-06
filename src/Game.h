#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "EntityManager.h"

class Game {
  private:
    bool _isRunning;
    SDL_Window* _window;
    static SDL_Renderer* _renderer;
    EntityManager* _entityManager;

  public:
    Game();
    bool IsRunning() const;
    void Initialize(const int width, const int height);
    void Update();
    void Render();
    void ProcessInput();
    void Destroy();
};

#endif

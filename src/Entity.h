#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>

struct Cordinate{
  int x;
  int y;
};

class Entity{
  private:
    Cordinate _position;
    SDL_Rect _body;

  public:
    Entity(const int height, const int width, const Cordinate position);
    void Spawn(SDL_Renderer* renderer);
    void Update();
    void Render();
};

#endif

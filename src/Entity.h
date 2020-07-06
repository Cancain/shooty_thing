#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <string>

struct Cordinate{
  int x;
  int y;
};

class Entity{
  private:
    SDL_Rect _body;
    std::string _name;

  public:
    Entity(const std::string name, const int height, const int width, const Cordinate position);
    void Spawn(SDL_Renderer* renderer);
    void Update();
    void Render(SDL_Renderer* renderer);
};

#endif

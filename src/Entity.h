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
    std::string _name;

  protected:
    SDL_Rect _body;

  public:
    Entity(
        const std::string name, 
        const int height, 
        const int width, 
        const Cordinate position
        );
    void Update();
    void Render(SDL_Renderer* renderer);
};

#endif

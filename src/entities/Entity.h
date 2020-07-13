#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <string>
#include "../Constants.h"

struct Cordinate{
  int x;
  int y;
};

enum Bounds {
  top,
  right,
  bottom,
  left,
  none
};

class Entity{
  private:
    std::string _name;

  protected:
    SDL_Rect _body;
    bool _isOutOfBounds(const Cordinate pos);
    Bounds _hasReachedBounds(const Cordinate pos);

  public:
    Entity(
        const std::string name, 
        const int height, 
        const int width, 
        const Cordinate position
        );
    void Render(SDL_Renderer* renderer);
    void Update();
    void HandleInput(const SDL_Event& event);
    Cordinate GetPosition() const;
};

#endif

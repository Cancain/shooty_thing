#include "Entity.h"

Entity::Entity(const std::string name, const int height, const int width, const Cordinate position): _name(name){
  _body = {
    position.x,
    position.y,
    width,
    height,
  };
}

bool Entity::_isOutOfBounds(const Cordinate pos){
  unsigned int x = pos.x;
  unsigned int y = pos.y;
  const bool XOob = x <= 0 || x >= WIDTH - _body.w;
  const bool YOob = y <= 0 || y >= HEIGHT - _body.h;
  return XOob && YOob;
}

void Entity::Render(SDL_Renderer* renderer){
  SDL_RenderFillRect(renderer, &_body);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}


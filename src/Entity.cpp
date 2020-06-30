#include "Entity.h"

Entity::Entity(const int height, const int width, const Cordinate position): _position(position){
  _body = {
    position.x,
    position.y,
    height,
    width
  };
}

void Entity::Spawn(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &_body);
}

#include "Entity.h"

Entity::Entity(const std::string name, const int height, const int width, const Cordinate position): _name(name){
  _body = {
    position.x,
    position.y,
    height,
    width
  };
}

void Entity::Update(){

}

void Entity::Render(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &_body);
}

void Entity::Spawn(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &_body);
}

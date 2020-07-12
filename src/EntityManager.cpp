#include "EntityManager.h"
#include <iostream>

void EntityManager::Update(){
  for (Entity* entity : _entities){
    entity->Update();
  }
}

void EntityManager::Render(){
  for (Entity* entity : _entities){
    entity->Render(Game::Renderer);
  }
}

void EntityManager::HandleInput(const SDL_Event &event){
  for (Entity* entity: _entities){
    entity->HandleInput(event);
  }
}

bool EntityManager::HasNoEntities() const {
  return _entities.size() <= 0;
}

void EntityManager::AddEntity(Entity* entity){
  _entities.push_back(entity);
}

std::vector<Entity*> EntityManager::GetEntities() const {
  return _entities;
}

unsigned int EntityManager::GetEntityCount() const {
  return _entities.size();
}

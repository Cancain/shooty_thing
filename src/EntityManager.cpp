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

bool EntityManager::HasNoEntities() const {
  return _entities.size() <= 0;
}

Entity& EntityManager::AddEntity(Entity* entity){
  /* Cordinate position = { */
  /*   400, */
  /*   300 */
  /* }; */
  /* Entity* entity = new Entity(entityName, height, width, position); */
  _entities.push_back(entity);
  return *entity;
}

std::vector<Entity*> EntityManager::GetEntities() const {
  return _entities;
}

unsigned int EntityManager::GetEntityCount() const {
  return _entities.size();
}

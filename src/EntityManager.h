#ifndef ENTITY_MANAGER
#define ENTITY_MANAGER

#include <vector>
#include <string>
#include "Entity.h"
#include "Game.h"

class EntityManager{
  private:
    std::vector<Entity*> _entities;

  public:
    void Update();
    void Render();
    void HandleInput(const SDL_Event& event);
    bool HasNoEntities() const;
    void AddEntity(Entity* entity);
    std::vector<Entity*> GetEntities() const;
    unsigned int GetEntityCount() const;
};

#endif

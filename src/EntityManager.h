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
    bool HasNoEntities() const;
    Entity& AddEntity(const std::string entityName, const int width, const int height);
    std::vector<Entity*> GetEntities() const;
    unsigned int GetEntityCount() const;
};

#endif

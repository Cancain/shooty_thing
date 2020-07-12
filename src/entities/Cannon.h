#ifndef CANNON_H
#define CANNON_H

#include "Entity.h"
#include "../Constants.h"

class Cannon : public Entity {
  private: 
    float _velocity;

   public: 
    Cannon(
        const std::string name = "Cannon", 
        const int height = DEFAULT_CANNON_HEIGHT,
        const int width = DEFAULT_CANNON_WIDTH,
        const Cordinate position = {
        WIDTH / 2 - DEFAULT_CANNON_WIDTH,
        HEIGHT - DEFAULT_CANNON_HEIGHT
        });
    void HandleInput(const SDL_Keycode key);
    void Render(SDL_Renderer* renderer);
    void Update();
    void SetVelocity(const float velocity);
    float GetVelocity() const;
};


#endif

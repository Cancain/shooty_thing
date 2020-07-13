#ifndef BALL_H
#define BALL_H

#include "Entity.h"
#include "Cannon.h"

class Cannon;

class Ball : public Entity {
  private:
    Cordinate _velocity;
    Cannon* _cannon;
    bool _isHeld;
    void _updatePosition();
    void _serve();
    bool _cannonCollision();

  public:
    Ball(
        const std::string name = "Ball",
        const int height = 10,
        const int width = 10,
        const Cordinate position = {
        100,
        200
        }
    );
    Ball(Cannon* cannon);
    float GetVelocity() const;
    void SetVelocity(const float velocity);
    void Render(SDL_Renderer* renderer);
    void Update();
    void HandleInput(const SDL_Keycode key);
    void SetCannon(Cannon* cannon);
    void SetIsHeld(bool isHeld);
    bool GetIsHeld();
    Cordinate GetPosition();
    
};

#endif

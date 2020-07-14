#ifndef BALL_H
#define BALL_H

#include "Entity.h"
#include "Cannon.h"

class Cannon;

class Ball : public Entity {
  private:
    float _currentVelocity;
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
    void SetCannon(Cannon* cannon);
    void SetIsHeld(bool isHeld);
    bool GetIsHeld() const;
    Cordinate GetPosition() const;
    void SetCurrentVelocity(const float velocity);
    float GetCurrentVelocity()const ;
    void SetVelocity(const float velocity);
    void Render(SDL_Renderer* renderer);
    void Update();
    void HandleInput(const Uint8* keyState);
};

#endif

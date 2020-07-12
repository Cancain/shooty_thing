#include <iostream>
#include "Game.h"
#include "Constants.h"
#include "./entities/Cannon.h"

SDL_Renderer* Game::Renderer;

Game::Game():_isRunning(false){
  _entityManager = new EntityManager;
};

bool Game::IsRunning() const{
  return _isRunning;
}

SDL_Window* createWindow(const int width, const int height){
  SDL_Window *window = SDL_CreateWindow(
      "Shooty thing",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      width,
      height,
      SDL_WINDOW_BORDERLESS);

  if(!window){
    throw "Could not create a window";
  }

  return window;
}

SDL_Renderer* createRenderer(SDL_Window* window){
  SDL_Renderer* renderer = SDL_CreateRenderer(
      window,
      -1,
      0);

  if(!renderer){
    throw "Could not create renderer";
  }

  return renderer;
}

void Game::Initialize(const int width, const int height){
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
    throw "Sorry, could not initialize SDL";
    return;
  }

  _window = createWindow(800, 600);
  Renderer = createRenderer(_window);

  Cannon* cannon = new Cannon();
  _entityManager->AddEntity(cannon);

  _isRunning = true;
}

void Game::ProcessInput(){
  SDL_Event event;
  SDL_PollEvent(&event);
  _entityManager->HandleInput(event);

  switch(event.type) {
    case SDL_QUIT:
      _isRunning = false;
      break;
    default:
      break;
  }
}

void Game::_waitForTargetFramerate(){
  const unsigned int FRAME_TARGET_TIME = 1000 / 60;
  int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - _ticksLastFrame);

  if(timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME){
    SDL_Delay(timeToWait);
  }
}

void Game::_updateDeltaTime(){
  _deltaTime = (SDL_GetTicks() - _ticksLastFrame) / 1000.0f;
  _ticksLastFrame = SDL_GetTicks();
  _deltaTime = _deltaTime > 0.05f ? 0.05f : _deltaTime;
}

void Game::Update(){
  _waitForTargetFramerate();
  _updateDeltaTime();
  _entityManager->Update();

}

void Game::Render(){
  SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
  SDL_RenderClear(Renderer);
  _entityManager->Render();
  SDL_RenderPresent(Renderer);

}

void Game::Destroy(){
  delete _entityManager;
  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(_window);
  SDL_Quit();
}

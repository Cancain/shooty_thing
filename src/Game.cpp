#include "Game.h"
#include "Constants.h"


/*
 * Globals
 */
SDL_Renderer* Game::Renderer;


/*
 * Constructors
 */
bool Game::IsRunning() const{
  return _isRunning;
}

SDL_Window* createWindow(const int width, const int height){
  SDL_Window* window = SDL_CreateWindow(
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


/*
 * Deconstructor
 */
Game::~Game(){
  delete _cannon;
  delete _ball;
  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(_window);
  SDL_Quit();
}
Game::Game():_isRunning(false){};


/*
 * Methods and functions
 */
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

  _window = createWindow(width, height);
  Renderer = createRenderer(_window);
  _cannon = new Cannon();
  _ball = new Ball();
  _ball->SetCannon(_cannon);

  _isRunning = true;
}

void Game::_waitForTargetFramerate(){
  const unsigned int FRAME_TARGET_TIME = 1000 / 60;
  unsigned int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - _ticksLastFrame);

  if(timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME){
    SDL_Delay(timeToWait);
  }
}

void Game::ProcessInput(){
  SDL_Event event;
  SDL_PollEvent(&event);
  const Uint8* keyState = SDL_GetKeyboardState(NULL);

  if(event.type == SDL_QUIT){
    _isRunning = false;
  }

  _cannon->HandleInput(keyState);
  _ball->HandleInput(keyState);
}

void Game::_updateDeltaTime(){
  _deltaTime = (SDL_GetTicks() - _ticksLastFrame) / 1000.0f;
  _ticksLastFrame = SDL_GetTicks();
  _deltaTime = _deltaTime > 0.05f ? 0.05f : _deltaTime;
}

void Game::Update(){
  _waitForTargetFramerate();
  _updateDeltaTime();
  _ball->Update();
  _cannon->Update();
}

void Game::Render(){
  SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
  SDL_RenderClear(Renderer);
  _cannon->Render(Renderer);
  _ball->Render(Renderer);
  SDL_RenderPresent(Renderer);
}


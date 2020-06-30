#include "Game.h"

Game::Game():_isRunning(false){};
SDL_Renderer* Game::_renderer;

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
  _renderer = createRenderer(_window);

  _isRunning = true;
}

void Game::ProcessInput(){
  SDL_Event event;
  SDL_PollEvent(&event);

  switch(event.type) {
    case SDL_QUIT:
      _isRunning = false;
      break;
    default:
      break;
  }
}

void Game::Update(){

}

void Game::Render(){
  SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
  SDL_RenderClear(_renderer);
  SDL_RenderPresent(_renderer);
}

void Game::Destroy(){
  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_window);
  SDL_Quit();
}

#include <iostream>
#include <SDL2/SDL.h>

#include "Game.h"

const int thickness = 15;
const float paddleH = 100.0f;

Game::Game() : mWindow(nullptr),
               mRenderer(nullptr),
               mTicksCount(0),
               mIsRunning(true),
               mPaddleDir(0) {
  // Empty body
}

bool Game::Initialize() {
  int sdlResult = SDL_Init(SDL_INIT_VIDEO);
  if (sdlResult != 0) {
    SDL_Log("Unable to i itialize SDL: %s", SDL_GetError());
    return false;
  }

  // Create an SDL window
  mWindow = SDL_CreateWindow(
    "Game Window",
    100,
    100,
    1024,
    768,
    0
  );

  if (!mWindow) {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return false;
  }

  mRenderer = SDL_CreateRenderer(
    mWindow, // Window to create renderer for
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  );

  if (!mRenderer) {
    SDL_Log("Failed to create renderer: %s", SDL_GetError());
    return false;
  }

  mPaddlePos.x = 10.0f;
  mPaddlePos.y = 768.0f/2.0f;
  mBallPos.x = 1024.0f/2.0f;
  mBallVel.x = -200.0f;
  mBallVel.y = 235.0f;
  return true;
}

void Game::RunLoop() {
  while (mIsRunning) {
    ProcessInput();
    //UpdateGame();
    //GenerateOutput();
  }
}

void Game::ProcessInput() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == 'QUIT') {
      mIsRunning = false;
    }
  }

  // Get a snapshot of the current state of the keyboard.
  const Uint8* state = SDL_GetKeyboardState(nullptr);
  
  if (state[SDL_SCANCODE_ESCAPE]) {
    mIsRunning = false;
  }

  // Update paddle direction when up/down arrow key is pressed
  if (state[SDL_SCANCODE_UP]) {
    mPaddleDir -= 1;
  }
  if (state[SDL_SCANCODE_DOWN]) {
    mPaddleDir += 1;
  }

}

void Game::UpdateGame() {
  // Wait until 16ms has elapsed since last frame
  while(!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16))
    ;
  
  // Delta time is the difference in ticks from the last frame
  // converted to seconds.
  float deltaTime = (SDL_GetTicks() - mTicksCount / 1000.0f);

  // Put a limit on the max delta time value
  if (deltaTime > 0.05f) {
    deltaTime = 0.05f;
  }

  // Update ticksCount for next frame
  mTicksCount = SDL_GetTicks();

  // Update paddle position based on direction
  
}

void Game::Shutdown() {
  SDL_DestroyRenderer(mRenderer);
  SDL_DestroyWindow(mWindow);
  SDL_Quit();
}
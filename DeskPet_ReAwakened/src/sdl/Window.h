#pragma once
#include <SDL.h>
#include <SDL_Image.h>
#include <string>

namespace sdl {
  class Texture;

  class Window {
  private:
    SDL_Window* sdlWindow;
    SDL_Renderer* sdlRenderer;
    bool open;

  public:
    Window(std::string title, int width, int height);
    ~Window();

    SDL_Renderer& getSDLRenderer();
    bool isOpen();

    bool pollEvent(SDL_Event& sdlEvent);

    void setRenderDrawColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
    void renderClear();
    void render(Texture& texture);
    void renderPresent();

    Texture* createTextureFromFile(std::string filename);
  };
}
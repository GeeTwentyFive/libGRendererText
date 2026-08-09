#include <GWindower.hpp>
#include <glad/glad.h>
#include "../include/GRendererText.hpp"

#include <stdexcept>
#include <string>
#include <iostream>


#define ERROR(msg) throw std::runtime_error(std::string("[ERROR] ") + __FILE__ + "@" + std::to_string(__LINE__) + " (" + __func__ + "): " + (msg))


int main() { try {
        GWindower gw{1280, 720, 4, 6};

        if (!gladLoadGL()) ERROR("Failed to load OpenGL");

        GRendererText grtxt;

        GRendererText::Text example = grtxt.AddText("Hello, World!");
        example.SetColor(0x87CEFAFF);

        glClearColor(0.0, 0.0, 0.0, 1.0);
        while (gw.Update(true, 0.1, true)) { if(gw.key_states[GWindower::KEY_ESCAPE]) break;
                glViewport(0, 0, gw.window_width, gw.window_height);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                example.SetLetterSize((float)gw.window_height / 60);
                example.SetPosY((float)gw.window_height/2 - example.GetLetterSize()/2);  // center vertically
                example.SetPosX((float)gw.window_width/2 - example.GetLetterSize()*example.GetLetterCount()/2);  // center horizontally

                grtxt.DrawFrame(gw.window_width, gw.window_height);
        }
} catch (const std::exception& e) { std::cout << e.what() << std::endl; return 1; } }
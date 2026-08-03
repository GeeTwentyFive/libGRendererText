#include <GWindower_OpenGL.hpp>
#include "../libGRendererText.hpp"

#include <thread>


int main() {
        GWindower_OpenGL gwgl; // (GWindower_OpenGL already calls `glViewport()` and `glClearColor()` internally)

        GRendererText grtxt{(uint32_t)gwgl.screen_width, (uint32_t)gwgl.screen_height};

        GRendererText::Text example = grtxt.AddText("Hello, World!");
        example.SetLetterSize(gwgl.screen_height / 60);
        example.SetColor(0x87CEFAFF);
        example.SetPosY(gwgl.screen_height/2 - example.GetLetterSize()/2);  // center vertically
        example.SetPosX(gwgl.screen_width/2 - example.GetLetterSize()*example.GetLetterCount()/2);  // center horizontally

        while (gwgl.Update()) { if(gwgl.key_states[GW_KEY_ESCAPE]) break; std::this_thread::sleep_for(std::chrono::milliseconds(1));
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                grtxt.DrawFrame();
        }
}
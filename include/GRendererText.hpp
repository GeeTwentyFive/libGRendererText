#pragma once

#include <stdint.h>
#include <memory>
#include <string>

class GRendererText { public: ~GRendererText(); private: struct _impl; std::unique_ptr<_impl> _; public:
        explicit GRendererText();

        float camera_pos[2] = {0, 0};  // in Normalized Device Coordinates (-1 - 1)
        float camera_zoom = 1.0;

        struct Text { void* user_data = nullptr; GRendererText* _renderer_instance; uint64_t _id; ~Text() noexcept;
                void SetLetterSize(float size) noexcept; float GetLetterSize() noexcept;  // in pixels (default: 8.0f)
                size_t GetLetterCount() noexcept;
                void SetPosX(float pos_x) noexcept; float GetPosX() noexcept;  // in pixels
                void SetPosY(float pos_y) noexcept; float GetPosY() noexcept;  // in pixels
                void SetColor(uint32_t color_RGBA) noexcept; uint32_t GetColor() noexcept;
        };
        Text AddText(std::string text);

        int DrawFrame(int framebuffer_width, int framebuffer_height) noexcept;  // returns non-0 on error
};
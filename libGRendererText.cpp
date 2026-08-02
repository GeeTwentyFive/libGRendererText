#include "libGRendererText.hpp"

#include <GRenderer2D.hpp>
#include <GFont.h>

#include <unordered_map>


struct GRendererText::_impl { uint64_t _last_uid = 0; uint64_t NewUID() { return _last_uid++; }
        std::unique_ptr<GRenderer2D> gr2d;
        uint64_t sprites_char[128];
        // TODO: std::unordered_map<uint64_t, Text> texts;
        // ^ OR: std::unordered_map<uint64_t, std::vector<GRenderer2D::SpriteInstance*>> texts;
};

GRendererText::GRendererText(uint32_t window_width, uint32_t window_height) { this->_ = std::make_unique<GRendererText::_impl>();
        this->_->gr2d = std::make_unique<GRenderer2D>(window_width, window_height);
        for (int i = 0; i < 128; i++) { this->_->sprites_char[i] = this->_->gr2d->CreateSprite(GFONT[i], 8, 8); }
        // TODO
}

GRendererText::Text* GRendererText::AddText(const std::string_view text) noexcept { if (text.empty()) return nullptr;
        // TODO
}

void GRendererText::Text::SetSize(float size) noexcept {}  // TODO: Loop through each letter and set its size
float GRendererText::Text::GetSize() noexcept {}  // TODO: Return size of first letter
void GRendererText::Text::SetPosX(float pos_x) noexcept {}  // TODO: Loop through each letter and set its horiz. position based on `pos_x + size*index`
float GRendererText::Text::GetPosX() noexcept {}  // TODO: Return horiz. position of first letter
void GRendererText::Text::SetPosY(float pos_x) noexcept {}  // TODO: Loop through each letter and set its vert. position based on `pos_y + size*index`
float GRendererText::Text::GetPosY() noexcept {}  // TODO: Return vert. position of first letter
void GRendererText::Text::SetColor(uint32_t color_RGBA) noexcept {}  // TODO: Loop through each letter and set its color
uint32_t GRendererText::Text::GetColor() noexcept {}  // TODO: Return color of first letter
void GRendererText::Text::Remove() noexcept {}  // TODO: Loop through each letter and `->Remove()` it, then remove this `Text` from internal map

int GRendererText::DrawFrame() noexcept { this->_->gr2d->DrawFrame(); }

GRendererText::~GRendererText() {} // TODO: Destroy texts
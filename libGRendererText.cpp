#include "libGRendererText.hpp"

#include <GRenderer2D.hpp>
#include <GFont.h>
static constexpr size_t FONT_SIZE = 8;  // font must have same width & height

#include <stdexcept>
#include <string>
#include <unordered_map>


#define ERROR(msg) throw std::runtime_error(std::string("[ERROR] ") + __FILE__ + "@" + std::to_string(__LINE__) + " (" + __func__ + "): " + (msg))


struct GRendererText::_impl { uint64_t _last_uid = 0; uint64_t NewUID() { return _last_uid++; }
        uint32_t window_width, window_height;
        std::unique_ptr<GRenderer2D> gr2d;
        uint64_t sprites_char[128];
        std::unordered_map<uint64_t, std::vector<GRenderer2D::SpriteInstance*>> texts;
};

GRendererText::GRendererText(uint32_t window_width, uint32_t window_height) { this->_ = std::make_unique<GRendererText::_impl>();
        this->_->window_width = window_width; this->_->window_height = window_height;
        this->_->gr2d = std::make_unique<GRenderer2D>(window_width, window_height);
        for (int i = 0; i < 128; i++) { this->_->sprites_char[i] = this->_->gr2d->CreateSprite(GFONT[i], FONT_SIZE, FONT_SIZE); }
}

GRendererText::Text GRendererText::AddText(const std::string_view text) { if (text.empty()) ERROR("text empty");
        Text out; out._renderer_instance = this; out._id = out._renderer_instance->_->NewUID();
        for (const auto& letter : text) { out._renderer_instance->_->texts[out._id].push_back(this->_->gr2d->AddSprite(this->_->sprites_char[letter])); } out.SetLetterSize(FONT_SIZE); out.SetPosY(0.0f); out.SetPosX(0.0f);
        return out;
}

void GRendererText::Text::SetLetterSize(float size) noexcept { for (const auto& letter : this->_renderer_instance->_->texts[this->_id]) { letter->size[0] = size; letter->size[1] = -size; } }
float GRendererText::Text::GetLetterSize() noexcept { return this->_renderer_instance->_->texts[this->_id][0]->size[0]; }
size_t GRendererText::Text::GetLetterCount() noexcept { return this->_renderer_instance->_->texts[this->_id].size(); }
void GRendererText::Text::SetPosX(float pos_x) noexcept {
        for (size_t i = 0; i < this->_renderer_instance->_->texts[this->_id].size(); i++) {
                GRenderer2D::SpriteInstance*& letter = this->_renderer_instance->_->texts[this->_id][i];
                letter->position[0] = (pos_x + (letter->size[0] * i));
        }
}
float GRendererText::Text::GetPosX() noexcept { return this->_renderer_instance->_->texts[this->_id][0]->position[0]; }
void GRendererText::Text::SetPosY(float pos_y) noexcept { for (const auto& letter : this->_renderer_instance->_->texts[this->_id]) { letter->position[1] = (this->_renderer_instance->_->window_height - pos_y); } }
float GRendererText::Text::GetPosY() noexcept { return this->_renderer_instance->_->texts[this->_id][0]->position[1]; }
void GRendererText::Text::SetColor(uint32_t color_RGBA) noexcept { for (const auto& letter : this->_renderer_instance->_->texts[this->_id]) { letter->color_RGBA = color_RGBA; } }
uint32_t GRendererText::Text::GetColor() noexcept { return this->_renderer_instance->_->texts[this->_id][0]->color_RGBA; }
GRendererText::Text::~Text() noexcept { for (const auto& letter : this->_renderer_instance->_->texts[this->_id]) { letter->Remove(); } this->_renderer_instance->_->texts.erase(this->_id); }

int GRendererText::DrawFrame() noexcept {
        this->_->gr2d->camera_pos[0] = this->camera_pos[0]; this->_->gr2d->camera_pos[1] = this->camera_pos[1];
        this->_->gr2d->camera_zoom = this->camera_zoom;
        return this->_->gr2d->DrawFrame();
}

GRendererText::~GRendererText() {
        for (const auto& text : this->_->texts) {
                for (const auto& letter : text.second) {
                        letter->Remove();
                }
        }
}
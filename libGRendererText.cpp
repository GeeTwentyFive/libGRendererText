#include "libGRendererText.hpp"

#include <unordered_map>


struct GRendererText::_impl { uint64_t _last_uid = 0; uint64_t NewUID() { return _last_uid++; }
        // TODO: std::unordered_map<uint64_t, Text> texts;
};

GRendererText::GRendererText(uint32_t window_width, uint32_t window_height) { this->_ = std::make_unique<GRendererText::_impl>();
        // TODO
}

// TODO

int GRendererText::DrawFrame() noexcept {} // TODO

GRendererText::~GRendererText() {} // TODO: Destroy texts
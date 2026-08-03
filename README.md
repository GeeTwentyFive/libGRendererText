Minimalistic simple cross-platform text renderer

![](_EXAMPLE.png)


# Usage

1) Create native window with OpenGL context (e.g. with [GWindower_OpenGL](https://github.com/GeeTwentyFive/GWindower_OpenGL) or GLFW)
2) `GRendererText grtxt{WINDOW_WIDTH, WINDOW_HEIGHT};`
3) ...add text(s)...
4) `grtxt.DrawFrame();` (+ do a `glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)` each frame (lib doesn't do that so that you can compose it with other rendering))


# API

- `.camera_pos` - Set/Get camera position
- `.camera_zoom` - Set/Get camera zoom
- `.AddText()` - Add text to screen (creates & returns instance of `Text`)
- ##### AT END OF FRAME: `.DrawFrame()`  (returns 0 on success, source line number on error)

#

#### Text (created with `.AddText()`):
- `.SetSize()`, `.GetSize()` (in pixels (default: `8.0f`))
- `.SetPosX()`, `.GetPosX()` (in pixels)
- `.SetPosY()`, `.GetPosY()` (in pixels)
- `.SetColor()`, `.GetColor()` (0xRRGGBBAA) (alpha less than 0x80 = hidden/invisible)

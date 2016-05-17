#include "../includes/meta.h"

extern const float WINDOW_WIDTH = 640.0f;
extern const float WINDOW_HEIGHT = 480.0f;

//playing screen
extern const float SCREEN_PLAY_WIDTH = 385.0f;
extern const float SCREEN_PLAY_HEIGHT = 450.0f;
//TODO
//probably add constants for the info screen?

extern const int SCREEN_MENU = 0;
extern const int SCREEN_DIFFICULTY = 1;
extern const int SCREEN_SCORES = 2;
extern const int SCREEN_GAME = 3;
extern const int SCREEN_GAME_OVER = 4;

extern const int DIR_UP = 0;
extern const int DIR_RIGHT = 1;
extern const int DIR_DOWN = 2;
extern const int DIR_LEFT = 3;

extern const std::string FCHARACTER_SPRITE_SHEET = "sprites/player/pl00/pl00.png";
extern const std::string FENEMY_SPRITE_SHEET = "sprites/enemy/enemy.png";

extern const std::string FEFFECT_SPRITE_SHEET = "sprites/effect/eff_base.png";
extern const std::string FENEMY_BULLET_SPRITE_SHEET_1 = "sprites/bullet/bullet1.png";
extern const std::string FENEMY_BULLET_SPRITE_SHEET_2 = "sprites/bullet/bullet2.png";

extern const std::string FSCORE = "media/data";

extern const float SCREEN_PLAY_BUFFER = (WINDOW_HEIGHT - SCREEN_PLAY_HEIGHT) / 2.0;

extern const int FPS = 60;

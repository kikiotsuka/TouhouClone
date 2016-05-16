#ifndef META_H
#define META_H

#include <string>

extern const float WINDOW_WIDTH, WINDOW_HEIGHT; //window dim
extern const float SCREEN_PLAY_WIDTH, SCREEN_PLAY_HEIGHT; //play screen dim
//TODO
//add constraints for info screen
extern const int SCREEN_MENU;
extern const int SCREEN_DIFFICULTY, SCREEN_GAME;
extern const int SCREEN_SCORES, SCREEN_GAME_OVER;

extern const int DIR_UP, DIR_DOWN;
extern const int DIR_LEFT, DIR_RIGHT;

extern const std::string FCHARACTER_SPRITE_SHEET;
extern const std::string FENEMY_SPRITE_SHEET;

extern const std::string FEFFECT_SPRITE_SHEET;
extern const std::string FENEMY_BULLET_SPRITE_SHEET_1;
extern const std::string FENEMY_BULLET_SPRITE_SHEET_2;

extern const std::string FSCORE;

extern const float SCREEN_PLAY_BUFFER;

extern const int FPS;

#endif // META_H

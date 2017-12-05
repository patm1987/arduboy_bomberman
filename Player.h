#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdint.h>

#include "MapPosition.h"

class Arduboy;

/*!
 * Class representing the player in Bomberman
 */
class Player
{
public:
  /*!
   * Constructs the player from an image and places him in the given Map
   * @param pPlayerImage a pointer to the memory used to draw the player
   * @param pMap the map the player will belong to
   */
  Player(const uint8_t *pPlayerImage, Map *pMap);

  /*!
   * Ticks the player by a single frame
   * @param arduboy the instance of the Arduboy library
   */
  void update(Arduboy &arduboy);

  /*!
   * Draws the player to the screen
   * @param arduboy the arduboy library (to help draw)
   */
  void draw(Arduboy &arduboy) const;

  /*!
   * Instantly sets the player to the given position, cancelling animations
   * @param position the position to move to
   */
  void setPosition(const Vec2i &position);

  /*!
   * Retrieves the position of the player
   */
  const Vec2i &getPosition() const;

private:
  /*!
   * Processes the player input to move the player
   * @param arduboy the arduboy from which we'll process input
   */
  void processInput(Arduboy &arduboy);

  MapPosition _position;
  Map *_pMap;
};

inline Player::Player(const uint8_t *pPlayerImage, Map *pMap)
    : _position(20),
      _pMap(pMap)
{
}

inline void Player::setPosition(const Vec2i &position)
{
  _position.setPosition(position);
}

inline const Vec2i &Player::getPosition() const
{
  return _position.getPosition();
  ;
}

#endif //_PLAYER_H
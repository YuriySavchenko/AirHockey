//
//  engine.h
//  Air Hockey
//
//  Created by YuriySavchenko on 7/13/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#ifndef engine_h
#define engine_h

#include "borders.h"
#include "realplayer.h"
#include "virtualplayer.h"
#include "brassy.h"
#include "gates.h"
#include "ball.h"
#include "point.h"
#include "operations.h"
#include "math.h"

/**
 * \brief class which presents \b Engine for counting of physic
 */
class Engine {
private:
    int moveDirection;                              ///< \e variable for saving \b direction of \b move
    Borders borders;                                ///< \e variable for saving \b borders of \a board
    std::shared_ptr<Ball> ball;                     ///< \e variable for saving \a object of \b Ball
    std::shared_ptr<RealPlayer> realPlayer;         ///< \e variable for saving \a object of \b real \b player
    std::shared_ptr<VirtualPlayer> virtualPlayer;   ///< \e variable for saving \a object of \b virtual \b player
    std::vector<Point> ballPoints;                  ///< \e vector for saving \a points of \b ball
    
public:
    Engine() = default;
    ~Engine() = default;
    Engine(Borders &&, std::shared_ptr<Ball>, std::shared_ptr<RealPlayer>, std::shared_ptr<VirtualPlayer>);     ///< explicit \e constructor
    
private:
    void updatePoints();            ///< \e method for update \a points of \b ball
    void checkCollisions();         ///< \e method for checking of \a collisions with \b board and \b brasses
    void checkDirection();          ///< \e method for checking \a move \b direction
    void moveToLeftUpperSide();     ///< \e method for \a moving to \b left \b upper side
    void moveToLeftDownSide();      ///< \e method for \a moving to \b left \b down side
    void moveToRightUpperSide();    ///< \e method for \a moving to \b right \b upper side
    void moveToRightDownSide();     ///< \e method for \a moving to \b right \b down side
    void moveToLeftSide();          ///< \e method for \a moving to \b left side
    void moveToRightSide();         ///< \e method for \a moving to \b right side
    void moveToUpperSide();         ///< \e method for \a moving to \b upper side
    void moveToDownSide();          ///< \e method for \a moving to \b down side
    
public:
    void handling();                ///< \e method for main \a handling of \b engine
    void resetScores();             ///< \e method for \a clearing \b gates
};

#endif /* engine_h */

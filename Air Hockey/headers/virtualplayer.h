//
//  virualplayer.h
//  Air Hockey
//
//  Created by YuriySavchenko on 7/15/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#ifndef virualplayer_h
#define virualplayer_h

#include "player.h"
#include "borders.h"
#include "point.h"

/**
 * \brief class which presents \b virtual \b Player
 */
class VirtualPlayer : public Player {
private:
    /**
     * \brief variable which presents direction of move in binary mode\n
     * Exists two variants:\n
     *  \a 01 - direction to \b right \b side\n
     *  \a 10 - direction to \b left \b side\n
     */
    int directionMove;
    
public:
    VirtualPlayer() = default;
    ~VirtualPlayer() = default;
    VirtualPlayer(std::unique_ptr<Brassy> &, std::unique_ptr<Gates> &);     ///< explicit \e constructor
    
public:
    void manipulate(SDL_Event &) override;      ///< \e method for manipulating of \b Brassy
    
public:
    std::unique_ptr<Brassy> &getBrassy();   ///< \e function which returns \a on the \b Brassy
    std::unique_ptr<Gates> &getGates();     ///< \e function which returns \a on the \b Gates
    std::string getName();                  ///< \e function which return \a name of \b Player
};

#endif /* virualplayer_h */

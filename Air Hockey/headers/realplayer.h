//
//  realplayer.h
//  Air Hockey
//
//  Created by YuriySavchenko on 7/15/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#ifndef realplayer_h
#define realplayer_h

#include "player.h"
#include "borders.h"
#include "point.h"

/**
 * \brief class which presents \b real \b Player
 */
class RealPlayer : public Player {
public:
    RealPlayer() = default;
    ~RealPlayer() = default;
    RealPlayer(const std::string &, std::unique_ptr<Brassy>&, std::unique_ptr<Gates> &);     ///< explicit \e constructor
    
public:
    void manipulate(SDL_Event &) override;     ///< \e method for manipulating of \b Brassy
    
public:
    std::unique_ptr<Brassy> &getBrassy();   ///< \e function which returns \a on the \b Brassy
    std::unique_ptr<Gates> &getGates();     ///< \e function which returns \a on the \b Gates
    std::string getName();                  ///< \e function which return \a name of \b Player
};

#endif /* realplayer_h */

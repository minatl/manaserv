/*
 *  The Mana World Server
 *  Copyright 2004 The Mana World Development Team
 *
 *  This file is part of The Mana World.
 *
 *  The Mana World is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  The Mana World is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with The Mana World; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 */

#ifndef ITEMS_H
#define ITEMS_H

#include "object.h"

namespace tmwserv
{

/**
 * Class for all types of in-game items.
 */
class Item : public Object
{
    //Item type
    unsigned int type;

  public:
    /**
     * Enumeration of available Item types.
     */
    enum {
        Usable,
        Equipment
    };

    virtual ~Item() throw() { }

    /**
     * The function called to use an item
     */
    void use();

    /**
     * Return type of item
     */
    unsigned int getType() { return type; }
};

} // namespace tmwserv

#endif

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
#ifndef TMWSERV_STORAGE_H
#define TMWSERV_STORAGE_H

#include "object.h"
#include "account.h"

/**
 * A storage of persistent dynamic data.
 */
class Storage
{
    public:
        static Storage *getInstance();
        static void deleteInstance();

        /**
         * Make sure any changes are saved.
         */
        virtual void flush() = 0;

        /**
         * Account count (test function).
         */
        virtual unsigned int getAccountCount() = 0;

        /**
         * Get account by username.
         */
        virtual Account *getAccount(const std::string &username) = 0;

    protected:
        /**
         * Constructor.
         */
        Storage();

        /**
         * Destructor.
         */
        virtual ~Storage();

    private:
        static Storage *instance;
};

#endif /* TMWSERV_STORAGE_H */
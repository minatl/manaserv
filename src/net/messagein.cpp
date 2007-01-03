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

#include <string>
#include <enet/enet.h>

#include "net/messagein.hpp"

MessageIn::MessageIn(const char *data, int length):
    mData(data),
    mLength(length),
    mPos(0)
{
    // Read the message ID
    mId = readShort();
}

MessageIn::~MessageIn()
{
}

char MessageIn::readByte()
{
    char value = -1;
    if (mPos < mLength)
    {
        value = mData[mPos];
    }
    mPos += 1;
    return value;
}

short MessageIn::readShort()
{
    short value = -1;
    if (mPos + 2 <= mLength)
    {
        uint16_t t;
        memcpy(&t, mData + mPos, 2);
        value = ENET_NET_TO_HOST_16(t);
    }
    mPos += 2;
    return value;
}

long MessageIn::readLong()
{
    long value = -1;
    if (mPos + 4 <= mLength)
    {
        uint32_t t;
        memcpy(&t, mData + mPos, 4);
        value = ENET_NET_TO_HOST_32(t);
    }
    mPos += 4;
    return value;
}

std::string MessageIn::readString(int length)
{
    // Get string length
    if (length < 0) {
        length = readShort();
    }

    // Make sure the string isn't erroneous
    if (length < 0 || mPos + length > mLength) {
        mPos = mLength + 1;
        return "";
    }

    // Read the string
    char const *stringBeg = mData + mPos;
    char const *stringEnd = (char const *)memchr(stringBeg, '\0', length);
    std::string readString(stringBeg,
            stringEnd ? stringEnd - stringBeg : length);
    mPos += length;

    return readString;
}
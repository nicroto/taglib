/**************************************************************************
    copyright            : (C) 2010 by Lukáš Lalinský
    email                : lalinsky@gmail.com
 **************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License version   *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  *
 *   USA                                                                   *
 *                                                                         *
 *   Alternatively, this file is available under the Mozilla Public        *
 *   License Version 1.1.  You may obtain a copy of the License at         *
 *   http://www.mozilla.org/MPL/                                           *
 ***************************************************************************/

#ifndef TAGLIB_FLACMETADATABLOCKS_H
#define TAGLIB_FLACMETADATABLOCKS_H

#include "tlist.h"
#include "tbytevector.h"
#include "taglib_export.h"

namespace TagLib {

  namespace FLAC {

    class File;

    class TAGLIB_EXPORT MetadataBlocks
    {
    public:
      MetadataBlocks();
      virtual ~MetadataBlocks();

      /*!
       * Read the blocks from a file.
       */
      bool read(File *file);

      /*!
       * Render the blocks into a byte vector.
       */
      ByteVector render(int originalLength) const;

      const List<MetadataBlock *> &metadataBlockList() const;

    private:
      MetadataBlocks(const MetadataBlocks &item);
      MetadataBlocks &operator=(const MetadataBlocks &item);

      class MetadataBlocksPrivate;
      MetadataBlocksPrivate *d;
    };

  }

}

#endif

/***************************************************************************
 *   Copyright (C) 2005 by Robot Group Leipzig                             *
 *    martius@informatik.uni-leipzig.de                                    *
 *    der@informatik.uni-leipzig.de                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                         *
 *
 *******************************************`********************************/
#ifndef __IMAGEPROCESSOR
#define __IMAGEPROCESSOR

#include <osg/Image>
#include "camera.h"

namespace lpzrobots {

  /**
     Base class for image processing units. 
     The result of a processing is an image (returned by init)
     The source for processing can be any image from previous
     units. An implemenation must store the pointers to the source(s)
     and must also hold a destination image.    
  */
  struct ImageProcessor {
    ImageProcessor() {};
    virtual ~ImageProcessor() {};

    /**
       initialization with all images so far. The last image in the list
       is probably the one to use for processing. (output from last processor)
       @return result image structure of this processor
    */
    virtual Camera::CameraImage init(const Camera::CameraImages& imgs) = 0;

    /// perform the image calculation here
    virtual void process() = 0;

  };

}

#endif
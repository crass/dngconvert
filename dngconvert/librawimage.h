/* This file is part of the dngconvert project
   Copyright (C) 2011 Jens Mueller <tschensensinger at gmx dot de>
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public   
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.
   
   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#pragma once

#include "dng_auto_ptr.h"
#include "dng_image.h"
#include "dng_pixel_buffer.h"
#include "dng_matrix.h"
#include "dng_orientation.h"
#include "dng_string.h"
#include "dng_stream.h"
#include "dng_tag_values.h"

#include "libraw/libraw_types.h"

class LibRawImage :
        public dng_image
{
public:
    LibRawImage(const char *filename, dng_memory_allocator &allocator);
    LibRawImage(dng_stream &stream, dng_memory_allocator &allocator);
    LibRawImage(const dng_rect &bounds, uint32 planes, uint32 pixelType, dng_memory_allocator &allocator);
    ~LibRawImage(void);

    virtual dng_image* Clone() const;

    const dng_vector& CameraNeutral() const;
    const dng_string& ModelName() const;
    const dng_string& MakeName() const;
    const dng_rect& ActiveArea() const;
    uint32 Channels() const;
    const dng_matrix& ColorMatrix() const;
    real64 BlackLevel(uint32 channel) const;
    real64 WhiteLevel(uint32 channel) const;
    const dng_urational& DefaultScaleH() const;
    const dng_urational& DefaultScaleV() const;
    const dng_urational& DefaultCropSizeH() const;
    const dng_urational& DefaultCropSizeV() const;
    const dng_urational& DefaultCropOriginH() const;
    const dng_urational& DefaultCropOriginV() const;
    const dng_orientation Orientation() const;
    uint32 Pattern() const;
    ColorKeyCode ColorKey(uint32 plane) const;

protected:
    virtual void AcquireTileBuffer(dng_tile_buffer &buffer, const dng_rect &area, bool dirty) const;

private:
    void Parse(dng_stream &stream);

protected:
    dng_memory_allocator &m_Allocator;
    dng_pixel_buffer m_Buffer;
    AutoPtr<dng_memory_block> m_Memory;
    dng_rect m_ActiveArea;
    dng_vector m_CameraNeutral;
    dng_string m_ModelName;
    dng_string m_MakeName;
    uint32 m_Channels;
    dng_matrix m_ColorMatrix;
    dng_vector m_WhiteLevel;
    dng_vector m_BlackLevel;
    dng_urational m_DefaultScaleH;
    dng_urational m_DefaultScaleV;
    dng_urational m_DefaultCropSizeH;
    dng_urational m_DefaultCropSizeV;
    dng_urational m_DefaultCropOriginH;
    dng_urational m_DefaultCropOriginV;
    dng_orientation m_BaseOrientation;
    uint32 m_Pattern;
    ColorKeyCode m_CFAPlaneColor[4];
};

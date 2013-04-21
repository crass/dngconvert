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

#include "dngifd.h"

#include "dngreadimage.h"

DngIfd::DngIfd(void)
{
}

DngIfd::~DngIfd(void)
{
}

bool DngIfd::CanRead() const
{
    DngReadImage reader;
    return reader.CanRead(*this);
}

void DngIfd::ReadImage(dng_host &host,
                       dng_stream &stream,
                       dng_image &image,
                       dng_jpeg_image *jpegImage,
                       dng_fingerprint *jpegDigest) const
{
    DngReadImage reader;
    reader.Read(host, *this, stream, image, jpegImage, jpegDigest);
}


/**
 * Orthanc - A Lightweight, RESTful DICOM Store
 * Copyright (C) 2012-2015 Sebastien Jodogne, Medical Physics
 * Department, University Hospital of Liege, Belgium
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 **/


#pragma once

#include "Cache/ICacheFactory.h"

#include <orthanc/OrthancCPlugin.h>
#include <stdint.h>

namespace OrthancPlugins
{
  class DecodedImageAdapter : public ICacheFactory
  {
  private:
    enum CompressionType
    {
      CompressionType_Jpeg,
      CompressionType_Deflate
    };

    static bool ParseUri(CompressionType& type,
                         uint8_t& compressionLevel,
                         std::string& instanceId,
                         const std::string& uri);

    OrthancPluginContext* context_;

  public:
    DecodedImageAdapter(OrthancPluginContext* context) : context_(context)
    {
    }

    virtual bool Create(std::string& content,
                        const std::string& uri);  
  };
}

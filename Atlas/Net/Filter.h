// This file is distributed under the GNU Lesser General Public license.
// Copyright (C) 2000 Michael Day (See the file COPYING for details).

#ifndef ATLAS_NET_FILTER_H
#define ATLAS_NET_FILTER_H

#include <string>
using std::string;

namespace Atlas
{

/**	Abstract Base Class for Atlas protocol filter.
@doc
<p>Filters provide streaming data commpression and decompression for Client connections

@see Client
**/

class Filter
{
    public:
    
    virtual ~Filter() { }
    
    virtual string encode(const string& data) = 0;
    virtual string decode(const string& data) = 0;
};

} // end namespace Atlas

#endif
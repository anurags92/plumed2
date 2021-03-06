/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Copyright (c) 2011-2014 The plumed team
   (see the PEOPLE file at the root of the distribution for a list of names)

   See http://www.plumed-code.org for more information.

   This file is part of plumed, version 2.

   plumed is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   plumed is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with plumed.  If not, see <http://www.gnu.org/licenses/>.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#include "ArgumentOnlyDistance.h"
#include "core/Value.h"

namespace PLMD {

ArgumentOnlyDistance::ArgumentOnlyDistance( const ReferenceConfigurationOptions& ro ):
ReferenceConfiguration(ro),
ReferenceArguments(ro)
{
}

double ArgumentOnlyDistance::calculate( const std::vector<Value*>& vals, const bool& squared ){
  clearDerivatives();
  if( tmparg.size()!=vals.size() ) tmparg.resize( vals.size() );
  for(unsigned i=0;i<vals.size();++i) tmparg[i]=vals[i]->get();
  return calc( vals, tmparg, squared );
}

double ArgumentOnlyDistance::calc( const std::vector<Vector>& pos, const Pbc& pbc, const std::vector<Value*>& vals, const std::vector<double>& arg, const bool& squared ){
  plumed_dbg_assert( pos.size()==0 );
  return calc( vals, arg, squared );
}

}

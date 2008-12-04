#ifndef COS_GEN_LOGIC_H
#define COS_GEN_LOGIC_H

/*
 o---------------------------------------------------------------------o
 |
 | COS generic logical operators
 |
 o---------------------------------------------------------------------o
 |
 | C Object System
 |
 | Copyright (c) 2006+ Laurent Deniau, laurent.deniau@cern.ch
 |
 | For more information, see:
 | http://cern.ch/laurent.deniau/cos.html
 |
 o---------------------------------------------------------------------o
 |
 | This file is part of the C Object System framework.
 |
 | The C Object System is free software; you can redistribute it and/or
 | modify it under the terms of the GNU Lesser General Public License
 | as published by the Free Software Foundation; either version 3 of
 | the License, or (at your option) any later version.
 |
 | The C Object System is distributed in the hope that it will be
 | useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 | of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 |
 | See <http://www.gnu.org/licenses> for more details.
 |
 o---------------------------------------------------------------------o
 |
 | $Id: logic.h,v 1.4 2008/12/02 17:32:21 ldeniau Exp $
 |
*/

#include <cos/gen/object.h>

// return True, False or TrueFalse (= uncertain, undetermined)
defgeneric(OBJ, gnot    , _1);     
defgeneric(OBJ, gand    , _1, _2);
defgeneric(OBJ, gor     , _1, _2);
defgeneric(OBJ, gxor    , _1, _2); // not (_1 equal _2)
defgeneric(OBJ, gimplies, _1, _2); // (not _1) or _2

// gequal() and gcompare() are provided by cos/gen/object.h

// inliners
static inline OBJ
gEQ(OBJ _1, OBJ _2) {
  useclass(Equal);
  OBJ res = gcompare(_1,_2);
  return res == Equal ? True : False; COS_UNUSED(gEQ);
}

static inline OBJ
gNE(OBJ _1, OBJ _2) {
  useclass(Equal);
  OBJ res = gcompare(_1,_2);
  return res == Equal ? False : True; COS_UNUSED(gNE);
}

static inline OBJ
gLT(OBJ _1, OBJ _2) {
  useclass(Lesser);
  OBJ res = gcompare(_1,_2);
  return res == Lesser ? True : False; COS_UNUSED(gLT);
}

static inline OBJ
gGT(OBJ _1, OBJ _2) {
  useclass(Greater);
  OBJ res = gcompare(_1,_2);
  return res == Greater ? True : False; COS_UNUSED(gGT);
}

static inline OBJ
gLE(OBJ _1, OBJ _2) {
  useclass(Greater);
  OBJ res = gcompare(_1,_2);
  return res == Greater ? False : True; COS_UNUSED(gLE);
}

static inline OBJ
gGE(OBJ _1, OBJ _2) {
  useclass(Lesser);
  OBJ res = gcompare(_1,_2);
  return res == Lesser ? False : True; COS_UNUSED(gGE);
}

#endif // COS_GEN_LOGIC_H
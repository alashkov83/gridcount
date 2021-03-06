/* $Id$

   Copyright (C) 2004-2010 Oliver Beckstein <oliver@biop.ox.ac.uk>
   This program is made available under the terms of the GNU Public License. 
   See the file LICENSE or http://www.gnu.org/copyleft/gpl.html
*/

#ifndef _utilgmx_h
#define _utilgmx_h

static char *SRCID_utilgmx_h = "$Id$";

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdarg.h>
#include "typedefs.h"
#include "vec.h"
#include "tpxio.h"

/* use constants from physics.h in newer version of Gromacs */
#ifdef M_PI
#define PI M_PI
#else
#define PI 3.14159265358979323844
#endif
#ifndef AMU
#define AMU 1.66054e-27                 /* 1u = AMU kg */
#endif
#ifdef AVOGADRO
#define AvogadroConstant AVOGADRO
#else
#define AvogadroConstant 6.02214e+23    /* mol^-1 */
#endif

#ifndef aswap
#define aswap(v,i,j) {  \
  atom_id temp;         \
                        \
  temp=v[i];            \
  v[i]=v[j];            \
  v[j]=temp;            \
}
#endif

#ifndef MIN
#define MIN(A, B) ((A) < (B) ? (A) : (B))
#endif
#ifndef MAX
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#endif
#ifndef NEWLINE
#define NEWLINE(period, count) ((count)+1) % (period) ? "" : "\n"
#endif

extern real ***grid3_alloc(const int nx,const int ny,const int nz);
extern real **grid2_alloc(const int nx,const int ny);
extern void grid3_free(real ***);
extern void grid2_free(real **);
extern void msg     (const char *format, ...);
extern void dmsg    (const char *format, ...);
extern void dbgprintf (const char *format, ...);
extern void dfprintf (const char *format, ...);
extern real ldist (const rvec x, const rvec p, const rvec c);
extern real dt_tpx (const char *fn);
extern int  list_add_atomid (const atom_id, int *, atom_id *);

static gmx_inline void new_rvec (rvec r, real x, real y, real z)
{
  r[XX] = x;
  r[YY] = y;
  r[ZZ] = z;
};

#endif /* _utilgmx_h */

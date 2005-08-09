#if !defined( STCSEARCHLOCATION_INCLUDED ) /* Include this file only once */
#define STCSEARCHLOCATION_INCLUDED
/*
*+
*  Name:
*     stcsearchlocation.h

*  Type:
*     C include file.

*  Purpose:
*     Define the interface to the StcSearchLocation class.

*  Invocation:
*     #include "stcsearchlocation.h"

*  Description:
*     This include file defines the interface to the StcSearchLocation class 
*     and provides the type definitions, function prototypes and macros,
*     etc.  needed to use this class.
*
*     The StcSearchLocation class is a sub-class of Stc used to describe 
*     the coverage of a VO query.
*
*     See http://hea-www.harvard.edu/~arots/nvometa/STC.html

*  Inheritance:
*     The StcSearchLocation class inherits from the Stc class.

*  Feature Test Macros:
*     astCLASS
*        If the astCLASS macro is undefined, only public symbols are
*        made available, otherwise protected symbols (for use in other
*        class implementations) are defined. This macro also affects
*        the reporting of error context information, which is only
*        provided for external calls to the AST library.

*  Copyright:
*     <COPYRIGHT_STATEMENT>

*  Authors:
*     DSB: David S. Berry (Starlink)

*  History:
*     26-NOV-2004 (DSB):
*        Original version.
*-
*/

/* Include files. */
/* ============== */
/* Interface definitions. */
/* ---------------------- */
#include "stc.h"                 /* Coordinate stcs (parent class) */

#if defined(astCLASS)            /* Protected */
#include "channel.h"             /* I/O channels */
#endif

/* C header files. */
/* --------------- */
#if defined(astCLASS)            /* Protected */
#include <stddef.h>
#endif

/* Type Definitions. */
/* ================= */
/* StcSearchLocation structure. */
/* ----------------------------- */
/* This structure contains all information that is unique to each object in
   the class (e.g. its instance variables). */
typedef struct AstStcSearchLocation {

/* Attributes inherited from the parent class. */
   AstStc stc;             /* Parent class structure */

} AstStcSearchLocation;

/* Virtual function table. */
/* ----------------------- */
/* This table contains all information that is the same for all
   objects in the class (e.g. pointers to its virtual functions). */
#if defined(astCLASS)            /* Protected */
typedef struct AstStcSearchLocationVtab {

/* Properties (e.g. methods) inherited from the parent class. */
   AstStcVtab stc_vtab;          /* Parent class virtual function table */

/* Unique flag value to determine class membership. */
   int *check;                   /* Check value */

/* Properties (e.g. methods) specific to this class. */
} AstStcSearchLocationVtab;
#endif

/* Function prototypes. */
/* ==================== */
/* Prototypes for standard class functions. */
/* ---------------------------------------- */
astPROTO_CHECK(StcSearchLocation)          /* Check class membership */
astPROTO_ISA(StcSearchLocation)            /* Test class membership */

/* Constructor. */
#if defined(astCLASS)            /* Protected. */
AstStcSearchLocation *astStcSearchLocation_(  void *, int, AstKeyMap **, const char *, ... );
#else
AstStcSearchLocation *astStcSearchLocationId_(  void *, int, AstKeyMap **, const char *, ... );
#endif

#if defined(astCLASS)            /* Protected */

/* Initialiser. */
AstStcSearchLocation *astInitStcSearchLocation_( void *, size_t, int, AstStcSearchLocationVtab *, const char *, AstRegion *, int, AstKeyMap ** );

/* Vtab initialiser. */
void astInitStcSearchLocationVtab_( AstStcSearchLocationVtab *, const char * );

/* Loader. */
AstStcSearchLocation *astLoadStcSearchLocation_( void *, size_t, AstStcSearchLocationVtab *, const char *, AstChannel * );

#endif

/* Prototypes for member functions. */
/* -------------------------------- */

/* Function interfaces. */
/* ==================== */
/* These macros are wrap-ups for the functions defined by this class
   to make them easier to invoke (e.g. to avoid type mis-matches when
   passing pointers to objects from derived classes). */

/* Interfaces to standard class functions. */
/* --------------------------------------- */
/* Some of these functions provide validation, so we cannot use them
   to validate their own arguments. We must use a cast when passing
   object pointers (so that they can accept objects from derived
   classes). */

/* Check class membership. */
#define astCheckStcSearchLocation(this) astINVOKE_CHECK(StcSearchLocation,this)

/* Test class membership. */
#define astIsAStcSearchLocation(this) astINVOKE_ISA(StcSearchLocation,this)

/* Constructor. */
#if defined(astCLASS)            /* Protected. */
#define astStcSearchLocation astINVOKE(F,astStcSearchLocation_)
#else
#define astStcSearchLocation astINVOKE(F,astStcSearchLocationId_)
#endif

#if defined(astCLASS)            /* Protected */

/* Initialiser. */
#define astInitStcSearchLocation(mem,size,init,vtab,name,region,ncoords,coords) \
astINVOKE(O,astInitStcSearchLocation_(mem,size,init,vtab,name,region,ncoords,coords))

/* Vtab Initialiser. */
#define astInitStcSearchLocationVtab(vtab,name) astINVOKE(V,astInitStcSearchLocationVtab_(vtab,name))
/* Loader. */
#define astLoadStcSearchLocation(mem,size,vtab,name,channel) \
astINVOKE(O,astLoadStcSearchLocation_(mem,size,vtab,name,astCheckChannel(channel)))
#endif

/* Interfaces to public member functions. */
/* -------------------------------------- */
/* Here we make use of astCheckStcSearchLocation to validate StcSearchLocation pointers
   before use.  This provides a contextual error report if a pointer
   to the wrong sort of Object is supplied. */

#if defined(astCLASS)            /* Protected */
#endif
#endif
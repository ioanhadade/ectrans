SUBROUTINE TRANS_INQ(KRESOL,KSPEC,KSPEC2,KSPEC2G,KSPEC2MX,KNUMP,&
                    &KGPTOT,KGPTOTG,KGPTOTMX,&
                    &KMYMS,KASM0,KUMPP,KPOSSP,KPTRMS,KALLMS,KDIM0G,&
                    &KFRSTLAT,KLSTLAT,KFRSTLOFF,KPTRLAT,&
                    &KPTRFRSTLAT,KPTRLSTLAT,KPTRFLOFF,KSTA,KONL,&
                    &KULTPP,KPTRLS,&
                    &LDSPLITLAT,&
                    &PMU,PGW,PRPNM)

!**** *TRANS_INQ* - Extract information from the transform package

!     Purpose.
!     --------
!     Interface routine for extracting information from the T.P.

!**   Interface.
!     ----------
!     CALL TRANS_INQ(...)
!     Explicit arguments : All arguments are optional.
!     -------------------- 
!     KRESOL   - resolution tag for which info is required ,default is the
!                first defined resulution (input)

!                   SPECTRAL SPACE
!     KSPEC    - number of complex spectral coefficients on this PE
!     KSPEC2   - 2*KSPEC 
!     KSPEC2G  - global KSPEC2
!     KSPEC2MX - maximun KSPEC2 among all PEs
!     KNUMP    - Number of spectral waves handled by this PE
!     KGPTOT   - Total number of grid columns on this PE
!     KGPTOTG  - Total number of grid columns on the Globe
!     KGPTOTMX - Maximum number of grid columns on any of the PEs
!     KMYMS    - This PEs spectral zonal wavenumbers
!     KASM0    - Address in a spectral array of (m, n=m)
!     KUMPP    - No. of wave numbers each wave set is responsible for
!     KPOSSP   - Defines partitioning of global spectral fields among PEs
!     KPTRMS   - Pointer to the first wave number of a given a-set
!     KALLMS   - Wave numbers for all wave-set concatenated together 
!                to give all wave numbers in wave-set order
!     KDIM0G   - Defines partitioning of global spectral fields among PEs

!                 GRIDPOINT SPACE                  
!     KFRSTLAT    - First latitude of each a-set in grid-point space
!     KLSTTLAT    - Last latitude of each a-set in grid-point space
!     KFRSTLOFF   - Offset for first lat of own a-set in grid-point space
!     KPTRLAT     - Pointer to the start of each latitude
!     KPTRFRSTLAT - Pointer to the first latitude of each a-set in 
!                   NSTA and NONL arrays
!     KPTRLSTLAT  - Pointer to the last latitude of each a-set in
!                   NSTA and NONL arrays
!     KPTRFLOFF   - Offset for pointer to the first latitude of own a-set
!                   NSTA and NONL arrays, i.e. nptrfrstlat(myseta)-1
!     KSTA        - Position of first grid column for the latitudes on a 
!                   processor. The information is available for all processors.
!                   The b-sets are distinguished by the last dimension of 
!                   nsta().The latitude band for each a-set is addressed by 
!                   nptrfrstlat(jaset),nptrlstlat(jaset), and 
!                   nptrfloff=nptrfrstlat(myseta) on this processors a-set.
!                   Each split latitude has two entries in nsta(,:) which 
!                   necessitates the rather complex addressing of nsta(,:)
!                   and the overdimensioning of nsta by nprgpns.
!     KONL        - Number of grid columns for the latitudes on a processor.
!                   Similar to nsta() in data structure.
!     LDSPLITLAT  - TRUE if latitude is split in grid point space over 
!                   two a-sets

!                FOURIER SPACE
!     KULTPP   - number of latitudes for which each a-set is calculating 
!                the FFT's.
!     KPTRLS   - pointer to first global latitude of each a-set for which
!                it performs the Fourier calculations

!                 LEGENDRE
!     PMU      - sin(Gaussian latitudes)
!     PGW      - Gaussian weights
!     PRPNM    - Legendre polynomials

!     Method.
!     -------

!     Externals.  SET_RESOL - set resolution
!     ----------  

!     Author.
!     -------
!        Mats Hamrud *ECMWF*

!     Modifications.
!     --------------
!        Original : 00-03-03

!     ------------------------------------------------------------------

#include "tsmbkind.h"


IMPLICIT NONE

INTEGER_M ,OPTIONAL, INTENT(IN)  :: KRESOL

INTEGER_M ,OPTIONAL, INTENT(OUT) :: KSPEC
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KSPEC2
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KSPEC2G
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KSPEC2MX
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KNUMP
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KGPTOT
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KGPTOTG
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KGPTOTMX
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KFRSTLOFF
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KPTRFLOFF

INTEGER_M ,OPTIONAL, INTENT(OUT) :: KMYMS(:)
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KASM0(0:)
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KUMPP(:)
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KPOSSP(:)
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KPTRMS(:)
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KALLMS(:)
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KDIM0G(0:)
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KFRSTLAT(:)
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KLSTLAT(:)
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KPTRLAT(:)
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KPTRFRSTLAT(:)
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KPTRLSTLAT(:)
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KSTA(:,:)
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KONL(:,:)
LOGICAL   ,OPTIONAL, INTENT(OUT) :: LDSPLITLAT(:)

INTEGER_M ,OPTIONAL, INTENT(OUT) :: KULTPP(:)
INTEGER_M ,OPTIONAL, INTENT(OUT) :: KPTRLS(:)

REAL_B    ,OPTIONAL, INTENT(OUT) :: PMU(:)
REAL_B    ,OPTIONAL, INTENT(OUT) :: PGW(:)
REAL_B    ,OPTIONAL, INTENT(OUT) :: PRPNM(:,:)


END SUBROUTINE TRANS_INQ






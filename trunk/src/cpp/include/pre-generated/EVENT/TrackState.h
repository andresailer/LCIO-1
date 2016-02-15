// -*- C++ -*-
// AID-GENERATED
// =========================================================================
// This class was generated by AID - Abstract Interface Definition          
// DO NOT MODIFY, but use the org.freehep.aid.Aid utility to regenerate it. 
// =========================================================================
#ifndef EVENT_TRACKSTATE_H
#define EVENT_TRACKSTATE_H 1

#include "EVENT/LCObject.h"
#include "LCIOSTLTypes.h"
#include "empty_ignore.h"

namespace EVENT {


class TrackState ;
/**Vector of (pointers to) TrackStates.*/
typedef std::vector<TrackState*> TrackStateVec ;
/** The LCIO TrackState class.
 * 
 * @author gaede, engels
 * @version $Id:$
 */

class TrackState : public LCObject {

public: 
    /// Destructor.
    virtual ~TrackState() { /* nop */; }


    /** Useful typedef for template programming with LCIO */
    typedef TrackState lcobject_type ;


    static const int AtOther = 0 ; // any location other than the ones defined below	     
    static const int AtIP = 1 ;							    
    static const int AtFirstHit = 2 ; 							    
    static const int AtLastHit = 3 ;							    
    static const int AtCalorimeter = 4 ;						    
    static const int AtVertex = 5 ;     
    static const int LastLocation = AtVertex  ;     
    
     /** The location of the track state.
     *   Location can be set to: TrackState::AtIP, TrackState::AtFirstHit, TrackState::AtLastHit, TrackState::AtCalorimeter, TrackState::AtVertex, TrackState::AtOther
     */
    virtual int getLocation() const = 0;

    /** Impact paramter of the track
     *  in (r-phi).
     */
    virtual float getD0() const = 0;

    /** Phi of the track at the reference point.
     * @see getReferencePoint
     */
    virtual float getPhi() const = 0;

    /** Omega is the signed curvature of the track in [1/mm].
     * The sign is that of the particle's charge.
     */
    virtual float getOmega() const = 0;

    /** Impact paramter of the track
     *  in (r-z).
     */
    virtual float getZ0() const = 0;

    /** Lambda is the dip angle of the track in r-z at the reference point. 
     * @see getReferencePoint
     */
    virtual float getTanLambda() const = 0;

    /** Covariance matrix of the track parameters. Stored as lower triangle matrix where
     * the order of parameters is:   d0, phi, omega, z0, tan(lambda).
     * So we have cov(d0,d0), cov( phi, d0 ), cov( phi, phi), ...
     */
    virtual const FloatVec & getCovMatrix() const = 0;

    /** Reference point of the track parameters, e.g. the origin at the IP, or the position
     *  of the first/last hits or the entry point into the calorimeter.
     */
    virtual const float* getReferencePoint() const = 0;
}; // class
} // namespace EVENT
#endif /* ifndef EVENT_TRACKSTATE_H */

//
//  ConstraintBase.h
//  BulletSourceTest
//
//  Created by Ryan Bartley on 4/7/14.
//
//

#pragma once

#include "Common.h"
#include "PhyObjBase.h"

namespace bullet {
	
class ConstraintBase {
public:
	
	struct Format {
		Format();
		
		void setObjA( const PhyObjBaseRef &objA ) { mObjA = objA; }
		void setObjB( const PhyObjBaseRef &objB ) { mObjB = objB; }
		
	protected:
		PhyObjBaseRef	mObjA, mObjB;
		
	};
	
	//! Returns the Typed Constraint Type.
	btTypedConstraintType getConstraintType() { return mConstraint->getConstraintType(); }
	
	//! The default global value of a parameter (such as ERP or CFM), optionally provide the axis (0..5). If no axis is provided, it uses the default axis for this constraint.
	void setParam(int num, btScalar value, int axis = -1) { mConstraint->setParam( num, value, axis ); }
	//! Returns the local value of parameter.
	btScalar getParam(int num, int axis = -1) const { return mConstraint->getParam( num, axis ); }
	
	//! Returns a pointer to the typed constraint.
	btTypedConstraint* getTypedConstraint() { return mConstraint; }
	//! Returns a const pointer to the typed constraint.
	const btTypedConstraint* getTypedConstraint() const { return mConstraint; }
	
	//! Sets the Breaking Threshold of this Constraint.
	void setBreakingImpulseThreshold( btScalar threshold ) { mConstraint->setBreakingImpulseThreshold( threshold ); }
	//! Returns the Breaking Threshold of this Constraint.
	btScalar getBreakingImpulseThreshold() { return mConstraint->getBreakingImpulseThreshold(); }
	
	//! Returns a btRigidBodyRef of Rigid Body A stored by the constraint.
	btRigidBodyRef getRigidBodyA() { return btRigidBodyRef( &mConstraint->getRigidBodyA() ); }
	//! Returns a btRigidBodyRef of Rigid Body B stored by the constraint.
	btRigidBodyRef getRigidBodyB() { return btRigidBodyRef( &mConstraint->getRigidBodyB() ); }
	
	//! Sets the size to draw the constraint, scales in all directions.
	void setDebugDrawSize( btScalar size ) { mConstraint->setDbgDrawSize( size ); }
	//! Returns the current set debug draw size.
	btScalar getDebugDrawSize() { return mConstraint->getDbgDrawSize(); }
	
protected:
	ConstraintBase();
	
	btTypedConstraint* mConstraint;
};
	
}

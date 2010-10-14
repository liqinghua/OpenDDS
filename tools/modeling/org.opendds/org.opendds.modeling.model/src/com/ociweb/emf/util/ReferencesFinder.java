/**
 * 
 */
package com.ociweb.emf.util;

import org.eclipse.emf.common.util.BasicEList;
import org.eclipse.emf.common.util.EList;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EReference;
import org.eclipse.emf.ecore.impl.EReferenceImpl;

/**
 * Given an EMF class definition and object representation, find object references.
 */
public class ReferencesFinder {

	/**
	 * Find all references in an object that are instances of a specified base type.
	 * @param <T> The EObject derived base type
	 * @param superType The base type to check if the reference is an instance of
	 * @param referrerObject The object that has the references
	 * @return the list of references
	 */
	public static <T extends EObject> EList<T> findInstancesOf(Class superType, EObject referrerObject) {
		EList<T> refs = new BasicEList<T>();
		for (EObject obj : referrerObject.eCrossReferences()) {
			if (superType.isInstance(obj)) {
				refs.add((T) obj);
				System.out.println("    Reference found: " + obj.toString());
			}
		}
		return refs;
	}

	/**
	 * Find references in a class that are inherited from a super type.
	 * @param superType The parent type for the references
	 * @param referrer The class containing the references
	 * @return The list of referrer references that inherit from superType
	 */
	public static EList<EClass> findDerivedFrom(EClass superType, EClass referrer) {
		EList<EClass> refs = new BasicEList<EClass>();
		for (EReference ref : referrer.getEAllReferences()) {
			EClass clazz = ((EReferenceImpl) ref).basicGetEReferenceType();
			if (superType.isSuperTypeOf(clazz)) {
				refs.add(clazz);
			}
		}
		return refs;
	}

}

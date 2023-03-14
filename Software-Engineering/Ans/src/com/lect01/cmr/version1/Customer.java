package com.lect01.cmr.version1;
import utils.*;

import java.lang.reflect.Type;
//java.doc
/**
 *
 * @overview
 * 	Represents people with which we have a potential commercial relationship.
 *
 * @attributes
 * 	id		Integer		int
 * 	name	String
 * 	address	String
 *  dob		Date
 *
 * @object
 * 	A typical Customer is (id, name)
 *
 * @abstract_properties (domain constraints)
 * 	mutable(id) = false /\ option(id) = false /\ min(id) = 1
 * 	mutable(name) = true /\ option(name) = false /\ length(name) = 50
 *  optional(address) = true
 *
 * @author LENOVO
 *
 */

public class Customer {
    /** OBJECT REPRESENTATION
     * - field declaration (<= @attributes)
     * - domain constraints (<= @abstract_properties)
     * */

    @DomainConstraint(mutable = false, optional = false, min = 1)
    private int id;

    @DomainConstraint(mutable = false, optional = false, length = 50)
    private String name;

    /** OPERATION SPECIFICATION
     * types: constructor, mutator, observer, default, helper
     *
     */
//    constructor
    /**
     * @requires (pre-condition)
     *  (empty)
     *
     * @effects (post-condition)
     *  if i, n are valid
     *      initialise this as Customer(id = i, name = n)
     *  else
     *      throw new NotPossibleException
     *
     * @modifies(side-effects)
     *  (empty)
     *
     * @param i (id)
     * @param n (name)
     */
    public Customer(
            @AttrRef("id")
            int i,
            @AttrRef("name")
            String n){
//        todo
    }
//    mutator

    /** This is the mutator for name
     * @effects
     *  if name is valid
     *      set this.name = name
     *      return true
     *  else
     *      return false
     */

    @DOpt(type = OptType.Mutator) @AttrRef("name")
    public boolean setName(){
//        todo
        return false; //dummy
    }
//    observer
    /** This is the observer for id
     * @ effects
     *  return this.id
     */
    @DOpt(type = OptType.Observer) @AttrRef("id")
    public int getId(){
        return -1;
    }

    /** This is the observer for name
     * @ effects
     *  return this.name
     */
    @DOpt(type = OptType.Observer) @AttrRef("name")
    public int getName(){
        return -1;
    }
//    default
    @Override
    public String toString(){
//        todo
        return null;
    }
//    helper
//    validation methods

    /**
     * Validate id against domain constraint
     * @effects
     *  if id is valid
     *      return True
     *  else
     *      return False
     * @param id (id)
     */

    private boolean validateID(int id){
        return false;
    }

    /**
     * Validate name against domain constraint
     * @effects
     *  if name is valid
     *      return True
     *  else
     *      return False
     * @param name (name)
     */

    private boolean validateName(int name){
        return false;
    }
}


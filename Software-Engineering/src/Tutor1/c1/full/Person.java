package tutor.c1.full;

import java.sql.Blob;

import utils.AttrRef;
import utils.DOpt;
import utils.DomainConstraint;
import utils.NotPossibleException;
import utils.OptType;

/**
 * @overview
 *      Represents a general person which owned a phone
 *
 * @attributes
 *      id      Integer         int
 *      name    String
 *      phone   MobilePhone
 *
 * @object
 *      A typical Person is (id, name)
 *
 * @abstract_properties (domain constraints)
 *      mutable(id) = false /\ optional(id) = false /\ min(id) = 1
 *      mutable(name) = true /\ optional(name) = false /\ length(name) = 30
 *      mutable(phone) = true /\ optional(phone) = true
 *
 * @author Vivarium
 */

public class Person {
    /** OBJECT REPRESENTATION
     * - field declaration (<= @attributes)
     * - domain constraints (<= @abstract_properties)
     */
    //Constants
    private static final int MIN_ID = 1;
    private static final int LEN_NAME = 30;
    @DomainConstraint(type = "Integer", mutable = false, optional = false, min = MIN_ID)
    private int id;

    @DomainConstraint(type = "String", optional = false, length = LEN_NAME)
    private String name;

    @DomainConstraint(type = "MobilePhone")
    private MobilePhone phone;

    /** OPERATION SPECIFICATION
     * types: constructor, mutator, observer, default, helper
     */
    // Constructor
    public Person(
            @AttrRef("id") int id,
            @AttrRef("name") String name) throws NotPossibleException{
    	if (!validateID(id)) {
    		throw new NotPossibleException("Person.init: Invalid Id: " + id);
    	}
    	if (!validateName(name)) {
    		throw new NotPossibleException("Person.init: Invalid Name: " + name);
    	}
    	this.id = id;
    	this.name = name;
    }

    //Observer
    /**
     * @effects
     *      return id
     */
    @DOpt(type = OptType.Observer) @AttrRef("id")
    public int getId() {
        return id;
    }

    /**
     * @effects
     *      return phone
     */
    @DOpt(type = OptType.Observer) @AttrRef("phone")
    public MobilePhone getPhone() {
        return phone;
    }

    /**
     * @effects
     *      return name
     */
    @DOpt(type = OptType.Observer) @AttrRef("name")
    public String getName() {
        return name;
    }

    //Mutator

    /**
     * @effects
     *      if name is valid
     *          set this.name = name
     *          return true
     *      else:
     *          return false
     *
     */
    @DOpt(type = OptType.Mutator) @AttrRef("name")
    public boolean setName (String name) {
    	if(validateName(name)) {
        this.name = name;
        return true;
    	}
    	return false;
    }

    /**
     * @effects
     *      if phone is valid
     *          set this.phone = phone
     *          return true
     *      else:
     *          return false
     *
     */
    @DOpt(type = OptType.Mutator) @AttrRef("phone")
    public boolean setPhone(MobilePhone phone) {
    	if(validatePhone(phone)) {
    		this.phone = phone;
    		return true;
    	}
    	return false;
    }
    
    @Override
    public String toString() {
    	StringBuilder sb = new StringBuilder("Person: <");
    	sb.append("ID: ").append(id).append(", ")
    	  .append("Name: ").append(name).append(">");
    	return sb.toString();
    }
    
    @Override
    public boolean equals(Object o) {
    	if (o == null || !(o instanceof Person)) 
    		return false;
    	else {
    		Person otherPerson = (Person) o;
    		return id == otherPerson.getId();
    	}
    }
    	
    public boolean repOK() {
    	if (validateID(id) && validateName(name))
    		return true;
    	else
    		return false;
    }
    
    public boolean validateID(int id) {
    	if (id < 1)
    		return false;
    	else
    		return true;
    }
    
    public boolean validateName (String name) {
    	if (name == null || name.length() == 0)
    		return false;
    	if (name.length() > 30)
    		return false;
    	else
    		return true;
    }
    
    public boolean validatePhone (MobilePhone phone) {
    	return true;
    }
}

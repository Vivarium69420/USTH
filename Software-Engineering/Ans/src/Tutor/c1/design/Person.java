package Tutor.c1.design;
import Tutor.c1.design.MobilePhone;
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
    public void setName(String name) {
        this.name = name;
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
    public void setPhone(MobilePhone phone) {
        this.phone = phone;
    }

    // default
    @DOpt(type = OptType.Default)
    @Override
    public String toString(){return "a";}

    // helper
    /**
     * @effects
     *      if this == obj
     *          return true
     *      else:
     *          return false
     *
     */
    @DOpt(type = OptType.Helper)
    @Override
    public boolean equals(Object obj){return true;}


    /**
     * Validate id against domain constraint
     * @effects
     *  if id is valid
     *      return true
     *  else
     *      return false
     */
    @DOpt(type = OptType.Helper)
    private boolean validateID(int id){return true;}

    /**
     * Validate name against domain constraint
     * @effects
     *  if name is valid
     *      return true
     *  else
     *      return false
     */
    @DOpt(type = OptType.Helper)
    private boolean validateName(String name){return true;}

    /**
     * Validate phone against domain constraint
     * @effects
     *  if phone is valid
     *      return true
     *  else
     *      return false
     */
    @DOpt(type = OptType.Helper)
    private boolean validatePhone(MobilePhone phone){return true;}

    /**
     * @effects
     *  if this satisfies abstract properties
     *      return true
     *  else:
     *      return false
     */
    @DOpt(type = OptType.Helper)
    public boolean repOK(){
        return true;
    }
}

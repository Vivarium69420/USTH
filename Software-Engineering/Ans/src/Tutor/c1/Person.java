package Tutor.c1;
import utils.*;

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
 *      mutable(id) = false /\ option(id) = false /\ min(id) = 1
 *      mutable(name) = true /\ option(name) = false /\ length(name) = 30
 *      mutable(id) = false /\ option(id) = false /\ min(id) = 1
 *      
 *
 *
 *
 *
 *
 *
 *
 */

public class Person {
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
     *
     */
    // Constructor
    public Person(
            @AttrRef("id") int id,
            @AttrRef("name") String name) throws NotFoundException{

    }

    @DOpt(type = OptType.Observer) @AttrRef("id")
    public int getId() {
        return id;
    }

    //Observer
    @DOpt(type = OptType.Observer) @AttrRef("phone")
    public MobilePhone getPhone() {
        return phone;
    }

    @DOpt(type = OptType.Observer) @AttrRef("name")
    public String getName() {
        return name;
    }

    //Mutator
    @DOpt(type = OptType.Mutator) @AttrRef("name")
    public void setName(String name) {
        this.name = name;
    }

    @DOpt(type = OptType.Mutator) @AttrRef("phone")
    public void setPhone(MobilePhone phone) {
        this.phone = phone;
    }

    @Override
    public String toString(){return "a";}

    @Override
    public boolean equals(Object o){return true;}

    private boolean validateID(int id){return true;}

    private boolean validateName(String name){return true;}

    private boolean validatePhone(MobilePhone phone){return true;}






}

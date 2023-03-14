package Tutor.c1.design;
import utils.AttrRef;
import utils.DOpt;
import utils.DomainConstraint;
import utils.NotPossibleException;
import utils.OptType;

/**
 * @overview
 *      Represents a general Mobile Phone
 *
 * @attributes
 *      manName     String
 *      model       String
 *      color       Character
 *      year        Integer         int
 *      guaranteed  Boolean

 * @object
 *      A typical Person is (manName, model, color, year, guaranteed)
 *
 * @abstract_properties (domain constraints)
 *      mutable(manName) = false /\ optional(manName) = false /\ length(manName) = 100
 *      mutable(model) = true /\ optional(model) = false /\ length(model) = 50
 *      mutable(color) = true /\ optional(color) = false /\ length(color) = 1
 *      mutable(year) = false /\ optional(year) = false /\ min(year) = 1970
 *      mutable(guaranteed) = true /\ optional(guaranteed) = true
 *
 * @author Vivarium
 */

public class MobilePhone {
    /** OBJECT REPRESENTATION
     * - field declaration (<= @attributes)
     * - domain constraints (<= @abstract_properties)
     */

    // Constants
    private static final int LEN_NAME = 100;
    private static final int LEN_MODEL = 50;
    private static final int LEN_COLOR = 1;
    private static final int MIN_YEAR = 1970;

    @DomainConstraint(type = "String", mutable = false, optional = false, length = LEN_NAME)
    private String manName;

    @DomainConstraint(type = "String", mutable = false, optional = false, length = LEN_MODEL)
    private String model;

    @DomainConstraint(type = "Character", optional = false, length = LEN_COLOR)
    private char color;

    @DomainConstraint(type = "Integer", min = MIN_YEAR)
    private int year;

    @DomainConstraint(type = "Boolean")
    private boolean guaranteed;

    //Constructor
    public MobilePhone(
            @AttrRef("manName") String manName,
            @AttrRef("model") String model,
            @AttrRef("color") char color,
            @AttrRef("year") int year,
            @AttrRef("guaranteed") int guaranteed) throws NotPossibleException{}

    // Observer
    @DOpt(type = OptType.Observer) @AttrRef("manName")
    public String getManName() {
        return manName;
    }

    @DOpt(type = OptType.Observer) @AttrRef("model")
    public String getModel() {
        return model;
    }

    @DOpt(type = OptType.Observer) @AttrRef("color")
    public char getColor() {
        return color;
    }

    @DOpt(type = OptType.Observer) @AttrRef("year")
    public int getYear() {
        return year;
    }
    @DOpt(type = OptType.Observer) @AttrRef("guaranteed")
    public boolean getGuaranteed(){return guaranteed;}

    // mutator
    @DOpt(type = OptType.Mutator) @AttrRef("guaranteed")
    public boolean setGuaranteed(boolean guaranteed){return true;}

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
    @Override
    public boolean equals(Object obj){return true;}


    /**
     * Validate manName against domain constraint
     * @effects
     *  if manName is valid
     *      return true
     *  else
     *      return false
     */
    private boolean validateManName(String manName){return true;}

    /**
     * Validate model against domain constraint
     * @effects
     *  if model is valid
     *      return true
     *  else
     *      return false
     */
    private boolean validateModel(String model){return true;}

    /**
     * Validate color against domain constraint
     * @effects
     *  if color is valid
     *      return true
     *  else
     *      return false
     */
    private boolean validateColor(char color){return true;}

    /**
     * Validate year against domain constraint
     * @effects
     *  if year is valid
     *      return true
     *  else
     *      return false
     */
    private boolean validateYear(int year){return true;}


    /**
     * @effects
     *  if this satisfies abstract properties
     *      return true
     *  else:
     *      return false
     */
    public boolean repOK(){
        return true;
    }

}

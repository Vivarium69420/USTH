package tutor.c1.full;

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
 *
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
            @AttrRef("year") int year) throws NotPossibleException{
    	if (!validateManName(manName)) {
    		throw new NotPossibleException("MobilePhone.init: Invalid manName: " + manName);
    	}
    	if (!validateModel(model)) {
    		throw new NotPossibleException("MobilePhone.init: Invalid model: " + model);
    	}
    	if(!validateColor(color)){
    		throw new NotPossibleException("MobilePhone.init: Invalid color: " + color);
    	}
    	if(!validateYear(year)) {
    		throw new NotPossibleException("MobilePhone.init: Invalid year: " + year);
    	}
    	this.manName = manName;
    	this.model = model;
    	this.color = color;
    	this.year = year;
    }

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
    public boolean getGuaranteed(){
    	return guaranteed;
    }

    // mutator
    @DOpt(type = OptType.Mutator) @AttrRef("guaranteed")
    public boolean setGuaranteed(boolean guaranteed){
    	this.guaranteed = guaranteed;
    	return true;
    }

    // default
    @Override
    public String toString(){
    	StringBuilder sb = new StringBuilder("MobilePhone: <");
    	sb.append("manName: ").append(manName).append(", ")
    	  .append("Model: ").append(model).append(", ")
    	  .append("Color: ").append(color).append(", ")
    	  .append("Guaranteed: ").append(guaranteed).append(">");
    	return sb.toString();
    }

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
    public boolean equals(Object obj){
    	if (obj == null || !(obj instanceof MobilePhone))
    		return false;
    	else {
    		MobilePhone otherMobilePhone = (MobilePhone) obj;
    		return manName.equals(otherMobilePhone.getManName()) &&
    				model.equals(otherMobilePhone.getManName()) &&
    				color == otherMobilePhone.getColor() &&
    				guaranteed == otherMobilePhone.getGuaranteed();
    	}
    }


    /**
     * Validate manName against domain constraint
     * @effects
     *  if manName is valid
     *      return true
     *  else
     *      return false
     */
    private boolean validateManName(String manName){
    	return manName != null && manName.length() <= 100;
    }

    /**
     * Validate model against domain constraint
     * @effects
     *  if model is valid
     *      return true
     *  else
     *      return false
     */
    private boolean validateModel(String model) {
    	return model != null && model.length() <= 50;
    }

    /**
     * Validate color against domain constraint
     * @effects
     *  if color is valid
     *      return true
     *  else
     *      return false
     */
    private boolean validateColor(char color) {
    	char[] validColors = {'R', 'O', 'Y', 'B', 'P'};
    	for (char vc : validColors) {
    		if (color == vc)
    			return true;
    	}
    	return false;
    }

    /**
     * Validate year against domain constraint
     * @effects
     *  if year is valid
     *      return true
     *  else
     *      return false
     */
    private boolean validateYear(int year){
    	return year >= 1970;
    }


    /**
     * @effects
     *  if this satisfies abstract properties
     *      return true
     *  else:
     *      return false
     */
    public boolean repOK(){
        return validateColor(color) && validateManName(manName) && validateModel(model) && validateYear(year);
    }
}
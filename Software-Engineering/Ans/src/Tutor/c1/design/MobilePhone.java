package Tutor.c1.design;
import utils.AttrRef;
import utils.DOpt;
import utils.DomainConstraint;
import utils.NotPossibleException;
import utils.OptType;
import java.lang.reflect.Type;

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

    private boolean guaranteed;
}

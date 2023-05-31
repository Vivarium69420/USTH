package studentman;
import utils.AttrRef;
import utils.DomainConstraint;
import utils.NotPossibleException;

/**
 * @overview 
 * 			UndergradStudent is a sub-class of Student representing an student that is
 * 			in an undergraduate course
 * 
 * @abstract_properties
 * 			P_Student /\
 * 			min(id)=10^5 /\ max(id)=10^8 
 * @object
 * 			A typical UndergradStudent is <i, n, p, a>, where i (id), n (name), p (phoneNumber), a (address)
 
 * @author BI12-076 Mai Hai Dang
 *
 */
public class UndergradStudent extends Student{

	private static final int MIN_UNDERGRADSTUDENT_ID = 100000;
	private static final int MAX_UNDERGRADSTUDENT_ID = 100000000;
	
	// constructor methods
	/**
	 * @effect <pre>
	 * 			if id, name, phoneNumber, address are valid
	 * 				initialize this as UndergradStudent:<id, name, phoneNumber, address>
	 * 			else
	 * 				throws NotPossibleException
	 * 			</pre>
	 */
	public UndergradStudent(
			@AttrRef("id") int id,
			@AttrRef("name") String name,
			@AttrRef("phoneNumber") String phoneNumber,
			@AttrRef("address") String address) throws NotPossibleException {
		super(id, name, phoneNumber, address);
	}
	
	// methods
	/**
	 * @effects <pre>
	 * 			return a string representation of this object
	 * 			</pre>
	 */
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder("UndergradStudent: <");
    	sb.append("Id: ").append(getId()).append(", ")
    	  .append("Name: ").append(this.getName()).append(", ")
    	  .append("Phone Number: ").append(getPhoneNumber()).append(", ")
    	  .append("Address: ").append(getAddress()).append(">");
    	return sb.toString();
	}
	
	/**
	 * @effects <pre>
	 * 			if id is valid
	 * 				return true
	 * 			else
	 * 				return false
	 * 			</pre>
	 */
	@Override
	@DomainConstraint(type = "Integer", mutable = false, optional = false, min = MIN_UNDERGRADSTUDENT_ID, max = MAX_UNDERGRADSTUDENT_ID)
	protected boolean validateId(int id) {
		if (!(super.validateId(id)))
			return false;
		
		if (id < MIN_UNDERGRADSTUDENT_ID || id > MAX_UNDERGRADSTUDENT_ID)
			return false;
		else
			return true;
	}

	/**
	 * @effects
	 * 
	 *          <pre>
	 * 			if o is null
	 * 				return false
	 * 			else if o is not an instance of UndergradStudent
	 * 				return false
	 * 			else
	 * 				return this.id = o.id
	 *          </pre>
	 */
	public int compareTo(Student o){
		return super.compareTo(o);
	}
}
